#ifndef _BUZZER_H_
#define _BUZZER_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <../h/p33EP512MU814.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	IO_OUT_BUZZER			_RB11		//buzzer port

#define	BUZZER_HIGH			1
#define	BUZZER_LOW			0

#define	BUZZER_TIMER_US		1000		//timer's times ,unit us
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	BUZZER_COUNT_MAX		131070000		//buzzer count max
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Buzzer_Timer(void);		//called in timer
extern void Buzzer_Handle(void);		//called in mian
extern void Buzzer_Input(unsigned int sound_interval_ms, unsigned char sound_times);		//for external module calls


#endif

