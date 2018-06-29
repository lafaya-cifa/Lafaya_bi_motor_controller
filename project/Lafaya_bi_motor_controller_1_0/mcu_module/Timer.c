#include "Timer.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Timer(void)	//called in main
{
	Initialize_Timer1();
	Initialize_Timer2();
	Initialize_Timer3();
	Initialize_Timer4();
	Initialize_Timer5();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Timer1(void)
{
    T1CON = 0x0010;         //Timer1 input clock prescale select 1:8,Timer1 clock sourse select internal clock(Fp))
    TMR1 = 0x0000;          //Tcount=2*8/120M=0.133us
    PR1 = 0x1D4C;           //timer 1ms=7500*0.133us
    IPC0bits.T1IP = 3;   //set timer1 interrupt priority level
    IFS0bits.T1IF = 0;      //clear timer1 interrupt flag
    IEC0bits.T1IE = 1;      //enable timer1 interrupt
    T1CONbits.TON = 1;      //start Timer
}
/*example code for timer1 ISR*/
void __attribute__((interrupt,no_auto_psv)) _T1Interrupt(void)
{
	Buzzer_Timer();		//called in timer
	Led_Timer();	//called in timer
	Uart_Timer();
 	Door_Timer();
	
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    IFS0bits.T1IF = 0;  //clear timer1 interrupt flag
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Timer2(void)
{
    T2CON = 0x0030;         //Timer2 input clock prescale select 1:256,Timer1 clock sourse select internal clock(Fp))
    TMR2 = 0x0000;          //Tcount=2*256/120M=4.26667us
    PR2 = 0x5B8D;           //timer 100ms=23437*4.26667us
    IPC1bits.T2IP = 4;   //set timer2 interrupt priority level
    IFS0bits.T2IF = 0;      //clear timer2 interrupt flag
    IEC0bits.T2IE = 1;      //enable timer2 interrupt
    T2CONbits.TON = 1;      //start Timer
}
/*example code for timer2 ISR*/
void __attribute__((interrupt,no_auto_psv)) _T2Interrupt(void)
{
//	test_time++;
//	if(test_time >= 1)
//	{
		Command_All_Test();
//		test_time = 0;
//	}
	 Read_Write_Time();

	
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    IFS0bits.T2IF = 0;  //clear timer2 interrupt flag
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Timer3(void)
{
    T3CON = 0x0010;         //Timer3 input clock prescale select 1:8,Timer1 clock sourse select internal clock(Fp))
    TMR3 = 0x0000;          //Tcount=2*8/120M=133.33ns
    PR3 = 0x927C;           //timer 5ms=37500*133.3.33ns
    IPC2bits.T3IP = 7;   //set timer3 interrupt priority level
    IFS0bits.T3IF = 0;      //clear timer3 interrupt flag
    IEC0bits.T3IE = 1;      //enable timer3 interrupt
    T3CONbits.TON = 1;      //start Timer
}
/*example code for timer3 ISR*/
void __attribute__((interrupt,no_auto_psv)) _T3Interrupt(void)
{
	Speed1_Counter();	//called in timer

	
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    IFS0bits.T3IF = 0;  //clear timer3 interrupt flag
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Timer4(void)
{
	T4CON = 0x0010;         //Timer4 input clock prescale select 1:8,Timer1 clock sourse select internal clock(Fp))
	TMR4 = 0x0000;          //Tcount=2*8/120M=133.33ns
	PR4 = 0x927C;           //timer 5ms=37500*133.33ns
	IPC6bits.T4IP = 7;   //set timer4 interrupt priority level
	IFS1bits.T4IF = 0;      //clear timer4 interrupt flag
	IEC1bits.T4IE = 1;      //enable timer4 interrupt
	T4CONbits.TON = 1;      //start Timer
}
/*example code for timer4 ISR*/
void __attribute__((interrupt,no_auto_psv)) _T4Interrupt(void)
{
	Speed2_Counter();	//called in timer
	
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    IFS1bits.T4IF = 0;  //clear timer4 interrupt flag
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Timer5(void)
{
    T5CON = 0x0000;         //Timer5 input clock prescale select 1:1,Timer1 clock sourse select internal clock(Fp))
    TMR5 = 0x0000;          //Tcount=2/120M=0.016667us
    PR5 = 0x6978;           //timer 450us=27000*0.016667us
    IPC7bits.T5IP = 5;   //set timer5 interrupt priority level
    IFS1bits.T5IF = 0;      //clear timer5 interrupt flag
    IEC1bits.T5IE = 1;      //enable timer5 interrupt
    T5CONbits.TON = 1;      //start Timer
}
/*example code for timer5 ISR*/
void __attribute__((interrupt,no_auto_psv)) _T5Interrupt(void)
{
	Motor_Control();	//called in main or timer

	
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    IFS1bits.T5IF = 0;  //clear timer5 interrupt flag
}








