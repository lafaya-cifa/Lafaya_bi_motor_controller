#include "mcu_module/Header.h"
#include "communication/Command.h"
#include "communication/Uart.h"
#include "data/DEE Emulation 16-bit.h"
#include "logic_control/Door Control.h"
#include "mcu_module/Adc.h"
#include "mcu_module/Ic.h"
#include "mcu_module/Pwm.h"
#include "mcu_module/Qei.h"
#include "mcu_module/Timer.h"
#include "motor_driver/Motor Drive.h"
#include "util_tool/Algorithm.h"
#include "util_tool/Buzzer.h"
#include "util_tool/Current.h"
#include "util_tool/Led.h"
#include "util_tool/Rtc.h"
#include "util_tool/Speed.h"
#include "util_tool/Temperature.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
_FOSCSEL(FNOSC_FRC      //Internal Fast RC (FRC)
        & IESO_OFF);    //Start up with user-selected oscillator source
_FOSC(POSCMD_XT         //XT Crystal Oscillator Mode
        & OSCIOFNC_OFF  //OSC2 is clock output
        & FCKSM_CSECMD  //Clock switching is enabled,Fail-safe Clock Monitor is disabled
        & IOL1WAY_ON);  //Allow only one reconfiguration

_FWDT(WDTPOST_PS128    // 1:128
        & WDTPRE_PR128  // 1:128
        & PLLKEN_ON     //Clock switch to PLL source will wait until the PLL lock signal is valid
        & WINDIS_OFF    //Watchdog Timer in Non-Window mode
        & FWDTEN_ON);   //Watchdog timer always enabled
_FPOR(FPWRT_PWR128      //128ms
        & BOREN_ON      //BOR is enabled
        & ALTI2C1_OFF   //SDA1/SCK1 pins are selected as the I/O pins for I2C1
        & ALTI2C2_OFF); //I2C2 mapped to SDA2/SCL2 pins  
