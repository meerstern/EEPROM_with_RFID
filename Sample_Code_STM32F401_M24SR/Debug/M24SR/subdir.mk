################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../M24SR/M24SR.cpp \
../M24SR/NDefNfcTagM24SR.cpp 

OBJS += \
./M24SR/M24SR.o \
./M24SR/NDefNfcTagM24SR.o 

CPP_DEPS += \
./M24SR/M24SR.d \
./M24SR/NDefNfcTagM24SR.d 


# Each subdirectory must supply rules for building sources it contributes
M24SR/%.o: ../M24SR/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 '-D__MBED__=1' '-DDEVICE_I2CSLAVE=1' '-D__FPU_PRESENT=1' '-DDEVICE_PORTOUT=1' -DUSBHOST_OTHER -DTARGET_NUCLEO_F401RE -DTARGET_RTOS_M4_M7 '-DDEVICE_RTC=1' '-DDEVICE_SERIAL_ASYNCH=1' -DTARGET_STM32F4 -D__CMSIS_RTOS -DTOOLCHAIN_GCC '-DDEVICE_I2C_ASYNCH=1' -DTARGET_CORTEX_M -DTARGET_LIKE_CORTEX_M4 -DTARGET_M4 '-DMBED_BUILD_TIMESTAMP=1554477765.9' '-DDEVICE_SPI_ASYNCH=1' '-DDEVICE_SERIAL=1' '-DDEVICE_INTERRUPTIN=1' -DTARGET_CORTEX '-DDEVICE_I2C=1' '-DTRANSACTION_QUEUE_SIZE_SPI=2' -D__CORTEX_M4 '-DDEVICE_STDIO_MESSAGES=1' -DTARGET_STM32F401RE -DTARGET_FF_MORPHO -DTARGET_FAMILY_STM32 -DTARGET_FF_ARDUINO '-DDEVICE_PORTIN=1' -DTARGET_RELEASE -DTARGET_STM '-DDEVICE_SERIAL_FC=1' '-DTARGET_NAME=NUCLEO_F401RE' '-DDEVICE_PORTINOUT=1' -DTARGET_LIKE_MBED -D__MBED_CMSIS_RTOS_CM '-DDEVICE_SLEEP=1' -DTOOLCHAIN_GCC_ARM '-DDEVICE_SPI=1' -DUSB_STM_HAL '-DDEVICE_ERROR_RED=1' '-DDEVICE_SPISLAVE=1' '-DDEVICE_ANALOGIN=1' '-DDEVICE_PWMOUT=1' -DARM_MATH_CM4 -DTARGET_STM32F401xE -DMBED_DEBUG '-DMBED_TRAP_ERRORS_ENABLED=1' -DMBED_DEBUG '-DMBED_TRAP_ERRORS_ENABLED=1' -DNDEBUG -DNDEBUG -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/M24SR" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/M24SR/ST_INTERFACES" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/M24SR/ST_INTERFACES/Actuators" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/M24SR/ST_INTERFACES/Common" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/M24SR/ST_INTERFACES/Communications" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/M24SR/ST_INTERFACES/Sensors" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/NDefLib" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/NDefLib/RecordType" -I"..//usr/src/mbed-sdk" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/TARGET_NUCLEO_F401RE" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/TARGET_NUCLEO_F401RE/TARGET_STM" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/TARGET_NUCLEO_F401RE/TARGET_STM/TARGET_STM32F4" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/TARGET_NUCLEO_F401RE/TARGET_STM/TARGET_STM32F4/TARGET_STM32F401xE" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/TARGET_NUCLEO_F401RE/TARGET_STM/TARGET_STM32F4/TARGET_STM32F401xE/TARGET_NUCLEO_F401RE" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/TARGET_NUCLEO_F401RE/TARGET_STM/TARGET_STM32F4/TARGET_STM32F401xE/device" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/TARGET_NUCLEO_F401RE/TARGET_STM/TARGET_STM32F4/device" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/drivers" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/hal" -I"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed/platform"  -includeD:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/mbed_config.h -O0 -funsigned-char -fno-delete-null-pointer-checks -fomit-frame-pointer -fmessage-length=0 -fno-builtin -g3 -Wall -Wextra -Wvla -Wno-unused-parameter -Wno-missing-field-initializers -ffunction-sections -fdata-sections -c -fno-exceptions -fno-rtti -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


