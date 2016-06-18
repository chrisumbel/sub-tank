#include "logging.h"

#include <plib/usart.h>
#include <pic18f2550.h>
#include <xc.h>

void log_init() {
    TRISC6 = 0;
    OpenUSART(USART_TX_INT_ON & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_BRGH_HIGH, 51);
}

void log_message(char *s) {
    putrsUSART(s);
}

void log_message_ln(char *s) {
    log_message(s);
    log_message("\r\n");    
}