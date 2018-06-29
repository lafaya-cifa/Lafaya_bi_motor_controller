#include "Current.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static unsigned int current1_value;
static unsigned int current2_value;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Current_Varialbe(void)	//called in main
{
	current1_value = 0;
	current2_value = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Current_Handle(void)	//called in adc
{
	static unsigned char current_sample_count = 0;
	
	static unsigned int current1_sample[8] = {0,0,0,0,0,0,0,0};
	static unsigned int current2_sample[8] = {0,0,0,0,0,0,0,0};
	
	static unsigned int current1_move[5] = {0,0,0,0,0};
	static unsigned int current2_move[5] = {0,0,0,0,0};
	
	unsigned int adc_current1 = 0;
	unsigned int adc_current2 = 0;

	unsigned int current1_average = 0;
	unsigned int current2_average = 0;

	if(current_sample_count == 0)
	{
		current1_sample[0] = read_adc[0];
		current1_sample[1] = read_adc[4];
		current1_sample[2] = read_adc[8];
		current1_sample[3] = read_adc[12];

		current2_sample[0] = read_adc[3];
		current2_sample[1] = read_adc[7];
		current2_sample[2] = read_adc[11];
		current2_sample[3] = read_adc[15];

	
		current_sample_count++;
	}
	else
	{
		current1_sample[4] = read_adc[0];
		current1_sample[5] = read_adc[4];
		current1_sample[6] = read_adc[8];
		current1_sample[7] = read_adc[12];

		current2_sample[4] = read_adc[3];
		current2_sample[5] = read_adc[7];
		current2_sample[6] = read_adc[11];
		current2_sample[7] = read_adc[15];
		
		current_sample_count = 0;

		adc_current1 = (current1_sample[0] + current1_sample[1] + current1_sample[2] + current1_sample[3] + current1_sample[4] + current1_sample[5] + current1_sample[6] + current1_sample[7]) / 8;
		adc_current2 = (current2_sample[0] + current2_sample[1] + current2_sample[2] + current2_sample[3] + current2_sample[4] + current2_sample[5] + current2_sample[6] + current2_sample[7]) / 8;

		current1_move[4] = current1_move[3];
		current1_move[3] = current1_move[2];
		current1_move[2] = current1_move[1];
		current1_move[1] = current1_move[0];
		current1_move[0] = adc_current1;

		current2_move[4] = current2_move[3];
		current2_move[3] = current2_move[2];
		current2_move[2] = current2_move[1];
		current2_move[1] = current2_move[0];
		current2_move[0] = adc_current2;

		current1_average = (current1_move[4] + current1_move[3] + current1_move[2] + current1_move[1] + current1_move[0]) / 5;
		current2_average = (current2_move[4] + current2_move[3] + current2_move[2] + current2_move[1] + current2_move[0]) / 5;

		current1_value = Current_Calculate(current1_average);
		current2_value = Current_Calculate(current2_average);
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int Current_Calculate(unsigned int read_data)
{
	/*
	reference point sampling value = (0.5 / 3.3) * 1024 = 155.15
	sensitivity = 185mV/A
	185mV / 1A = (3.3V - 0.5V) / XA ==> X = ((3.3 - 0.5) * 1000)mV / (185mV/A) = 15.135A
	sampling precision = 15.135A / (1024 - 155.15)  = 0.01742A = 17.42mA
	actual sample value = (sample value - 155.15) * sampling presision = (sample value - 155.15) * 17.42mA
	or
	actial sample value = (sample value - 155.15) * 15.135 * 1000 / (1024 - 155.15) = (sample value - 155.15) * 17.42mA
	****************************************************************************************************
	actual test sample value is 151 when no motor in circuit 
	actial sample value = (sample value - 151) * 15.135 * 1000 / (1024 - 151) =  (sample value - 151) * 17.34mA
	*/
	if(read_data > CURRENT_SAMPLE_LEVEL)
	{
		return (read_data - CURRENT_SAMPLE_LEVEL) * CURRENT_SAMPLE_RATE;
	}
	else
	{
		return 0;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int Current1_Now(void)
{
	return current1_value;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int Current2_Now(void)
{
	return current2_value;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




