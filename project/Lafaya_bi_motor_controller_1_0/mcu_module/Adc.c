#include "Adc.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int read_adc[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Adc(void)			//called in main
{
	AD1CON1 = 0x00EC;		//
//	AD1CON1bits.ADON = 0;		//ADC is off
//	AD1CON1bits.ADSIDL = 0;		//continues module operation in idle mode
//	AD1CON1bits.ADDMABM = 0;	//DMA buffers are writen in scatter/gather mode
//	AD1CON1bits.AD12B = 0;		//10-bit, 4-channel ADC operation
//	AD1CON1bits.FORM = 0;		//data output format is integer
//	AD1CON1bits.SSRC = 0x0E;		//sample clock sourse select internal counter ends sampling and starts conversion (auto-convert)
//	AD1CON1bits.SSRCG = 0;		//sample clock sourse group is 0
//	AD1CON1bits.SIMSAM = 1;		//sample CH0,CH1,CH2,CH3 simutaneously
//	AD1CON1bits.ASAM = 1;		//sampling begins immediately after the last conversion
//	AD1CON1bits.SAMP = 0;		//ADC S&H ampifiers are holding
//	AD1CON1bits.DONE = 0;		//ADC conversion has not

	AD1CON2 = 0x023C;
//	AD1CON2bits.VCFG = 0;		//converter voltage reference configuration is Vrefh-AVdd,Vrefl-AVss
//	AD1CON2bits.CSCNA = 0;		//no scans CH0+
//	AD1CON2bits.CHPS = 0x20;		//converts CH0,CH1,CH2 and CH3
//	AD1CON2bits.BUFS = 0;		//ADC is currently filling the first half of the buffer;the user application should accsess data in the second of the buffer
//	AD1CON2bits.SMPI = 0x0F;		//generates interrupt affter completion of every 16th sample/conversion operation
//	AD1CON2bits.BUFM = 0;		//always starts filling the buffer from the start address
//	AD1CON2bits.ALTS = 0;			//always uses channel input selects for sample A

	AD1CON3 = 0x0F0F;
//	AD1CONbits.ADRC = 0;			//clock derived from system clock
//	AD1CONbits.SAMC = 0x0F;		//auto-sample time is 15 TAD
//	AD1CONbits.ADCS = 0x0F;		//ADC conversion clock select 16 * Tcy = TAD

	AD1CON4 = 0x0000;
//	AD1CON4bits.ADDMAEN = 0;	//conversion results are stored in ADC1BUF0 through ADC1BUFF registers; DMA will not be used
//	AD1CON4bits.DMABL = 0;		//allocates 1 word of buffer to each analog input

	AD1CSSH = 0x0000;			//select AN0 for scanning
	AD1CSSL = 0x0000;			//select AN0 for scanning because CH0 +ve is not scans

	AD1CHS0bits.CH0SA = 3;		//CH0SA bits  for CH0 +ve input select AN3
	AD1CHS0bits.CH0NA = 0;		//select Vref- for CH0 -ve input
	AD1CHS123bits.CH123SA = 0;	//select AN0 for CH1 +ve input;select AN1 for CH2 +ve input;select AN2 for CH3 +ve input
	AD1CHS123bits.CH123NA = 0;
    
//	AD1CHS0bits.CH0SB= 23;		//CH0SB bits ignored for CH0 +ve input selection
//	AD1CHS0bits.CH0NB = 0;		//select Vref- for CH0 -ve input
	

	IPC3bits.AD1IP = 6;			//set AD1IP is 3
	IEC0bits.AD1IE = 1;			//enable AD1 interrupt
	IFS0bits.AD1IF = 0;			//clear AD1IF

	AD1CON1bits.ADON = 1;		//ADC module is operation
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __attribute__((__interrupt__,no_auto_psv)) _AD1Interrupt(void)
{
	read_adc[0] = ADC1BUF0;		//read the AN3 conversion result
	read_adc[1] = ADC1BUF1;		//read the AN0 conversion result
	read_adc[2] = ADC1BUF2;		//read the AN1 conversion result
	read_adc[3] = ADC1BUF3;		//read the AN2 conversion result
	read_adc[4] = ADC1BUF4;		//read the AN3 conversion result
	read_adc[5] = ADC1BUF5;		//read the AN0 conversion result
	read_adc[6] = ADC1BUF6;		//read the AN1 conversion result
	read_adc[7] = ADC1BUF7;		//read the AN2 conversion result
	read_adc[8] = ADC1BUF8;		//read the AN3 conversion result
	read_adc[9] = ADC1BUF9;		//read the AN0 conversion result
	read_adc[10] = ADC1BUFA;	//read the AN1 conversion result
	read_adc[11] = ADC1BUFB;	//read the AN2 conversion result
	read_adc[12] = ADC1BUFC;	//read the AN3 conversion result
	read_adc[13] = ADC1BUFD;	//read the AN0 conversion result
	read_adc[14] = ADC1BUFE;	//read the AN1 conversion result
	read_adc[15] = ADC1BUFF;		//read the AN2 conversion result

	IFS0bits.AD1IF = 0;


	Temperature_Handle();
	Current_Handle();
	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





