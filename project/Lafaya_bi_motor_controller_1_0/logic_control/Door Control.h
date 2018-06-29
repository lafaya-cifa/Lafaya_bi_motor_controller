#ifndef DOOR_CONTROL_H_
#define DOOR_CONTROL_H_

//#include <../h/p33EP512MU814.h>
#include "../data/Eeprom Address.h"
#include "../mcu_module/Header.h"
#include "../util_tool/Led.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	POSITION_OPEN					100000
#define	POSITION_CLOSE_MIN			105000
#define	POSITION_CLOS_MAX				3000000
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	SPEED_OPEN_MAX				350000
#define	SPEED_CLOSE_MAX				300000
#define	SPEED_CRAWL					30000
#define	SPEED_LOW_LIMIT				4000
#define	SPEED_FALL_RATIO				70
#define	SPEED_LOCK_STATUS				0
//~~~~~~~~~~~~~~~~
#define	SPEED_MIN						10000
#define	SPEED_MAX						1000000
#define	SPEED_LOW_MIN					1000
#define	SPEED_LOW_MAX				30000
#define	SPEED_FALL_RATIO_MIN			30
#define	SPEED_FALL_RATIO_MAX			90
#define	SPEED_FALL_RATIO_MIN			30
#define	SPEED_FALL_RATIO_MAX			90
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	LENGHT_CRAWL_OPEN			2000
#define	LENGHT_CRAWL_CLOSE			2000
#define	LENGHT_END_OPEN				1000
#define	LENGHT_END_CLOSE				1000
#define	LENGHT_HOLD_CLOSE_MAX		1500
#define	LENGHT_HOLD_CLOSE_MIN		1400
#define	LENGHT_AMBLE_OPEN			0
//~~~~~~~~~~~~~~~~~
#define	LENGHT_CRAWL_MIN				500
#define	LENGHT_CRAWL_MAX				8000
#define	LENGHT_END_MIN				100
#define	LENGHT_END_MAX				5000
#define	LENGHT_HOLD_MIN				500
#define	LENGHT_HOLD_MAX				10000
#define	LENGHT_AMBLE_OPEN_MAX		30000
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	CURRENT_LIMIT_NO1				4000
#define	CURRENT_LIMIT_NO2				5000
#define	CURRENT_LIMIT_NO3				6000
#define	CURRENT_LIMIT_NO4				7000
#define	CURRENT_KEEP_OPEN			100
#define	CURRENT_KEEP_CLOSE			100
#define	CURRENT_LIMIT_HARDWARE		10000
//~~~~~~~~~~~~~~~~~
#define	CURRENT_LIMIT_MIN				100
#define	CURRENT_LIMIT_MAX				14000
#define	CURRENT_LIMIT_HARDWARE_MIN	8000
#define	CURRENT_KEEP_MAX				1000
#define	CURRENT_INTEGRATION_MAX		0x7FFFFFFF
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	TIME_OPEN_KEEP				3
#define	TIME_OPEN_MODE_KEEP			0	
#define	TIME_ACCELERATE_MIN			2000
#define	TIME_SPEED_LOW_LIMIT			100		//no address,time=450us*100=45ms
#define	TIME_SPEED_LOW_MAX			3000	//time=450us*3000=1.35s
#define	TIME_SPEED_OVER_
#define	TIME_OPEN_FAULT_HOLD			3		//no address
//~~~~~~~~~~~~~~~~~~
#define	TIME_OPEN_KEEP_MAX			10
#define	TIME_OPEN_MODE_KEEP_MAX		30
#define	TIME_ACCELERATE_MIN_MIN		600
#define	TIME_ACCELERATE_MIN_MAX		4000	//300us * 4000 = 1200ms
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	PWM_RATE_MIN					10
#define	PWM_RATE_MAX					385
#define	PWM_FACTOR_DRIVE				1
#define	PWM_FACTOR_UNDRIVE			6
#define	PWM_FACTOR_REVIVE_BRAKE		5
#define	PWM_FACTOR_REVERSE_BRAKE	1
#define	PWM_REVERSE_PERMIT			0
#define	PWM_UNIFORM_NO_REDUCE		100
#define	PWM_CRAWL_END_NO_REDUCE	110
#define	PWM_BRAKE_ALLOW_REDUCE		100
#define	PWM_PID_REGULATE_CYCLE		10
//~~~~~~~~~~~~~~~~~~
#define	PWM_RATE_MIN_LIMIT			5
#define	PWM_RATE_MAX_LIMIT			390
#define	PWM_FACTOR_MIN				1
#define	PWM_FACTOR_MAX				100
#define	PWM_REDUCE_MIN				90
#define	PWM_REDUCE_MAX				250
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	TEMPERATURE_LIMIT_HIGH		80
#define	TEMPERATURE_LIMIT_LOW		60
//#define	TEMPERATURE_HISTORY_MAX		50
//~~~~~~~~~~~~~~~~~~~~~~~
#define	TEMPERATURE_MAX				100
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	DOOR_POWER_LOW_STATUS		0
#define	DOOR_RUNNING_TEST_MODE		1
#define	DOOR_ACCELERATE_STEP			6			
#define	DOOR_BATTERY_ENABLE			0
#define	DOOR_OPEN_WIDTH				100
//~~~~~~~~~~~~~~~~~~~
#define	DOOR_RUN_MODE_EXIT			0x01
#define	DOOR_RUN_MODE_CLOSE			0x02
#define	DOOR_RUN_MODE_OPEN			0x04
#define	DOOR_RUN_MODE_AUTO			0x08
#define	DOOR_CAN_MODE_LINKAGE		0x00
#define	DOOR_CAN_MODE_SLAVE			0x01
#define	DOOR_CAN_MODE_MASTER		0x02
#define	DOOR_CAN_MODE_ALONE			0x03
#define	DOOR_ACCELERATE_STEP_MIN	1
#define	DOOR_ACCELERATE_STEP_MAX	10
#define	DOOR_RUN_COUNT_MAX			0x7FFFFFFF

