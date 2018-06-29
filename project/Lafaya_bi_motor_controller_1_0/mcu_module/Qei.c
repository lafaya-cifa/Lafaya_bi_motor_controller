#include "Qei.h"

typedef struct tagQEI
{
	unsigned	long	qei1_step;
	unsigned	char	qei1_good;


	unsigned long	qei2_step;
	unsigned	char	qei2_good;
	
}QEI;
static QEI sqei;

//~~~~~~~~~~test~~~~~~~~~~~
unsigned long test_step_history;
unsigned long test_step_temp;





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Qei(void)    //initialize qei,called in main
{
	QEI1CON = 0x0070;
//	QEI1CONbits.QEIEN = 0;	//module counters are disable
//	QEI1CONbits.QEISIDL = 0;	//continues module operation in idle mode
//	QEI1CONbits.PIMOD = PIMOD_NUMBER;	//resets the position counter when the position counter equals the QEI1GEC register
//	QEI1CONbits.IMV = 0;		//index match value :index input event does not affect position counter
//	QEI1CONbits.INTDIV = 111;	//prescale value 1:256
//	QEI1CONbits.CNTPOL = 0;	//counter direction is positive unless modified by extern up/down signal
//	QEI1CONbits.GATEN = 0;	//external gate signal does not affect position counter/timer operation
//	QEI1CONbits.CCM = 0;		//quadrature encoder interface (x4 mode) count mode is selected

	QEI1IOC = 0x0000;
//	QEI1IOCbits.QCAPEN = 0;	//HOME1 input event (positive edge) does not trigger a capture event
//	QEI1IOCbits.FLTREN = 0;	//input pin digital filter is disable
//	QEI1IOCbits.QFDIV = 0;	//clock divide 1:1
//	QEI1IOCbits.OUTFNC = 0;	//output is disabled
//	if (SWPAB1_CHOICE == 1 )
//	{
//		QEI1IOCbits.SWPAB = 0;	  //QEA1 and QEB1 are not swapped
//	}
//	else
//	{
//		QEI1IOCbits.SWPAB = 1;	//QEA1 and QEB1 are swapped prior to quadrature decoder logic
//	}

	QEI1STAT = 0x1100;
//	QEI1STATbits.PCHEQIRQ = 0;
//	QEI1STATbits.PCHEQIEN  = 1;
//	QEI1STATbits.PCLEQIRQ = 0;
//	QEI1STATbits.PCLEQIEE = 0;
//	QEI1STATbits.POSOVIRQ = 0;
//	QEI1STATbits.POSOVIEN = 0;
//	QEI1STATbits.PCIIRQ = 0;
//	QEI1STATbits.PCIIEN = 0;
//	QEI1STATbits.VELOVIRQ = 0;
//	QEI1STATbits.VELOVIEN = 0;
//	QEI1STATbits.HOMIRQ = 0;
//	QEI1STATbits.HOMIEN = 0;
//	QEI1STATbits.IDXIRQ = 0;
//	QEI1STATbits.IDXIEN = 0;

	QEI1_Poscnt_Input(QEI_INIT);

	
	QEI1GECH = QEI_QEIGEC >> 16;
	QEI1GECL = QEI_QEIGEC & 0x0000FFFF;				//set QEIGECL as 2000
	
	IPC14bits.QEI1IP = QEIIP_NUMNBER;		//QEIIP number
	IEC3bits.QEI1IE = 1;					//qei1 interrupt is enabled
	IFS3bits.QEI1IF = 0;					//clear qei1 flag     
	
	QEI1CONbits.QEIEN = 1;	//module counters are enable
	
	sqei.qei1_step = QEI_STEP_INIT;			//qei step initialize
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	QEI2CON = 0x0070;
	QEI2IOC = 0x0000;
	QEI2STAT = 0x1100;
	
//	if (IO_DIP1 == 1 )
//	{
//		QEI2IOCbits.SWPAB = 0;	  //QEA1 and QEB1 are not swapped
//	}
//	else
//	{
//		QEI2IOCbits.SWPAB = 1;	//QEA1 and QEB1 are swapped prior to quadrature decoder logic
//	}

	QEI2_Poscnt_Input(QEI_INIT);


	QEI2GECH = QEI_QEIGEC >> 16;
	QEI2GECL = QEI_QEIGEC & 0x0000FFFF;		//set QEI1GECL

//	QEI2ICH = QEI_QEIGEC >> 16;
//	QEI2ICL = QEI_QEIGEC & 0x0000FFFF;		//set QEI1GECL
	
	IPC18bits.QEI2IP = QEIIP_NUMNBER;		//QEIIP number
	IEC4bits.QEI2IE = 1;					//qei2 interrupt is enabled
	IFS4bits.QEI2IF = 0;					//clear qei1 flag     
	
//	QEI2STATbits.PCHEQIRQ = 0;
//	QEI2STATbits.POSOVIRQ = 0;
	
	QEI2CONbits.QEIEN = 1;	//module counters are enable

	sqei.qei2_step = QEI_STEP_INIT;			//qei step initialize
	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  __attribute__((interrupt, no_auto_psv))_QEI1Interrupt(void)  //qei1 interrupt input
{ 
	unsigned long qei_temp = 0;

	if(QEI1STATbits.PCHEQIRQ == 1)
	{
		if(QEI1STATbits.POSOVIRQ == 1)	//the same to POSOVIRQ == 1 only,motor is clockwise rotation
		{
			sqei.qei1_step--;
			qei_temp = QEI_QEIGEC - (QEI_INIT - Qei1_Poscnt());
			QEI1_Poscnt_Input(qei_temp);
		
			QEI1STATbits.POSOVIRQ = 0;
		}
		else		//PCHEQIRQ==1 only,motor is anciclockwise rotation
		{
			sqei.qei1_step++;
			qei_temp = QEI_INIT + (Qei1_Poscnt() - QEI_QEIGEC);
			QEI1_Poscnt_Input(qei_temp);
		}
		QEI1STATbits.PCHEQIRQ = 0;
	}

	sqei.qei1_good = 1;		//qei is good
	
	IFS3bits.QEI1IF = 0;	//clear qei1 flag
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  __attribute__((interrupt, no_auto_psv))_QEI2Interrupt(void)  //qei2 interrupt input
{
	unsigned long qei_temp = 0;

	if(QEI2STATbits.PCHEQIRQ == 1)
	{
		if(QEI2STATbits.POSOVIRQ == 1)	//the same to POSOVIRQ == 1 only,motor is clockwise rotation
		{
			sqei.qei2_step--;
			qei_temp = QEI_QEIGEC - (QEI_INIT - Qei2_Poscnt());
			QEI2_Poscnt_Input(qei_temp);
		
			QEI2STATbits.POSOVIRQ = 0;
		}
		else		//PCHEQIRQ==1 only,motor is anticlockwise rotation
		{
			sqei.qei2_step++;
			qei_temp = QEI_INIT + (Qei2_Poscnt() - QEI_QEIGEC);
			QEI2_Poscnt_Input(qei_temp);
		}
		QEI2STATbits.PCHEQIRQ = 0;
	}
	




	//~~~~~~~~~~~~~~~~~~~~~~~~~~
	sqei.qei2_good = 1;		//qei is good
	
	IFS4bits.QEI2IF = 0;		//clear qei2 flag
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void QEI1_Poscnt_Input(unsigned long poscnt_value)
{
	POS1HLD = poscnt_value >> 16;			//POS1HLD initialize
	POS1CNTL = poscnt_value & 0x0000FFFF;			//POS1CNTH initialize
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void QEI2_Poscnt_Input(unsigned long poscnt_value)
{
	POS2HLD = poscnt_value >> 16;			//POS1HLD initialize
	POS2CNTL = poscnt_value & 0x0000FFFF;			//POS1CNTH initialize
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned long Qei1_Poscnt(void)
{
	unsigned long poscnt_low, poscnt_high, poscnt;
	poscnt_low = POS1CNTL;
	poscnt_high = POS1HLD;
	poscnt = (poscnt_high << 16) + poscnt_low;
	return poscnt;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned long Qei2_Poscnt(void)
{
	long poscnt_low, poscnt_high, poscnt;
	poscnt_low = POS2CNTL;
	poscnt_high = POS2HLD;
	poscnt = (poscnt_high << 16) + poscnt_low;
	return poscnt;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned long Qei1_Position(void)
{
	return sqei.qei1_step * QEI_STEPS + Qei1_Poscnt() - QEI_INIT;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned long Qei2_Position(void)
{
	return sqei.qei2_step * QEI_STEPS + Qei2_Poscnt() - QEI_INIT;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Qei1_Position_input(unsigned long position_input)	//position input
{
	sqei.qei1_step = position_input / QEI_STEPS;
	QEI1_Poscnt_Input((position_input % QEI_STEPS) + QEI_INIT);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Qei2_Position_input(unsigned long position_input)	//position input
{
	sqei.qei2_step = position_input / QEI_STEPS;
	QEI2_Poscnt_Input((position_input % QEI_STEPS) + QEI_INIT);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char Qei1_Good(void)
{
	return sqei.qei1_good;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char Qei2_Good(void)
{
	return sqei.qei2_good;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


