#ifndef SPEED_H_
#define SPEED_H_

#include <../h/p33EP512MU814.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	MOTOR_REDUCTIOB_RATIO	15
#define	TIME_BASE					133		//ns
#define	ENCODER_CYCLES			500
#define	PULLEY_DIAMETER			58000	//um
#define	PAI							314		//¦Ð* 100
/*motor reduction ratio is 15 : 1,timer3 time base is 133.33ns,encoder 500 cycles per cycle
* speed = 1 / (500 * speed_time * 133.33ns) = 15000 / speed_time[cycle / second]
*pulley diameter is 58mm = 58000um,so,motor speed = (¦Ð * 58000 * 15000 / speed_time) / 15 = 182,212,373 / speed_time[um/s]   */
#define	CALCULATE_SPEED_TIME		(PAI * PULLEY_DIAMETER / ENCODER_CYCLES * 100000UL / TIME_BASE * 100 /  MOTOR_REDUCTIOB_RATIO)		//182,576,440 um/s
#define	CALCULATE_SPEED_MAX		(1400 * 1000UL)	// 1400 mm/s = 1400 * 1000 um/s
#define	CALCULATE_SPEED_MIN		100			// 0.1 mm/s = 100 um/s
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	TIMER_RP					0x927C
#define	SPEED_STEP_MAX			(CALCULATE_SPEED_TIME / CALCULATE_SPEED_MIN / TIMER_RP + 1)		// 182212373 / 100 / PR4 + 1 = 48.59 + 1 = 49
#define	SPEED_TIME_MAX			(CALCULATE_SPEED_TIME / CALCULATE_SPEED_MIN)					// 182212373 / 100 = 1822123
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Initialize_Speed_Varialbe(void);	//called in main
extern void Speed1_Time(void);	//called in ic
extern void Speed2_Time(void);	//called in ic
extern void Speed1_Counter(void);		//called in timer
extern void Speed2_Counter(void);		//called in timer
extern long Speed1_Calculate(void);
extern long Speed2_Calculate(unsigned char motor_status,unsigned long position_now);
//void Speed_Is_Low(unsigned char speed_low_enable,long speed_now,unsigned int speed_low_limit,unsigned int time_speed_low_limit,unsigned int *speed_low_count,unsigned char *speed_is_low);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif

