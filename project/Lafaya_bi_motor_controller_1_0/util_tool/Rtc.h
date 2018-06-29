#ifndef RTC_H_
#define RTC_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <../h/p33EP512MU814.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define		IO_SDA		_RD9
#define		IO_SCL		_RD10
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define		ACK			0x00		//answer signal
#define		NACK		0x01		//not answer signal
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct
{
	unsigned char real_year;
	unsigned char real_month;
	unsigned char real_day;
	unsigned char real_week;
	unsigned char real_hour;
	unsigned char real_minute;
	unsigned char real_second;
}REAL_TIME_STYLE;

extern REAL_TIME_STYLE real_timeflags;
//extern REAL_TIME_STYLE real_set_timeflags;    //day and time set variable
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Initialize_Rtc_Variable(void);    //Rtc mode variable Initialization
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void I2c_Start(void);			//I2c start
void I2c_Stop(void);			//I2c stop
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void I2c_Write(unsigned char data);    //I2c write
unsigned char I2c_Read(unsigned char answer_information);    //I2c read
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void I2c_Delay_Time(unsigned char num);		//I2c delay
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Read_Write_Time(void);			//time to read and write
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char Bcd_To_Decimal(unsigned char bcd_number);    //BCD code to decimal number
unsigned char Decimal_To_Bcd(unsigned char decimal_number);    //decimal number to BCD code
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Real_Time_Inquiry_Set(unsigned char read_write_num);    //read state and write state set
extern unsigned char Real_Time_Inquiry_Fig(void);    //read write fiag return
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif

