/*
 * File:   main.c
 * Author: cumbel
 *
 * Created on June 17, 2016, 6:15 PM
 */


#include <xc.h>
#include <pic18f2550.h>
#include <plib/usart.h>

#include "hardware_configuration.h"
#include "itoa.h"
#include "logging.h"
#include "distance.h"

void main() {
    OSCCON = 0b01110000;
    CMCON = 7;
      
    int i = 0;
    int j = 0;
    char s[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    log_init();
    distance_init();
    
    while (1) {
        itoa(i, s);
        log_message(s);
        log_message(": ");
        
        int d = distance_capture();
        itoa(d, s);
        log_message_ln(s);        

        i++;
        
        for(j = 0; j  < 10; j++) {
            __delay_ms(10);
        }
    }    
}
