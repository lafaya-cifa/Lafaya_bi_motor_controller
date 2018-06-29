#include "Eeprom Address.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
EEP_POSITION_STYLE eep1_position;
EEP_POSITION_STYLE eep2_position;
EEP_SPEED_STYLE eep1_speed;
EEP_SPEED_STYLE eep2_speed;
EEP_LENGHT_STYLE eep1_lenght;
EEP_LENGHT_STYLE eep2_lenght;
EEP_CURRENT_STYLE eep1_current;
EEP_CURRENT_STYLE eep2_current;
EEP_TIME_STYLE eep1_time;
EEP_TIME_STYLE eep2_time;
EEP_PWM_STYLE eep1_pwm;
EEP_PWM_STYLE eep2_pwm;
EEP_TEMPERATURE_STYLE eep1_temperature;
EEP_TEMPERATURE_STYLE eep2_temperature;
EEP_PARAMETER_STYLE eep1_parameter;
EEP_PARAMETER_STYLE eep2_parameter;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
long Read_Eeprom_32bit(unsigned int e32_address)
{
	long data_32,data_32H,data_32L;

	data_32H = DataEERead(e32_address);	//read data for high 16 bit
	data_32L = DataEERead(e32_address + 1);
	data_32 = (data_32H << 16) | data_32L;
	return data_32;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Write_Eeprom_32bit(unsigned int e32_address, long e32_data)
{
	int data_16;

	data_16 = (e32_data >> 16) & 0x0000FFFF;
	DataEEWrite(data_16,e32_address);
	data_16 = e32_data & 0x0000FFFF;
	DataEEWrite(data_16,(e32_address + 1));
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

















