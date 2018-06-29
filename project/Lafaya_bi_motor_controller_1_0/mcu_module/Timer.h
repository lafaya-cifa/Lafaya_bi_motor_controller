#ifndef TIMER_H_
#define TIMER_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <../h/p33EP512MU814.h>
#include "../motor_driver/Motor Drive.h"
#include "../util_tool/Speed.h"
#include "../util_tool/Buzzer.h"
#include "../util_tool/Led.h"
#include "../util_tool/Rtc.h"
#include "../communication/Uart.h"
#include "../logic_control/Door Control.h"
#include "../communication/Command.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

extern void Initialize_Timer(void);	//called in main
void Initialize_Timer1(void);
void Initialize_Timer2(void);
void Initialize_Timer3(void);
void Initialize_Timer4(void);
void Initialize_Timer5(void);
#endif