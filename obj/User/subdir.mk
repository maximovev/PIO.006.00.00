################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v20x_it.c \
../User/system_ch32v20x.c 

CPP_SRCS += \
../User/main.cpp 

OBJS += \
./User/ch32v20x_it.o \
./User/main.o \
./User/system_ch32v20x.o 

C_DEPS += \
./User/ch32v20x_it.d \
./User/system_ch32v20x.d 

CPP_DEPS += \
./User/main.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Debug" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Core" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\User" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/%.o: ../User/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C++ Compiler'
	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Peripheral\inc" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Pegas\RISC\CH32V203" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Debug" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\Core" -I"C:\Users\maximove\mrs_community_workspace\PIO006v100\User" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


