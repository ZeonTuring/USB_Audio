# This is a generated file. Please do not edit.

.PHONY: all

COMMANDS := 	\
	    scd_cmd_1	\
	    scd_cmd_2

all: $(COMMANDS)

scd_cmd_1:
	@echo begin generating scanner info for $@
	arm-none-eabig++ -mthumb -mthumb-interwork -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -E -P -v -dD specs.cpp
	@echo end generating scanner info for $@

scd_cmd_2:
	@echo begin generating scanner info for $@
	arm-none-eabi-gcc -D 'DEBUG=1' -O0 -mthumb -mthumb-interwork -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -I "D:\STMLibrary\STM32F4_lib\inc" -I "D:\STMLibrary\STM32F4_lib\src" -E -P -v -dD specs.c
	@echo end generating scanner info for $@


