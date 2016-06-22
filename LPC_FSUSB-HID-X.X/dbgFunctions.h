/* 
 * File:   dbgFunctions.h
 * Author: Franco
 *
 * Created on 17 de junio de 2016, 16:35
 */

#ifndef DBGFUNCTIONS_H
#define	DBGFUNCTIONS_H

#include <usart.h>
#include "system.h"
#include <adc.h>

#ifdef	__cplusplus
extern "C" {
#endif

    void USARTstart(int baudrate);
    unsigned int sp;
    
    void ADCstart();

#ifdef	__cplusplus
}
#endif

#endif	/* DBGFUNCTIONS_H */

