################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TestDriver.cpp \
../DESDriver.cpp \
../des.cpp 

O_SRCS += \
../endian.o 

OBJS += \
./DESDriver.o \
./TestDriver.o \
./des.o 

CPP_DEPS += \
./TestDriver.d \
./DESDriver.d \
./des.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -m64 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


