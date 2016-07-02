#include <xc.h>
#include <pic18f2550.h>
#include "sonar_servo.h"
#include "hardware_configuration.h"

int _i = 0;

#define PERIOD 160
#define TMR0_PRELOAD 156

float pct = 0.5;
int fall_at = 5;

void servo_turn(float pos) {
    int j;
    servo_set_pct(pos);

    for(j = 0; j  < 30; j++) {
        __delay_ms(10);
    }    
}

int servo_set_pct(float _pct) {
    pct = _pct;
    fall_at = PERIOD * pct;
}

void servo_init() {
    servo_set_pct(0.5);
    
    TRISB1 = 0;    
    LATB1 = 0;
    T0CONbits.T0CS = 0;
    T0CONbits.T08BIT = 1;
    T0CONbits.TMR0ON = 1;
    T0CONbits.PSA = 0;
    T0CONbits.T0PS0 = 0;
    T0CONbits.T0PS1 = 0;
    T0CONbits.T0PS2 = 0;
     
    INTCONbits.T0IE = 1;    
    INTCONbits.T0IF = 0;
    TMR0 = TMR0_PRELOAD;    
}

void interrupt TimerOverflow() {    
    if(TMR0IF == 1) {
        _i += 1;        

        if(_i >= PERIOD) {
            if(pct != 0) {
                LATB1 = 1;
            }
            _i = 0;
        } else if(_i >= fall_at) {
            LATB1 = 0;
        }
   
        TMR0IF = 0;    
        TMR0 = TMR0_PRELOAD;
    }
}

