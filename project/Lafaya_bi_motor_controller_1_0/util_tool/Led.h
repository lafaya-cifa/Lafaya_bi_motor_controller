#ifndef LED_H_
#define LED_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <../../../include/stdarg.h>
#include <../h/p33EP512MU814.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define		LED_COUNT_MAX			255000UL	//led count max

#define		LED_INTERVAL_TIME		10		//led exchange display interval times
#define		LED_RUNNING_TIME		100		//led horse race lamp exchange times


#define		IO_OUT_LEDPORT		PORTJ	 //led port
#define		IO_OUT_LEDDIG1		_RG0    //led dig1 io
#define		IO_OUT_LEDDIG2		_RD4    //led dig2 io

#define		LED_TIMER_US			1000		//timer's times ,unit us

#define		LED_PIN_START			0		//led defualt number
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Led_Timer(void);	//called in timer
extern void Led_Handle(void);	//called in main
extern void Led_Input(unsigned char display_status, unsigned char display_dot,...);	//for external modul calls
//extern void Led_Input(unsigned char display_status, unsigned char display_number, unsigned char display_dot);		
extern void Led_Double_Handle(void);		//called in main
extern void Led_Double_Input(unsigned char display_status,unsigned char display_number, unsigned char display_dot, ...);    //for external modul calls


#endif

