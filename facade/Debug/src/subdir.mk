################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cipher.cpp \
../src/Facade.cpp \
../src/Reader.cpp \
../src/Writer.cpp \
../src/main.cpp 

OBJS += \
./src/Cipher.o \
./src/Facade.o \
./src/Reader.o \
./src/Writer.o \
./src/main.o 

CPP_DEPS += \
./src/Cipher.d \
./src/Facade.d \
./src/Reader.d \
./src/Writer.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


