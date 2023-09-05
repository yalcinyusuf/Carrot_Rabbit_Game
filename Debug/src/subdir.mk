################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Carrot_Rabbit_Game.cpp \
../src/try6.cpp 

CPP_DEPS += \
./src/Carrot_Rabbit_Game.d \
./src/try6.d 

OBJS += \
./src/Carrot_Rabbit_Game.o \
./src/try6.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -DOPENCV_ACTIVE -DUBUNTUx64 -I/opt/boost_1_71_0 -I../src -I/opt/tensorflow -I/opt/tensorflow/tensorflow/lite/tools/make/downloads/absl -I/opt/tensorflow/tensorflow/lite/tools/make/downloads/flatbuffers/include -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Carrot_Rabbit_Game.d ./src/Carrot_Rabbit_Game.o ./src/try6.d ./src/try6.o

.PHONY: clean-src

