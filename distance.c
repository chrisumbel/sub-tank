
#include "distance.h"
#include "hardware_configuration.h"

#include <plib/capture.h>
#include <plib/timers.h>

void distance_init() {
    TRISB0 = 0; // trigger
    TRISC2 = 1; // echo
    LATBbits.LATB0 = 0;    
}

int distance_capture() {
     LATBbits.LATB0 = 1;    
    __delay_us(10);
     LATBbits.LATB0 = 0;

    PIR1bits.CCP1IF = 0; 
    
    SetTmrCCPSrc(T1_SOURCE_CCP);
    OpenCapture1(CAP_EVERY_FALL_EDGE & CAPTURE_INT_ON);    
    OpenTimer1(TIMER_INT_OFF & T1_SOURCE_INT);
    PIR1bits.CCP1IF = 0; 
    
    while(PIR1bits.CCP1IF == 0);  // Wait for event
  
    int d = ReadCapture1();

    PIR1bits.CCP1IF = 0;

    CloseCapture1();
    CloseTimer1();
    return d;
}

