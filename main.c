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

#define DISTANCE_THRESHOLD 100

#define DIRECTION_LEFT     -1
#define DIRECTION_STRAIGHT  0
#define DIRECTION_RIGHT     1

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
                
        int left_delta = left_distance - center_distance;
        int right_delta = right_distance - center_distance;
        
        if(left_delta > DISTANCE_THRESHOLD || right_delta > DISTANCE_THRESHOLD) {
            int direction = DIRECTION_LEFT;
            
            if(right_delta > left_delta) {
                direction = DIRECTION_RIGHT;
            }
            
            if(direction == DIRECTION_LEFT) {
                drive_motors_turn_left();
            } else {
                drive_motors_turn_right();
            }
        }
        
        drive_motors_move_forward();
        drive_motors_move_stop();
    }    
}
