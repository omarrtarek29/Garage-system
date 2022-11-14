/*
 * APP.c
 *
 * Created: Created: 11/14/2022 1:40:34 PM
 *  Author: omart
 */ 


#include "APP.h"


static uint8_t car_counter = 0;


/*****************************************************************************
* Function Name: APP_init
* Purpose      : Initialize app
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void APP_init(void){
	LCD_init();
	PIR_init_exInt(INT0_t, ANY_LOGIC_CHANGE, PIR_entry_action);
	PIR_init_exInt(INT1_t, ANY_LOGIC_CHANGE, PIR_exit_action);
	SERVO_init(PORTC_t, PIN0_t);
	SERVO_init(PORTC_t, PIN1_t);
}


/*****************************************************************************
* Function Name: APP_loop
* Purpose      : Keep app running continuously
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void APP_loop(void){
	while (1)
	{
		if (car_counter < 10)
		{
			LCD_write_command(0x80);
			LCD_write_number(car_counter);
			LCD_write_string((uint8_t *)" cars inside.");
			
			LCD_write_command(0xC0);
			LCD_write_number(10 - car_counter);
			LCD_write_string((uint8_t *)" cars left!");
		}
		else
		{
			LCD_write_command(0x80);
			LCD_write_string((uint8_t *)"Garage is full.");
			
			LCD_write_command(0xC0);
			LCD_write_string((uint8_t *)"Check later!");
		}
	}
}


/*****************************************************************************
* Function Name: PIR_entry_action
* Purpose      : Functionality when cars enter the garage
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void PIR_entry_action(void){
	static uint8_t flag = 0;
	
	// Do nothing if the garage is full
	if (car_counter < 10)
	{
		/*
		When IR senses a car, it turns on the motor
		After then, when the car enters (meaning another ISR), turns the motor back off
		*/
		if (flag % 2 == 0)
		{
			// Delay between on and off should've been 1500 us but just did some calibration because of the MCU freq and simulation delay
			SERVO_on(PORTC_t, PIN0_t);
			_delay_us(1462);
			SERVO_off(PORTC_t, PIN0_t);
		}
		else{
			SERVO_on(PORTC_t, PIN0_t);
			// Delay between on and off should've been 1000 us but just did some calibration because of the MCU freq and simulation delay
			_delay_us(962);
			SERVO_off(PORTC_t, PIN0_t);
			car_counter++;
		}
		
		flag++;
	}
}


/*****************************************************************************
* Function Name: PIR_entry_action
* Purpose      : Functionality when cars exit the garage
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void PIR_exit_action(void){
	static uint8_t flag = 0;
	
	// Do nothing if the garage is empty .. Do not open the slider from inside
	if (car_counter > 0)
	{
		/*
		When IR senses a car, it turns on the motor
		After then, when the car enters (meaning another ISR), turns the motor back off
		*/
		if (flag % 2 == 0)
		{
			// Delay between on and off should've been 1500 us but just did some calibration because of the MCU freq and simulation delay
			SERVO_on(PORTC_t, PIN1_t);
			_delay_us(1457);
			SERVO_off(PORTC_t, PIN1_t);
		}
		else{
			// Delay between on and off should've been 1000 us but just did some calibration because of the MCU freq and simulation delay
			SERVO_on(PORTC_t, PIN1_t);
			_delay_us(957);
			SERVO_off(PORTC_t, PIN1_t);
			car_counter--;
		}
		
		flag++;
	}
}