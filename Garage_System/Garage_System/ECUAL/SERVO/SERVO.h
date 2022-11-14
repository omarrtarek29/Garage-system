/*
 * SERVO.h
 *
 * Created: 11/14/2022 8:45:25 PM
 *  Author: omart
 */ 


#ifndef SERVO_H_
#define SERVO_H_


#include "../../MCAL/DIO/DIO.h"


void SERVO_init(REG_name_t reg, PIN_num_t pin);
void SERVO_on(REG_name_t reg, PIN_num_t pin);
void SERVO_off(REG_name_t reg, PIN_num_t pin);


#endif /* SERVO_H_ */