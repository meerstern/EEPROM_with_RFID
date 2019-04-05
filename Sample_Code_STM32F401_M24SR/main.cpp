#include "mbed.h"
#include "M24SR.h"
#include "ReadUriCallbacks.h"
#include "WriteUriCallbacks.h"


#ifdef TARGET_DISCO_L475VG_IOT01A
// Pins definition for the DISCO_L475VG_IOT01A board
#define NFC_I2C_SDA_PIN     PB_11
#define NFC_I2C_SCL_PIN     PB_10
#define NFC_GPO_PIN         PE_4
#define NFC_RF_DISABLE_PIN  PE_2

#define LED1_PIN    PA_5
#define LED2_PIN    PB_14
#define LED3_PIN    PC_9

#else // X-NUCLEO-NFC01A1

#define NFC_I2C_SDA_PIN     D14
#define NFC_I2C_SCL_PIN     D15
#define NFC_GPO_PIN         D13
#define NFC_RF_DISABLE_PIN  D11

#define LED1_PIN    D8
#define LED2_PIN    D9
#define LED3_PIN    D2

#endif // DISCO_L475VG_IOT01A

#define M24SR_ADDR          0xAC 

/* Status PIN */
DigitalOut sessionOpenLed(LED1_PIN); // tag session is open
DigitalOut ongoingOperationLed(LED2_PIN); // ongoing read/write operation
DigitalOut sessionClosedLed(LED3_PIN); // tag session is closed


/** Variable set to true when we receive an interrupt from the NFC component */
static volatile bool nfcInterruptFlag = false;

/** Variable set to true when the user press the board user button */
static volatile bool buttonPress = false;

/** NFC ISR called when the NFC component has a message ready */
static void nfc_interrupt_callback()
{
    nfcInterruptFlag = true;
}

static void set_button_press()
{
    buttonPress = true;
}

int main()
{
    printf("\n\rNFC HelloWord Async example started\n\r");
        
    InterruptIn userButton(USER_BUTTON);
    userButton.fall(set_button_press);

    // Create the NFC component
    I2C i2cChannel(NFC_I2C_SDA_PIN, NFC_I2C_SCL_PIN);
    
    M24SR nfcTag(M24SR_ADDR,i2cChannel, &nfc_interrupt_callback, NFC_GPO_PIN, NFC_RF_DISABLE_PIN);

    // init needed to enable the component
    nfcTag.init(NULL);
    // No call back needed since default behavior is sync
    nfcTag.get_session();
    //nfcTag.manage_I2C_GPO(M24SR::I2C_ANSWER_READY); // Switch to async mode

    NDefLib::NDefNfcTag &tag = nfcTag.get_NDef_tag();

    printf("Init done\n\r");

    // Create the callback to use to write a tag
    WriteUriCallbacks NDefWriteCallback(sessionOpenLed,ongoingOperationLed,sessionClosedLed);
    ReadUriCallbacks NDefReadCallback(sessionOpenLed,ongoingOperationLed,sessionClosedLed);
    tag.set_callback(&NDefWriteCallback); // Set the callback
    tag.open_session(); // Start the callback chain

    printf("Start main loop\n\r");

    while(true) {
        
        if (nfcInterruptFlag) {
            nfcInterruptFlag = false;
            // Manage an async event from the NFC component
            nfcTag.manage_event();
        }

        if (buttonPress) {
            buttonPress = false;
            printf("\n\rPressed\n\r");
            tag.set_callback(&NDefReadCallback);
            tag.open_session();
        }
        
        __WFE(); // Wait For Event
    }
}
