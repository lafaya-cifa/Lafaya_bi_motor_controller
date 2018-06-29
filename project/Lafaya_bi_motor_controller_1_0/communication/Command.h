#ifndef COMMAND_H_
#define COMMAND_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "../motor_driver/Motor Drive.h"
#include "../util_tool/Rtc.h"
#include "../util_tool/Temperature.h"
#include "../logic_control/Door Control.h"
#include "../util_tool/Current.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define     UART_DATA_NUMBER_MAX     30  //define uart data number max
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Initialize_Command_Varialbe(void);		//called in main
extern void Send_Data_Exchange(unsigned char *data_input);
extern unsigned char Command_Flag_Output(void);
extern void Command_Flag_Clear(void);
extern void Command_0x51(void);
extern void Command_Rtc_Test(void);
extern void Command_temperature_Test(void);
extern void Command_Qei_End_Test(void);
extern void Command_Qei_Start_Test(void);
extern void Command_Current_Test(void);
//extern void Command_Speed_Test(void);
//extern void Command_Pwm_Test(void);
extern void Command_All_Test(void);
//extern void Command_All_Test1(int value);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~













#endif

