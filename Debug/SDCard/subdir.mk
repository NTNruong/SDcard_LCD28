################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDCard/fatfs_sd.c \
../SDCard/user_diskio.c 

OBJS += \
./SDCard/fatfs_sd.o \
./SDCard/user_diskio.o 

C_DEPS += \
./SDCard/fatfs_sd.d \
./SDCard/user_diskio.d 


# Each subdirectory must supply rules for building sources it contributes
SDCard/%.o SDCard/%.su SDCard/%.cyclo: ../SDCard/%.c SDCard/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/nntru/Desktop/TH_HTH/TH_HTN/LCD28" -I../FATFS/Target -I../FATFS/App -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/LibJPEG/include -I"C:/Users/nntru/Desktop/TH_HTH/TH_HTN/SDCard" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SDCard

clean-SDCard:
	-$(RM) ./SDCard/fatfs_sd.cyclo ./SDCard/fatfs_sd.d ./SDCard/fatfs_sd.o ./SDCard/fatfs_sd.su ./SDCard/user_diskio.cyclo ./SDCard/user_diskio.d ./SDCard/user_diskio.o ./SDCard/user_diskio.su

.PHONY: clean-SDCard

