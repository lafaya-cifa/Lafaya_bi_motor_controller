#ifndef UART_H_
#define UART_H_
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <../h/p33EP512MU814.h>
#include "../mcu_module/Header.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	IO_OUT_UART		_RC13		//uart control io
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	UART_DATA_BUFFER_SIZE			60		//
#define	UART_DATA_COMM_SIZE			30		//

#define	UART_TIME_COUNT_MAX			10000000	//
#define	UART_COMM_TIME					600	//600ms
#define	UART_TIMER_US						1000	//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	UART_COMM_HAND_WORD			0x7E	//hand word
#define	UART_COMM_END_WORD			0x0D	//end word
#define	UART_COMM_CHAR_MAX			58
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define	U1TXIP_NUMBER						2		//
#define	U1RXIP_NUMBER						2		//
#define	U1BRG_NUMBER						390		//baud rate set 9600
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Uart_Varialbe(void);    //initialize uart bariable
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Initialize_Uart(void);   //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Hex_To_Ascii(void);    //
extern void Uart_Send_Start(void);   //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Uart_Send(void);     //
extern void Uart_Handle(void);      //called in main to send data
void Uart_Receive(void);        //
void Ascii_To_Hex(void);      //
unsigned char Data_Checkcode(void);    //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Uart_Timer(void);    //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern void Uart_Data_Output(unsigned char *lenght, unsigned char *data);
extern unsigned char Uart_Recieve_Flag(void);    //receive flag output
extern void Uart_Flag_Clear(void);      //receive flag clear
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif

