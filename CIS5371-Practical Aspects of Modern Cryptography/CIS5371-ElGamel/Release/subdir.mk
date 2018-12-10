################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CIS5371Driver.cpp \
../ElGamal.cpp \
../itest.cpp \
../test.cpp 

O_SRCS += \
../test.o 

OBJS += \
./CIS5371Driver.o \
./ElGamal.o \
./itest.o \
./test.o 

CPP_DEPS += \
./CIS5371Driver.d \
./ElGamal.d \
./itest.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


