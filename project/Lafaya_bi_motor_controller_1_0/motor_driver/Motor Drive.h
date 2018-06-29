#ifndef	MOTOR_DRIVE_H_
#define	MOTOR_DRIVE_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#include <../h/p33EP512MU814.h>
#include "../mcu_module/Header.h"
#include "../mcu_module/Qei.h"
#include "../util_tool/Speed.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	LABS(x)		(x > 0) ? x : (-x)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define		MOTOR1_ENABLE		_RB5       //motor1 enable io control
#define		MOTOR2_ENABLE		_RB9	//motor2 enable io control
#define		DIP1				
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef enum tagMOTOR
{
	STOP = 0,
	FORWARD,
	REVERSE,
}MOTOR_STATUS_ENUM;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagPWM
{
	int rate_output;
	int rate_calc;
	int rate_min;
	int rate_max;
}MOTOR_PWM_STYLE;
extern MOTOR_PWM_STYLE motor1_pwm;
extern MOTOR_PWM_STYLE motor2_pwm;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagPID
{
	int kp;
	int ki;
	int kd;
	unsigned char regulate_count;
	unsigned char regulate_interval;
}MOTOR_PID_STYLE;
extern MOTOR_PID_STYLE motor1_pid;
extern MOTOR_PID_STYLE motor2_pid;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagSPEED
{
	long goal;
	long now;

}MOTOR_SPEED_STYLE;
extern MOTOR_SPEED_STYLE motor1_speed;
extern MOTOR_SPEED_STYLE motor2_speed;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagPOSITION
{
	unsigned long now;
	

}MOTOR_POSITION_STYLE;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagCONTROL
{
	unsigned char drive_allow;
	unsigned char dip_direction;
	MOTOR_STATUS_ENUM status;
	unsigned char phasic_no;
	
}MOTOR_CONTROL_STYLE;
extern MOTOR_CONTROL_STYLE motor1_control;
extern MOTOR_CONTROL_STYLE motor2_control;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Emulation_MOTOR1_Phasic(unsigned char phasic_number);
void Emulation_MOTOR2_Phasic(unsigned char phasic_number);

extern void Initialize_Motor_Drive_Variable(void);

int Speed_Pid(MOTOR_PID_STYLE smotor,long speed_now,long speed_goal);

extern void Motor_Control(void);

void Motor2_Drive(void);
void Motor_Drive_Pwm_Calculate(void);

void Motor2_Start(void);
extern void Motor2_Stopping(void);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
