/* 
 * File:   drive_motors.h
 * Author: cumbel
 *
 * Created on June 19, 2016, 10:06 AM
 */
#include <pic18f2550.h>

#ifndef DRIVE_MOTORS_H
#define	DRIVE_MOTORS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MOTOR_LEFT_1_TRIS TRISA5
#define MOTOR_LEFT_2_TRIS TRISA4

#define MOTOR_RIGHT_1_TRIS TRISB4
#define MOTOR_RIGHT_2_TRIS TRISB3

    
#define MOTOR_LEFT_1_LAT LATA5
#define MOTOR_LEFT_2_LAT LATA4

#define MOTOR_RIGHT_1_LAT LATB4
#define MOTOR_RIGHT_2_LAT LATB3


void drive_motors_init();
    
#ifdef	__cplusplus
}
#endif

#endif	/* DRIVE_MOTORS_H */

