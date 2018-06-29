#include "Motor Drive.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const int fuzzy_table[169] ={6, 5, 6, 5, 6, 6, 6, 3, 3, 2, 1, 0, 0,
                                 5, 6, 5, 6, 5, 5, 5, 3, 2, 2, 1, 0, 0,
                                 6, 5, 6, 5, 6, 6, 6, 3, 2, 1, 0,-1,-1,
                                 6, 5, 5, 6, 5, 5, 5, 3, 1, 0,-1,-1,-1,
                                 5, 4, 3, 4, 3, 3, 2, 1, 0,-2,-1,-2,-2,
 				     4, 3, 3, 4, 3, 3, 1, 0, 0,-2,-2,-2,-2,
                                 3, 3, 3, 4, 2, 1, 0,-1,-2,-4,-3,-3,-4,
                                 2, 2, 2, 2, 0, 0,-1,-3,-3,-4,-3,-3,-4,
                                 2, 2, 1, 2, 0,-1,-2,-3,-3,-4,-3,-4,-5,
                                 1, 2, 1, 0,-1,-3,-5,-5,-5,-6,-5,-5,-6,
  				     1, 1, 0,-1,-2,-3,-6,-6,-6,-5,-6,-5,-6,
                                 0, 0,-1,-2,-3,-3,-5,-5,-5,-6,-6,-5,-5,
                                 0, 0,-1,-2,-3,-4,-6,-6,-6,-6,-5,-6,-6};

const int difference_goal[12] = {-5500,-4500,-3500,-2500,-1500,-500,500,1500,2500,3500,4500,5500};

const unsigned int accelerate_time_curve[180] = {1,3,7,12,19,28, 38, 49 ,62 ,77 ,93 ,110 ,129 ,149 ,171 ,195 ,219 ,246 ,273 ,303 ,333 ,
                                           365 ,399 ,433 ,470 ,507 ,546 ,587 ,628 ,671 ,743 ,815 ,887 ,959 ,1031 ,1103 ,1175 ,1247 ,
                                           1319 ,1391 ,1463 ,1535 ,1607 ,1679 ,1751 ,1823 ,1895 ,1967 ,2039 ,2111 ,2183 ,2255 ,2327 ,
 						 2399 ,2471 ,2543 ,2615 ,2687 ,2759 ,2831 ,2903 ,2975 ,3047 ,3119 ,3191 ,3263 ,3335 ,3407 ,
                                           3479 ,3551 ,3623 ,3695 ,3767 ,3839 ,3911 ,3983 ,4055 ,4127 ,4199 ,4271 ,4343 ,4415 ,4487 ,
                                           4559 ,4631 ,4703 ,4775 ,4847 ,4919 ,4991 ,5063 ,5135 ,5207 ,5279 ,5351 ,5423 ,5495 ,5567 ,
 						 5639 ,5711 ,5783 ,5855 ,5927 ,5999 ,6071 ,6143 ,6215 ,6287 ,6359 ,6431 ,6503 ,6575 ,6647 ,
                                           6719 ,6791 ,6863 ,6935 ,7007 ,7079 ,7151 ,7223 ,7295 ,7367 ,7439 ,7511 ,7583 ,7655 ,7727 ,
                                           7799 ,7871 ,7943 ,8015 ,8087 ,8159 ,8231 ,8303 ,8375 ,8447 ,8519 ,8591 ,8663 ,8735 ,8807 ,
						 8879 ,8951 ,9023 ,9095 ,9167 ,9239 ,9311 ,9372 ,9413 ,9454 ,9493 ,9530 ,9567 ,9601 ,9635 ,
                                           9667 ,9697 ,9727 ,9754 ,9781 ,9805 ,9829 ,9851 ,9871 ,9890 ,9907 ,9923 ,9938 ,9951 ,9962 ,
                                           9972 ,9981 ,9988 ,9993 ,9997 ,9999 ,10000 };
																
