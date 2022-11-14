/*
 * TIMER1.h
 *
 * Created: 8/30/2022 11:18:36 PM
 *  Author: omart
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_


#include "TIMER_reg_conf.h"
#include "../../std_macros.h"


void TIMER1_normalMode_init(void);
void TIMER1_ctcMode_init(uint16 oc, void (*fptr)(void));
void TIMER1_write(uint16 value);
uint16 TIMER1_read(void);
void TIMER1_ctcMode_stop(void);


#endif /* TIMER1_H_ */