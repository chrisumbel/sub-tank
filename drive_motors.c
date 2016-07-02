#include <xc.h>
#include <pic18f2550.h>

#include "drive_motors.h"
#include "hardware_configuration.h"

void wait(int n) {
    for(int j = 0; j < 100; j++) {
        __delay_ms(10);
    }      
}

void turn_wait() {
    wait(MOTOR_TURN_WAIT);
}

void drive_motors_init() {
    MOTOR_LEFT_1_LAT = 0;
    MOTOR_LEFT_2_LAT = 0;
    MOTOR_RIGHT_1_LAT = 0;
    MOTOR_RIGHT_2_LAT = 0;    
    
    MOTOR_LEFT_1_TRIS = 0;
    MOTOR_LEFT_2_TRIS = 0;
    MOTOR_RIGHT_1_TRIS = 0;
    MOTOR_RIGHT_2_TRIS = 0;
}

void drive_motors_turn_left() {
    MOTOR_LEFT_1_LAT = 1;
    MOTOR_LEFT_2_LAT = 0;
    
    MOTOR_RIGHT_1_LAT = 0;    
    MOTOR_RIGHT_2_LAT = 0;
    
    turn_wait();
}

void drive_motors_turn_right() {
    MOTOR_LEFT_1_LAT = 0;
    MOTOR_LEFT_2_LAT = 0;
    
    MOTOR_RIGHT_1_LAT = 1;    
    MOTOR_RIGHT_2_LAT = 0;        
        
    turn_wait();
}

void drive_motors_move_forward() {
    MOTOR_LEFT_1_LAT = 1;
    MOTOR_LEFT_2_LAT = 0;
    
    MOTOR_RIGHT_1_LAT = 1;    
    MOTOR_RIGHT_2_LAT = 0;
    
    wait(MOTOR_FORWARD_WAIT);    
}