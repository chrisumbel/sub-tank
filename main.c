/*
 * File:   main.c
 * Author: cumbel
 *
 * Created on June 17, 2016, 6:15 PM
 */


#include <xc.h>
#include <pic18f2550.h>

#include "hardware_configuration.h"
#include "itoa.h"
#include "logging.h"
#include "distance.h"

#include <plib/timers.h>


int _i = 0;

#define PERIOD 20

float pct = 0.5;
int fall_at = 5;

int set_pct(float _pct) {
    pct = _pct;
    fall_at = PERIOD * pct;
}

void interrupt TimerOverflow()
{    
    if(TMR0IF == 1) {
        _i += 1;        

        if(_i >= 20) {
            if(pct != 0) {
                LATB1 = 1;
            }
            _i = 0;
        } else if(_i >= fall_at) {
            LATB1 = 0;
        }
   
        TMR0IF = 0;    
        TMR0 = 6;
    }
}

void main() {
    OSCCON = 0b01110000;
    CMCON = 7;
      
    int i = 0;
    int j = 0;
    char s[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    log_init();
    distance_init();
    
    set_pct(0.75);
    
    TRISB1 = 0;    
    LATB1 = 0;
    T0CONbits.T0CS = 0;
    T0CONbits.T08BIT = 1;
    T0CONbits.TMR0ON = 1;
    T0CONbits.PSA = 0;
    T0CONbits.T0PS0 = 0;
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS2 = 0;
     
    INTCONbits.T0IE = 1;    
    INTCONbits.T0IF = 0;
    TMR0 = 6;
    
    ei();     // This is like fliping the master switch to enable interrupt

    while (1) {
        itoa(i, s);
        log_message(s);
        log_message(": ");
        
        int d = distance_capture();
        itoa(d, s);
        log_message_ln(s);        
        
        itoa(fall_at, s);
        log_message_ln(s);
        log_message_ln("===============");
        
        i++;
        
        for(j = 0; j  < 10; j++) {
            __delay_ms(10);
        }
    }    
}
