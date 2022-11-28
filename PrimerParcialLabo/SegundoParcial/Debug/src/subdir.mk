################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Libro.c \
../src/LinkedList.c \
../src/SegundoParcial.c \
../src/input.c \
../src/menu.c 

C_DEPS += \
./src/Controller.d \
./src/Libro.d \
./src/LinkedList.d \
./src/SegundoParcial.d \
./src/input.d \
./src/menu.d 

OBJS += \
./src/Controller.o \
./src/Libro.o \
./src/LinkedList.o \
./src/SegundoParcial.o \
./src/input.o \
./src/menu.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Controller.d ./src/Controller.o ./src/Libro.d ./src/Libro.o ./src/LinkedList.d ./src/LinkedList.o ./src/SegundoParcial.d ./src/SegundoParcial.o ./src/input.d ./src/input.o ./src/menu.d ./src/menu.o

.PHONY: clean-src

