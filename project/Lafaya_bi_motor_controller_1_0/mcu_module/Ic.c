#include "Ic.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Ic(void)    //initialize qei,called in main
{
	IC1CON1 = 0x0003;
//	IC1CON1bits.ICSIDL = 0;
//	IC1CON1bits.ICTSEL = 0;	//T3CLK
//	IC1CON1bits.ICI = 0;
//	IC1CON1bits.ICOV = 0;
//	IC1CON1bits.ICBNE = 0;
//	IC1CON1bits.ICM = 3;
	
	IC1CON2 = 0x0000;

	IFS0bits.IC1IF = 0;
	IEC0bits.IC1IE = 1;
	IPC0bits.IC1IP = 7;

	IC2CON1 = 0x0803;
//	IC2CON1bits.ICSIDL = 0;
//	IC2CON1bits.ICTSEL = 2;	//T4CLK
//	IC2CON1bits.ICI = 0;
//	IC2CON1bits.ICOV = 0;
//	IC2CON1bits.ICBNE = 0;
//	IC2CON1bits.ICM = 3;
	
	IC2CON2 = 0x0000;

	IFS0bits.IC2IF = 0;
	IEC0bits.IC2IE = 1;
	IPC1bits.IC2IP = 6;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __attribute__((interrupt,no_auto_psv)) _IC1Interrupt(void)
{
	Speed1_Time();
	
	IFS0bits.IC1IF = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __attribute__((interrupt,no_auto_psv)) _IC2Interrupt(void)
{
	Speed2_Time();
	
	IFS0bits.IC2IF = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~















//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

