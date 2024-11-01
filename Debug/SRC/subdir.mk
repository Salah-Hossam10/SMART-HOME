################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/ADC_program.c \
../SRC/DIO_program.c \
../SRC/EXTI_program.c \
../SRC/GI_program.c \
../SRC/KEYPAD_program.c \
../SRC/LCD_program.c \
../SRC/LED_program.c \
../SRC/SERVO_program.c \
../SRC/TIMER1_program.c \
../SRC/app.c 

OBJS += \
./SRC/ADC_program.o \
./SRC/DIO_program.o \
./SRC/EXTI_program.o \
./SRC/GI_program.o \
./SRC/KEYPAD_program.o \
./SRC/LCD_program.o \
./SRC/LED_program.o \
./SRC/SERVO_program.o \
./SRC/TIMER1_program.o \
./SRC/app.o 

C_DEPS += \
./SRC/ADC_program.d \
./SRC/DIO_program.d \
./SRC/EXTI_program.d \
./SRC/GI_program.d \
./SRC/KEYPAD_program.d \
./SRC/LCD_program.d \
./SRC/LED_program.d \
./SRC/SERVO_program.d \
./SRC/TIMER1_program.d \
./SRC/app.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/%.o: ../SRC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


