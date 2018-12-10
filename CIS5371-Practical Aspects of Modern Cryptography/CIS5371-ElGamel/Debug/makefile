################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: CIS5371-ElGamal test itest test2

# Tool invocations
CIS5371-ElGamal: CIS5371Driver.o ElGamal.o 
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "CIS5371-ElGamal" CIS5371Driver.o ElGamal.o $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
test: test.o ElGamal.o
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "test" test.o ElGamal.o $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

itest: itest.o 
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "itest" itest.o $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

test2: test2.o ElGamal.o
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "test2" test2.o ElGamal.o $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) CIS5371-ElGamal itest test test2 
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
