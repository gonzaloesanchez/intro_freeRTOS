################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/main.obj: ../src/main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/gonza/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/gonza/CodeComposer/workspace/freeRTOS" --include_path="/home/gonza/CodeComposer/workspace/freeRTOS/freeRTOS_kernel/inc" --include_path="/home/gonza/CodeComposer/workspace/freeRTOS" --include_path="/home/gonza/ti/TivaWare" --include_path="/home/gonza/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --include_path="/home/gonza/ti/TivaWare/examples/boards/ek-tm4c123gxl" --define=ccs="ccs" --define=PART_TM4C1233H6PM --define=TARGET_IS_TM4C123_RB1 -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/main.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

src/startup_ccs.obj: ../src/startup_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/gonza/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/gonza/CodeComposer/workspace/freeRTOS" --include_path="/home/gonza/CodeComposer/workspace/freeRTOS/freeRTOS_kernel/inc" --include_path="/home/gonza/CodeComposer/workspace/freeRTOS" --include_path="/home/gonza/ti/TivaWare" --include_path="/home/gonza/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --include_path="/home/gonza/ti/TivaWare/examples/boards/ek-tm4c123gxl" --define=ccs="ccs" --define=PART_TM4C1233H6PM --define=TARGET_IS_TM4C123_RB1 -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/startup_ccs.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


