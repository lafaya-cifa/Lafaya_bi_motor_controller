#include "Rtc.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
REAL_TIME_STYLE real_timeflags;
//REAL_TIME_STYLE real_set_timeflags;    //day and time set variable
unsigned char real_time_inquiry;    //real time inquiry flag
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Rtc_Variable(void)    //Rtc mode variable Initialization
{
	real_time_inquiry = 0;    //real time inquiry flag clear
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void I2c_Start(void)	//I2c start
{
	IO_SDA = 1;
	I2c_Delay_Time(50);

	IO_SCL = 1;
	I2c_Delay_Time(50);

	IO_SDA = 0;
	I2c_Delay_Time(50);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void I2c_Stop(void)		//I2c stop
{
	IO_SDA = 0;
	I2c_Delay_Time(50);

	IO_SCL = 1;
	I2c_Delay_Time(50);

	IO_SCL = 1;
	I2c_Delay_Time(50);

	IO_SDA = 1;
	I2c_Delay_Time(50);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void I2c_Write(unsigned char data)    //I2c write
{
	unsigned char i,temp;

	TRISDbits.TRISD9 = 0;		//data io is output
	I2c_Delay_Time(50);

	IO_SCL = 0;
	for (i = 0; i < 8; i++)		//I2c write 1 byte
	{
		temp = data & 0x80;

		if(temp == 0)
		{
			IO_SDA = 0;
		}
		else
		{
			IO_SDA=1;
		}
		data = data << 1;		//increase SCL high time
		I2c_Delay_Time(50);
		IO_SCL = 1;
		I2c_Delay_Time(50);
		IO_SCL = 0;
		I2c_Delay_Time(50);
	}
	IO_SDA = 1;
	I2c_Delay_Time(50);
	TRISDbits.TRISD9 = 1;		//data io is input
	I2c_Delay_Time(50);
	IO_SCL = 0;
	I2c_Delay_Time(50);
	IO_SCL = 1;				//write 1byte over ,SCL is rising edge
	I2c_Delay_Time(50);
	IO_SCL = 0;
	I2c_Delay_Time(50);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char I2c_Read(unsigned char answer_information)    //I2c read
{
	unsigned char i;
	unsigned char read_data = 0;
	TRISDbits.TRISD9 = 1;		//data io is input
	I2c_Delay_Time(50);

	IO_SDA = 1;            		 //Let go of SDA line
	I2c_Delay_Time(50);
	IO_SCL = 0;
	for (i = 0; i < 8; i++)		//read the msb first
	{
		IO_SCL = 1;			//read data whin rising edge,1 byte
		read_data = read_data << 1;
		if(IO_SDA == 1)
		{
			read_data = read_data | 0x01;
		}
		IO_SCL = 0;
		I2c_Delay_Time(50);
	}

	TRISDbits.TRISD9 = 0;		//data io is output
	I2c_Delay_Time(50);

	IO_SDA = answer_information;          //Hold sda low for acknowledge,this step is to judge whether or not respond
	I2c_Delay_Time(50);
	IO_SCL = 0;
	I2c_Delay_Time(50);
	IO_SCL = 1;						//rising edge to respond
	if(answer_information == NACK)
	{
		IO_SDA = 1;					//SDA = 1 if next cycle is reset 
	}
	I2c_Delay_Time(50);
	IO_SCL = 0;
	I2c_Delay_Time(50);
	IO_SDA = 1;          			//Release the SDA line

	return read_data;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void I2c_Delay_Time(unsigned char num)    //I2c delay
{
	unsigned char i;
	for(i = 0; i < num; i++)
	{
		asm("nop");
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Read_Write_Time(void)	//time to read and write
{
	if(real_time_inquiry == 0)    //read time
	{
		I2c_Start();
		I2c_Write(0xD0);		//write slave address + write
		I2c_Write(0x00);		//write register address, 1st clock register
		I2c_Start();
		I2c_Write(0xD1);		//write slave address + read
		real_timeflags.real_second = Bcd_To_Decimal(I2c_Read(ACK));		//second
		real_timeflags.real_minute = Bcd_To_Decimal(I2c_Read(ACK));		//minute
		real_timeflags.real_hour = Bcd_To_Decimal(I2c_Read(ACK));		//hour
		real_timeflags.real_week = Bcd_To_Decimal(I2c_Read(ACK));		//week
		real_timeflags.real_day = Bcd_To_Decimal(I2c_Read(ACK));			//day
		real_timeflags.real_month = Bcd_To_Decimal(I2c_Read(ACK));		//month
		real_timeflags.real_year = Bcd_To_Decimal(I2c_Read(NACK));	//year,the last time not to answer
		I2c_Stop();
	}
	else if(real_time_inquiry == 1)
	{
		I2c_Start();				//The following Enables the Oscillator
		I2c_Write(0xD0);			//address the part to write
		I2c_Write(0x00);			//position the address pointer to 0
		I2c_Write(0x00);			//write 0 to the seconds register, clear the CH bit(bit7),sart clock
		I2c_Stop();

		I2c_Start();
		I2c_Write(0xD0);			//write slave address + write
		I2c_Write(0x00);			//write register address, 1st clock register
		I2c_Write(Decimal_To_Bcd(real_timeflags.real_second));
		I2c_Write(Decimal_To_Bcd(real_timeflags.real_minute));		
		I2c_Write(Decimal_To_Bcd(real_timeflags.real_hour));
		I2c_Write(Decimal_To_Bcd(real_timeflags.real_week));
		I2c_Write(Decimal_To_Bcd(real_timeflags.real_day));
		I2c_Write(Decimal_To_Bcd(real_timeflags.real_month));
		I2c_Write(Decimal_To_Bcd(real_timeflags.real_year));

		I2c_Write(0x10);		//enable sqwe, 1Hz output

		I2c_Start();			//address pointer wraps at 7, so point to flag register
		I2c_Write(0xD0);		//write slave address + write 
		I2c_Write(0x09);		//write register address, control register
		I2c_Write(0);		//clear OSF

		I2c_Stop();
		real_time_inquiry = 2;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char Bcd_To_Decimal(unsigned char bcd_number)    //BCD code to decimal number
{
	unsigned char temp;
	temp = ((bcd_number >> 4) * 10) + (bcd_number & 0x0F);
	return temp;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char Decimal_To_Bcd(unsigned char decimal_number)    //decimal number to BCD code
{
	unsigned char temp;
	temp = ((decimal_number / 10) << 4) + (decimal_number % 10);
	return temp;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Real_Time_Inquiry_Set(unsigned char read_write_num)    //read state and write state set
{
	real_time_inquiry = read_write_num;		//=0:read;=1:wrtie
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char Real_Time_Inquiry_Fig(void)    //read write fiag return
{
	return real_time_inquiry;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