const unsigned int speed_brake_curve[180] = {538 ,538 ,599 ,705 ,839 ,991 ,1152,1320,1493,1668,1845,2024,2189,2341,2485,2621,2750,
										2873,2991,3104,3214,3320,3423,3522,3619,3714,3806,3896,3984,4070,4154,4236,4317,4397,
										4475,4551,4627,4701,4774,4846,4917,4987,5056,5124,5191,5257,5323,5388,5451,5515,5577,
										5639,5700,5760,5820,5879,5938,5996,6053,6110,6167,6222,6278,6333,6387,6441,6495,6548,
										6600,6653,6705,6756,6807,6858,6908,6958,7008,7057,7106,7154,7202,7250,7298,7345,7392,
										7439,7485,7531,7577,7623,7668,7713,7758,7802,7847,7891,7934,7978,8021,8064,8107,8150,
										8192,8234,8276,8318,8359,8401,8442,8483,8523,8564,8604,8644,8684,8724,8764,8803,8842,
										8881,8920,8958,8996,9032,9068,9103,9137,9170,9203,9235,9266,9297,9326,9355,9384,9411,
										9438,9465,9490,9515,9539,9563,9586,9608,9630,9651,9671,9691,9710,9728,9746,9763,9779,
										9795,9811,9825,9839,9853,9866,9878,9890,9901,9911,9921,9931,9939,9947,9955,9962,9968,
										9974,9979,9984,9988,9991,9994,9997,9998,9999,10000}; 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MOTOR_PWM_STYLE motor1_pwm;
