################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../FileChecker.cpp \
../connection.cpp \
../file.cpp \
../graphe.cpp \
../main.cpp \
../node.cpp \
../tablemaker.cpp \
../view.cpp 

CPP_DEPS += \
./FileChecker.d \
./connection.d \
./file.d \
./graphe.d \
./main.d \
./node.d \
./tablemaker.d \
./view.d 

OBJS += \
./FileChecker.o \
./connection.o \
./file.o \
./graphe.o \
./main.o \
./node.o \
./tablemaker.o \
./view.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./FileChecker.d ./FileChecker.o ./connection.d ./connection.o ./file.d ./file.o ./graphe.d ./graphe.o ./main.d ./main.o ./node.d ./node.o ./tablemaker.d ./tablemaker.o ./view.d ./view.o

.PHONY: clean--2e-

