/*************************************************************************************************

*************************************************************************************************/
#include "Buzzer.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagBUZZER
{
	unsigned	long	bee_time_count;		//buzzer bee time count
	unsigned	long	bee_interval;			//buzzer bee interval
	unsigned	char	bee_times;				//buzzer bee times
}BUZZER;
static BUZZER sbuzzer;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*************************************************************************************************
conditions for execution:
		timer's times must be less than the buzzer call interval time,and more than 0.46ms
*************************************************************************************************/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Buzzer_Timer(void)	//called in timer
{
	if(sbuzzer.bee_time_count < BUZZER_COUNT_MAX)
	{
		sbuzzer.bee_time_count++;
	}
	else
	{
		sbuzzer.bee_time_count = BUZZER_COUNT_MAX;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*************************************************************************************************

*************************************************************************************************/
void Buzzer_Handle(void)		//called in main
{
	if(sbuzzer.bee_times >= 1)
	{
		if(sbuzzer.bee_time_count < sbuzzer.bee_interval)
		{
			IO_OUT_BUZZER = BUZZER_HIGH;
		}
		else
		{
			if(sbuzzer.bee_time_count <= (sbuzzer.bee_interval << 1))
			{
				IO_OUT_BUZZER = BUZZER_LOW;
			}
			else
			{
				sbuzzer.bee_times--;
				if(sbuzzer.bee_times >= 1)
				{
					sbuzzer.bee_time_count = 0;
				}
			}
		}
	}
	else
	{
		IO_OUT_BUZZER = BUZZER_LOW;	//if the buzzer number is 0,then the buzzer does not call
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/**************************************************************************************************

**************************************************************************************************/
void Buzzer_Input(unsigned int sound_interval_ms, unsigned char sound_times)	//for external module calls
{
	sbuzzer.bee_time_count = 0;		//clearn bee time count
	sbuzzer.bee_times = sound_times;			//input bee times
	sbuzzer.bee_interval = sound_interval_ms;	//input bee interval times
	sbuzzer.bee_interval = sbuzzer.bee_interval * 1000 / BUZZER_TIMER_US;
}


