/* 
 * File:   hardware_configuration.h
 * Author: cumbel
 *
 * Created on June 18, 2016, 9:01 AM
 */

#ifndef HARDWARE_CONFIGURATION_H
#define	HARDWARE_CONFIGURATION_H

#ifdef	__cplusplus
extern "C" {
#endif

#pragma config FOSC = INTOSC_HS, WDT = OFF
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF
#pragma config LVP = OFF, BOR = OFF
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF

#define _XTAL_FREQ 8000000

#ifdef	__cplusplus
}
#endif

#endif	/* HARDWARE_CONFIGURATION_H */

