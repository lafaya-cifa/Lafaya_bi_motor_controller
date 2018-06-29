#ifndef PWM_H_
#define PWM_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <../h/p33EP512MU814.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Initialize_Pwm(void);	//PWM initialized to called in main

extern void Pwm_Input(unsigned int pwm4_pdc,unsigned int pwm4_sdc,unsigned int pwm5_pdc,unsigned int pwm5_sdc, unsigned int pwm6_pdc, unsigned int pwm6_sdc);






//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif

