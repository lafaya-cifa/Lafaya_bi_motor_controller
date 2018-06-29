#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Layafa_bi_motor_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Layafa_bi_motor_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../util_tool/Algorithm.c ../util_tool/Buzzer.c ../util_tool/Current.c ../util_tool/Led.c ../util_tool/Rtc.c ../util_tool/Speed.c ../util_tool/Temperature.c "../motor_driver/Motor Drive.c" ../mcu_module/Adc.c ../mcu_module/Ic.c ../mcu_module/Pwm.c ../mcu_module/Qei.c ../mcu_module/Timer.c "../logic_control/Door Control.c" "../data/Eeprom Address.c" "../data/Flash Operations 33E_24E.s" ../communication/Command.c ../communication/Uart.c ../Main.c "../data/DEE Emulation 16-bit.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1106869798/Algorithm.o ${OBJECTDIR}/_ext/1106869798/Buzzer.o ${OBJECTDIR}/_ext/1106869798/Current.o ${OBJECTDIR}/_ext/1106869798/Led.o ${OBJECTDIR}/_ext/1106869798/Rtc.o ${OBJECTDIR}/_ext/1106869798/Speed.o ${OBJECTDIR}/_ext/1106869798/Temperature.o "${OBJECTDIR}/_ext/353869023/Motor Drive.o" ${OBJECTDIR}/_ext/925568837/Adc.o ${OBJECTDIR}/_ext/925568837/Ic.o ${OBJECTDIR}/_ext/925568837/Pwm.o ${OBJECTDIR}/_ext/925568837/Qei.o ${OBJECTDIR}/_ext/925568837/Timer.o "${OBJECTDIR}/_ext/1351202669/Door Control.o" "${OBJECTDIR}/_ext/761081191/Eeprom Address.o" "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o" ${OBJECTDIR}/_ext/408565305/Command.o ${OBJECTDIR}/_ext/408565305/Uart.o ${OBJECTDIR}/_ext/1472/Main.o "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o"
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1106869798/Algorithm.o.d ${OBJECTDIR}/_ext/1106869798/Buzzer.o.d ${OBJECTDIR}/_ext/1106869798/Current.o.d ${OBJECTDIR}/_ext/1106869798/Led.o.d ${OBJECTDIR}/_ext/1106869798/Rtc.o.d ${OBJECTDIR}/_ext/1106869798/Speed.o.d ${OBJECTDIR}/_ext/1106869798/Temperature.o.d "${OBJECTDIR}/_ext/353869023/Motor Drive.o.d" ${OBJECTDIR}/_ext/925568837/Adc.o.d ${OBJECTDIR}/_ext/925568837/Ic.o.d ${OBJECTDIR}/_ext/925568837/Pwm.o.d ${OBJECTDIR}/_ext/925568837/Qei.o.d ${OBJECTDIR}/_ext/925568837/Timer.o.d "${OBJECTDIR}/_ext/1351202669/Door Control.o.d" "${OBJECTDIR}/_ext/761081191/Eeprom Address.o.d" "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o.d" ${OBJECTDIR}/_ext/408565305/Command.o.d ${OBJECTDIR}/_ext/408565305/Uart.o.d ${OBJECTDIR}/_ext/1472/Main.o.d "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o.d"

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1106869798/Algorithm.o ${OBJECTDIR}/_ext/1106869798/Buzzer.o ${OBJECTDIR}/_ext/1106869798/Current.o ${OBJECTDIR}/_ext/1106869798/Led.o ${OBJECTDIR}/_ext/1106869798/Rtc.o ${OBJECTDIR}/_ext/1106869798/Speed.o ${OBJECTDIR}/_ext/1106869798/Temperature.o ${OBJECTDIR}/_ext/353869023/Motor\ Drive.o ${OBJECTDIR}/_ext/925568837/Adc.o ${OBJECTDIR}/_ext/925568837/Ic.o ${OBJECTDIR}/_ext/925568837/Pwm.o ${OBJECTDIR}/_ext/925568837/Qei.o ${OBJECTDIR}/_ext/925568837/Timer.o ${OBJECTDIR}/_ext/1351202669/Door\ Control.o ${OBJECTDIR}/_ext/761081191/Eeprom\ Address.o ${OBJECTDIR}/_ext/761081191/Flash\ Operations\ 33E_24E.o ${OBJECTDIR}/_ext/408565305/Command.o ${OBJECTDIR}/_ext/408565305/Uart.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/761081191/DEE\ Emulation\ 16-bit.o

