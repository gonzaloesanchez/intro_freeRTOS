################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
utils/uartstdio.obj: /home/gonza/ti/TivaWare/utils/uartstdio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/gonza/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/gonza/CodeComposer/workspace/freeRTOS" --include_path="/home/gonza/CodeComposer/workspace/freeRTOS/freeRTOS_kernel/inc" --include_path="/home/gonza/CodeComposer/workspace/freeRTOS" --include_path="/home/gonza/ti/TivaWare" --include_path="/home/gonza/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --include_path="/home/gonza/ti/TivaWare/examples/boards/ek-tm4c123gxl" --define=ccs="ccs" --define=PART_TM4C1233H6PM --define=TARGET_IS_TM4C123_RB1 -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="utils/uartstdio.d_raw" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

utils/ustdlib.obj: /home/gonza/ti/TivaWare/utils/ustdlib.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/gonza/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/gonza/CodeComposer/workspace/freeRTOS" --include_path="/home/gonza/CodeComposer/workspace/freeRTOS/freeRTOS_kernel/inc" --include_path="/home/gonza/CodeComposer/workspace/freeRTOS" --include_path="/home/gonza/ti/TivaWare" --include_path="/home/gonza/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --include_path="/home/gonza/ti/TivaWare/examples/boards/ek-tm4c123gxl" --define=ccs="ccs" --define=PART_TM4C1233H6PM --define=TARGET_IS_TM4C123_RB1 -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="utils/ustdlib.d_raw" --obj_directory="utils" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