#define	DOOR_OPEN_WIDTH_MIN		30
#define	DOOR_OPEN_WIDTH_MAX		100
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagDOOR_POSITION
{
	long start;
	long end;
	long open_end;
}DOOR_POSITION_STYLE;
extern DOOR_POSITION_STYLE door1_position;
extern DOOR_POSITION_STYLE door2_position;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagDOOR_SPEED
{
	long open_max;
	long close_max;
	long crawl;
	unsigned int low_limit;
	unsigned char fall_ratio;
	unsigned char lock_status;
}DOOR_SPEED_STYLE;
extern DOOR_SPEED_STYLE door1_speed;
extern DOOR_SPEED_STYLE door2_speed;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagDOOR_LENGHT
{
	unsigned int crawl_open;
	unsigned int crawl_close;
	unsigned int end_open;
	unsigned int end_close;
	unsigned int hold_close_max;
	unsigned int hold_close_min;
	unsigned int amble_open;
}DOOR_LENGHT_STYLE;
extern DOOR_LENGHT_STYLE door1_lenght;
extern DOOR_LENGHT_STYLE door2_lenght;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagDOOR_CURRENT
{
	unsigned int limit_no1;
	unsigned int limit_no2;
	unsigned int limit_no3;
	unsigned int limit_no4;
	unsigned int keep_open;
	unsigned int keep_close;
	unsigned int limit_hardware;
	unsigned int history_max;
	unsigned long integration_max;
}DOOR_CURRENT_STYLE;
extern DOOR_CURRENT_STYLE door1_current;
extern DOOR_CURRENT_STYLE door2_current;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagDOOR_TIME
{
	unsigned int open_keep;
	unsigned int open_mode_keep;
	unsigned int open_mode_keep_count;
	unsigned int accelerate_min;
	unsigned int speed_low_limit;
	unsigned int open_fault_hold;
	unsigned int stop_count;
	unsigned int test_mode_count;
	unsigned int open_keep_count;
}DOOR_TIME_STYLE;
extern DOOR_TIME_STYLE door1_time;
extern DOOR_TIME_STYLE door2_time;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagDOOR_PWM
{
	int rate_min;
	int rate_max;
	int factor_drive;
	int factor_undrive;
	int factor_revive_brake;
	int factor_reverse_brake;
	unsigned char reverse_permit;
	unsigned char uniform_no_reduce;
	unsigned char crawl_end_no_reduce;
	unsigned int brake_allow_reduce;
	unsigned char pid_regulate_cycle;
}DOOR_PWM_STYLE;
extern DOOR_PWM_STYLE door1_pwm;
extern DOOR_PWM_STYLE door2_pwm;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagDOOR_TEMPERATURE
{
	unsigned char limit_high;
	unsigned char limit_low;
	unsigned char history_max;
}DOOR_TEMPERATURE_STYLE;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagDOOR
{
	unsigned char power_low_stauts;
	unsigned char run_mode;
	unsigned char can_mode;
	unsigned char run_test_mode;
	unsigned char accelerate_step;
	unsigned long run_count;
	unsigned long run_history_count;
	unsigned char battery_enable;
	unsigned char open_fault_count;
	unsigned char close_fault_count;
	unsigned char open_width;
	unsigned char run_enable;
}DOOR_STYLE;
extern DOOR_STYLE door1_parameter;
extern DOOR_STYLE door2_parameter;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef	enum
{
	LEARN_OK = 0,
	LEARN_AUTO,
	LEARN_SEARCH
}DOOR_LEARN_STATUS_ENUM;
extern DOOR_LEARN_STATUS_ENUM door1_learn_status;
extern DOOR_LEARN_STATUS_ENUM door2_learn_status;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef enum
{
	DOOR_KEEP_CLOSE = 0,
	DOOR_OPEN,
	DOOR_KEEP_OPEN,
	DOOR_CLOSE
}DOOR_RUN_WAY_ENUM;
extern DOOR_RUN_WAY_ENUM door1_run_way;
extern DOOR_RUN_WAY_ENUM door2_run_way;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Initialize_Door_Control_Varialbe(void);    //initialize door control ,called in main
void Initialize_Door_Learn(unsigned char door_which,DOOR_POSITION_STYLE *sdoor_position,DOOR_LEARN_STATUS_ENUM *door_learn_status,DOOR_RUN_WAY_ENUM *door_run_way);
void Initialize_Door_Speed(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_SPEED_STYLE *sdoor_speed,EEP_SPEED_STYLE *seep_speed);
void Initialize_Door_Lenght(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_LENGHT_STYLE *sdoor_lenght,EEP_LENGHT_STYLE *seep_lenght);
void Initialize_Door_Current(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_CURRENT_STYLE *sdoor_current,EEP_CURRENT_STYLE *seep_current);
void Initialize_Door_Time(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_TIME_STYLE *sdoor_time,EEP_TIME_STYLE *seep_time);
void Initialize_Door_Pwm(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_PWM_STYLE *sdoor_pwm,EEP_PWM_STYLE *seep_pwm);
void Initialize_Door_Temperature(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_TEMPERATURE_STYLE *sdoor_temperature,EEP_TEMPERATURE_STYLE *seep_temperature);
void Initialize_Door_Pamameter(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_STYLE *sdoor_parameter,EEP_PARAMETER_STYLE *seep_parameter);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Save_Door_Countrol_Varialbe(void);	//save door control,called in main
void Save_Door_Speed(unsigned char door_which,EEP_SPEED_STYLE *seep_speed,DOOR_SPEED_STYLE *sdoor_speed);
void Save_Door_Lenght(unsigned char door_which,EEP_LENGHT_STYLE *seep_lenght,DOOR_LENGHT_STYLE *sdoor_lenght);
void Save_Door_Current(unsigned char door_which,EEP_CURRENT_STYLE *seep_current,DOOR_CURRENT_STYLE *sdoor_current);
void Save_Door_Time(unsigned char door_which,EEP_TIME_STYLE *seep_time,DOOR_TIME_STYLE *sdoor_time);
void Save_Door_Pwm(unsigned char door_which,EEP_PWM_STYLE *seep_pwm,DOOR_PWM_STYLE *sdoor_pwm);
void Save_Door_Temperature(unsigned char door_which,EEP_TEMPERATURE_STYLE *seep_temperature,DOOR_TEMPERATURE_STYLE *sdoor_temperature);
void Save_Door_Parameter(unsigned char door_which,EEP_PARAMETER_STYLE *seep_parameter,DOOR_STYLE *sdoor_parameter);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Door_Timer(void);	//called in timer
void Door2_Test_Mode(void);
extern void Door_Control(void);	//called in main while
//void Door2_Control(void);
//void Door2_Learn_Auto(void);
//void Door2_Learn_Search(void);
//void Door2_Logical(void);










#endif

