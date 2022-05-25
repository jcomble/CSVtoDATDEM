################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../connection.cpp \
../file.cpp \
../main.cpp \
../node.cpp \
../tablemaker.cpp \
../traffic.cpp \
../view.cpp 

CPP_DEPS += \
./connection.d \
./file.d \
./main.d \
./node.d \
./tablemaker.d \
./traffic.d \
./view.d 

OBJS += \
./connection.o \
./file.o \
./main.o \
./node.o \
./tablemaker.o \
./traffic.o \
./view.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./connection.d ./connection.o ./file.d ./file.o ./main.d ./main.o ./node.d ./node.o ./tablemaker.d ./tablemaker.o ./traffic.d ./traffic.o ./view.d ./view.o

.PHONY: clean--2e-

