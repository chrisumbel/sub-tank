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

int servo_set_pct(float _pct);
void servo_init();
void interrupt TimerOverflow();

#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

