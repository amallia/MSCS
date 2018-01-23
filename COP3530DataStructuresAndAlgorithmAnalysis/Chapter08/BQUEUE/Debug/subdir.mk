################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BQUEUE.cpp \
../BQUEUE_driver.cpp \
../BQUEUE_test.cpp 

OBJS += \
./BQUEUE.o \
./BQUEUE_driver.o \
./BQUEUE_test.o 

CPP_DEPS += \
./BQUEUE.d \
./BQUEUE_driver.d \
./BQUEUE_test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


