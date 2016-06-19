#include <xc.h>
#include <pic18f2550.h>

#include "drive_motors.h"
 
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