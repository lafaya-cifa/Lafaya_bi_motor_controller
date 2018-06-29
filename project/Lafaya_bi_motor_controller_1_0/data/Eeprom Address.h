#ifndef EEPROM_ADDRESS_H_
#define EEPROM_ADDRESS_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "DEE Emulation 16-bit.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS1_POSITION_START					0x00C8
#define	ADDRESS1_POSITION_END					0x00CA
//#define	ADDRESS1_POSITION_OPEN_END			0x00CC
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS1_SPEED_OPEN_MAX					0x00CE
#define	ADDRESS1_SPEED_CLOSE_MAX				0x00D0
#define	ADDRESS1_SPEED_CRAWL					0x00D2
#define	ADDRESS1_SPEED_FALL_RATIO				0x00D4
#define	ADDRESS1_SPEED_LOW_LIMIT				0x00D6
#define	ADDRESS1_SPEED_LOCK_STATUS				0x00D8
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS1_LENGHT_CRAWL_OPEN				0x00DA
#define	ADDRESS1_LENGHT_CRAWL_CLOSE			0x00DC
#define	ADDRESS1_LENGHT_END_OPEN				0x00DE
#define	ADDRESS1_LENGHT_END_CLOSE				0x00E0
#define	ADDRESS1_LENGHT_HOLD_CLOSE_MAX			0x00E2
#define	ADDRESS1_LENGHT_HOLD_CLOSE_MIN			0x00E4
#define	ADDRESS1_LENGHT_AMBLE_OPEN				0x00E6
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS1_CURRENT_LIMIT_NO1				0x00E8
#define	ADDRESS1_CURRENT_LIMIT_NO2				0x00EA
#define	ADDRESS1_CURRENT_LIMIT_NO3				0x00EC
#define	ADDRESS1_CURRENT_LIMIT_NO4				0x00EE
#define	ADDRESS1_CURRENT_KEEP_OPEN				0x00F0
#define	ADDRESS1_CURRENT_KEEP_CLOSE				0x00F2
#define	ADDRESS1_CURRENT_LIMIT_HARDWARE		0x00F4
#define	ADDRESS1_CURRENT_HISTORY_MAX			0x00F6
#define	ADDRESS1_CURRENT_INTEGRATION_MAX		0x00F8
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#define	ADDRESS1_TIME_OPEN_FAULT_HOLD			0x00FA
#define	ADDRESS1_TIME_OPEN_KEEP					0x00FC
#define	ADDRESS1_TIME_OPEN_MODE_KEEP			0x00FE
#define	ADDRESS1_TIME_ACCELERATE_MIN			0x0100
//#define	ADDRESS1_TIME_SPEED_LOW					0x0102
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS1_PWM_RATE_MIN					0x0104
#define	ADDRESS1_PWM_RATE_MAX					0x0106
#define	ADDRESS1_PWM_FACTOR_DRIVE				0x0108
#define	ADDRESS1_PWM_FACTOR_UNDRIVE			0x010A
#define	ADDRESS1_PWM_FACTOR_REVIVE_BRAKE		0x010C
#define	ADDRESS1_PWM_FACTOR_REVERSE_BRAKE		0x010E
#define	ADDRESS1_PWM_REVERSE_PERMIT			0x0110
#define	ADDRESS1_PWM_UNIFORM_NO_REDUCE		0x0112
#define	ADDRESS1_PWM_CRAWL_END_NO_REDUCE		0x0114
#define	ADDRESS1_PWM_BRAKE_ALLOW_REDUCE		0x0116
#define	ADDRESS1_PWM_PID_REGULATE_CYCLE		0x0118
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS1_TEMPERATURE_LIMIT_HIGH		0x011A
#define	ADDRESS1_TEMPERATURE_LIMIT_LOW			0x011C
#define	ADDRESS1_TEMPERATURE_HISTORY_MAX		0x011E
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS1_DOOR_POWER_LOW_STATUS		0x0120
#define	ADDRESS1_DOOR_RUN_MODE					0x0122
#define	ADDRESS1_DOOR_CAN_MODE					0x0124
#define	ADDRESS1_DOOR_RUN_TEST_MODE			0x0126
#define	ADDRESS1_DOOR_ACCELERATE_STEP			0x0128
#define	ADDRESS1_DOOR_RUN_COUNT					0x012A
#define	ADDRESS1_DOOR_RUN_HISTORY_COUNT		0x0000
#define	ADDRESS1_DOOR_BATTERY_ENABLE			0x012C
#define	ADDRESS1_DOOR_OPEN_WIDTH				0x012E
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//***********************************************************//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS2_POSITION_START					0x0258
#define	ADDRESS2_POSITION_END					0x025A
//#define	ADDRESS2_POSITION_OPEN_END			0x025C
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS2_SPEED_OPEN_MAX					0x025E
#define	ADDRESS2_SPEED_CLOSE_MAX				0x0260
#define	ADDRESS2_SPEED_CRAWL					0x0262
#define	ADDRESS2_SPEED_FALL_RATIO				0x0264
#define	ADDRESS2_SPEED_LOW_LIMIT				0x0266
#define	ADDRESS2_SPEED_LOCK_STATUS				0x0268
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS2_LENGHT_CRAWL_OPEN				0x026A
#define	ADDRESS2_LENGHT_CRAWL_CLOSE			0x026C
#define	ADDRESS2_LENGHT_END_OPEN				0x026E
#define	ADDRESS2_LENGHT_END_CLOSE				0x0270
#define	ADDRESS2_LENGHT_HOLD_CLOSE_MAX			0x0272
#define	ADDRESS2_LENGHT_HOLD_CLOSE_MIN			0x0274
#define	ADDRESS2_LENGHT_AMBLE_OPEN				0x0276
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS2_CURRENT_LIMIT_NO1				0x0278
#define	ADDRESS2_CURRENT_LIMIT_NO2				0x027A
#define	ADDRESS2_CURRENT_LIMIT_NO3				0x027C
#define	ADDRESS2_CURRENT_LIMIT_NO4				0x027E
#define	ADDRESS2_CURRENT_KEEP_OPEN				0x0280
#define	ADDRESS2_CURRENT_KEEP_CLOSE				0x0282
#define	ADDRESS2_CURRENT_LIMIT_HARDWARE		0x0284
#define	ADDRESS2_CURRENT_HISTORY_MAX			0x0286
#define	ADDRESS2_CURRENT_INTEGRATION_MAX		0x0288
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#define	ADDRESS2_TIME_OPEN_FAULT_HOLD			0x028A
#define	ADDRESS2_TIME_OPEN_KEEP					0x028C
#define	ADDRESS2_TIME_OPEN_MODE_KEEP			0x028E
#define	ADDRESS2_TIME_ACCELERATE_MIN			0x0290
//#define	ADDRESS2_TIME_SPEED_LOW					0x0292
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS2_PWM_RATE_MIN					0x0294
#define	ADDRESS2_PWM_RATE_MAX					0x0296
#define	ADDRESS2_PWM_FACTOR_DRIVE				0x0298
#define	ADDRESS2_PWM_FACTOR_UNDRIVE			0x029A
#define	ADDRESS2_PWM_FACTOR_REVIVE_BRAKE		0x029C
#define	ADDRESS2_PWM_FACTOR_REVERSE_BRAKE		0x029E
#define	ADDRESS2_PWM_REVERSE_PERMIT			0x02A0
#define	ADDRESS2_PWM_UNIFORM_NO_REDUCE		0x02A2
#define	ADDRESS2_PWM_CRAWL_END_NO_REDUCE		0x02A4
#define	ADDRESS2_PWM_BRAKE_ALLOW_REDUCE		0x02A6
#define	ADDRESS2_PWM_PID_REGULATE_CYCLE			0x02A8
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS2_TEMPERATURE_LIMIT_HIGH		0x02AA
#define	ADDRESS2_TEMPERATURE_LIMIT_LOW			0x02AC
#define	ADDRESS2_TEMPERATURE_HISTORY_MAX		0x02AE
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	ADDRESS2_DOOR_POWER_LOW_STATUS		0x02B0
#define	ADDRESS2_DOOR_RUN_MODE					0x02B2
#define	ADDRESS2_DOOR_CAN_MODE					0x02B4
#define	ADDRESS2_DOOR_RUN_TEST_MODE			0x02B6
#define	ADDRESS2_DOOR_ACCELERATE_STEP			0x02B8
#define	ADDRESS2_DOOR_RUN_COUNT					0x02BA
#define	ADDRESS2_DOOR_RUN_HISTORY_COUNT		0x0064
#define	ADDRESS2_DOOR_BATTERY_ENABLE			0x02BC
#define	ADDRESS2_DOOR_OPEN_WIDTH				0x02BE
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagEEP_POSITION
{
	unsigned		start :				1;
	unsigned		end : 				1;
	unsigned		open_end : 			1;
}EEP_POSITION_STYLE;
extern EEP_POSITION_STYLE eep1_position;
extern EEP_POSITION_STYLE eep2_position;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagEEP_SPEED
{
	unsigned		open_max :			1;
	unsigned		close_max :			1;
	unsigned		crawl :				1;
	unsigned		low_limit :			1;
	unsigned		fall_ratio :			1;
	unsigned		lock_status :		1;
}EEP_SPEED_STYLE;
extern EEP_SPEED_STYLE eep1_speed;
extern EEP_SPEED_STYLE eep2_speed;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagEEP_LENGHT
{
	unsigned		crawl_open :		1;
	unsigned		crawl_close :		1;
	unsigned		end_open :			1;
	unsigned		end_close :			1;
	unsigned		hold_close_max :	1;
	unsigned		hold_close_min :		1;
	unsigned		amble_open :		1;
}EEP_LENGHT_STYLE;
extern EEP_LENGHT_STYLE eep1_lenght;
extern EEP_LENGHT_STYLE eep2_lenght;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagEEP_CURRENT
{
	unsigned		limit_no1 :			1;
	unsigned		limit_no2 :			1;
	unsigned		limit_no3 :			1;
	unsigned		limit_no4 :			1;
	unsigned		keep_open :			1;
	unsigned		keep_close :			1;
	unsigned		limit_hardware :		1;
	unsigned		history_max :		1;
	unsigned		integration_max :	1;
}EEP_CURRENT_STYLE;
extern EEP_CURRENT_STYLE eep1_current;
extern EEP_CURRENT_STYLE eep2_current;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagEEP_TIME
{
	unsigned		open_keep :			1;
	unsigned		open_mode_keep :	1;
	unsigned		accelerate_min :		1;
	unsigned		speed_low_limit :	1;
	unsigned		open_fault_hold :	1;
}EEP_TIME_STYLE;
extern EEP_TIME_STYLE eep1_time;
extern EEP_TIME_STYLE eep2_time;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagEEP_PWM
{
	unsigned		rate_min :			1;
	unsigned		rate_max :			1;
	unsigned		factor_drive :		1;
	unsigned		factor_undrive :		1;
	unsigned		factor_revive_brake :1;
	unsigned		factor_reverse_brake :1;
	unsigned		reverse_permit :		1;
	unsigned		uniform_no_reduce :	1;
	unsigned		crawl_end_no_reduce :1;
	unsigned		brake_allow_reduce :1;
	unsigned		pid_regulate_cycle :	1;
}EEP_PWM_STYLE;
extern EEP_PWM_STYLE eep1_pwm;
extern EEP_PWM_STYLE eep2_pwm;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagEEP_TEMPERATURE
{
	unsigned		limit_high :			1;
	unsigned		limit_low :			1;
	unsigned		history_max :		1;
}EEP_TEMPERATURE_STYLE;
extern EEP_TEMPERATURE_STYLE eep1_temperature;
extern EEP_TEMPERATURE_STYLE eep2_temperature;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagEEP_PARAMETER
{
	unsigned		run_mode :			1;
	unsigned		can_mode :			1;
	unsigned		run_test_mode :		1;
	unsigned		accelerate_step :	1;
	unsigned		run_count :			1;
	unsigned		run_history_count :	1;
	unsigned		battery_enable :		1;
	unsigned		open_width :		1;
}EEP_PARAMETER_STYLE;
extern EEP_PARAMETER_STYLE eep1_parameter;
extern EEP_PARAMETER_STYLE eep2_parameter;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern long Read_Eeprom_32bit(unsigned int e32_address);
extern void Write_Eeprom_32bit(unsigned int e32_address, long e32_data);




#endif

