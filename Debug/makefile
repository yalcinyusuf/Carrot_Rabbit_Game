################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Carrot_Rabbit_Game
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: Carrot_Rabbit_Game

# Tool invocations
Carrot_Rabbit_Game: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS) /opt/tensorflow/tensorflow/lite/tools/make/gen/linux_x86_64/lib/libtensorflow-lite.a /opt/boost_1_71_0/stage/lib/libboost_system.a /opt/boost_1_71_0/stage/lib/libboost_regex.a /opt/boost_1_71_0/stage/lib/libboost_random.a /opt/boost_1_71_0/stage/lib/libboost_thread.a /opt/boost_1_71_0/stage/lib/libboost_filesystem.a /opt/boost_1_71_0/stage/lib/libboost_iostreams.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -pthread -o "Carrot_Rabbit_Game" $(OBJS) $(USER_OBJS) $(LIBS) /opt/tensorflow/tensorflow/lite/tools/make/gen/linux_x86_64/lib/libtensorflow-lite.a /opt/boost_1_71_0/stage/lib/libboost_system.a /opt/boost_1_71_0/stage/lib/libboost_regex.a /opt/boost_1_71_0/stage/lib/libboost_random.a /opt/boost_1_71_0/stage/lib/libboost_thread.a /opt/boost_1_71_0/stage/lib/libboost_filesystem.a /opt/boost_1_71_0/stage/lib/libboost_iostreams.a -ldl -lz -lgpiod -ledgetpu -lflatbuffers -lcurl -lcrypto -lcryptopp -lraspicam -lraspicam_cv -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_videoio -lopencv_imgcodecs -lopencv_flann
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Carrot_Rabbit_Game
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