# Source Files
SOURCEFILES=../util_tool/Algorithm.c ../util_tool/Buzzer.c ../util_tool/Current.c ../util_tool/Led.c ../util_tool/Rtc.c ../util_tool/Speed.c ../util_tool/Temperature.c ../motor_driver/Motor Drive.c ../mcu_module/Adc.c ../mcu_module/Ic.c ../mcu_module/Pwm.c ../mcu_module/Qei.c ../mcu_module/Timer.c ../logic_control/Door Control.c ../data/Eeprom Address.c ../data/Flash Operations 33E_24E.s ../communication/Command.c ../communication/Uart.c ../Main.c ../data/DEE Emulation 16-bit.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Layafa_bi_motor_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512MU814
MP_LINKER_FILE_OPTION=,--script=p33EP512MU814.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1106869798/Algorithm.o: ../util_tool/Algorithm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Algorithm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Algorithm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Algorithm.c  -o ${OBJECTDIR}/_ext/1106869798/Algorithm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Algorithm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Algorithm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Buzzer.o: ../util_tool/Buzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Buzzer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Buzzer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Buzzer.c  -o ${OBJECTDIR}/_ext/1106869798/Buzzer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Buzzer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Buzzer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Current.o: ../util_tool/Current.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Current.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Current.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Current.c  -o ${OBJECTDIR}/_ext/1106869798/Current.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Current.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Current.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Led.o: ../util_tool/Led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Led.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Led.c  -o ${OBJECTDIR}/_ext/1106869798/Led.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Led.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Led.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Rtc.o: ../util_tool/Rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Rtc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Rtc.c  -o ${OBJECTDIR}/_ext/1106869798/Rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Rtc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Rtc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Speed.o: ../util_tool/Speed.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Speed.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Speed.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Speed.c  -o ${OBJECTDIR}/_ext/1106869798/Speed.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Speed.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Speed.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Temperature.o: ../util_tool/Temperature.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Temperature.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Temperature.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Temperature.c  -o ${OBJECTDIR}/_ext/1106869798/Temperature.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Temperature.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Temperature.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/353869023/Motor\ Drive.o: ../motor_driver/Motor\ Drive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/353869023" 
	@${RM} "${OBJECTDIR}/_ext/353869023/Motor Drive.o".d 
	@${RM} "${OBJECTDIR}/_ext/353869023/Motor Drive.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../motor_driver/Motor Drive.c"  -o "${OBJECTDIR}/_ext/353869023/Motor Drive.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/353869023/Motor Drive.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/353869023/Motor Drive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Adc.o: ../mcu_module/Adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Adc.c  -o ${OBJECTDIR}/_ext/925568837/Adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Ic.o: ../mcu_module/Ic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Ic.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Ic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Ic.c  -o ${OBJECTDIR}/_ext/925568837/Ic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Ic.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Ic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Pwm.o: ../mcu_module/Pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Pwm.c  -o ${OBJECTDIR}/_ext/925568837/Pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Pwm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Pwm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Qei.o: ../mcu_module/Qei.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Qei.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Qei.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Qei.c  -o ${OBJECTDIR}/_ext/925568837/Qei.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Qei.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Qei.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Timer.o: ../mcu_module/Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Timer.c  -o ${OBJECTDIR}/_ext/925568837/Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1351202669/Door\ Control.o: ../logic_control/Door\ Control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1351202669" 
	@${RM} "${OBJECTDIR}/_ext/1351202669/Door Control.o".d 
	@${RM} "${OBJECTDIR}/_ext/1351202669/Door Control.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../logic_control/Door Control.c"  -o "${OBJECTDIR}/_ext/1351202669/Door Control.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1351202669/Door Control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1351202669/Door Control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761081191/Eeprom\ Address.o: ../data/Eeprom\ Address.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761081191" 
	@${RM} "${OBJECTDIR}/_ext/761081191/Eeprom Address.o".d 
	@${RM} "${OBJECTDIR}/_ext/761081191/Eeprom Address.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../data/Eeprom Address.c"  -o "${OBJECTDIR}/_ext/761081191/Eeprom Address.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761081191/Eeprom Address.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/761081191/Eeprom Address.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408565305/Command.o: ../communication/Command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/408565305" 
	@${RM} ${OBJECTDIR}/_ext/408565305/Command.o.d 
	@${RM} ${OBJECTDIR}/_ext/408565305/Command.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../communication/Command.c  -o ${OBJECTDIR}/_ext/408565305/Command.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408565305/Command.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/408565305/Command.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408565305/Uart.o: ../communication/Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/408565305" 
	@${RM} ${OBJECTDIR}/_ext/408565305/Uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/408565305/Uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../communication/Uart.c  -o ${OBJECTDIR}/_ext/408565305/Uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408565305/Uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/408565305/Uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Main.c  -o ${OBJECTDIR}/_ext/1472/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761081191/DEE\ Emulation\ 16-bit.o: ../data/DEE\ Emulation\ 16-bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761081191" 
	@${RM} "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o".d 
	@${RM} "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../data/DEE Emulation 16-bit.c"  -o "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1106869798/Algorithm.o: ../util_tool/Algorithm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Algorithm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Algorithm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Algorithm.c  -o ${OBJECTDIR}/_ext/1106869798/Algorithm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Algorithm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Algorithm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Buzzer.o: ../util_tool/Buzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Buzzer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Buzzer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Buzzer.c  -o ${OBJECTDIR}/_ext/1106869798/Buzzer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Buzzer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Buzzer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Current.o: ../util_tool/Current.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Current.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Current.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Current.c  -o ${OBJECTDIR}/_ext/1106869798/Current.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Current.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Current.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Led.o: ../util_tool/Led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Led.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Led.c  -o ${OBJECTDIR}/_ext/1106869798/Led.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Led.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Led.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Rtc.o: ../util_tool/Rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Rtc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Rtc.c  -o ${OBJECTDIR}/_ext/1106869798/Rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Rtc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Rtc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Speed.o: ../util_tool/Speed.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Speed.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Speed.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Speed.c  -o ${OBJECTDIR}/_ext/1106869798/Speed.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Speed.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Speed.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1106869798/Temperature.o: ../util_tool/Temperature.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1106869798" 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Temperature.o.d 
	@${RM} ${OBJECTDIR}/_ext/1106869798/Temperature.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../util_tool/Temperature.c  -o ${OBJECTDIR}/_ext/1106869798/Temperature.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1106869798/Temperature.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1106869798/Temperature.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/353869023/Motor\ Drive.o: ../motor_driver/Motor\ Drive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/353869023" 
	@${RM} "${OBJECTDIR}/_ext/353869023/Motor Drive.o".d 
	@${RM} "${OBJECTDIR}/_ext/353869023/Motor Drive.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../motor_driver/Motor Drive.c"  -o "${OBJECTDIR}/_ext/353869023/Motor Drive.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/353869023/Motor Drive.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/353869023/Motor Drive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Adc.o: ../mcu_module/Adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Adc.c  -o ${OBJECTDIR}/_ext/925568837/Adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Ic.o: ../mcu_module/Ic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Ic.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Ic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Ic.c  -o ${OBJECTDIR}/_ext/925568837/Ic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Ic.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Ic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Pwm.o: ../mcu_module/Pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Pwm.c  -o ${OBJECTDIR}/_ext/925568837/Pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Pwm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Qei.o: ../mcu_module/Qei.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Qei.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Qei.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Qei.c  -o ${OBJECTDIR}/_ext/925568837/Qei.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Qei.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Qei.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/925568837/Timer.o: ../mcu_module/Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925568837" 
	@${RM} ${OBJECTDIR}/_ext/925568837/Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/925568837/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mcu_module/Timer.c  -o ${OBJECTDIR}/_ext/925568837/Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/925568837/Timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/925568837/Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1351202669/Door\ Control.o: ../logic_control/Door\ Control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1351202669" 
	@${RM} "${OBJECTDIR}/_ext/1351202669/Door Control.o".d 
	@${RM} "${OBJECTDIR}/_ext/1351202669/Door Control.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../logic_control/Door Control.c"  -o "${OBJECTDIR}/_ext/1351202669/Door Control.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1351202669/Door Control.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1351202669/Door Control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761081191/Eeprom\ Address.o: ../data/Eeprom\ Address.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761081191" 
	@${RM} "${OBJECTDIR}/_ext/761081191/Eeprom Address.o".d 
	@${RM} "${OBJECTDIR}/_ext/761081191/Eeprom Address.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../data/Eeprom Address.c"  -o "${OBJECTDIR}/_ext/761081191/Eeprom Address.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761081191/Eeprom Address.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/761081191/Eeprom Address.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408565305/Command.o: ../communication/Command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/408565305" 
	@${RM} ${OBJECTDIR}/_ext/408565305/Command.o.d 
	@${RM} ${OBJECTDIR}/_ext/408565305/Command.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../communication/Command.c  -o ${OBJECTDIR}/_ext/408565305/Command.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408565305/Command.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/408565305/Command.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408565305/Uart.o: ../communication/Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/408565305" 
	@${RM} ${OBJECTDIR}/_ext/408565305/Uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/408565305/Uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../communication/Uart.c  -o ${OBJECTDIR}/_ext/408565305/Uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408565305/Uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/408565305/Uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Main.c  -o ${OBJECTDIR}/_ext/1472/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761081191/DEE\ Emulation\ 16-bit.o: ../data/DEE\ Emulation\ 16-bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761081191" 
	@${RM} "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o".d 
	@${RM} "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../data/DEE Emulation 16-bit.c"  -o "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/761081191/DEE Emulation 16-bit.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/761081191/Flash\ Operations\ 33E_24E.o: ../data/Flash\ Operations\ 33E_24E.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761081191" 
	@${RM} "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o".d 
	@${RM} "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o" 
	${MP_CC} $(MP_EXTRA_AS_PRE)  "../data/Flash Operations 33E_24E.s"  -o "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/761081191/Flash\ Operations\ 33E_24E.o: ../data/Flash\ Operations\ 33E_24E.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761081191" 
	@${RM} "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o".d 
	@${RM} "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o" 
	${MP_CC} $(MP_EXTRA_AS_PRE)  "../data/Flash Operations 33E_24E.s"  -o "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/761081191/Flash Operations 33E_24E.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Layafa_bi_motor_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Layafa_bi_motor_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Layafa_bi_motor_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Layafa_bi_motor_controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Layafa_bi_motor_controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
