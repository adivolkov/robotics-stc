################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Driver.cpp \
../Main.cpp \
../Map.cpp \
../Node.cpp \
../Robot.cpp \
../STC.cpp \
../lodepng.cpp 

OBJS += \
./Driver.o \
./Main.o \
./Map.o \
./Node.o \
./Robot.o \
./STC.o \
./lodepng.o 

CPP_DEPS += \
./Driver.d \
./Main.d \
./Map.d \
./Node.d \
./Robot.d \
./STC.d \
./lodepng.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


