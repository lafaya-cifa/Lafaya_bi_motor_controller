#include "Uart.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
enum
{
	UART_COMM_FREE = 0,
	UART_COMM_SENDING,
	UART_COMM_RECEIVING
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagUART_COMM
{
	unsigned	char	data_tx[UART_DATA_COMM_SIZE];           //send data
	unsigned	char	data_rx[UART_DATA_COMM_SIZE];        //receive data
	unsigned	char	data_tx_ascii[UART_DATA_BUFFER_SIZE];       //send ascii data
	unsigned	char	data_rx_ascii[UART_DATA_BUFFER_SIZE];    //receive ascii data
//	unsigned	char	apply_receive[UART_DATA_COMM_SIZE];   //applay receive data
	
	unsigned    char	uart_status;			//uart status,=0:free,=1:send,=2:receive
	unsigned	long	uart_time_count;        //uart time count
	unsigned	char	uart_number;            //uart number
	unsigned	char	uart_rx_number;         //uart receive number
	unsigned	char	uart_receive_ok;        //uart receive ok
}UART_COMM;	
UART_COMM	suart;

const	unsigned long uart_time_count_max = UART_COMM_TIME * 1000UL / UART_TIMER_US;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Uart_Varialbe(void)    //initialize uart bariable
{
	suart.data_tx[UART_DATA_COMM_SIZE] = 0;
	suart.data_rx[UART_DATA_COMM_SIZE] = 0;
	suart.data_tx_ascii[UART_DATA_BUFFER_SIZE] = 0;
	suart.data_rx_ascii[UART_DATA_BUFFER_SIZE] = 0;
//	suart.apply_receive[UART_DATA_COMM_SIZE] = 0;
		
	suart.uart_status = UART_COMM_FREE;
	suart.uart_time_count = 0;
	suart.uart_number = 0;
	suart.uart_rx_number = 0;
	suart.uart_receive_ok = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Uart(void)   //called in main
{
	Initialize_Uart_Varialbe();    //
    
	U1MODE = 0x0000;   //UART1 is disable
	U1STA = 0x0000;
	
	U1BRG  = U1BRG_NUMBER;     //baud rate set 9600
	IPC3bits.U1TXIP = U1TXIP_NUMBER;   //
	IPC2bits.U1RXIP = U1RXIP_NUMBER;   //
    
	U1MODEbits.UARTEN = 1;  //enable UART
	U1STAbits.UTXEN = 1;  //enable UART TX
    
	IEC0bits.U1TXIE = 0;  //disable Transmit Interrupt
	IFS0bits.U1TXIF = 0;    //clear tx interrupt flag
    
	IEC0bits.U1RXIE = 1;  //Enable Receive Interrupt
	IFS0bits.U1RXIF = 0;    //clear rx interrupt flag
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __attribute__((interrupt,no_auto_psv)) _U1TXInterrupt(void)
{ 
	Uart_Send();    //
	IFS0bits.U1TXIF = 0;    //clear tx interrupt flag
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __attribute__((interrupt,no_auto_psv)) _U1RXInterrupt(void)
{
	Uart_Receive();     //
	IFS0bits.U1RXIF = 0;    //clear rx interrupt flag
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Hex_To_Ascii(void)    //
{   
	unsigned char split_temp, ascii_temp, data_tx_lenght;
	unsigned char ascii_lenght = 1;//
	
	data_tx_lenght = suart.data_tx[0];        //
//
	for(split_temp = 1; split_temp <= data_tx_lenght; split_temp++)
	{
		suart.data_tx_ascii[ascii_lenght] = suart.data_tx[split_temp] >> 4;
		ascii_lenght++;
		suart.data_tx_ascii[ascii_lenght] = suart.data_tx[split_temp] & 0x0F;    //
		ascii_lenght++;
	}

	for(ascii_temp = 1; ascii_temp < ascii_lenght; ascii_temp++)
	{
		if(suart.data_tx_ascii[ascii_temp] < 10)
		{
			suart.data_tx_ascii[ascii_temp] = suart.data_tx_ascii[ascii_temp] + 0x30;
		}
		else
		{
			suart.data_tx_ascii[ascii_temp] = suart.data_tx_ascii[ascii_temp] + 0x37;
		}
	}
    
	suart.data_tx_ascii[ascii_lenght] = UART_COMM_END_WORD;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Uart_Send_Start(void)   //uart send start
{
	if(suart.uart_status == UART_COMM_FREE)
	{
		suart.uart_time_count = 0;		//clear uart time count
		IEC0bits.U1TXIE = 1; //enable tx interrupt
		suart.uart_status = UART_COMM_SENDING;     //uart status is sending
		IO_OUT_UART = 1;      //hardware to be tx
		suart.uart_number = 0;  //clear uart number
		Command_Flag_Clear();   //clear command flag
		Uart_Send();      //send data
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Uart_Send(void)     //
{
	if(suart.uart_number == 0)   //
	{
		U1TXREG = UART_COMM_HAND_WORD;    //
		suart.uart_number = 1;   //
	}
	else if(suart.uart_number == 1)   //
	{
		U1TXREG = suart.data_tx_ascii[suart.uart_number];    //
		suart.uart_number++;                       //
	}
	else if(suart.uart_number >= 2)
	{
		if(suart.uart_number < UART_DATA_BUFFER_SIZE)
		{
			if(suart.data_tx_ascii[suart.uart_number - 1] == UART_COMM_END_WORD) //
			{
				while(!U1STAbits.TRMT)     //wait data for send over
				{
					ClrWdt();
				}
	        		
				IEC0bits.U1TXIE = 0;	//disable tx interrupt
				suart.uart_time_count = 0;	//clear uart time count
				suart.uart_status = UART_COMM_FREE;        //uart status to be free
				IO_OUT_UART = 0;         //hardware is received
			}
			else    //
			{
				U1TXREG = suart.data_tx_ascii[suart.uart_number];    //
				suart.uart_number++;                       //
			}	      
		}
		else
		{
			Initialize_Uart_Varialbe();     //clear uart
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Uart_Handle(void)      //called in main to send data
{
    if(Command_Flag_Output() == 1)
    {
        Send_Data_Exchange(suart.data_tx);
        Hex_To_Ascii();
        Uart_Send_Start();   //uart send start
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Uart_Receive(void)     //data received
{
	unsigned char data_read;

	while(U1STAbits.URXDA == TRUE)	//
	{
		data_read = U1RXREG;
		
		if (data_read == UART_COMM_HAND_WORD)	//read data is hand work
		{
			suart.data_rx_ascii[0] = UART_COMM_HAND_WORD;
			suart.uart_number = 1;
			suart.uart_status = UART_COMM_RECEIVING;
			suart.uart_time_count = 0;
		}
		else if(data_read == UART_COMM_END_WORD)	//
		{
			if((suart.data_rx_ascii[0] == UART_COMM_HAND_WORD) && (suart.uart_number >= 4))
			{			
				suart.data_rx_ascii[suart.uart_number] = data_read;
			}

			if (U1STAbits.URXDA == TRUE)	//
			{
				continue;
			}
			Ascii_To_Hex();
			if(Data_Checkcode() == 1)	//
			{
				suart.uart_receive_ok = 1;		//
				suart.uart_rx_number = suart.uart_number;	//
			}
			else
			{
				suart.uart_receive_ok = 0;
				suart.uart_rx_number = 0;	//
			}
			suart.uart_status = UART_COMM_FREE;		//
		}
		else if( suart.data_rx_ascii[0] == UART_COMM_HAND_WORD)	//
		{
			suart.data_rx_ascii[suart.uart_number] = data_read;

			suart.uart_number++;
			if(suart.uart_number >= UART_COMM_CHAR_MAX)
			{	
				suart.uart_number = 0;
				suart.data_rx_ascii[0] = 0;
				suart.uart_status = UART_COMM_FREE;		//
			}
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Ascii_To_Hex(void)      //
{
	unsigned char split_temp, ascii_temp;

	unsigned char data_rx_number = 1;
                       
	for(ascii_temp = 1; ascii_temp < suart.uart_number; ascii_temp++)
	{
		if(suart.data_rx_ascii[ascii_temp] < 0x40)
		{
			suart.data_rx_ascii[ascii_temp] = suart.data_rx_ascii[ascii_temp] - 0x30;
		}
		else
		{
			suart.data_rx_ascii[ascii_temp] = suart.data_rx_ascii[ascii_temp] - 0x37;
		}
	}

	for(split_temp = 1; split_temp <= (suart.uart_number >> 1); split_temp++)
	{
		suart.data_rx[data_rx_number] = (suart.data_rx_ascii[(split_temp << 1) - 1] << 4) + suart.data_rx_ascii[split_temp << 1]; 
		data_rx_number++; 
	}
	suart.data_rx[0] = UART_COMM_HAND_WORD;
	suart.data_rx[data_rx_number] = UART_COMM_END_WORD;
	suart.uart_number = data_rx_number;	//
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char Data_Checkcode(void)    //
{
	unsigned char data_check = 0x00;  //
	unsigned char check_temp;
	for(check_temp = 1; check_temp < (suart.uart_number - 1); check_temp++)
	{
		data_check  = data_check  ^ suart.data_rx[check_temp];   //
	}     
    
	if(suart.data_rx[suart.uart_number - 1] == data_check)     //
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Uart_Timer(void)    //
{
	if(suart.uart_time_count < UART_TIME_COUNT_MAX)
	{
		suart.uart_time_count++;
		if(suart.uart_status != UART_COMM_FREE)
		{
			if(suart.uart_time_count > uart_time_count_max)	//
			{
				Initialize_Uart_Varialbe();
			}
		}
	}
	else
	{
		suart.uart_time_count = UART_TIME_COUNT_MAX;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Uart_Data_Output(unsigned char *lenght, unsigned char *data)  //
{
	unsigned char data_temp;
	*lenght = suart.uart_rx_number;	//
	for(data_temp = 0; data_temp <= *lenght; data_temp++)
	{
		data[data_temp] = suart.data_rx[data_temp];
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char Uart_Recieve_Flag(void)    //receive flag output
{
	return suart.uart_receive_ok;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Uart_Flag_Clear(void)      //receive flag clear
{
    suart.uart_receive_ok = 0;
}