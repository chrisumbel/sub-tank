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
    
    while (1) {
        itoa(i, s);
        log_message(s);
        log_message(": ");
                
        i++;

        log_message_ln("===============");

        servo_turn(SERVO_LEFT);
        
        int right_distance = distance_capture();
        itoa(right_distance, s);
        log_message("right: ");
        log_message_ln(s);

        servo_turn(SERVO_CENTER);        
       
        int center_distance = distance_capture();
        itoa(center_distance, s);
        log_message("center: ");                
        log_message_ln(s);                

        servo_turn(SERVO_RIGHT);
        
        int left_distance = distance_capture();
        itoa(left_distance, s);
        log_message("left: ");        
        log_message_ln(s);                        
        
        for(j = 0; j  < 100; j++) {
            __delay_ms(10);
        }
    }    
}
