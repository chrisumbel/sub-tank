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
#include "sonar_servo.h"
#include "drive_motors.h"
#include <plib/timers.h>

void main() {
    OSCCON = 0b01110000;
    CMCON = 7;
      
    int i = 0;
    int j = 0;
    char s[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    log_init();
    distance_init();    
    servo_init();
    drive_motors_init();
    
    MOTOR_LEFT_1_LAT = 1;
    MOTOR_LEFT_2_LAT = 0;
    
    MOTOR_RIGHT_1_LAT = 1;    
    MOTOR_RIGHT_2_LAT = 0;    
    
    ei();     // This is like fliping the master switch to enable interrupt

    servo_set_pct(0.05);
    
    while (1) {
        itoa(i, s);
        log_message(s);
        log_message(": ");
        
        int d = distance_capture();
        itoa(d, s);
        log_message_ln(s);                
        log_message_ln("===============");
        
        i++;
        
        for(j = 0; j  < 10; j++) {
            __delay_ms(10);
        }
    }    
}