MOTOR_PWM_STYLE motor2_pwm;
MOTOR_PID_STYLE motor1_pid;
MOTOR_PID_STYLE motor2_pid;
MOTOR_SPEED_STYLE motor1_speed;
MOTOR_SPEED_STYLE motor2_speed;
MOTOR_POSITION_STYLE motor1_position;
MOTOR_POSITION_STYLE motor2_position;
MOTOR_CONTROL_STYLE motor1_control;
MOTOR_CONTROL_STYLE motor2_control;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
void Emulation_MOTOR1_Phasic(unsigned char phasic_number)
{
	switch(phasic_number)
	{
		case 0 :	// 6L opened by manual,4H is controled by PWM,others are closed
				PDC4 = motor1_pwm.rate_output;
				SDC4 = 0;

				PDC5 = 0;
				SDC5 = 0;

				PDC6 = 0;
				SDC6 = 4000;
				break;
		case 1 :	// 6L opened by manual,5H is controled by PWM,others are closed
				PDC4 = 0;
				SDC4 = 0;

				PDC5 = motor1_pwm.rate_output;
				SDC5 = 0;

				PDC6 = 0;
				SDC6 = 4000;

				break;
		case 2 :	// 4L opened by manual,5H is controled by PWM,others are closed
				PDC4 = 0;
				SDC4 = 4000;

				PDC5 = motor1_pwm.rate_output;
				SDC5 = 0;

				PDC6 = 0;
				SDC6 = 0;
				break;
		case  3 :	// 4L opened by manual,6H is controled by PWM,others are closed
				PDC4 = 0;
				SDC4 = 4000;

				PDC5 = 0;
				SDC5 = 0;

				PDC6 = motor1_pwm.rate_output;
				SDC6 = 0;
				break;
		case 4 :	// 5L opened by manual,6H is controled by PWM,others are closed
				PDC4 = 0;
				SDC4 = 0;

				PDC5 = 0;
				SDC5 = 4000;

				PDC6 = motor1_pwm.rate_output;
				SDC6 = 0;
				break;
		case 5 :	// 5L opened by manual,4H is controled by PWM,others are closed
				PDC4 = motor1_pwm.rate_output;
				SDC4 = 0;

				PDC5 = 0;
				SDC5 = 4000;

				PDC6 = 0;
				SDC6 = 0;
				break;
		case 6 :	// 4L,5L,6L are controled by PWM,4H,5H,6H are closed
				PDC4 = 0;
				SDC4 = motor1_pwm.rate_output;

				PDC5 = 0;
				SDC5 = motor1_pwm.rate_output;

				PDC6 = 0;
				SDC6 = motor1_pwm.rate_output;
				break;
		case 7 :	// 4L,5L are controled by PWM,others are closed
				PDC4 = 0;
				SDC4 = motor1_pwm.rate_output;

				PDC5 = 0;
				SDC5 = motor1_pwm.rate_output;

				PDC6 = 0;
				SDC6 = 0;
				break;
		case 8 :	// 4L,5L,6L opened by manual,4H,5H,6H are closed
				PDC4 = 0;
				SDC4 = 4000;

				PDC5 = 0;
				SDC5 = 4000;

				PDC6 = 0;
				SDC6 = 4000;
				break;
		default : // all PWM are closed
				PDC4 = 0;
				SDC4 = 0;

				PDC5 = 0;
				SDC5 = 0;

				PDC6 = 0;
				SDC6 = 0;
			break;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Emulation_MOTOR2_Phasic(unsigned char phasic_number)
{
	switch(phasic_number)
	{
		case 0 :	// 3L opened by manual,1H is controled by PWM,others are closed
				PDC1 = motor2_pwm.rate_output;
				SDC1 = 0;

				PDC2 = 0;
				SDC2 = 0;

				PDC3 = 0;
				SDC3 = 4000;
				break;
		case 1 :	// 3L opened by manual,2H is controled by PWM,others are closed
				PDC1 = 0;
				SDC1 = 0;

				PDC2 = motor2_pwm.rate_output;
				SDC2 = 0;

				PDC3 = 0;
				SDC3 = 4000;

				break;
		case 2 :	// 1L opened by manual,2H is controled by PWM,others are closed
				PDC1 = 0;
				SDC1 = 4000;

				PDC2 = motor2_pwm.rate_output;
				SDC2 = 0;

				PDC3 = 0;
				SDC3 = 0;
				break;
		case  3 :	// 1L opened by manual,3H is controled by PWM,others are closed
				PDC1 = 0;
				SDC1 = 4000;

				PDC2 = 0;
				SDC2 = 0;

				PDC3 = motor2_pwm.rate_output;
				SDC3 = 0;
				break;
		case 4 :	// 2L opened by manual,3H is controled by PWM,others are closed
				PDC1 = 0;
				SDC1 = 0;

				PDC2 = 0;
				SDC2 = 4000;

				PDC3 = motor2_pwm.rate_output;
				SDC3 = 0;
				break;
		case 5 :	// 2L opened by manual,1H is controled by PWM,others are closed
				PDC1 = motor2_pwm.rate_output;
				SDC1 = 0;

				PDC2 = 0;
				SDC2 = 4000;

				PDC3 = 0;
				SDC3 = 0;
				break;
		case 6 :	// 1L,2L,3L are controled by PWM,1H,2H,3H are closed
				PDC1 = 0;
				SDC1 = motor2_pwm.rate_output;

				PDC2 = 0;
				SDC2 = motor2_pwm.rate_output;

				PDC3 = 0;
				SDC3 = motor2_pwm.rate_output;
				break;
		case 7 :	// 1L,2L are controled by PWM,others are closed
				PDC1 = 0;
				SDC1 = motor2_pwm.rate_output;

				PDC2 = 0;
				SDC2 = motor2_pwm.rate_output;

				PDC3 = 0;
				SDC3 = 0;
				break;
		case 8 :	// 1L,2L,3L opened by manual,1H,2H,3H are closed
				PDC1 = 0;
				SDC1 = 4000;

				PDC2 = 0;
				SDC2 = 4000;

				PDC3 = 0;
				SDC3 = 4000;
				break;
		default : // all PWM are closed
				PDC1 = 0;
				SDC1 = 0;

				PDC2 = 0;
				SDC2 = 0;

				PDC3 = 0;
				SDC3 = 0;
			break;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Motor_Drive_Variable(void)	
{
	motor1_pwm.rate_calc = 0;
	motor1_pwm.rate_output = 0;
	motor1_pwm.rate_min = 60;
	motor1_pwm.rate_max = 3850;

	motor2_pwm.rate_calc = 0;
	motor2_pwm.rate_output = 0;
	motor2_pwm.rate_min = 60;
	motor2_pwm.rate_max = 3850;

	motor1_pid.kp = 0;
	motor1_pid.ki = 0;
	motor1_pid.kd = 0;
	motor1_pid.regulate_count = 0;
	motor1_pid.regulate_interval = 20;

//	motor2_pid.kp = 328;
//	motor2_pid.ki = 392;
//	motor2_pid.kd = 739;
	motor2_pid.kp = 3;
	motor2_pid.ki = 4;
	motor2_pid.kd = 7;
	motor2_pid.regulate_count = 0;
	motor2_pid.regulate_interval = 20;

	motor1_speed.goal = 0;
	motor1_speed.now = 0;

	motor2_speed.goal = 0;
	motor2_speed.now = 0;

	motor1_position.now = 0;

	motor2_position.now = 0;
	
	motor1_control.drive_allow = 0;
	motor1_control.dip_direction = IO_DIP1;
	motor1_control.status = STOP;
	motor1_control.phasic_no = 0;

	motor2_control.drive_allow = 0;
	motor2_control.dip_direction = IO_DIP1;
	motor2_control.status = STOP;
	motor2_control.phasic_no = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int Speed_Pid(MOTOR_PID_STYLE smotor,long speed_now,long speed_goal)
{
	long speed_change,speed_set,this_error,midule_error,last_error;

	static long this_speed = 0;
	static long midule_speed = 0;
	static long last_speed = 0;

	last_speed = midule_speed;
	midule_speed = this_speed;
	this_speed = (speed_now / 1000);
	
	speed_set = speed_goal / 1000;
	this_error = speed_set - this_speed;
	midule_error = speed_set - midule_speed;
	last_error = speed_set - last_speed;

//	speed_change = smotor.kp * (this_error - midule_error) + smotor.ki * midule_error + smotor.kd * (this_error + last_error - 2 * midule_error);
	speed_change = smotor.kp * this_error + smotor.ki * (this_error - midule_error) + smotor.kd * ((this_error - midule_error) - (midule_error - last_error));
	return speed_change;
//	smotor.kp = 3.278;
//	smotor.ki = 3.92;
//	smotor.kd = 7.39;
	
//	pwm = pwm + speed_change;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Motor_Drive_Phasic(MOTOR_CONTROL_STYLE *smotor_control,int pwm_rate_calc)
{
	MOTOR_STATUS_ENUM drive_direction_temp;	//驱动方向临时变量
	if(motor2_control.dip_direction == 1)
	{
		switch(smotor_control->status)
		{
			case FORWARD :
				drive_direction_temp = REVERSE;
				break;
			case REVERSE :
				drive_direction_temp = FORWARD;
				break;
			default : drive_direction_temp = STOP;
				break;
		}
	}
	else
	{
		drive_direction_temp = smotor_control->status;
	}

	if(pwm_rate_calc <= 0 && pwm_rate_calc >= -4000)
	{
		smotor_control->phasic_no = 7;
	}
	else
	{
		if(drive_direction_temp == FORWARD && pwm_rate_calc > 0)
		{
			smotor_control->phasic_no = 2;
		}
		else
		{
			if(drive_direction_temp == REVERSE && pwm_rate_calc > 0)
			{
				smotor_control->phasic_no = 5;
			}
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void Motor_Drive_Stage_Calculate(void)
{
	
}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Motor_Control(void)
{
	Motor2_Drive();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Motor2_Drive(void)
{
	motor2_position.now = Qei2_Position();
	motor2_speed.now = Speed2_Calculate(1,motor2_position.now);

	if(motor2_control.drive_allow == 0)
	{
		if(motor2_control.status == FORWARD || motor2_control.status == REVERSE)
		{
			Motor2_Start();
		}
	}
	else
	{
		motor2_pid.regulate_count++;
		if(motor2_pid.regulate_count >= motor2_pid.regulate_interval)
		{
			Motor_Drive_Pwm_Calculate();
			Motor_Drive_Phasic(&motor2_control,motor2_pwm.rate_calc);
			motor2_pid.regulate_count = 0;
		}
	}
	Emulation_MOTOR2_Phasic(motor2_control.phasic_no);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Motor_Drive_Pwm_Calculate(void)
{
	motor2_pwm.rate_calc = + Speed_Pid(motor2_pid,motor2_speed.now,motor2_speed.goal);
	motor2_pwm.rate_output = LABS(motor2_pwm.rate_calc);
	if(motor2_pwm.rate_output > motor2_pwm.rate_max)
	{
		motor2_pwm.rate_output = motor2_pwm.rate_max;
	}
	else if(motor2_pwm.rate_output < motor2_pwm.rate_min)
	{
		motor2_pwm.rate_output = motor2_pwm.rate_min;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Motor2_Start(void)
{
	motor2_speed.goal = 300000;	//300mm/s
	motor2_position.now = 0;
	Qei2_Position_input(0);
	motor2_pid.regulate_count = 0;
	motor2_control.drive_allow = 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Motor2_Stopping(void)
{
	
	motor2_pwm.rate_calc = 0;
	motor2_pwm.rate_output = 0;
	motor2_control.drive_allow = 0;
	motor2_control.status = STOP;
	motor2_control.phasic_no = 8;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

