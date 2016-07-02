/* 
 * File:   servo.h
 * Author: cumbel
 *
 * Created on June 18, 2016, 7:49 PM
 */

#ifndef SERVO_H
#define	SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif

#define PERIOD 20

#define SERVO_LEFT   0.03
#define SERVO_CENTER 0.06
#define SERVO_RIGHT  0.09    
    
int servo_set_pct(float _pct);
void servo_init();
void servo_turn(float pos);
void interrupt TimerOverflow();

#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

