################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main_app/source/main_app.c \
../main_app/source/spi.c \
../main_app/source/spi_lcd.c \
../main_app/source/timer4.c \
../main_app/source/uart.c 

OBJS += \
./main_app/source/main_app.o \
./main_app/source/spi.o \
./main_app/source/spi_lcd.o \
./main_app/source/timer4.o \
./main_app/source/uart.o 

C_DEPS += \
./main_app/source/main_app.d \
./main_app/source/spi.d \
./main_app/source/spi_lcd.d \
./main_app/source/timer4.d \
./main_app/source/uart.d 


# Each subdirectory must supply rules for building sources it contributes
main_app/source/%.o main_app/source/%.su: ../main_app/source/%.c main_app/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/osonoderin/HomeFort/Homefort_Codes/main_app/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-main_app-2f-source

clean-main_app-2f-source:
	-$(RM) ./main_app/source/main_app.d ./main_app/source/main_app.o ./main_app/source/main_app.su ./main_app/source/spi.d ./main_app/source/spi.o ./main_app/source/spi.su ./main_app/source/spi_lcd.d ./main_app/source/spi_lcd.o ./main_app/source/spi_lcd.su ./main_app/source/timer4.d ./main_app/source/timer4.o ./main_app/source/timer4.su ./main_app/source/uart.d ./main_app/source/uart.o ./main_app/source/uart.su

.PHONY: clean-main_app-2f-source

