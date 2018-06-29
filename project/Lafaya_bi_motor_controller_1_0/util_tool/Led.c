#include "Led.h"

const unsigned int  led_show_table[28]={
								0x00C0,	0x00F9,	0x00A4,	0x00B0,  	//	0,	1,	2,	3	= 1100 0000 	1111 1001	1010 0100	1011 0000
								0x0099,	0x0092,	0x0082,	0x00F8,  	// 	4,	5,	6,	7 	= 1001 1001		1001 0010	1000 0010	1111 1000
								0x0080,	0x0090,	0x0088,	0x0083,  	//	8,	9,	A,	b	= 1000 0000		1001 0000 	1000 1000	1000 0011
								0x00C6,	0x00A1,	0x0086,	0x008E,  	//	C,	d,	E,	F	= 1100 0110		1010 0001	1000 0110	1000 1110
								0x00AF,	0x00E3,	0x00AB,	0x007F,  	//	r,	u,	n,	.,	= 1010 1111 	1110 0011	1010 1011	0111 1111
								0x00FE,	0x00FD,	0x00FB,	0x00F7,  	//	"a"	"b"	"c"	"d"	= 1111 1110		1111 1101	1111 1011	1111 0111
								0x00EF,	0x00DF,	0x00BF,	0x00A3}; 	//	"e"	"f"	"g"	"o"	= 1110 1111		1101 1111	1011 1111	1010 0011
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagDISPLAY
{
	unsigned	long    led_time_count;	//show time count
	unsigned	long	led_runing_count;	//led runing count
	unsigned	char	led_status;			//led status,use to send to pc
	unsigned	char	led_number;		//led show number,relative to display led table array
	unsigned	char	led_dot;				//led show dot
	unsigned	char	led_direction;		//led show direction
}DISPLAY;
static DISPLAY sdisplay;

