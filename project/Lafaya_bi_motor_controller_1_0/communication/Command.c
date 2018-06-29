#include "Command.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static unsigned char send_data[UART_DATA_NUMBER_MAX];
static unsigned char command_flag;     //command loading flag
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Command_Varialbe(void)
{
    send_data[UART_DATA_NUMBER_MAX] = 0;
    command_flag = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Send_Data_Exchange(unsigned char *data_input)
{
    unsigned char temp;
    for(temp = 0; temp <= send_data[0]; temp++)
    {
        data_input[temp] = send_data[temp];
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char Command_Flag_Output(void)
{
    return command_flag;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Command_Flag_Clear(void)
{
    command_flag = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Command_0x51(void)
{
    send_data[0] = 0x09;    //tx number is 9
    send_data[1] = 0x14;
    send_data[2] = 0x51;
    send_data[3] = 0x08;    //auto mode
    send_data[4] = 0x00;    //open lock
    send_data[5] = 0x01;    //
    send_data[6] = 0x02;
    send_data[7] = 0x03;
    send_data[8] = 0x01;
    send_data[9] = 0x00 ^ send_data[1] ^ send_data[2] ^ send_data[3] ^ send_data[4] ^ send_data[5] ^ send_data[6] ^ send_data[7] ^ send_data[8];
    command_flag = 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Command_Rtc_Test(void)
{
	send_data[0] = 0x07;    //tx number is 7
	send_data[1] = real_timeflags.real_year;
	send_data[2] = real_timeflags.real_month;
	send_data[3] = real_timeflags.real_day;
	send_data[4] = real_timeflags.real_hour;
	send_data[5] = real_timeflags.real_minute;
	send_data[6] = real_timeflags.real_second;
	send_data[7] = 0x00 ^ send_data[1] ^ send_data[2] ^ send_data[3] ^ send_data[4] ^ send_data[5] ^ send_data[6];
	command_flag = 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Command_temperature_Test(void)
{
	send_data[0] = 0x03;    //tx number is 3
	send_data[1] = Temperature2_Now() >> 8;
	send_data[2] = Temperature2_Now() & 0x00FF;
	send_data[3] = 0x00 ^ send_data[1] ^ send_data[2];
	command_flag = 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Command_Qei_End_Test(void)
{
	unsigned long qei_temp;
	qei_temp = door2_position.end;
	send_data[0] = 0x05;
	send_data[1] = qei_temp >> 24;
	send_data[2] = (qei_temp & 0x00FF0000) >> 16;
	send_data[3] = (qei_temp & 0x0000FF00) >> 8;
	send_data[4] = qei_temp & 0x000000FF;
	send_data[5] = 0x00 ^ send_data[1] ^ send_data[2] ^ send_data[3] ^ send_data[4];
	command_flag = 1;
}
void Command_Qei_Start_Test(void)
{
	unsigned long qei_temp;
	qei_temp = door2_position.start;
	send_data[0] = 0x05;
	send_data[1] = qei_temp >> 24;
	send_data[2] = (qei_temp & 0x00FF0000) >> 16;
	send_data[3] = (qei_temp & 0x0000FF00) >> 8;
	send_data[4] = qei_temp & 0x000000FF;
	send_data[5] = 0x00 ^ send_data[1] ^ send_data[2] ^ send_data[3] ^ send_data[4];
	command_flag = 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Command_Current_Test(void)
{
	send_data[0] = 0x03;    //tx number is 3
	send_data[1] = Current2_Now() >> 8;
	send_data[2] = Current2_Now() & 0x00FF;
	send_data[3] = 0x00 ^ send_data[1] ^ send_data[2];
	command_flag = 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void Command_Speed_Test(void)
{
	unsigned long speed_temp;
	speed_temp = motor2_speed.now;
	send_data[0] = 0x05;
	send_data[1] = speed_temp >> 24;
	send_data[2] = (speed_temp & 0x00FF0000) >> 16;
	send_data[3] = (speed_temp & 0x0000FF00) >> 8;
	send_data[4] = speed_temp & 0x000000FF;
	send_data[5] = 0x00 ^ send_data[1] ^ send_data[2] ^ send_data[3] ^ send_data[4];
	command_flag = 1;
}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Command_Pwm_Test(void)
{
	unsigned long pwm_temp;
	pwm_temp = motor2_pwm.rate_output;
	send_data[0] = 0x05;
	send_data[1] = pwm_temp >> 24;
	send_data[2] = (pwm_temp & 0x00FF0000) >> 16;
	send_data[3] = (pwm_temp & 0x0000FF00) >> 8;
	send_data[4] = pwm_temp & 0x000000FF;
	send_data[5] = 0x00 ^ send_data[1] ^ send_data[2] ^ send_data[3] ^ send_data[4];
	command_flag = 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Command_All_Test(void)
{
	unsigned long all_temp;
	send_data[0] = 15;
	//~~~~~~~~current~~~~~~~~~~~
	all_temp = Current2_Now();
	send_data[1] = all_temp >> 8;
	send_data[2] = all_temp & 0x00FF;
	//~~~~~~~~~~~~~~~~~~~~~~~~
	all_temp = motor2_speed.goal + 1000000;
	send_data[3] = all_temp >> 24;
	send_data[4] = (all_temp & 0x00FF0000) >> 16;
	send_data[5] = (all_temp & 0x0000FF00) >> 8;
	send_data[6] = all_temp & 0x000000FF;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	all_temp = motor2_speed.now + 1000000 ;
	send_data[7] = all_temp >> 24;
	send_data[8] = (all_temp & 0x00FF0000) >> 16;
	send_data[9] = (all_temp & 0x0000FF00) >> 8;
	send_data[10] = all_temp & 0x000000FF;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	all_temp = motor2_pwm.rate_calc + 8000;
	send_data[11] = all_temp >> 24;
	send_data[12] = (all_temp & 0x00FF0000) >> 16;
	send_data[13] = (all_temp & 0x0000FF00) >> 8;
	send_data[14] = all_temp & 0x000000FF;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	send_data[15] = 0x00 ^ send_data[1] ^ send_data[2] ^ send_data[3] ^ send_data[4] ^ send_data[5] ^ send_data[6] ^ send_data[7] ^ send_data[8] ^ send_data[9] ^ send_data[10] ^ send_data[11] ^ send_data[12] ^ send_data[13] ^ send_data[14];
	command_flag = 1;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
void Command_All_Test1(int value)
{
	unsigned long all_temp;
	all_temp = value;
	send_data[0] = 15;
	//~~~~~~~~current~~~~~~~~~~~
	send_data[1] = all_temp >> 8;
	send_data[2] = all_temp & 0x00FF;
	//~~~~~~~~~~~~~~~~~~~~~~~~
	all_temp = motor2_speed.now / 1000 + 1000 ;
	send_data[3] = all_temp >> 24;
	send_data[4] = (all_temp & 0x00FF0000) >> 16;
	send_data[5] = (all_temp & 0x0000FF00) >> 8;
	send_data[6] = all_temp & 0x000000FF;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	all_temp = motor2_pwm.fuzzy_regulate_value;
	send_data[7] = all_temp >> 24;
	send_data[8] = (all_temp & 0x00FF0000) >> 16;
	send_data[9] = (all_temp & 0x0000FF00) >> 8;
	send_data[10] = all_temp & 0x000000FF;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	all_temp = motor2_pwm.rate_calc + 800;
	send_data[11] = all_temp >> 24;
	send_data[12] = (all_temp & 0x00FF0000) >> 16;
	send_data[13] = (all_temp & 0x0000FF00) >> 8;
	send_data[14] = all_temp & 0x000000FF;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	send_data[15] = 0x00 ^ send_data[1] ^ send_data[2] ^ send_data[3] ^ send_data[4] ^ send_data[5] ^ send_data[6] ^ send_data[7] ^ send_data[8] ^ send_data[9] ^ send_data[10] ^ send_data[11] ^ send_data[12] ^ send_data[13] ^ send_data[14];
	command_flag = 1;
}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~






