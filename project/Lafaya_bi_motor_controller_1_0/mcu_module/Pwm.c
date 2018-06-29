#include "Pwm.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Pwm(void)	//PWM initialized to called in main
{
	PTCON = 0x0000;
/*	PTCONbits.PTEN = 0;		//PWM module is disabled
	PTCONbits.PTSIDL = 0;		//PWM time base runs in CPU idle mode
	PTCONbits.SESTAT = 0;		//special event interrupt is not pending
	PTCONbits.SEIEN = 0;		//special event interrupt is disabled
	PTCONbits.EIPU = 0;		//active period register updates occur on PWM cycle boundaries
	PTCONbits.SYNCPOL = 0;	//SYNCLx/SYNCO is active-high
	PTCONbits.SYNCOEN = 0;	//SYNCO output is disabled
	PTCONbits.SYNCEN = 0;	//external synchronization of primary time base is disabled
	PTCONbits.SYNCSRC = 0;	//synchronous source selection is SYNCL1
	PTCONbits.SEVTPS = 0;		// 1:1 postscaler generates special event trigger on every  compare match event
*/
	PTCON2 = 0;	//divide-by-1

//	PTPER = ;		//primary master time base(PMTMR) period value
    
//	SEVTCMP = ;		//special event compare count value

	STCON = 0x0000;
	STCON2 = 0x0000;
    
//    STPER = ;       //

//	SSEVTCMP = 0x0000;

	CHOP = 0;	//chop clock generator is disabled
	
/*  MDC,PDCx,SDCx = (Fosc / Fpwm * PWM input clock prescaler * 2) * required duty cycle
 *                 = (120MHZ / 15KHZ * 1 * 2) * 80%
 *                 = 3200
 */
//	MDC = 3200;		//master PWM duty cycle value
    
	PWMCON1 = 0x1204;
	PWMCON2 = 0x1204;
	PWMCON3 = 0x1204;
	PWMCON4 = 0x1204;
	PWMCON5 = 0x1204;
	PWMCON6 = 0x1204;

/*	PWMCON1bits.ITB = 1;		//phase1/sphase1 registers provide time base period for this PWM generator
	PWMCON1bits.CAM = 1;		//center-aligned mode is enabled
	PWMCON2bits.ITB = 1;
	PWMCON2bits.CAM = 1;
	PWMCON3bits.ITB = 1;
	PWMCON3bits.MDCS = 0;	//PDCx and SDCx register provides duty cycle information for this PWM generator
	PWMCON3bits.CAM = 1;
	PWMCON4bits.ITB = 1;
	PWMCON4bits.CAM = 1;
	PWMCON5bits.ITB = 1;
	PWMCON5bits.CAM = 1;
	PWMCON6bits.ITB = 1;
	PWMCON6bits.CAM = 1;
*/
	PDC1 = 0000;         //PWM1H duty cycle is 10% = 4000 * 10% = 400
	SDC1 = 0000;         //PWM1H duty cycle is 15% = 4000 * 15% = 600
    
	PDC2 = 0000;		//PWM2H duty cycle is 20% = 4000 * 20% = 800
	SDC2 = 0000;		//PWM2H duty cycle is 25% = 4000 * 25% = 1000
    
	PDC3 = 0000;		//PWM3H duty cycle is 30% = 4000 * 30% = 1200
	SDC3 = 0000;		//PWM3H duty cycle is 35% = 4000 * 35% = 1400
    
	PDC4 = 0000;         //PWM4H duty cycle is 40% = 4000 * 40% = 1600
	SDC4 = 0000;         //PWM4H duty cycle is 45% = 4000 * 45% = 1800

	PDC5 = 0000;         //PWM5H duty cycle is 50% = 4000 * 10% = 400
	SDC5 = 0000;		//PWM5H duty cycle is 55% = 4000 * 40% = 1600
    
	PDC6 = 0000;		//PWM6H duty cycle is 60% = 4000 * 70% = 2800
	SDC6 = 0000;		//PWM6H duty cycle is 65% = 4000 * 65% = 2600
    
/*  PHASE,SPHASE = 120MHZ/(15KHZ * 1 * 2) = 4000
    *   Fpwm = 15KHZ
    *   PWM input clock prescaler(divider) select 1:1
    *   Fosc = 120MHZ
 */
	PHASE1 = 4000;
	SPHASE1 = 4000;

	PHASE2 = 4000;
	SPHASE2 = 4000;

	PHASE3 = 4000;
	SPHASE3 = 4000;
    
	PHASE4 = 4000;
	SPHASE4 = 4000;

	PHASE5 = 4000;
	SPHASE5 = 4000;

	PHASE6 = 4000;
	SPHASE6 = 4000;
    
	DTR1 = 0x0000;
	DTR2 = 0x0000;
	DTR3 = 0x0000;
	DTR4 = 0x0000;
	DTR5 = 0x0000;
	DTR6 = 0x0000;
    
	ALTDTR1 = 0x0000;
	ALTDTR2 = 0x0000;
	ALTDTR3 = 0x0000;
	ALTDTR4 = 0x0000;
	ALTDTR5 = 0x0000;
	ALTDTR6 = 0x0000;
    
	TRGCON1 = 0x0000;
	TRGCON2 = 0x0000;
	TRGCON3 = 0x0000;
	TRGCON4 = 0x0000;
	TRGCON5 = 0x0000;
	TRGCON6 = 0x0000;
    
	IOCON1 = 0xFC00;
	IOCON2 = 0xFC00;
	IOCON3 = 0xFC00;
	IOCON4 = 0xFC00;
	IOCON5 = 0xFC00;
	IOCON6 = 0xFC00;
    
/*	IOCON1bits.PENH = 1;		//PWM module controls PWM1H pin
	IOCON1bits.PENL = 1;		//PWM module controls PWM1L pin
	IOCON1bits.POLH = 1;		//
	IOCON1bits.POLL = 1;		//
	IOCON1bits.PMOD = 3;		//
	IOCON1bits.OVRENH = 0;		//
	IOCON1bits.OVRENL = 0;		//
	IOCON1bits.SWAP = 1;		//
*/
//	TRIG1 = ;		//

	FCLCON1 = 0x0000;
	FCLCON2 = 0x0000;
	FCLCON3 = 0x0000;
	FCLCON4 = 0x0000;
	FCLCON5 = 0x0000;
	FCLCON6 = 0x0000;
    
	LEBCON1 = 0x0000;
	LEBCON2 = 0x0000;
	LEBCON3 = 0x0000;
	LEBCON4 = 0x0000;
	LEBCON5 = 0x0000;
	LEBCON6 = 0x0000;
    
	LEBDLY1 = 0x0000;
	LEBDLY2 = 0x0000;
	LEBDLY3 = 0x0000;
	LEBDLY4 = 0x0000;
	LEBDLY5 = 0x0000;
	LEBDLY6 = 0x0000;
    
	AUXCON1 = 0x0000;
	AUXCON2 = 0x0000;
	AUXCON3 = 0x0000;
	AUXCON4 = 0x0000;
	AUXCON5 = 0x0000;
	AUXCON6 = 0x0000;

 //   PWMCAPx = ;       //

	PTCONbits.PTEN = 1;		//PWM module is enabled
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Pwm_Input(unsigned int pwm4_pdc,unsigned int pwm4_sdc,unsigned int pwm5_pdc,unsigned int pwm5_sdc, unsigned int pwm6_pdc, unsigned int pwm6_sdc)
{
	PDC4 = pwm4_pdc;
	SDC4 = pwm4_sdc;
	PDC5 = pwm5_pdc;
	SDC5 = pwm5_sdc;
	PDC6 = pwm6_pdc;
	SDC6 = pwm6_sdc;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~






















