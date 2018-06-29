#include "Door Control.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
DOOR_POSITION_STYLE door1_position;
DOOR_POSITION_STYLE door2_position;

DOOR_SPEED_STYLE door1_speed;
DOOR_SPEED_STYLE door2_speed;

DOOR_LENGHT_STYLE door1_lenght;
DOOR_LENGHT_STYLE door2_lenght;

DOOR_CURRENT_STYLE door1_current;
DOOR_CURRENT_STYLE door2_current;

DOOR_TIME_STYLE door1_time;
DOOR_TIME_STYLE door2_time;

DOOR_PWM_STYLE door1_pwm;
DOOR_PWM_STYLE door2_pwm;

DOOR_TEMPERATURE_STYLE door1_temperature;
DOOR_TEMPERATURE_STYLE door2_temperature;

DOOR_STYLE door1_parameter;
DOOR_STYLE door2_parameter;

DOOR_LEARN_STATUS_ENUM door1_learn_status;
DOOR_LEARN_STATUS_ENUM door2_learn_status;

DOOR_RUN_WAY_ENUM door1_run_way;
DOOR_RUN_WAY_ENUM door2_run_way;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Door_Control_Varialbe(void)    //initialize uart bariable
{
	Initialize_Door_Learn(2,&door2_position,&door2_learn_status,&door2_run_way);
	Initialize_Door_Speed(2,door2_learn_status,&door2_speed,&eep2_speed);
	Initialize_Door_Lenght(2,door2_learn_status,&door2_lenght,&eep2_lenght);
	Initialize_Door_Current(2,door2_learn_status,&door2_current,&eep2_current);
	Initialize_Door_Time(2,door2_learn_status,&door2_time,&eep2_time);
	Initialize_Door_Pwm(2,door2_learn_status,&door2_pwm,&eep2_pwm);
	Initialize_Door_Temperature(2,door2_learn_status,&door2_temperature,&eep2_temperature);
	Initialize_Door_Pamameter(2,door2_learn_status,&door2_parameter,&eep2_parameter);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Door_Learn(unsigned char door_which,DOOR_POSITION_STYLE *sdoor_position,DOOR_LEARN_STATUS_ENUM *door_learn_status,DOOR_RUN_WAY_ENUM *door_run_way)
{
	if(door_which == 1)
	{
		sdoor_position->start = Read_Eeprom_32bit(ADDRESS1_POSITION_START);
		sdoor_position->end = Read_Eeprom_32bit(ADDRESS1_POSITION_END);
	}
	else
	{
		sdoor_position->start = Read_Eeprom_32bit(ADDRESS2_POSITION_START);
		sdoor_position->end = Read_Eeprom_32bit(ADDRESS2_POSITION_END);
	}

	if((sdoor_position->start != POSITION_OPEN) || (sdoor_position->end < POSITION_CLOSE_MIN) || (sdoor_position->end > POSITION_CLOS_MAX))
	{
		*door_learn_status = LEARN_AUTO;
	//	*door_run_way = DOOR_OPEN;
//		Led_Double_Input(1,1,0,0);
	}
	else
	{
		*door_learn_status = LEARN_SEARCH;
	//	*door_run_way = DOOR_CLOSE;
	//	Led_Double_Input(1,2,0,1);
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Door_Speed(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_SPEED_STYLE *sdoor_speed,EEP_SPEED_STYLE *seep_speed)
{
	if(door_learn_status == LEARN_AUTO)
	{
		sdoor_speed->open_max = SPEED_OPEN_MAX;
		sdoor_speed->close_max = SPEED_CLOSE_MAX;
		sdoor_speed->crawl = SPEED_CRAWL;
		sdoor_speed->low_limit = SPEED_LOW_LIMIT;
		sdoor_speed->fall_ratio = SPEED_FALL_RATIO;
		sdoor_speed->lock_status = SPEED_LOCK_STATUS;

		seep_speed->open_max = TRUE;
		seep_speed->close_max = TRUE;
		seep_speed->crawl = TRUE;
		seep_speed->low_limit = TRUE;
		seep_speed->fall_ratio = TRUE;
		seep_speed->lock_status = TRUE;
	}
	else
	{
		if(door_which == 1)
		{
			sdoor_speed->open_max = Read_Eeprom_32bit(ADDRESS1_SPEED_OPEN_MAX);
			sdoor_speed->close_max = Read_Eeprom_32bit(ADDRESS1_SPEED_CLOSE_MAX);
			sdoor_speed->crawl = Read_Eeprom_32bit(ADDRESS1_SPEED_CRAWL);
			sdoor_speed->low_limit = Read_Eeprom_32bit(ADDRESS1_SPEED_LOW_LIMIT);
			sdoor_speed->fall_ratio = Read_Eeprom_32bit(ADDRESS1_SPEED_FALL_RATIO);
			sdoor_speed->lock_status = Read_Eeprom_32bit(ADDRESS1_SPEED_LOCK_STATUS);
		}
		else
		{
			sdoor_speed->open_max = Read_Eeprom_32bit(ADDRESS2_SPEED_OPEN_MAX);
			sdoor_speed->close_max = Read_Eeprom_32bit(ADDRESS2_SPEED_CLOSE_MAX);
			sdoor_speed->crawl = Read_Eeprom_32bit(ADDRESS2_SPEED_CRAWL);
			sdoor_speed->low_limit = Read_Eeprom_32bit(ADDRESS2_SPEED_LOW_LIMIT);
			sdoor_speed->fall_ratio = Read_Eeprom_32bit(ADDRESS2_SPEED_FALL_RATIO);
			sdoor_speed->lock_status = Read_Eeprom_32bit(ADDRESS2_SPEED_LOCK_STATUS);
		}

		if((sdoor_speed->open_max < SPEED_MIN) || (sdoor_speed->open_max > SPEED_MAX))
		{
			sdoor_speed->open_max = SPEED_OPEN_MAX;
		}
			
		if((sdoor_speed->close_max < SPEED_MIN) || (sdoor_speed->close_max > SPEED_MAX))
		{
			sdoor_speed->close_max = SPEED_CLOSE_MAX;
		}

		if((sdoor_speed->crawl < SPEED_MIN) || (sdoor_speed->crawl > SPEED_MAX))
		{
			sdoor_speed->crawl = SPEED_CRAWL;
		}
			
		if((sdoor_speed->low_limit < SPEED_LOW_MIN) || (sdoor_speed->low_limit > SPEED_LOW_MAX))
		{
			sdoor_speed->low_limit = SPEED_LOW_LIMIT;
		}

		if((sdoor_speed->fall_ratio < SPEED_FALL_RATIO_MIN) || (sdoor_speed->fall_ratio > SPEED_FALL_RATIO_MAX))
		{
			sdoor_speed->fall_ratio = SPEED_FALL_RATIO;
		}

		if((sdoor_speed->lock_status != TRUE ) && (sdoor_speed->lock_status != FALSE))
		{
			sdoor_speed->lock_status = FALSE;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Door_Lenght(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_LENGHT_STYLE *sdoor_lenght,EEP_LENGHT_STYLE *seep_lenght)
{
	if(door_learn_status == LEARN_AUTO)
	{
		sdoor_lenght->crawl_open = LENGHT_CRAWL_OPEN;
		sdoor_lenght->crawl_close = LENGHT_CRAWL_CLOSE;
		sdoor_lenght->end_open = LENGHT_END_OPEN;
		sdoor_lenght->end_close = LENGHT_END_CLOSE;
		sdoor_lenght->hold_close_max = LENGHT_HOLD_CLOSE_MAX;
		sdoor_lenght->hold_close_min = LENGHT_HOLD_CLOSE_MIN;
		sdoor_lenght->amble_open = LENGHT_AMBLE_OPEN;

		seep_lenght->crawl_open = TRUE;
		seep_lenght->crawl_close = TRUE;
		seep_lenght->end_open = TRUE;
		seep_lenght->end_close = TRUE;
		seep_lenght->hold_close_max = TRUE;
		seep_lenght->hold_close_min = TRUE;
		seep_lenght->amble_open = TRUE;
	}
	else
	{
		if(door_which == 1)
		{
			sdoor_lenght->crawl_open = Read_Eeprom_32bit(ADDRESS1_LENGHT_CRAWL_OPEN);
			sdoor_lenght->crawl_close = Read_Eeprom_32bit(ADDRESS1_LENGHT_CRAWL_CLOSE);
			sdoor_lenght->end_open = Read_Eeprom_32bit(ADDRESS1_LENGHT_END_OPEN);
			sdoor_lenght->end_close = Read_Eeprom_32bit(ADDRESS1_LENGHT_END_CLOSE);
			sdoor_lenght->hold_close_max = Read_Eeprom_32bit(ADDRESS1_LENGHT_HOLD_CLOSE_MAX);
			sdoor_lenght->hold_close_min = Read_Eeprom_32bit(ADDRESS1_LENGHT_HOLD_CLOSE_MIN);
			sdoor_lenght->amble_open = Read_Eeprom_32bit(ADDRESS1_LENGHT_AMBLE_OPEN);
		}
		else
		{
			sdoor_lenght->crawl_open = Read_Eeprom_32bit(ADDRESS2_LENGHT_CRAWL_OPEN);
			sdoor_lenght->crawl_close = Read_Eeprom_32bit(ADDRESS2_LENGHT_CRAWL_CLOSE);
			sdoor_lenght->end_open = Read_Eeprom_32bit(ADDRESS2_LENGHT_END_OPEN);
			sdoor_lenght->end_close = Read_Eeprom_32bit(ADDRESS2_LENGHT_END_CLOSE);
			sdoor_lenght->hold_close_max = Read_Eeprom_32bit(ADDRESS2_LENGHT_HOLD_CLOSE_MAX);
			sdoor_lenght->hold_close_min = Read_Eeprom_32bit(ADDRESS2_LENGHT_HOLD_CLOSE_MIN);
			sdoor_lenght->amble_open = Read_Eeprom_32bit(ADDRESS2_LENGHT_AMBLE_OPEN);
		}
			
		if((sdoor_lenght->crawl_open < LENGHT_CRAWL_MIN) || (sdoor_lenght->crawl_open > LENGHT_CRAWL_MAX))
		{
			sdoor_lenght->crawl_open = LENGHT_CRAWL_OPEN;
		}
			
		if((sdoor_lenght->crawl_close < LENGHT_CRAWL_MIN) || (sdoor_lenght->crawl_close > LENGHT_CRAWL_MAX))
		{
			sdoor_lenght->crawl_close = LENGHT_CRAWL_CLOSE;
		}
			
		if((sdoor_lenght->end_open < LENGHT_END_MIN) || (sdoor_lenght->end_open > LENGHT_END_MAX))
		{
			sdoor_lenght->end_open = LENGHT_END_OPEN;
		}
			
		if((sdoor_lenght->end_close < LENGHT_END_MIN) || (sdoor_lenght->end_close > LENGHT_END_MAX))
		{
			sdoor_lenght->end_close = LENGHT_END_CLOSE;
		}
			
		if((sdoor_lenght->hold_close_max < LENGHT_HOLD_MIN) || (sdoor_lenght->hold_close_max > LENGHT_HOLD_MAX))
		{
			sdoor_lenght->hold_close_max = LENGHT_HOLD_CLOSE_MAX;
		}
			
		if((sdoor_lenght->hold_close_min < LENGHT_HOLD_MIN) || (sdoor_lenght->hold_close_min > LENGHT_HOLD_MAX))
		{
			sdoor_lenght->hold_close_min = LENGHT_HOLD_CLOSE_MIN;
		}
			
		if(sdoor_lenght->amble_open > LENGHT_AMBLE_OPEN_MAX)
		{
			sdoor_lenght->amble_open = LENGHT_AMBLE_OPEN;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Door_Current(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_CURRENT_STYLE *sdoor_current,EEP_CURRENT_STYLE *seep_current)
{
	if(door_learn_status == LEARN_AUTO)
	{
		sdoor_current->limit_no1 = CURRENT_LIMIT_NO1;
		sdoor_current->limit_no2 = CURRENT_LIMIT_NO2;
		sdoor_current->limit_no3 = CURRENT_LIMIT_NO3;
		sdoor_current->limit_no4 = CURRENT_LIMIT_NO4;
		sdoor_current->keep_open = CURRENT_KEEP_OPEN;
		sdoor_current->keep_close = CURRENT_KEEP_CLOSE;
		sdoor_current->limit_hardware = CURRENT_LIMIT_HARDWARE;
		sdoor_current->history_max = 0;
		sdoor_current->integration_max = 0;

		seep_current->limit_no1 = TRUE;
		seep_current->limit_no2 = TRUE;
		seep_current->limit_no3 = TRUE;
		seep_current->limit_no4 = TRUE;
		seep_current->keep_open = TRUE;
		seep_current->keep_close = TRUE;
		seep_current->limit_hardware = TRUE;
		seep_current->history_max = TRUE;
		seep_current->integration_max = TRUE;
	}
	else
	{
		if(door_which == 1)
		{
			sdoor_current->limit_hardware = Read_Eeprom_32bit(ADDRESS1_CURRENT_LIMIT_HARDWARE);
			sdoor_current->limit_no4 = Read_Eeprom_32bit(ADDRESS1_CURRENT_LIMIT_NO4);
			sdoor_current->limit_no3 = Read_Eeprom_32bit(ADDRESS1_CURRENT_LIMIT_NO3);
			sdoor_current->limit_no2 = Read_Eeprom_32bit(ADDRESS1_CURRENT_LIMIT_NO2);
			sdoor_current->limit_no1 = Read_Eeprom_32bit(ADDRESS1_CURRENT_LIMIT_NO1);
			sdoor_current->keep_open = Read_Eeprom_32bit(ADDRESS1_CURRENT_KEEP_OPEN);
			sdoor_current->keep_close = Read_Eeprom_32bit(ADDRESS1_CURRENT_KEEP_CLOSE);
			sdoor_current->history_max = Read_Eeprom_32bit(ADDRESS1_CURRENT_HISTORY_MAX);
			sdoor_current->integration_max = Read_Eeprom_32bit(ADDRESS1_CURRENT_INTEGRATION_MAX);
		}
		else
		{
			sdoor_current->limit_hardware = Read_Eeprom_32bit(ADDRESS2_CURRENT_LIMIT_HARDWARE);
			sdoor_current->limit_no4 = Read_Eeprom_32bit(ADDRESS2_CURRENT_LIMIT_NO4);
			sdoor_current->limit_no3 = Read_Eeprom_32bit(ADDRESS2_CURRENT_LIMIT_NO3);
			sdoor_current->limit_no2 = Read_Eeprom_32bit(ADDRESS2_CURRENT_LIMIT_NO2);
			sdoor_current->limit_no1 = Read_Eeprom_32bit(ADDRESS2_CURRENT_LIMIT_NO1);
			sdoor_current->keep_open = Read_Eeprom_32bit(ADDRESS2_CURRENT_KEEP_OPEN);
			sdoor_current->keep_close = Read_Eeprom_32bit(ADDRESS2_CURRENT_KEEP_CLOSE);
			sdoor_current->history_max = Read_Eeprom_32bit(ADDRESS2_CURRENT_HISTORY_MAX);
			sdoor_current->integration_max = Read_Eeprom_32bit(ADDRESS2_CURRENT_INTEGRATION_MAX);
		}
			
		if((sdoor_current->limit_hardware < CURRENT_LIMIT_HARDWARE_MIN) || (sdoor_current->limit_hardware > CURRENT_LIMIT_MAX))
		{
			sdoor_current->limit_hardware = CURRENT_LIMIT_HARDWARE;
		}
		
		if((sdoor_current->limit_no4 < sdoor_current->limit_no3) || (sdoor_current->limit_no4 > sdoor_current->limit_hardware))
		{
			sdoor_current->limit_no4 = CURRENT_LIMIT_NO4;
		}

		if((sdoor_current->limit_no3 < sdoor_current->limit_no2) || (sdoor_current->limit_no3 > sdoor_current->limit_no4))
		{
			sdoor_current->limit_no3 = CURRENT_LIMIT_NO3;
		}
			
		if((sdoor_current->limit_no2 < sdoor_current->limit_no1) || (sdoor_current->limit_no2 > sdoor_current->limit_no3))
		{
			sdoor_current->limit_no2 = CURRENT_LIMIT_NO2;
		}
	
		if((sdoor_current->limit_no1 < CURRENT_LIMIT_MIN) || (sdoor_current->limit_no1 > sdoor_current->limit_no2))
		{
			sdoor_current->limit_no1 = CURRENT_LIMIT_NO1;
		}
			
		if(sdoor_current->keep_open > CURRENT_KEEP_MAX)
		{
			sdoor_current->keep_open = CURRENT_KEEP_OPEN;
		}
	
		if(sdoor_current->keep_close > CURRENT_KEEP_MAX)
		{
			sdoor_current->keep_close = CURRENT_KEEP_CLOSE;
		}
			
		if(sdoor_current->history_max > CURRENT_LIMIT_MAX)
		{
			sdoor_current->history_max = 0;
		}
			
		if(sdoor_current->integration_max > CURRENT_INTEGRATION_MAX)
		{
			sdoor_current->integration_max = 0;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Door_Time(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_TIME_STYLE *sdoor_time,EEP_TIME_STYLE *seep_time)
{
	if(door_learn_status == LEARN_AUTO)
	{
		sdoor_time->open_keep = TIME_OPEN_KEEP;
		sdoor_time->open_mode_keep = TIME_OPEN_MODE_KEEP;
		sdoor_time->accelerate_min = TIME_ACCELERATE_MIN;

		seep_time->open_keep = TRUE;
		seep_time->open_mode_keep = TRUE;
		seep_time->accelerate_min = TRUE;
	}
	else
	{
		if(door_which == 1)
		{
			sdoor_time->open_keep = Read_Eeprom_32bit(ADDRESS1_TIME_OPEN_KEEP);
			sdoor_time->open_mode_keep = Read_Eeprom_32bit(ADDRESS1_TIME_OPEN_MODE_KEEP);
			sdoor_time->accelerate_min = Read_Eeprom_32bit(ADDRESS1_TIME_ACCELERATE_MIN);
		}
		else
		{
			sdoor_time->open_keep = Read_Eeprom_32bit(ADDRESS2_TIME_OPEN_KEEP);
			sdoor_time->open_mode_keep = Read_Eeprom_32bit(ADDRESS2_TIME_OPEN_MODE_KEEP);
			sdoor_time->accelerate_min = Read_Eeprom_32bit(ADDRESS2_TIME_ACCELERATE_MIN);
		}

		if(sdoor_time->open_keep > TIME_OPEN_KEEP_MAX)
		{
			sdoor_time->open_keep = TIME_OPEN_KEEP;
		}
			
		if(sdoor_time->open_mode_keep > TIME_OPEN_MODE_KEEP_MAX)
		{
			sdoor_time->open_mode_keep = TIME_OPEN_MODE_KEEP;
		}
			
		if((sdoor_time->accelerate_min < TIME_ACCELERATE_MIN_MIN) || (sdoor_time->accelerate_min > TIME_ACCELERATE_MIN_MAX))
		{
			sdoor_time->accelerate_min = TIME_ACCELERATE_MIN;
		}
	}
		
	sdoor_time->open_fault_hold = TIME_OPEN_FAULT_HOLD;
	sdoor_time->speed_low_limit = TIME_SPEED_LOW_LIMIT;
	sdoor_time->stop_count = 0;
	sdoor_time->test_mode_count = 0;
	sdoor_time->open_mode_keep_count = 0;
	sdoor_time->open_keep_count = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Door_Pwm(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_PWM_STYLE *sdoor_pwm,EEP_PWM_STYLE *seep_pwm)
{
	if(door_learn_status == LEARN_AUTO)
	{
		sdoor_pwm->rate_min = PWM_RATE_MIN;
		sdoor_pwm->rate_max = PWM_RATE_MAX;
		sdoor_pwm->factor_drive = PWM_FACTOR_DRIVE;
		sdoor_pwm->factor_undrive = PWM_FACTOR_UNDRIVE;
		sdoor_pwm->factor_revive_brake = PWM_FACTOR_REVIVE_BRAKE;
		sdoor_pwm->factor_reverse_brake = PWM_FACTOR_REVERSE_BRAKE;
		sdoor_pwm->reverse_permit = PWM_REVERSE_PERMIT;
		sdoor_pwm->uniform_no_reduce = PWM_UNIFORM_NO_REDUCE;
		sdoor_pwm->crawl_end_no_reduce = PWM_CRAWL_END_NO_REDUCE;
		sdoor_pwm->brake_allow_reduce = PWM_BRAKE_ALLOW_REDUCE;
		sdoor_pwm->pid_regulate_cycle = PWM_PID_REGULATE_CYCLE;

		seep_pwm->rate_min = TRUE;
		seep_pwm->rate_max = TRUE;
		seep_pwm->factor_drive = TRUE;
		seep_pwm->factor_undrive = TRUE;
		seep_pwm->factor_revive_brake = TRUE;
		seep_pwm->factor_reverse_brake = TRUE;
		seep_pwm->reverse_permit = TRUE;
		seep_pwm->uniform_no_reduce = TRUE;
		seep_pwm->crawl_end_no_reduce = TRUE;
		seep_pwm->brake_allow_reduce = TRUE;
		seep_pwm->pid_regulate_cycle = TRUE;
	}
	else
	{
		if(door_which == 1)
		{
			sdoor_pwm->rate_min = Read_Eeprom_32bit(ADDRESS1_PWM_RATE_MIN);
			sdoor_pwm->rate_max = Read_Eeprom_32bit(ADDRESS1_PWM_RATE_MAX);
			sdoor_pwm->factor_drive = Read_Eeprom_32bit(ADDRESS1_PWM_FACTOR_DRIVE);
			sdoor_pwm->factor_undrive = Read_Eeprom_32bit(ADDRESS1_PWM_FACTOR_UNDRIVE);
			sdoor_pwm->factor_revive_brake = Read_Eeprom_32bit(ADDRESS1_PWM_FACTOR_REVIVE_BRAKE);
			sdoor_pwm->factor_reverse_brake = Read_Eeprom_32bit(ADDRESS1_PWM_FACTOR_REVERSE_BRAKE);
			sdoor_pwm->reverse_permit = Read_Eeprom_32bit(ADDRESS1_PWM_REVERSE_PERMIT);
			sdoor_pwm->uniform_no_reduce = Read_Eeprom_32bit(ADDRESS1_PWM_UNIFORM_NO_REDUCE);
			sdoor_pwm->crawl_end_no_reduce = Read_Eeprom_32bit(ADDRESS1_PWM_CRAWL_END_NO_REDUCE);
			sdoor_pwm->brake_allow_reduce = Read_Eeprom_32bit(ADDRESS1_PWM_BRAKE_ALLOW_REDUCE);
			sdoor_pwm->pid_regulate_cycle = Read_Eeprom_32bit(ADDRESS1_PWM_PID_REGULATE_CYCLE);
		}
		else
		{
			sdoor_pwm->rate_min = Read_Eeprom_32bit(ADDRESS2_PWM_RATE_MIN);
			sdoor_pwm->rate_max = Read_Eeprom_32bit(ADDRESS2_PWM_RATE_MAX);
			sdoor_pwm->factor_drive = Read_Eeprom_32bit(ADDRESS2_PWM_FACTOR_DRIVE);
			sdoor_pwm->factor_undrive = Read_Eeprom_32bit(ADDRESS2_PWM_FACTOR_UNDRIVE);
			sdoor_pwm->factor_revive_brake = Read_Eeprom_32bit(ADDRESS2_PWM_FACTOR_REVIVE_BRAKE);
			sdoor_pwm->factor_reverse_brake = Read_Eeprom_32bit(ADDRESS2_PWM_FACTOR_REVERSE_BRAKE);
			sdoor_pwm->reverse_permit = Read_Eeprom_32bit(ADDRESS2_PWM_REVERSE_PERMIT);
			sdoor_pwm->uniform_no_reduce = Read_Eeprom_32bit(ADDRESS2_PWM_UNIFORM_NO_REDUCE);
			sdoor_pwm->crawl_end_no_reduce = Read_Eeprom_32bit(ADDRESS2_PWM_CRAWL_END_NO_REDUCE);
			sdoor_pwm->brake_allow_reduce = Read_Eeprom_32bit(ADDRESS2_PWM_BRAKE_ALLOW_REDUCE);
			sdoor_pwm->pid_regulate_cycle = Read_Eeprom_32bit(ADDRESS2_PWM_PID_REGULATE_CYCLE);
		}
		
		if((sdoor_pwm->rate_min < PWM_RATE_MIN_LIMIT) || (sdoor_pwm->rate_min > PWM_RATE_MAX_LIMIT))
		{
			sdoor_pwm->rate_min = PWM_RATE_MIN;
		}

		if((sdoor_pwm->rate_max < PWM_RATE_MIN_LIMIT) || (sdoor_pwm->rate_max > PWM_RATE_MAX_LIMIT))
		{
			sdoor_pwm->rate_max = PWM_RATE_MAX;
		}

		if((sdoor_pwm->factor_drive < PWM_FACTOR_MIN) || (sdoor_pwm->factor_drive > PWM_FACTOR_MAX))
		{
			sdoor_pwm->factor_drive = PWM_FACTOR_DRIVE;
		}

		if((sdoor_pwm->factor_undrive < PWM_FACTOR_MIN) || (sdoor_pwm->factor_undrive > PWM_FACTOR_MAX))
		{
			sdoor_pwm->factor_undrive = PWM_FACTOR_UNDRIVE;
		}

		if((sdoor_pwm->factor_revive_brake < PWM_FACTOR_MIN) || (sdoor_pwm->factor_revive_brake > PWM_FACTOR_MAX))
		{
			sdoor_pwm->factor_revive_brake = PWM_FACTOR_REVIVE_BRAKE;
		}

		if((sdoor_pwm->factor_reverse_brake < PWM_FACTOR_MIN) || (sdoor_pwm->factor_reverse_brake > PWM_FACTOR_MAX))
		{
			sdoor_pwm->factor_reverse_brake = PWM_FACTOR_REVERSE_BRAKE;
		}

		if((sdoor_pwm->reverse_permit != TRUE) && (sdoor_pwm->reverse_permit != FALSE))
		{
			sdoor_pwm->factor_drive = PWM_REVERSE_PERMIT;
		}

		if((sdoor_pwm->uniform_no_reduce < PWM_REDUCE_MIN) || (sdoor_pwm->uniform_no_reduce > PWM_REDUCE_MAX))
		{
			sdoor_pwm->uniform_no_reduce = PWM_UNIFORM_NO_REDUCE;
		}

		if((sdoor_pwm->crawl_end_no_reduce < PWM_REDUCE_MIN) || (sdoor_pwm->crawl_end_no_reduce > PWM_REDUCE_MAX))
		{
			sdoor_pwm->crawl_end_no_reduce = PWM_CRAWL_END_NO_REDUCE;
		}

		if((sdoor_pwm->brake_allow_reduce < PWM_REDUCE_MIN) || (sdoor_pwm->brake_allow_reduce > PWM_REDUCE_MAX))
		{
			sdoor_pwm->brake_allow_reduce = PWM_BRAKE_ALLOW_REDUCE;
		}

		if((sdoor_pwm->pid_regulate_cycle < PWM_FACTOR_MIN) || (sdoor_pwm->pid_regulate_cycle > PWM_FACTOR_MAX))
		{
			sdoor_pwm->pid_regulate_cycle = PWM_PID_REGULATE_CYCLE;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Door_Temperature(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_TEMPERATURE_STYLE *sdoor_temperature,EEP_TEMPERATURE_STYLE *seep_temperature)
{
	if(door_learn_status == LEARN_AUTO)
	{
		sdoor_temperature->limit_high = TEMPERATURE_LIMIT_HIGH;
		sdoor_temperature->limit_low = TEMPERATURE_LIMIT_LOW;
		sdoor_temperature->history_max= 0;

		seep_temperature->limit_high = TRUE;
		seep_temperature->limit_low = TRUE;
		seep_temperature->history_max = TRUE;
	}
	else
	{
		if(door_which == 1)
		{
			sdoor_temperature->limit_high = Read_Eeprom_32bit(ADDRESS1_TEMPERATURE_LIMIT_HIGH);
			sdoor_temperature->limit_low = Read_Eeprom_32bit(ADDRESS1_TEMPERATURE_LIMIT_LOW);
			sdoor_temperature->history_max= Read_Eeprom_32bit(ADDRESS1_TEMPERATURE_HISTORY_MAX);
		}
		else
		{
			sdoor_temperature->limit_high = Read_Eeprom_32bit(ADDRESS2_TEMPERATURE_LIMIT_HIGH);
			sdoor_temperature->limit_low = Read_Eeprom_32bit(ADDRESS2_TEMPERATURE_LIMIT_LOW);
			sdoor_temperature->history_max= Read_Eeprom_32bit(ADDRESS2_TEMPERATURE_HISTORY_MAX);
		}
		
		if(sdoor_temperature->limit_high > TEMPERATURE_MAX)
		{
			sdoor_temperature->limit_high = 0;
		}

		if(sdoor_temperature->limit_low > TEMPERATURE_MAX)
		{
			sdoor_temperature->limit_low = 0;
		}

		if(sdoor_temperature->history_max > TEMPERATURE_MAX)
		{
			sdoor_temperature->history_max = 0;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Door_Pamameter(unsigned char door_which,DOOR_LEARN_STATUS_ENUM door_learn_status,DOOR_STYLE *sdoor_parameter,EEP_PARAMETER_STYLE *seep_parameter)
{
	if(door_learn_status == LEARN_AUTO)
	{
		sdoor_parameter->run_mode = DOOR_RUN_MODE_AUTO;
		sdoor_parameter->can_mode = DOOR_CAN_MODE_LINKAGE;
		sdoor_parameter->run_test_mode = DOOR_RUNNING_TEST_MODE;
		sdoor_parameter->accelerate_step = DOOR_ACCELERATE_STEP;
		sdoor_parameter->run_count = 0;
		sdoor_parameter->run_history_count = 0;
		sdoor_parameter->battery_enable = DOOR_BATTERY_ENABLE;
		sdoor_parameter->open_width = DOOR_OPEN_WIDTH;

		seep_parameter->run_mode = TRUE;
		seep_parameter->can_mode = TRUE;
		seep_parameter->run_test_mode = TRUE;
		seep_parameter->accelerate_step = TRUE;
		seep_parameter->run_count = TRUE;
		seep_parameter->run_history_count = TRUE;
		seep_parameter->battery_enable = TRUE;
		seep_parameter->open_width = TRUE;
	}
	else
	{
		if(door_which == 1)
		{
			sdoor_parameter->run_mode = Read_Eeprom_32bit(ADDRESS1_DOOR_RUN_MODE);
			sdoor_parameter->can_mode = Read_Eeprom_32bit(ADDRESS1_DOOR_CAN_MODE);
			sdoor_parameter->run_test_mode = Read_Eeprom_32bit(ADDRESS1_DOOR_RUN_TEST_MODE);
			sdoor_parameter->accelerate_step = Read_Eeprom_32bit(ADDRESS1_DOOR_ACCELERATE_STEP);
			sdoor_parameter->run_count = Read_Eeprom_32bit(ADDRESS1_DOOR_RUN_COUNT);
			sdoor_parameter->run_history_count = Read_Eeprom_32bit(ADDRESS1_DOOR_RUN_HISTORY_COUNT);
			sdoor_parameter->battery_enable = Read_Eeprom_32bit(ADDRESS1_DOOR_BATTERY_ENABLE);
		}
		else
		{
			sdoor_parameter->run_mode = Read_Eeprom_32bit(ADDRESS2_DOOR_RUN_MODE);
			sdoor_parameter->can_mode = Read_Eeprom_32bit(ADDRESS2_DOOR_CAN_MODE);
			sdoor_parameter->run_test_mode = Read_Eeprom_32bit(ADDRESS2_DOOR_RUN_TEST_MODE);
			sdoor_parameter->accelerate_step = Read_Eeprom_32bit(ADDRESS2_DOOR_ACCELERATE_STEP);
			sdoor_parameter->run_count = Read_Eeprom_32bit(ADDRESS2_DOOR_RUN_COUNT);
			sdoor_parameter->run_history_count = Read_Eeprom_32bit(ADDRESS2_DOOR_RUN_HISTORY_COUNT);
			sdoor_parameter->battery_enable = Read_Eeprom_32bit(ADDRESS2_DOOR_BATTERY_ENABLE);
		}
			
		if((sdoor_parameter->run_mode != DOOR_RUN_MODE_AUTO) && (sdoor_parameter->run_mode != DOOR_RUN_MODE_CLOSE) && (sdoor_parameter->run_mode != DOOR_RUN_MODE_EXIT) && (sdoor_parameter->run_mode != DOOR_RUN_MODE_OPEN))
		{
			sdoor_parameter->run_mode = DOOR_RUN_MODE_AUTO;
		}
			
		if((sdoor_parameter->can_mode != DOOR_CAN_MODE_ALONE) && (sdoor_parameter->can_mode != DOOR_CAN_MODE_LINKAGE) && (sdoor_parameter->can_mode != DOOR_CAN_MODE_MASTER) && (sdoor_parameter->can_mode != DOOR_CAN_MODE_SLAVE))
		{
			sdoor_parameter->can_mode = DOOR_CAN_MODE_LINKAGE;
		}

		if((sdoor_parameter->run_test_mode != TRUE) && (sdoor_parameter->run_test_mode != FALSE))
		{
			sdoor_parameter->run_test_mode = FALSE;
		}

		if((sdoor_parameter->accelerate_step < DOOR_ACCELERATE_STEP_MIN) || (sdoor_parameter->accelerate_step > DOOR_ACCELERATE_STEP_MAX))
		{
			sdoor_parameter->accelerate_step = DOOR_ACCELERATE_STEP;
		}

		if(sdoor_parameter->run_count > DOOR_RUN_COUNT_MAX)
		{
			sdoor_parameter->run_count = 0;
		}
			
		if(sdoor_parameter->run_history_count > DOOR_RUN_COUNT_MAX)
		{
			sdoor_parameter->run_count = 0;
		}

		if((sdoor_parameter->battery_enable != TRUE) && (sdoor_parameter->battery_enable != FALSE))
		{
			sdoor_parameter->battery_enable = FALSE;
		}
	}
	sdoor_parameter->power_low_stauts = DOOR_POWER_LOW_STATUS;
	sdoor_parameter->open_fault_count = 0;
	sdoor_parameter->close_fault_count = 0;
	sdoor_parameter->run_enable = FALSE;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save_Door_Countrol_Varialbe(void) 
{
	Save_Door_Speed(2,&eep2_speed,&door2_speed);
	Save_Door_Lenght(2,&eep2_lenght,&door2_lenght);
	Save_Door_Current(2,&eep2_current,&door2_current);
	Save_Door_Time(2,&eep2_time,&door2_time);
	Save_Door_Pwm(2,&eep2_pwm,&door2_pwm);
	Save_Door_Temperature(2,&eep2_temperature,&door2_temperature);
	Save_Door_Parameter(2,&eep2_parameter,&door2_parameter);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save_Door_Speed(unsigned char door_which,EEP_SPEED_STYLE *seep_speed,DOOR_SPEED_STYLE *sdoor_speed)
{
	unsigned int address_open_max;
	unsigned int address_close_max;
	unsigned int address_crawl;
	unsigned int address_low_limit;
	unsigned int address_fall_ratio;
	unsigned int address_lock_status;
	if(door_which == 1)
	{
		address_open_max = ADDRESS1_SPEED_OPEN_MAX;
		address_close_max = ADDRESS1_SPEED_CLOSE_MAX;
		address_crawl = ADDRESS1_SPEED_CRAWL;
		address_low_limit = ADDRESS1_SPEED_LOW_LIMIT;
		address_fall_ratio = ADDRESS1_SPEED_FALL_RATIO;
		address_lock_status = ADDRESS1_SPEED_LOCK_STATUS;
	}
	else
	{
		address_open_max = ADDRESS2_SPEED_OPEN_MAX;
		address_close_max = ADDRESS2_SPEED_CLOSE_MAX;
		address_crawl = ADDRESS2_SPEED_CRAWL;
		address_low_limit = ADDRESS2_SPEED_LOW_LIMIT;
		address_fall_ratio = ADDRESS2_SPEED_FALL_RATIO;
		address_lock_status = ADDRESS2_SPEED_LOCK_STATUS;
	}
	
	if(seep_speed->open_max == TRUE)
	{
		Write_Eeprom_32bit(address_open_max,sdoor_speed->open_max);
		seep_speed->open_max = FALSE;
	}

	if(seep_speed->close_max == TRUE)
	{
		Write_Eeprom_32bit(address_close_max,sdoor_speed->close_max);
		seep_speed->close_max = FALSE;
	}

	if(seep_speed->crawl == TRUE)
	{
		Write_Eeprom_32bit(address_crawl,sdoor_speed->crawl);
		seep_speed->crawl = FALSE;
	}

	if(seep_speed->low_limit == TRUE)
	{
		Write_Eeprom_32bit(address_low_limit,sdoor_speed->low_limit);
		seep_speed->low_limit = FALSE;
	}

	if(seep_speed->fall_ratio == TRUE)
	{
		Write_Eeprom_32bit(address_fall_ratio,sdoor_speed->fall_ratio);
		seep_speed->fall_ratio = FALSE;
	}

	if(seep_speed->lock_status == TRUE)
	{
		Write_Eeprom_32bit(address_lock_status,sdoor_speed->lock_status);
		seep_speed->lock_status = FALSE;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save_Door_Lenght(unsigned char door_which,EEP_LENGHT_STYLE *seep_lenght,DOOR_LENGHT_STYLE *sdoor_lenght)
{
	unsigned int address_crawl_open;
	unsigned int address_crawl_close;
	unsigned int address_end_open;
	unsigned int address_end_close;
	unsigned int address_hold_close_max;
	unsigned int address_hold_close_min;
	unsigned int address_amble_open;
	if(door_which == 1)
	{
		address_crawl_open = ADDRESS1_LENGHT_CRAWL_OPEN;
		address_crawl_close = ADDRESS1_LENGHT_CRAWL_CLOSE;
		address_end_open = ADDRESS1_LENGHT_END_OPEN;
		address_end_close = ADDRESS1_LENGHT_END_CLOSE;
		address_hold_close_max = ADDRESS1_LENGHT_HOLD_CLOSE_MAX;
		address_hold_close_min = ADDRESS1_LENGHT_HOLD_CLOSE_MIN;
		address_amble_open = ADDRESS1_LENGHT_AMBLE_OPEN;
	}
	else
	{
		address_crawl_open = ADDRESS2_LENGHT_CRAWL_OPEN;
		address_crawl_close = ADDRESS2_LENGHT_CRAWL_CLOSE;
		address_end_open = ADDRESS2_LENGHT_END_OPEN;
		address_end_close = ADDRESS2_LENGHT_END_CLOSE;
		address_hold_close_max = ADDRESS2_LENGHT_HOLD_CLOSE_MAX;
		address_hold_close_min = ADDRESS2_LENGHT_HOLD_CLOSE_MIN;
		address_amble_open = ADDRESS2_LENGHT_AMBLE_OPEN;
	}
	
	if(seep_lenght->crawl_open == TRUE)
	{
		Write_Eeprom_32bit(address_crawl_open,sdoor_lenght->crawl_open);
		seep_lenght->crawl_open = FALSE;
	}

	if(seep_lenght->crawl_close == TRUE)
	{
		Write_Eeprom_32bit(address_crawl_close,sdoor_lenght->crawl_close);
		seep_lenght->crawl_close= FALSE;
	}

	if(seep_lenght->end_open == TRUE)
	{
		Write_Eeprom_32bit(address_end_open,sdoor_lenght->end_open);
		seep_lenght->end_open = FALSE;
	}

	if(seep_lenght->end_close == TRUE)
	{
		Write_Eeprom_32bit(address_end_close,sdoor_lenght->end_close);
		seep_lenght->end_close = FALSE;
	}

	if(seep_lenght->hold_close_max == TRUE)
	{
		Write_Eeprom_32bit(address_hold_close_max,sdoor_lenght->hold_close_max);
		seep_lenght->hold_close_max = FALSE;
	}

	if(seep_lenght->hold_close_min == TRUE)
	{
		Write_Eeprom_32bit(address_hold_close_min,sdoor_lenght->hold_close_min);
		seep_lenght->hold_close_min = FALSE;
	}

	if(seep_lenght->amble_open == TRUE)
	{
		Write_Eeprom_32bit(address_amble_open,sdoor_lenght->amble_open);
		seep_lenght->amble_open = FALSE;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save_Door_Current(unsigned char door_which,EEP_CURRENT_STYLE *seep_current,DOOR_CURRENT_STYLE *sdoor_current)
{
	unsigned int address_limit_no1;
	unsigned int address_limit_no2;
	unsigned int address_limit_no3;
	unsigned int address_limit_no4;
	unsigned int address_keep_open;
	unsigned int address_keep_close;
	unsigned int address_limit_hardware;
	unsigned int address_history_max;
	unsigned int address_integration_max;

	if(door_which == 1)
	{
		address_limit_no1 = ADDRESS1_CURRENT_LIMIT_NO1;
		address_limit_no2 = ADDRESS1_CURRENT_LIMIT_NO2;
		address_limit_no3 = ADDRESS1_CURRENT_LIMIT_NO3;
		address_limit_no4 = ADDRESS1_CURRENT_LIMIT_NO4;
		address_keep_open = ADDRESS1_CURRENT_KEEP_OPEN;
		address_keep_close = ADDRESS1_CURRENT_KEEP_CLOSE;
		address_limit_hardware = ADDRESS1_CURRENT_LIMIT_HARDWARE;
		address_history_max = ADDRESS1_CURRENT_HISTORY_MAX;
		address_integration_max = ADDRESS1_CURRENT_INTEGRATION_MAX;
	}
	else
	{
		address_limit_no1 = ADDRESS2_CURRENT_LIMIT_NO1;
		address_limit_no2 = ADDRESS2_CURRENT_LIMIT_NO2;
		address_limit_no3 = ADDRESS2_CURRENT_LIMIT_NO3;
		address_limit_no4 = ADDRESS2_CURRENT_LIMIT_NO4;
		address_keep_open = ADDRESS2_CURRENT_KEEP_OPEN;
		address_keep_close = ADDRESS2_CURRENT_KEEP_CLOSE;
		address_limit_hardware = ADDRESS2_CURRENT_LIMIT_HARDWARE;
		address_history_max = ADDRESS2_CURRENT_HISTORY_MAX;
		address_integration_max = ADDRESS2_CURRENT_INTEGRATION_MAX;
	}

	if(seep_current->limit_no1 == TRUE)
	{
		Write_Eeprom_32bit(address_limit_no1,sdoor_current->limit_no1);
		seep_current->limit_no1 = FALSE;
	}

	if(seep_current->limit_no2 == TRUE)
	{
		Write_Eeprom_32bit(address_limit_no2,sdoor_current->limit_no2);
		seep_current->limit_no2 = FALSE;
	}
	if(seep_current->limit_no3 == TRUE)
	{
		Write_Eeprom_32bit(address_limit_no3,sdoor_current->limit_no3);
		seep_current->limit_no3 = FALSE;
	}
	if(seep_current->limit_no4 == TRUE)
	{
		Write_Eeprom_32bit(address_limit_no4,sdoor_current->limit_no4);
		seep_current->limit_no4 = FALSE;
	}
	if(seep_current->keep_open == TRUE)
	{
		Write_Eeprom_32bit(address_keep_open,sdoor_current->keep_open);
		seep_current->keep_open = FALSE;
	}
	if(seep_current->keep_close == TRUE)
	{
		Write_Eeprom_32bit(address_keep_close,sdoor_current->keep_close);
		seep_current->keep_close = FALSE;
	}
	if(seep_current->limit_hardware == TRUE)
	{
		Write_Eeprom_32bit(address_limit_hardware,sdoor_current->limit_hardware);
		seep_current->limit_hardware = FALSE;
	}
	if(seep_current->history_max == TRUE)
	{
		Write_Eeprom_32bit(address_history_max,sdoor_current->history_max);
		seep_current->history_max = FALSE;
	}
	if(seep_current->integration_max == TRUE)
	{
		Write_Eeprom_32bit(address_integration_max,sdoor_current->integration_max);
		seep_current->integration_max = FALSE;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save_Door_Time(unsigned char door_which,EEP_TIME_STYLE *seep_time,DOOR_TIME_STYLE *sdoor_time)
{
	unsigned int address_open_keep;
	unsigned int address_open_mode_keep;
	unsigned int address_accelerate_min;

	if(door_which == 1)
	{
		address_open_keep = ADDRESS1_TIME_OPEN_KEEP;
		address_open_mode_keep = ADDRESS1_TIME_OPEN_MODE_KEEP;
		address_accelerate_min = ADDRESS1_TIME_ACCELERATE_MIN;
	}
	else
	{
		address_open_keep = ADDRESS2_TIME_OPEN_KEEP;
		address_open_mode_keep = ADDRESS2_TIME_OPEN_MODE_KEEP;
		address_accelerate_min = ADDRESS2_TIME_ACCELERATE_MIN;
	}

	if(seep_time->open_keep == TRUE)
	{
		Write_Eeprom_32bit(address_open_keep,sdoor_time->open_keep);
		seep_time->open_keep = FALSE;
	}

	if(seep_time->open_mode_keep == TRUE)
	{
		Write_Eeprom_32bit(address_open_mode_keep,sdoor_time->open_mode_keep);
		seep_time->open_mode_keep = FALSE;
	}

	if(seep_time->accelerate_min == TRUE)
	{
		Write_Eeprom_32bit(address_accelerate_min,sdoor_time->accelerate_min);
		seep_time->accelerate_min = FALSE;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save_Door_Pwm(unsigned char door_which,EEP_PWM_STYLE *seep_pwm,DOOR_PWM_STYLE *sdoor_pwm)
{
	unsigned int address_rate_min;
	unsigned int address_rate_max;
	unsigned int address_factor_drive;
	unsigned int address_factor_undrive;
	unsigned int address_factor_revive_brake;
	unsigned int address_factor_reverse_brake;
	unsigned int address_reverse_permit;
	unsigned int address_uniform_no_reduce;
	unsigned int address_crawl_end_no_reduce;
	unsigned int address_brake_allow_reduce;
	unsigned int address_pid_regulate_cycle;
	
	if(door_which == 1)
	{
		address_rate_min = ADDRESS1_PWM_RATE_MIN;
		address_rate_max = ADDRESS1_PWM_RATE_MAX;
		address_factor_drive = ADDRESS1_PWM_FACTOR_DRIVE;
		address_factor_undrive = ADDRESS1_PWM_FACTOR_UNDRIVE;
		address_factor_revive_brake = ADDRESS1_PWM_FACTOR_REVIVE_BRAKE;
		address_factor_reverse_brake = ADDRESS1_PWM_FACTOR_REVERSE_BRAKE;
		address_reverse_permit = ADDRESS1_PWM_REVERSE_PERMIT;
		address_uniform_no_reduce = ADDRESS1_PWM_UNIFORM_NO_REDUCE;
		address_crawl_end_no_reduce = ADDRESS1_PWM_CRAWL_END_NO_REDUCE;
		address_brake_allow_reduce = ADDRESS1_PWM_BRAKE_ALLOW_REDUCE;
		address_pid_regulate_cycle = ADDRESS1_PWM_PID_REGULATE_CYCLE;
	}
	else
	{
		address_rate_min = ADDRESS2_PWM_RATE_MIN;
		address_rate_max = ADDRESS2_PWM_RATE_MAX;
		address_factor_drive = ADDRESS2_PWM_FACTOR_DRIVE;
		address_factor_undrive = ADDRESS2_PWM_FACTOR_UNDRIVE;
		address_factor_revive_brake = ADDRESS2_PWM_FACTOR_REVIVE_BRAKE;
		address_factor_reverse_brake = ADDRESS2_PWM_FACTOR_REVERSE_BRAKE;
		address_reverse_permit = ADDRESS2_PWM_REVERSE_PERMIT;
		address_uniform_no_reduce = ADDRESS2_PWM_UNIFORM_NO_REDUCE;
		address_crawl_end_no_reduce = ADDRESS2_PWM_CRAWL_END_NO_REDUCE;
		address_brake_allow_reduce = ADDRESS2_PWM_BRAKE_ALLOW_REDUCE;
		address_pid_regulate_cycle = ADDRESS2_PWM_PID_REGULATE_CYCLE;
	}

	if(seep_pwm->rate_min == TRUE)
	{
		Write_Eeprom_32bit(address_rate_min,sdoor_pwm->rate_min);
		seep_pwm->rate_min = FALSE;
	}

	if(seep_pwm->rate_max == TRUE)
	{
		Write_Eeprom_32bit(address_rate_max,sdoor_pwm->rate_max);
		seep_pwm->rate_max = FALSE;
	}

	if(seep_pwm->factor_drive == TRUE)
	{
		Write_Eeprom_32bit(address_factor_drive,sdoor_pwm->factor_drive);
		seep_pwm->factor_drive = FALSE;
	}

	if(seep_pwm->factor_undrive == TRUE)
	{
		Write_Eeprom_32bit(address_factor_undrive,sdoor_pwm->factor_undrive);
		seep_pwm->factor_undrive = FALSE;
	}

	if(seep_pwm->factor_revive_brake == TRUE)
	{
		Write_Eeprom_32bit(address_factor_revive_brake,sdoor_pwm->factor_revive_brake);
		seep_pwm->factor_revive_brake = FALSE;
	}

	if(seep_pwm->factor_reverse_brake == TRUE)
	{
		Write_Eeprom_32bit(address_factor_reverse_brake,sdoor_pwm->factor_reverse_brake);
		seep_pwm->factor_reverse_brake = FALSE;
	}
	
	if(seep_pwm->reverse_permit == TRUE)
	{
		Write_Eeprom_32bit(address_reverse_permit,sdoor_pwm->reverse_permit);
		seep_pwm->reverse_permit = FALSE;
	}
	
	if(seep_pwm->uniform_no_reduce == TRUE)
	{
		Write_Eeprom_32bit(address_uniform_no_reduce,sdoor_pwm->uniform_no_reduce);
		seep_pwm->uniform_no_reduce = FALSE;
	}
	
	if(seep_pwm->crawl_end_no_reduce == TRUE)
	{
		Write_Eeprom_32bit(address_crawl_end_no_reduce,sdoor_pwm->crawl_end_no_reduce);
		seep_pwm->crawl_end_no_reduce = FALSE;
	}
	
	if(seep_pwm->brake_allow_reduce == TRUE)
	{
		Write_Eeprom_32bit(address_brake_allow_reduce,sdoor_pwm->brake_allow_reduce);
		seep_pwm->brake_allow_reduce = FALSE;
	}
	
	if(seep_pwm->pid_regulate_cycle == TRUE)
	{
		Write_Eeprom_32bit(address_pid_regulate_cycle,sdoor_pwm->pid_regulate_cycle);
		seep_pwm->pid_regulate_cycle = FALSE;
	}															
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save_Door_Temperature(unsigned char door_which,EEP_TEMPERATURE_STYLE *seep_temperature,DOOR_TEMPERATURE_STYLE *sdoor_temperature)
{
	unsigned int address_limit_high;
	unsigned int address_limit_low;
	unsigned int address_history_max;
	
	if(door_which == 1)
	{
		address_limit_high = ADDRESS1_TEMPERATURE_LIMIT_HIGH;
		address_limit_low = ADDRESS1_TEMPERATURE_LIMIT_LOW;
		address_history_max = ADDRESS1_TEMPERATURE_HISTORY_MAX;
	}
	else
	{
		address_limit_high = ADDRESS2_TEMPERATURE_LIMIT_HIGH;
		address_limit_low = ADDRESS2_TEMPERATURE_LIMIT_LOW;
		address_history_max = ADDRESS2_TEMPERATURE_HISTORY_MAX;
	}

	if(seep_temperature->limit_high == TRUE)
	{
		Write_Eeprom_32bit(address_limit_high,sdoor_temperature->limit_high);
		seep_temperature->limit_high = FALSE;
	}

	if(seep_temperature->limit_low == TRUE)
	{
		Write_Eeprom_32bit(address_limit_low,sdoor_temperature->limit_low);
		seep_temperature->limit_low = FALSE;
	}

	if(seep_temperature->history_max == TRUE)
	{
		Write_Eeprom_32bit(address_history_max,sdoor_temperature->history_max);
		seep_temperature->history_max = FALSE;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save_Door_Parameter(unsigned char door_which,EEP_PARAMETER_STYLE *seep_parameter,DOOR_STYLE *sdoor_parameter)
{
	unsigned int address_run_mode;
	unsigned int address_can_mode;
	unsigned int address_run_test_mode;
	unsigned int address_accelerate_step;
	unsigned int address_run_count;
	unsigned int address_run_history_count;
	unsigned int address_battery_enable;
	unsigned int address_open_width;
	
	if(door_which == 1)
	{
		address_run_mode = ADDRESS1_DOOR_RUN_MODE;
		address_can_mode = ADDRESS1_DOOR_CAN_MODE;
		address_run_test_mode = ADDRESS1_DOOR_RUN_TEST_MODE;
		address_accelerate_step = ADDRESS1_DOOR_ACCELERATE_STEP;
		address_run_count = ADDRESS1_DOOR_RUN_COUNT;
		address_run_history_count = ADDRESS1_DOOR_RUN_HISTORY_COUNT;
		address_battery_enable = ADDRESS1_DOOR_BATTERY_ENABLE;
		address_open_width = ADDRESS1_DOOR_OPEN_WIDTH;
	}
	else
	{
		address_run_mode = ADDRESS2_DOOR_RUN_MODE;
		address_can_mode = ADDRESS2_DOOR_CAN_MODE;
		address_run_test_mode = ADDRESS2_DOOR_RUN_TEST_MODE;
		address_accelerate_step = ADDRESS2_DOOR_ACCELERATE_STEP;
		address_run_count = ADDRESS2_DOOR_RUN_COUNT;
		address_run_history_count = ADDRESS2_DOOR_RUN_HISTORY_COUNT;
		address_battery_enable = ADDRESS2_DOOR_BATTERY_ENABLE;
		address_open_width = ADDRESS2_DOOR_OPEN_WIDTH;
	}

	if(seep_parameter->run_mode == TRUE)
	{
		Write_Eeprom_32bit(address_run_mode,sdoor_parameter->run_mode);
		seep_parameter->run_mode = FALSE;
	}

	if(seep_parameter->can_mode == TRUE)
	{
		Write_Eeprom_32bit(address_can_mode,sdoor_parameter->can_mode);
		seep_parameter->can_mode = FALSE;
	}

	if(seep_parameter->run_test_mode == TRUE)
	{
		Write_Eeprom_32bit(address_run_test_mode,sdoor_parameter->run_test_mode);
		seep_parameter->run_test_mode = FALSE;
	}

	if(seep_parameter->accelerate_step == TRUE)
	{
		Write_Eeprom_32bit(address_accelerate_step,sdoor_parameter->accelerate_step);
		seep_parameter->accelerate_step = FALSE;
	}

	if(seep_parameter->run_count == TRUE)
	{
		Write_Eeprom_32bit(address_run_count,sdoor_parameter->run_count);
		seep_parameter->run_count = FALSE;
	}

	if(seep_parameter->run_history_count == TRUE)
	{
		Write_Eeprom_32bit(address_run_history_count,sdoor_parameter->run_history_count);
		seep_parameter->run_history_count = FALSE;
	}

	if(seep_parameter->battery_enable == TRUE)
	{
		Write_Eeprom_32bit(address_battery_enable,sdoor_parameter->battery_enable);
		seep_parameter->battery_enable = FALSE;
	}

	if(seep_parameter->open_width == TRUE)
	{
		Write_Eeprom_32bit(address_open_width,sdoor_parameter->open_width);
		seep_parameter->open_width = FALSE;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Door_Timer(void)
{
	if(door1_time.stop_count > 0)
	{
		door1_time.stop_count--;
	}

	if(door2_time.stop_count > 0)
	{
		door2_time.stop_count--;
	}

	if(door2_time.test_mode_count > 0)
	{
		door2_time.test_mode_count--;
	}

	if(door2_time.open_keep_count > 0)
	{
		door2_time.open_keep_count--;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Door2_Test_Mode(void)
{
	static unsigned char test_mode_temp = 0;
	if(door2_parameter.run_test_mode == TRUE)
	{
		if(door2_run_way == DOOR_KEEP_CLOSE)
		{
			if(test_mode_temp == 0)
			{
				door2_time.test_mode_count = 3000;	//hold time is 3000*1ms=3s
				test_mode_temp = 1;
			}

			if(door2_time.test_mode_count == 0)
			{
			;//	door2_run_way = DOOR_OPEN;
			}
		}
		else
		{
			test_mode_temp = 0;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Door_Control(void)	//called in main while
{
//	Door2_Control();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void Door2_Control(void)
{
	if(door2_learn_status == LEARN_AUTO)
	{
		Door2_Learn_Auto();
	}
	else if(door2_learn_status == LEARN_SEARCH)
	{
		Door2_Learn_Search();
	}
	else
	{
		Door2_Logical();
		Door2_Test_Mode();
	}
}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void Door2_Learn_Auto(void)
{
	switch(door2_run_way)
	{
		case DOOR_OPEN :
			if(motor2_drive_stage == STOP_STAGE && door2_parameter.run_enable == TRUE)
			{
				door2_run_way = DOOR_KEEP_OPEN;		// set door run way is open keep
				door2_parameter.run_enable = FALSE;
				door2_time.stop_count = 2000;		// stop door 2 s
				Qei2_Position_input(POSITION_OPEN);
				door2_position.start = Qei2_Position();
				Write_Eeprom_32bit(ADDRESS2_POSITION_START,door2_position.start);
				Buzzer_Input(500,2);
				Led_Double_Input(0,0x02,0);
				Command_Qei_Start_Test();
			}
			break;
		case DOOR_KEEP_OPEN :
			if(door2_time.stop_count == 0)
			{
				door2_run_way = DOOR_CLOSE;
				Led_Double_Input(1,2,0,1);
			}
			break;
		case DOOR_CLOSE :
			if(motor2_drive_stage == STOP_STAGE && door2_parameter.run_enable == TRUE)
			{
				door2_run_way = DOOR_KEEP_CLOSE;		// set door run way is close keep
				door2_parameter.run_enable = FALSE;
				door2_time.stop_count = 2000;		// stop door 2 s
				door2_position.end = Qei2_Position();
				Write_Eeprom_32bit(ADDRESS2_POSITION_END,door2_position.end);
				Buzzer_Input(500,4);
				Led_Double_Input(0,0x00,0);
				Command_Qei_End_Test();
			}
			break;
		case DOOR_KEEP_CLOSE :
			if(door2_time.stop_count == 0)
			{
				door2_learn_status = LEARN_OK;
			}
			break;
		default : 
			door2_run_way = DOOR_OPEN;
			break;
	}
}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void Door2_Learn_Search(void)
{
	switch(door2_run_way)
	{
		case DOOR_CLOSE :
			if(motor2_drive_stage == STOP_STAGE && door2_parameter.run_enable == TRUE)
			{
				door2_run_way = DOOR_KEEP_CLOSE;		// set door run way is close keep
				door2_parameter.run_enable = FALSE;
				door2_time.stop_count = 2000;		// stop door 2 s
				door2_position.start = POSITION_OPEN;
				door2_position.end = Read_Eeprom_32bit(ADDRESS2_POSITION_END);
				Qei2_Position_input(door2_position.end);
				Buzzer_Input(500,4);
				Led_Double_Input(0,0x00,0);
			}
			break;
		case DOOR_KEEP_CLOSE :
			if(door2_time.stop_count == 0)
			{
				door2_learn_status = LEARN_OK;
			}
			break;
		default : break;
	}
}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void Door2_Logical(void)
{
	switch(door2_run_way)
	{
		case DOOR_KEEP_CLOSE :
			
			break;
		case DOOR_OPEN :
			if(motor2_drive_stage == STOP_STAGE && door2_parameter.run_enable == TRUE)
			{
				door2_run_way = DOOR_KEEP_OPEN;		// set door run way is open keep
				door2_parameter.run_enable = FALSE;
				door2_time.open_keep_count = TIME_OPEN_KEEP * 1000;
				
			}
			break;
		case DOOR_KEEP_OPEN :
			if(door2_time.open_keep_count == 0)
			{
				door2_run_way = DOOR_CLOSE;
			}
			break;
		case DOOR_CLOSE :
			if(motor2_drive_stage == STOP_STAGE && door2_parameter.run_enable == TRUE)
			{
				door2_run_way = DOOR_KEEP_CLOSE;		// set door run way is open keep
				door2_parameter.run_enable = FALSE;
			}
			break;
		default :
			door2_learn_status = LEARN_SEARCH;
			break;
	}
}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