const long led_interval = LED_INTERVAL_TIME * 1000UL / LED_TIMER_US;
const long led_running_interval = LED_RUNNING_TIME * 1000UL / LED_TIMER_US;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Led_Timer(void)	//called in timer
{
	if(sdisplay.led_time_count < LED_COUNT_MAX)
	{
		sdisplay.led_time_count++;
	}
	else
	{
		sdisplay.led_time_count = LED_COUNT_MAX;
	}

	if(sdisplay.led_runing_count < LED_COUNT_MAX)
	{
		sdisplay.led_runing_count++;
	}
	else
	{
		sdisplay.led_runing_count = LED_COUNT_MAX;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/**************************************************************************************************************************
pamameter define:
				sdisplay.led_status=0:static display,display a number or a symbol only
								   =1:display clockwise horse race lamp
								   =2:display anti-clockwise horse race lamp
**************************************************************************************************************************/
void Led_Handle(void)		//called in main
{
	if(sdisplay.led_status == 0)
	{
		if(sdisplay.led_dot == 1)	//display point
		{
			IO_OUT_LEDPORT =  (IO_OUT_LEDPORT & 0xFF00) | (led_show_table[sdisplay.led_number] & led_show_table[19]);
		}
		else
		{
			IO_OUT_LEDPORT =  (IO_OUT_LEDPORT & 0xFF00) | led_show_table[sdisplay.led_number];
		}
	}
	else
	{
		if(sdisplay.led_time_count >=  led_interval)
		{
			if(sdisplay.led_dot == 1)	//display point
			{
				IO_OUT_LEDPORT =  (IO_OUT_LEDPORT & 0xFF00) | (led_show_table[sdisplay.led_number] & led_show_table[19]);
			}
			else
			{
				IO_OUT_LEDPORT =  (IO_OUT_LEDPORT & 0xFF00) | led_show_table[sdisplay.led_number];
			}
			if(sdisplay.led_status == 1)
			{
				if(sdisplay.led_number < 25)
				{
					sdisplay.led_number++;
				}
				else
				{
					sdisplay.led_number = 20;
				}
			}
			else
			{
				if(sdisplay.led_number > 20)
				{
					sdisplay.led_number--;
				}
				else
				{
					sdisplay.led_number = 25;
				}
			}
			
			sdisplay.led_time_count = 0;
		}
	}
}
/***************************************************************************************************************************

***************************************************************************************************************************/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Led_Input(unsigned char display_status, unsigned char display_dot,...)	//for external modul calls
{
	unsigned char display_number = 0;
	sdisplay.led_time_count = 0;
	sdisplay.led_status = display_status;
	sdisplay.led_dot = display_dot;
	if(display_status > 0)
	{
		sdisplay.led_number = 20;
	}
	else
	{
		va_list temp_list; ////define a list
		va_start(temp_list,display_dot);
		display_number = va_arg(temp_list,char);
		va_end(temp_list);
		sdisplay.led_number = display_number;
	}	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Led_Double_Handle(void)	//called in main
{
	static unsigned char display_runing_number = 20;	//the horse race lamp to display
	if(sdisplay.led_status == 0)	//now is the number valid,only to show the number
	{
		if(sdisplay.led_time_count < led_interval)
		{
			IO_OUT_LEDDIG2 = 0;
			if((sdisplay.led_dot & 0x01) == 0x01)	//point displayed within led1
			{
				IO_OUT_LEDPORT = (IO_OUT_LEDPORT & 0xFF00) |( led_show_table[sdisplay.led_number >> 4] & led_show_table[19]);
			}
			else
			{
				IO_OUT_LEDPORT = (IO_OUT_LEDPORT & 0xFF00) |  led_show_table[sdisplay.led_number >> 4];
			}	
			IO_OUT_LEDDIG1 = 1;
		}
		else
		{
			if(sdisplay.led_time_count < (led_interval << 1))
			{
				IO_OUT_LEDDIG1 = 0;
				if((sdisplay.led_dot & 0x02) == 0x02)	//point displayed within led2
				{
					IO_OUT_LEDPORT = (IO_OUT_LEDPORT & 0xFF00) | (led_show_table[sdisplay.led_number & 0x0F] & led_show_table[19]);
				}
				else
				{
					IO_OUT_LEDPORT = (IO_OUT_LEDPORT & 0xFF00) | led_show_table[sdisplay.led_number & 0x0F];
				}	
				IO_OUT_LEDDIG2 = 1;
			}
			else
			{
				sdisplay.led_time_count = 0;
			}
		}
	}
	else		//state and horse race lamp to be valid,display state and horse race lamp
	{
		if(sdisplay.led_time_count < led_interval)	//the led1 displayed
		{
			IO_OUT_LEDDIG2 = 0;
			if((sdisplay.led_dot & 0x01) == 0x01)	//display point
			{
				IO_OUT_LEDPORT = (IO_OUT_LEDPORT & 0xFF00) | (led_show_table[sdisplay.led_number] & led_show_table[19]);
			}
			else
			{
				IO_OUT_LEDPORT = (IO_OUT_LEDPORT & 0xFF00) | led_show_table[sdisplay.led_number];
			}
			IO_OUT_LEDDIG1 = 1;
		}
		else	//the led2 displayed
		{
			if(sdisplay.led_time_count < (led_interval << 1))
			{
				IO_OUT_LEDDIG1 = 0;
				if((sdisplay.led_dot & 0x02) == 0x02)	//display point
				{
					IO_OUT_LEDPORT = (IO_OUT_LEDPORT & 0xFF00) | (led_show_table[display_runing_number] & led_show_table[19]);
				}
				else
				{
					IO_OUT_LEDPORT = (IO_OUT_LEDPORT & 0xFF00) | led_show_table[display_runing_number];
				}
				IO_OUT_LEDDIG2 = 1;
				if(sdisplay.led_runing_count > led_running_interval)
				{
					if(sdisplay.led_direction == 0)
					{
						if(display_runing_number <25)
						{
							display_runing_number++;
						}
						else
						{
							display_runing_number = 20;
						}
					}
					else
					{
						if(display_runing_number > 20)
						{
							display_runing_number--;
						}
						else
						{
							display_runing_number = 25;
						}
					}
					sdisplay.led_runing_count = 0;
				}
			}
			else 
			{
				sdisplay.led_time_count = 0;
			}
		}
	}
}
/******************************************************************************************************************************
display_status:=0:display double numbers,=1:display a number + horse race lamp
display_number:display number
display_dot:=0:no display point.=1:led1 display point=2:led2 display point=3:led1 and led2 display point
display_direction:=0:display clockwise  =1:display anti-clockwise
*******************************************************************************************************************************/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void Led_Double_Input(unsigned char display_status , unsigned char display_number, unsigned char display_dot, unsigned char display_direction)
{
	sdisplay.led_time_count = 0;
	sdisplay.led_status = display_status;
	if(sdisplay.led_status > 1)
	{
		sdisplay.led_runing_count = 0;
		
	}
	sdisplay.led_number = display_number;
	sdisplay.led_dot = display_dot;
	sdisplay.led_direction = display_direction;
}*/
void Led_Double_Input(unsigned char display_status,unsigned char display_number, unsigned char display_dot, ...)    //for external modul calls
{
	unsigned char display_direction = 0;

	sdisplay.led_time_count = 0;
	sdisplay.led_status = display_status;
	sdisplay.led_number = display_number;
	sdisplay.led_dot = display_dot;
	
	if(sdisplay.led_status > 0)
	{
		sdisplay.led_runing_count = 0;
		
		va_list temp_list; //define a list
		va_start(temp_list,display_dot);
		display_direction = va_arg(temp_list,char);
		va_end(temp_list);
		sdisplay.led_direction = display_direction;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

