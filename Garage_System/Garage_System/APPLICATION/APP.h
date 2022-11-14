/*
 * APP.h
 *
 * Created: 11/14/2022 1:39:24 PM
 *  Author: omart
 */ 


#ifndef APP_H_
#define APP_H_


#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/PIR/PIR.h"
#include "../ECUAL/SERVO/SERVO.h"


void APP_init(void);
void APP_loop(void);
void PIR_entry_action(void);
void PIR_exit_action(void);


#endif /* APP_H_ */