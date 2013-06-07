################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fasor.c \
../src/funciones_complejos.c \
../src/list.c \
../src/pantalla.c \
../src/transferencia.c \
../src/wesselsoft.c 

OBJS += \
./src/fasor.o \
./src/funciones_complejos.o \
./src/list.o \
./src/pantalla.o \
./src/transferencia.o \
./src/wesselsoft.o 

C_DEPS += \
./src/fasor.d \
./src/funciones_complejos.d \
./src/list.d \
./src/pantalla.d \
./src/transferencia.d \
./src/wesselsoft.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/javier/git/wesselsoft/Includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


