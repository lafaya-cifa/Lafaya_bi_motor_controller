#include "Speed.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned long speed1_start;
unsigned long speed1_end;
unsigned long speed1_time;
unsigned long speed1_step;

unsigned long speed2_start;
unsigned long speed2_end;
unsigned long speed2_time;
unsigned long speed2_step;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Speed_Varialbe(void)
{
	speed1_start = 0;
	speed1_end = 0;
	speed1_time = 0;
	speed1_step = 0;

	speed2_start = 0;
	speed2_end = 0;
	speed2_time = 0;
	speed2_step = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Speed1_Time(void)
{
	speed1_start = speed1_end;
	while(IC1CON1bits.ICBNE > 0)
	{
		speed1_end = IC1BUF;
	}
	speed1_time = speed1_end + PR3 * speed1_step - speed1_start;
	speed1_step = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Speed2_Time(void)
{
	speed2_start = speed2_end;
	while(IC2CON1bits.ICBNE > 0)
	{
		speed2_end = IC2BUF;
	}
	speed2_time = speed2_end + PR4 * speed2_step - speed2_start;
	speed2_step = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Speed1_Counter(void)
{
	if(speed1_step < SPEED_STEP_MAX)
	{
		speed1_step++;
	}
	else
	{
		speed1_step = SPEED_STEP_MAX;
		speed1_time = SPEED_TIME_MAX;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Speed2_Counter(void)
{
	if(speed2_step < SPEED_STEP_MAX)
	{
		speed2_step++;
	}
	else
	{
		speed2_step = SPEED_STEP_MAX;
		speed2_time = SPEED_TIME_MAX;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
long Speed1_Calculate(void)
{
	long speed1_temp,speed1_now;
	static long speed1_avg[10] = {0,0,0,0,0,0,0,0,0,0};
	
	if((speed1_time > (CALCULATE_SPEED_TIME / CALCULATE_SPEED_MAX)) && (speed1_time < (CALCULATE_SPEED_TIME / CALCULATE_SPEED_MIN)))	//speed > 1400mm/s or speed < 0.1mm/s,speed as 0
	{
		speed1_temp = CALCULATE_SPEED_TIME / speed1_time;
	}
	else
	{
		speed1_temp = 0;
	}

	speed1_avg[0] = speed1_avg[1];
	speed1_avg[1] = speed1_avg[2];
	speed1_avg[2] = speed1_avg[3];
	speed1_avg[3] = speed1_avg[4];
	speed1_avg[4] = speed1_avg[5];
	speed1_avg[5] = speed1_avg[6];
	speed1_avg[6] = speed1_avg[7];
	speed1_avg[7] = speed1_avg[8];
	speed1_avg[8] = speed1_avg[9];
	speed1_avg[9] = speed1_temp;

	speed1_now = (speed1_avg[0] + speed1_avg[1] + speed1_avg[2] + speed1_avg[3] + speed1_avg[4] + speed1_avg[5] + speed1_avg[6] + speed1_avg[7] + speed1_avg[8] + speed1_avg[9]) / 10;
//	Speed_Is_Low(speed1_low_enable,speed1_now,speed1_low_limit,time_speed1_low_limit,&speed1_low_count,&speed1_is_low);
	return speed1_now;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
long Speed2_Calculate(unsigned char motor_status,unsigned long position_now)
{
	long speed2_temp,speed2_now;
	static long speed2_avg[10] = {0,0,0,0,0,0,0,0,0,0};
	static long position_temp = 0;
	
	if((speed2_time > (CALCULATE_SPEED_TIME / CALCULATE_SPEED_MAX)) && (speed2_time < (CALCULATE_SPEED_TIME / CALCULATE_SPEED_MIN)))	//speed > 1400mm/s or speed < 0.1mm/s,speed as 0
	{
		speed2_temp = CALCULATE_SPEED_TIME / speed2_time;
	}
	else
	{
		speed2_temp = 0;
	}

	speed2_avg[0] = speed2_avg[1];
	speed2_avg[1] = speed2_avg[2];
	speed2_avg[2] = speed2_avg[3];
	speed2_avg[3] = speed2_avg[4];
	speed2_avg[4] = speed2_avg[5];
	speed2_avg[5] = speed2_avg[6];
	speed2_avg[6] = speed2_avg[7];
	speed2_avg[7] = speed2_avg[8];
	speed2_avg[8] = speed2_avg[9];

	
	if((motor_status == 1 && position_now > position_temp) || (motor_status == 2 && position_now < position_temp))	//motor_status=1,as FORWARD_ROTATION;motor_status=2,as REVERSE_ROTATION
	{
		speed2_avg[9] = -speed2_temp;
	}
	else
	{
		speed2_avg[9] = speed2_temp;
	}
	position_temp = position_now;
	

	speed2_now = (speed2_avg[0] + speed2_avg[1] + speed2_avg[2] + speed2_avg[3] + speed2_avg[4] + speed2_avg[5] + speed2_avg[6] + speed2_avg[7] + speed2_avg[8] + speed2_avg[9]) / 10;
//	Speed_Is_Low(speed2_low_enable,speed2_now,speed2_low_limit,time_speed2_low_limit,&speed2_low_count,&speed2_is_low);
	return speed2_now;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void Speed_Is_Low(unsigned char speed_low_enable,long speed_now,unsigned int speed_low_limit,unsigned int time_speed_low_limit,unsigned int *speed_low_count,unsigned char *speed_is_low)
{//speed_is_low = 1,time 450us * 100 = 45000us = 45ms
	if(speed_now < speed_low_limit && speed_low_enable == 1)
	{
		if(*speed_low_count < TIME_SPEED_LOW_MAX)
		{
			(*speed_low_count)++;
			if(*speed_low_count >= time_speed_low_limit)
			{
				*speed_is_low = 1;
			}
		}
		else
		{
			*speed_low_count = TIME_SPEED_LOW_MAX;
		}
	}
	else
	{
		*speed_low_count = 0;
		*speed_is_low = 0;
	}
}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~







