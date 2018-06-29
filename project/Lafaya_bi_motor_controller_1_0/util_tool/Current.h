#ifndef CURRENT_H_
#define CURRENT_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "../mcu_module/Adc.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	CURRENT_SAMPLE_LEVEL		151
#define	CURRENT_SAMPLE_RATE		17
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Initialize_Current_Varialbe(void);	//called in main
extern void Current_Handle(void);	//called in adc
unsigned int Current_Calculate(unsigned int read_data);
extern unsigned int Current1_Now(void);
extern unsigned int Current2_Now(void);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif

