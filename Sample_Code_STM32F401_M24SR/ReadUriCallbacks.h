/**
  ******************************************************************************
  * @file       ReadUriCallbacks.cpp
  * @date       12/07/2017
  * @brief      Class to read and print a URI tag.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

#include "mbed.h"
#include "NDefLib/RecordType/RecordURI.h"

/**
 * Chain of callback that will read a NDef Message and print all the
 * record of type URI.
 * After each operation the class will switch on a led
 */
class ReadUriCallbacks : public NDefLib::NDefNfcTag::Callbacks {
 
    DigitalOut &mOnOpenSession;
    DigitalOut &mOnRead;
    DigitalOut &mOnCloseSession;
 
    NDefLib::Message mMsg;
 
public:
 
    /**
     * create the callback chain
     * @param onOpenSession led to switch on when the session open
     * @param onWrite led to switch on when the write end
     * @param onCloseSession led to switch on when the session end
     */
    ReadUriCallbacks(DigitalOut &onOpenSession,DigitalOut &onRead,
        DigitalOut &onCloseSession):mOnOpenSession(onOpenSession),
        mOnRead(onRead),mOnCloseSession(onCloseSession){};
 
    /**
     * crate the new message and write it
     * @param tag tag where write the message
     * @param success true if the session correctly open
     */
    virtual void on_session_open(NDefLib::NDefNfcTag *tag,bool success){
        if (!success) {
            printf("Error opening the session\r\n");
        }//else
        printf("Session opened\r\n");
        //ask to have an interrupt when the command finish
        mOnOpenSession=1;
        mOnCloseSession=0;
        
        tag->read(&mMsg);
    }
 
    /**
     * request to close the session
     * @param tag tag where close the session
     * @param success true if the message is correctly wrote
     * @param message wrote
     */
    virtual void on_message_read(NDefLib::NDefNfcTag *tag,bool success,
        const NDefLib::Message*){
 
        if (!success) {
            printf("Error Reading tag!\r\n");
        } else {
            const uint32_t nRecords =mMsg.get_N_records();
            printf("Read %d records!\r\n",nRecords);
            for (uint32_t i=0;i<nRecords;i++) {
                if (mMsg[i]->get_type()== NDefLib::Record::TYPE_URI) {
                    NDefLib::RecordURI *rUri = (NDefLib::RecordURI *)mMsg[i];
                    printf("UriType: %x\r\nUriContent: %s\r\n",
                        rUri->get_uri_id(),
                        rUri->get_content().c_str());
                }//if
            }//for
            NDefLib::Message::remove_and_delete_all_record(mMsg);
            mOnRead=1;
        }//if-else
        tag->close_session();
    }
 
    /**
     * switch on the led
     * @param tag where the session is closed
     * @param success true if the session is correctly close
     */
    virtual void on_session_close(NDefLib::NDefNfcTag*, bool success) {
        if (success) {
            printf("Session closed\r\n");
            mOnCloseSession=1;
            mOnOpenSession=0;
            mOnRead=0;
        } else {
            printf("Error opening the session\r\n");
        }
    }
};
