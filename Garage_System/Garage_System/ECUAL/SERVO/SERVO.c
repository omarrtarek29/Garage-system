/*
 * SERVO.c
 *
 * Created: 11/14/2022 8:45:11 PM
 *  Author: omart
 */ 


#include "SERVO.h"


/*****************************************************************************
* Function Name: SERVO_init
* Purpose      : Initialize Servo at a certain pin
* Parameters   : Register name and pin number of servo
* Return value : Void
*****************************************************************************/
void SERVO_init(REG_name_t reg, PIN_num_t pin){
	DIO_init_pin(reg, pin, OUTPUT);
}


/*****************************************************************************
* Function Name: SERVO_on
* Purpose      : Turn Servo on
* Parameters   : Register name and pin number of servo
* Return value : Void
*****************************************************************************/
void SERVO_on(REG_name_t reg, PIN_num_t pin){
	DIO_write(reg, pin, HIGH);
}


/*****************************************************************************
* Function Name: SERVO_off
* Purpose      : Turn Servo off
* Parameters   : Register name and pin number of servo
* Return value : Void
*****************************************************************************/
void SERVO_off(REG_name_t reg, PIN_num_t pin){
	DIO_write(reg, pin, LOW);
}