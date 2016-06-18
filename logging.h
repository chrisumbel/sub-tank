/* 
 * File:   logging.h
 * Author: cumbel
 *
 * Created on June 17, 2016, 7:57 PM
 */

#ifndef LOGGING_H
#define	LOGGING_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void log_init();
void log_message_ln(char *s);
void log_message(char *s);

#ifdef	__cplusplus
}
#endif

#endif	/* LOGGING_H */

