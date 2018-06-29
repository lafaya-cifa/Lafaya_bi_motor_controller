#ifndef QEI_H_
#define QEI_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <../h/p33EP512MU814.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#define	SWPAB1_CHOICE		1		//AB1 phase choice
//#define	SWPAB2_CHOICE		1		//AB1 phase choice

#define	QEI_STEPS		2000L
#define	QEI_INIT		0x80000000

#define	QEI_QEIGEC			(QEI_INIT + QEI_STEPS)
#define	QEI_STEP_INIT		10000		//qei initialize value

#define	PIMOD_NUMBER			5			//QEIM value

#define	QEIIP_NUMNBER		7			//qei1 ip number
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Initialize_Qei(void);    //initialize qei,called in main
void QEI1_Poscnt_Input(unsigned long poscnt_value);
void QEI2_Poscnt_Input(unsigned long poscnt_value);
unsigned long Qei1_Poscnt(void);
unsigned long Qei2_Poscnt(void);

extern unsigned long Qei1_Position(void);
extern unsigned long Qei2_Position(void);
extern void Qei1_Position_input(unsigned long position_input);	//position input
extern void Qei2_Position_input(unsigned long position_input);	//position input
extern unsigned char Qei1_Good(void);
extern unsigned char Qei2_Good(void);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif

