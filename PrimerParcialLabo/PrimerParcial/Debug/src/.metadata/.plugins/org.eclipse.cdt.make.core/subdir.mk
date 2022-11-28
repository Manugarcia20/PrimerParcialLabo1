################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.c 

C_DEPS += \
./src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 

OBJS += \
./src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.o 


# Each subdirectory must supply rules for building sources it contributes
src/.metadata/.plugins/org.eclipse.cdt.make.core/%.o: ../src/.metadata/.plugins/org.eclipse.cdt.make.core/%.c src/.metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-make-2e-core

clean-src-2f--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-make-2e-core:
	-$(RM) ./src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.d ./src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.o

.PHONY: clean-src-2f--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-make-2e-core

