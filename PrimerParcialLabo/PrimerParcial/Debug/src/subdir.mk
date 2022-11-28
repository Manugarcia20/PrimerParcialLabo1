################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PrimerParcial.c \
../src/funciones.c \
../src/input.c \
../src/libro.c 

C_DEPS += \
./src/PrimerParcial.d \
./src/funciones.d \
./src/input.d \
./src/libro.d 

OBJS += \
./src/PrimerParcial.o \
./src/funciones.o \
./src/input.o \
./src/libro.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/PrimerParcial.d ./src/PrimerParcial.o ./src/funciones.d ./src/funciones.o ./src/input.d ./src/input.o ./src/libro.d ./src/libro.o

.PHONY: clean-src

