#include "dbgFunctions.h"

void USARTstart(int baudrate){                 
    /*CloseUSART(); //turn off usart if was previously on                 
    TRISC = TRISC | 0b11000000;
    
    //-----configure USART -----               
    config = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT &                 
            USART_CONT_RX & USART_BRGH_HIGH & USART_ADDEN_OFF;                 

    //-----SPBRG needs to be changed depending upon oscillator frequency-------                     
    spbrg = 129; // At 20Mhz of oscillator frequency & baud rate of 9600.                 

    OpenUSART(config, spbrg);     
    
    baudconfig = BAUD_8_BIT_RATE & BAUD_AUTO_OFF;                 
    baudUSART(baudconfig);                 

    while (BusyUSART())                 
        ;  */
    
  sp = (_XTAL_FREQ - baudrate*64)/(baudrate*64);   //SPBRG for Low Baud Rate
  if(sp>255)                                       //If High Baud Rage Required
  {
    sp = (_XTAL_FREQ - baudrate*16)/(baudrate*16); //SPBRG for High Baud Rate
    BRGH = 1;                                     //Setting High Baud Rate
  }
  if(sp<256)
  {
    SPBRG = sp;                                    //Writing SPBRG Register
    SYNC = 0;                                     //Setting Asynchronous Mode, ie UART
    SPEN = 1;                                     //Enables Serial Port
    TRISC7 = 1;                                   //As Prescribed in Datasheet
    TRISC6 = 1;                                   //As Prescribed in Datasheet
    CREN = 1;                                     //Enables Continuous Reception
    TXEN = 1;                                     //Enables Transmission
  }
}
