#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "../mcu_module/Adc.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Initialize_Temperature_Varialbe(void);	//called in main
extern void Temperature_Handle(void);	//called in adc
char Temperature_Calculate(unsigned int temperature_value);
extern unsigned int Temperature1_Now(void);
extern unsigned int Temperature2_Now(void);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif

