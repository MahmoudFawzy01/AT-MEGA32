################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS_doubleWayLinkedList.c \
../PORT_program.c \
../SCH_program.c \
../TIMER_PROGRAME.c \
../app.c 

OBJS += \
./OS_doubleWayLinkedList.o \
./PORT_program.o \
./SCH_program.o \
./TIMER_PROGRAME.o \
./app.o 

C_DEPS += \
./OS_doubleWayLinkedList.d \
./PORT_program.d \
./SCH_program.d \
./TIMER_PROGRAME.d \
./app.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


