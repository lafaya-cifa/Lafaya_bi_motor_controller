#include "temperature.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static volatile unsigned int temperature1_value;		//temperature value
static volatile unsigned int temperature2_value;		//temperature value
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Temperature_Varialbe(void)
{
	temperature1_value = 0;
	temperature2_value = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Temperature_Handle(void)
{//Tsample = 67.2us
	static char temperature_sample_count = 0;

	static unsigned int temperature1_sample[8] = {0,0,0,0,0,0,0,0};
	static unsigned int temperature2_sample[8] = {0,0,0,0,0,0,0,0};

	unsigned int adc_temperature1 = 0;
	unsigned int adc_temperature2 = 0;

	if(temperature_sample_count == 0)
	{
		temperature1_sample[0] = read_adc[1];
		temperature1_sample[1] = read_adc[5];
		temperature1_sample[2] = read_adc[9];
		temperature1_sample[3] = read_adc[13];

		temperature2_sample[0] = read_adc[2];
		temperature2_sample[1] = read_adc[6];
		temperature2_sample[2] = read_adc[10];
		temperature2_sample[3] = read_adc[14];

		temperature_sample_count++;
	}
	else	
	{
		temperature1_sample[4] = read_adc[1];
		temperature1_sample[5] = read_adc[5];
		temperature1_sample[6] = read_adc[9];
		temperature1_sample[7] = read_adc[13];

		temperature2_sample[4] = read_adc[2];
		temperature2_sample[5] = read_adc[6];
		temperature2_sample[6] = read_adc[10];
		temperature2_sample[7] = read_adc[14];
		
		temperature_sample_count = 0;

		adc_temperature1 = (temperature1_sample[0] + temperature1_sample[1] + temperature1_sample[2] + temperature1_sample[3] + temperature1_sample[4] + temperature1_sample[5] + temperature1_sample[6] + temperature1_sample[7]) / 8;
		adc_temperature2 = (temperature2_sample[0] + temperature2_sample[1] + temperature2_sample[2] + temperature2_sample[3] + temperature2_sample[4] + temperature2_sample[5] + temperature2_sample[6] + temperature2_sample[7]) / 8;
		temperature1_value = Temperature_Calculate(adc_temperature1);
		temperature2_value = Temperature_Calculate(adc_temperature2);
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char Temperature_Calculate(unsigned int temperature_value)
{/*actual value		calculate value
	80				82
	70				71
	60				60
	50				49
	40				41
	30				34*/
	char temperature_temp = 0;
	temperature_temp = 161 - temperature_value * 7 / 50;
	return temperature_temp;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int Temperature1_Now(void)
{
	return temperature1_value;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int Temperature2_Now(void)
{
	return temperature2_value;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	