_FICD(ICS_PGD1          //Communicate on PGEC1 and PGED1
        & RSTPRI_PF     //Device will obtain reset instruction from Primary flash
        & JTAGEN_OFF);  //JTAG is disabled
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned long buzzer_temp;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Delay(unsigned long delay_time);
void Initialize_Port(void);
void Initialize_Cpu(void);
void Initialize_Mapping(void);   //mapping set
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(void)
{
	CLKDIVbits.PLLPOST = 0;     //N2=2*(PLLPOST+1)=2*(0+1)=2
	CLKDIVbits.PLLPRE = 0;      //N1=PLLPRE+2=0+2=2
	PLLFBD = 38;                //M=PLLFBD+38=40
    
	__builtin_write_OSCCONH(0x03);
	__builtin_write_OSCCONL(0x01);

	/*Fosc = Fin * (M / (N1 * N2))
	*      =12MHZ*(40/(2*2))
	*      = 12MHZ*10
	*      =120MHZ
	*/
	while(OSCCONbits.COSC != 0b011);     //Wait for PLL to lock
	while(OSCCONbits.LOCK != 1);        //Wait PLL to be locked
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Delay(1000000);		// 290ms
	
	DataEEInit();
 	dataEEFlags.val = 0;
    
	Initialize_Port();
	Initialize_Cpu();
	Initialize_Mapping();			//mapping set
	Initialize_Command_Varialbe();
	Initialize_Uart();				//
	Initialize_Qei();				//initialize qei,called in main
	Initialize_Pwm();				//PWM initialized to called in main
	Initialize_Rtc_Variable();		//Rtc mode variable Initialization
	Initialize_Adc();				//called in main
	Initialize_Temperature_Varialbe();	//called in main
	Initialize_Current_Varialbe();			//called in main
	Initialize_Ic();    						//initialize qei,called in main
	
	Initialize_Door_Control_Varialbe();	//initialize door control ,called in main
	Initialize_Speed_Varialbe();			//called in main
	Initialize_Motor_Drive_Variable();
	Initialize_Timer();					//called in main
	

	buzzer_temp = 0;

	while(1)
	{
		Buzzer_Handle();		//called in mian
		Led_Double_Handle();		//called in main
		Uart_Handle();      //called in main to send data

		switch(buzzer_temp)
		{
			case 0 :
					if(IO_INPUT_BUTTON == FALSE)
					{
						buzzer_temp = 1;
						motor2_control.status = FORWARD;
					}
					break;
			case 1 :
					if(IO_INPUT_BUTTON == TRUE)
					{
						buzzer_temp = 2;
					}
					break;
			case 2 :
					if(IO_INPUT_BUTTON == FALSE)
					{
						buzzer_temp = 3;
						Motor2_Stopping();
					}
					break;
			case 3 :
					if(IO_INPUT_BUTTON == TRUE)
					{
						buzzer_temp = 4;
					}
					break;
			case 4 :
				 	if(IO_INPUT_BUTTON == FALSE)
					{
						buzzer_temp = 5;
						motor2_control.status = REVERSE;
					}
					break;
			case 5 :
					if(IO_INPUT_BUTTON == TRUE)
					{
						buzzer_temp = 0;
					}
					break;
			default : buzzer_temp = 0;
					break;
		}
		
        
        
        

	//	Door_Control();	//called in main while

		if(door2_run_way == DOOR_KEEP_CLOSE || door2_run_way == DOOR_KEEP_OPEN) 
		{
			Save_Door_Countrol_Varialbe();
		}
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ClrWdt();
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Delay(unsigned long delay_time)
{	// 1000=290us
	unsigned long delay_temp;
	for(delay_temp = 0;delay_temp < delay_time;delay_temp++)
	{
		ClrWdt();
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Port(void)
{
	ANSELA = 0x0000;
	ANSELB = 0x000F;		//set RB0/RB1/RB2/RB3 as analog io
	ANSELC = 0x0000;
	ANSELD = 0x0000;
	ANSELE = 0x0000;
	ANSELG = 0x0000;

	TRISA = 0x007F;		//set RA0/RA1/RA2/RA3/RA4/RA5/RA6/ as input,RA7/RA9/RA10 as output
	TRISB = 0xF01F;		//set RB0/RB1/RB2/RB3/RB4/RB12/RB13/RB14/RB15 as input,RB5/RB6/RB7/RB8/RB9/RB10/RB11 as output
	TRISC = 0x0000;		//set PORTC as output
	TRISD = 0x290A;		//set RD1/RD3/RD8/RD11/RD13 as input,RD0/RD2/RD4/RD5/RD6/RD7/RD9/RD10/RD12/RD14/RD15 as output
	TRISE = 0x0000;		//set PORTE as output
	TRISF = 0x210D;		//set RF0/RF2/RF3/RF8/RF12/RF13/ as input,RF1/RF4/RF5 as output
	TRISG = 0x200C;		//set RG2/RG3/RG13 as input,RG0/RG1/RG6/RG7/RG8/RG9/RG12/RG14/RG15 as output
	TRISH = 0xFFF0;		//set RH4/RH5/RH6/RH7/RH8/RH9/RH10/RH11/RH12/RH13/RH14/RH15 as input,RH0/RH1 as output
	TRISJ = 0x0000;		//set PORTD as output
	TRISK = 0xF800;		//set RK11/RK12/RK13/RK14/RK15 as input,RK0/RK1/ as output

	PORTA = 0x0000;
	PORTB = 0x0000;
	PORTC = 0x0000;
	PORTD = 0x0000;
	PORTE = 0x0000;
	PORTF = 0x0000;
	PORTG = 0x0000;
	PORTH = 0x0000;
	PORTJ = 0x0000;
	PORTK = 0x0000;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Cpu(void)
{
	SRbits.IPL2 = 0;    //CPU IPL as 0;
	SRbits.IPL1 = 0;    //CPU IPL as 0;
	SRbits.IPL0 = 0;    //CPU IPL as 0;
    
//    CORCONbits.IPL3 = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Mapping(void)   //mapping set
{
/*    OSCCON = OSCCON & 0xFF46;
	OSCCON = OSCCON & 0xFF57;
	_IOLOCK = 0;    //clear IOLOCK,mapping enabled
    
	RPINR18bits.U1RXR = 0x60;   //assogn U1RXR to pin RP96
	RPOR13bits.RP113R = 1;      //assign U1TX to pin RP113

	 OSCCON = OSCCON & 0xFF46;
	OSCCON = OSCCON & 0xFF57;
    _IOLOCK = 1;    //mapping disabled
*/
	//the same to front
	__builtin_write_OSCCONL(OSCCON & ~(1 << 6));
    
	RPINR18bits.U1RXR = 0x60;   //assogn U1RXR to pin RP96
	RPOR13bits.RP113R = 1;      //assign U1TX to pin RP113
    
	RPINR14bits.QEA1R = 0x4E;
	RPINR14bits.QEB1R = 0x4F;
	RPINR15bits.INDX1R = 0x63;

	RPINR16bits.QEA2R = 0x14;
	RPINR16bits.QEB2R = 0x13;
	RPINR17bits.INDX2R = 0x12;

	RPINR7bits.IC1R = 0x6D;
	RPINR7bits.IC2R = 0x43;
	
	__builtin_write_OSCCONL(OSCCON | (1 << 6));  
}




