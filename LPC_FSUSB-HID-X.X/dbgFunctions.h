/* 
 * File:   dbgFunctions.h
 * Author: Franco
 *
 * Created on 17 de junio de 2016, 16:35
 */

#ifndef DBGFUNCTIONS_H
#define	DBGFUNCTIONS_H

#include <plib.h>

#ifndef _XTAL_FREQ
    #define _XTAL_FREQ 20000000
#endif

#ifdef	__cplusplus
extern "C" {
#endif

    void USARTstart(int baudrate);
    unsigned char config, spbrg, baudconfig;
    unsigned int sp;

#ifdef	__cplusplus
}
#endif

#endif	/* DBGFUNCTIONS_H */

