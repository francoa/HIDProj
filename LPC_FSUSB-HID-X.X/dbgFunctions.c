#include "dbgFunctions.h"

void USARTstart(int baudrate){                 
    //CloseUSART(); //turn off usart if was previously on                 
    //RCSTA = RCSTA | 0b10000000;
    TRISCbits.RC6 = 1;
    TRISCbits.RC7 = 1;
    
    //-----configure USART -----               
    config = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT
            & USART_BRGH_LOW;                 

    //-----SPBRG needs to be changed depending upon oscillator frequency-------                     
    spbrg = 31; // At 20Mhz of oscillator frequency & baud rate of 9600, low speed.                 

    OpenUSART(config, spbrg);     
    
    baudconfig = BAUD_8_BIT_RATE & BAUD_AUTO_ON;                 
    baudUSART(baudconfig);                 

    while (BusyUSART())                 
        ;  
    
  /*sp = (_XTAL_FREQ - baudrate*64)/(baudrate*64);   //SPBRG for Low Baud Rate
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
  }*/
}

void ADCstart(){
    //initADC();
    OpenADC(ADC_FOSC_16 & ADC_RIGHT_JUST & ADC_4_TAD,
            ADC_CH0 & ADC_INT_OFF & ADC_REF_VDD_VSS,
            ADC_1ANA);
}
