################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/CAN_NODE/can_node.c \
../Dave/Generated/CAN_NODE/can_node_conf.c 

OBJS += \
./Dave/Generated/CAN_NODE/can_node.o \
./Dave/Generated/CAN_NODE/can_node_conf.o 

C_DEPS += \
./Dave/Generated/CAN_NODE/can_node.d \
./Dave/Generated/CAN_NODE/can_node_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/CAN_NODE/%.o: ../Dave/Generated/CAN_NODE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"E:\DAVEv4\DAVE-4.1.4\eclipse\ARM-GCC-49/bin/arm-none-eabi-gcc" -DXMC4700_F144x2048 -I"D:\dholler\Dokumente\uni\bus\xmc\flooder\Libraries\XMCLib\inc" -I"D:\dholler\Dokumente\uni\bus\xmc\flooder/Libraries/CMSIS/Include" -I"D:\dholler\Dokumente\uni\bus\xmc\flooder/Libraries/CMSIS/Infineon/XMC4700_series/Include" -I"D:\dholler\Dokumente\uni\bus\xmc\flooder" -I"D:\dholler\Dokumente\uni\bus\xmc\flooder\Dave\Generated" -I"D:\dholler\Dokumente\uni\bus\xmc\flooder\Libraries" -O0 -ffunction-sections -fdata-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo.

