################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/subdir.mk
-include NDefLib/RecordType/subdir.mk
-include NDefLib/subdir.mk
-include M24SR/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: pre-build main-build

# Main-build Target
main-build: HelloWorld_Async_M24SR-debug.elf

# Tool invocations
HelloWorld_Async_M24SR-debug.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU G++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -L"D:\30_ARM_WS\workspace\HelloWorld_Async_M24SR\mbed\TARGET_NUCLEO_F401RE\TOOLCHAIN_GCC_ARM" -Wl,--wrap=main -Wl,--wrap=_memalign_r -Wl,--wrap=exit -Wl,--wrap=atexit -DMBED_DEBUG -DMBED_TRAP_ERRORS_ENABLED=1 -Wl,-n -Wl,--start-group -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys -Wl,--end-group,-specs=nono.specs -specs=nosys.specs -T"D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/Debug/linker-script-debug.ld" -Wl,-Map=output.map -Wl,--gc-sections -fno-exceptions -fno-rtti -o "HelloWorld_Async_M24SR-debug.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

pre-build:
	-@echo 'Creating makefile.defs:'
	-echo "export PREPROC_CMD = C:\Ac6\SystemWorkbench\plugins\fr.ac6.mcu.externaltools.arm-none.win32_1.15.0.201708311556\tools\compiler\bin/arm-none-eabi-cpp -E -P" > D:/30_ARM_WS/workspace/HelloWorld_Async_M24SR/makefile.defs
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "HelloWorld_Async_M24SR-debug.elf" "HelloWorld_Async_M24SR.bin"
	arm-none-eabi-size -B "HelloWorld_Async_M24SR-debug.elf"
	make ldclean
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: main-build pre-build post-build

-include ../makefile.targets
