################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DESDriver.cpp \
../TestDriver.cpp \
../des.cpp 

O_SRCS += \

OBJS += \
./DESDriver.o \
./TestDriver.o \
./des.o 

CPP_DEPS += \
./DESDriver.d \
./TestDriver.d \
./des.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++  -Wall -c -Os -fmessage-length=0  -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


