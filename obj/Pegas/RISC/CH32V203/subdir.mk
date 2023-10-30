################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Pegas/RISC/CH32V203/ch32v203_core.cpp 

OBJS += \
./Pegas/RISC/CH32V203/ch32v203_core.o 

CPP_DEPS += \
./Pegas/RISC/CH32V203/ch32v203_core.d 


# Each subdirectory must supply rules for building sources it contributes
Pegas/RISC/CH32V203/%.o: ../Pegas/RISC/CH32V203/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C++ Compiler'
	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Peripheral\inc" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Pegas\RISC\CH32V203" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Debug" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Core" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\User" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


