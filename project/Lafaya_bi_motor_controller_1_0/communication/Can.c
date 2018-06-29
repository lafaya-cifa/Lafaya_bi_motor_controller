#include "Header.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialize_Can(void)
{
    C1CTRL1bits.REQOP = 4;		//set configuration mode
    while(C1CTRL1bits.OPMODE != 4);     //hold on device module is in set configuration mode
 //   C1CTRL1 = 0x0000;
	C1CTRL1bits.CSIDL = 0;		//continues module operation in idle mode
	C1CTRL1bits.ABAT = 0;		//module will clear this bit when all transmissions are aborted
	C1CTRL1bits.CANCKS = 0;		//Fcan is equal to Fcy
	C1CTRL1bits.CANCAP = 0;		//disables can captue
	C1CTRL1bits.WIN = 0;		//uses buffer window

    C1CFG1 = 0x0008;
	//C1CFG1bits.SJW = 0;
	//C1CFG1bits.BRP = 8;
    /*  Fbaud = 166.7K bps = 1000K/6 bps
     *  N = 20 ----N must is more than 8 and less than 25
     * Ftq = Fbaud * N = 1000K/6 * 20 = 20000K/6
     * Tq = (2 * (BRP + 1)) / Fcan
     * Fcan = Fcy = Fosc / 2 = 120MHZ / 2 = 60MHZ
     * Tq = 1 / Ftq = 1 / (20000K / 6) = 6 / 20000K = (2 * (BRP + 1)) / Fcan
     *                                  6 / 20000K = (2 * (BRP + 1)) / 60MHZ
     *                                  6 / 20000k = (2 * (BRP + 1)) / 60000K
     *                                          18 = 2 * (BRP + 1)
     *                                          BRP = 8
     
     *  synchronization jump width length is 1 * TQ
     *  propagation time segment length is 5 * TQ
     *  phase segment 2 length is 6 * TQ
     *  phase wegment 1 length = 20TQ  - (1TQ + 5TQ + 6TQ) = 8TQ
     */
	C1CFG2 = 0x05FC;
	//C1CFG2bits.WAKFL = 0;		//can bus line filter is not used for wake-up
	//C1CFG2bits.SEG2PH = 0b101;		//phase segment2 length is 6*TQ
	//C1CFG2bits.SEG2PHTS = 1;		//phase segment2 time select freelyprogrammable
	//C1CFG2bits.SAM = 1;			//sample of the can bus line is sampled three times at the sample point
	//C1CFG2bits.SEG1PH = 0b111;			//phase segment1 length is 8*TQ
	//C1CFG2bits.PRSEG = 0b100;			//propagation time segment length is 5*TQ
    
    C1FCTRL = 0x0000;
	//C1FCTRLbits.DMABS = 0;		//4 buffers in DMA RAM
	//C1FCTRLbits.FSA = 0;		//TX/RX buffer TRB0
    
    
    
	C1CTRL2 = 0x0000;
	//C1CTRL2bits.DNCNT = 0;		//does not compare data bytes

	C1VEC = 0x0000;
	//C1VECbits.FILHIT = 0;		//filter0
	//C1VECbits.ICODE = 0;		//TRB0 buffer interrupt

	

	C1FIFO = 0x0000;
	//C1FIFObits.FBP = 0;			//TRB0 buffer
	//C1FIFObits.FNRB = 0;			//TRB0 buffer

	C1INTF = 0x0000;
	//C1INTFbits.TXBO = 0;		//transmitter is not in bus off state
	//C1INTFbits.TXBP = 0;			//transmitter is not in bus passive state
	//C1INTFbits.RXBP = 0;		//receiver is not in bus passive state
	//C1INTFbits.TXWAR = 0;		//transmitter is not error warning state
	//C1INTFbits.RXWAR = 0;		//receiver is not in error warning state
	//C1INTFbits.EWARN = 0;		//transmitter or receiver is not in error state warning state
	//C1INTFbits.IVRIF = 0;		//interrupt request has not occurred
	//C1INTFbits.WAKIF = 0;		//interrupt request has not occurred
	//C1INTFbits.ERRIF = 0;		//interrupt request has not occurred
	//C1INTFbits.FIFOIF = 0;		//interrupt request has not occurred
	//C1INTFbits.RBOVIF = 0;		//interrupt request has not occurred
	//C1INTFbits.RBIF = 0;			//interrupt request has not occurred
	//C1INTFbits.TBIF = 0;			//interrupt request has not occurred

	C1INTE = 0x0003;
	//C1INTEbits.IVRIE = 0;		//interrupt request is not enabled
	//C1INTEbits.WAKIE = 0;		//interrupt request is not enabled
	//C1INTEbits.ERRIE = 0;		//interrupt request is not enabled
	//C1INTEbits.FIFOIE = 0;		//interrupt request is not enabled
	//C1INTEbits.RBOVIE = 0;		//interrupt request is not enabled
	//C1INTEbits.RBIE = 1;			//interrupt request is enabled
	//C1INTEbits.TBIE = 1;			//interrupt request is enabled



	C1FEN1 = 0x0001;			//enable filter 1

	C1RXF0SID = 0x01 << 2;
	C1RXF1SID = 0x01 << 2;
	C1RXF0EID = 0;
	C1RXF1EID = 0;

	C1RXM0SID = 0x01FC;
	C1RXM1SID = 0x01FC;

	C1RXFUL1 = 0x0000;		//buffer is empty
	C1RXFUL2 = 0x0000;		//buffer is empty

	C1RXOVF1 = 0x0000;		//no overflow condition
	
	C1RXOVF2 = 0x0000;		//no overflow condition

	C1TR01CON = 0x0003;		//highest message priority

	IEC2bits.C1IE = 1;					//enable ECAN1 interrupt
    C1INTEbits.TBIE = 1;                //enable TX interrupt
    C1INTEbits.RBIE = 1;                //enalbe RX interrupt
	IPC8bits.C1IP = 5;                  //
	IFS2bits.C1IF = 0;					//
    
	C1CTRL1bits.REQOP = 0;		//set normal operation mode
	while(C1CTRL1bits.OPMODE != 0);	//hold on device module is in normal operation mode
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __attribute__((interrupt, no_auto_psv))_C1Interrupt(void)   //CAN1 interrupt
{
	if (C1INTFbits.TX0IF || C1INTFbits.TX1IF || C1INTFbits.TX2IF)    //
	{
		C1INTFbits.TX0IF = FALSE;		//
		C1INTFbits.TX1IF = FALSE;		//
		C1INTFbits.TX2IF = FALSE;		//
		C1TERRCNT = FALSE;			//
	}
	
	if(C1INTFbits.RX0IF)
	{
		Can_Receive_Messagge();
		C1RX0CONbits.RXFUL = FALSE;
		C1INTFbits.RX0IF = FALSE;
	}
	
	IFS2bits.C1IF = 0;		//clear C1IF
}




















