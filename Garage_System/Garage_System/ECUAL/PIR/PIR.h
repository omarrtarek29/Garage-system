/*
 * PIR.h
 *
 * Created: 11/14/2022 5:52:19 PM
 *  Author: omart
 */ 


#ifndef PIR_H_
#define PIR_H_


#include "../../MCAL/EX_INTERRUPT/EX_INTERRUPT.h"


void PIR_init_exInt(EX_INT_num_t exInt, EX_INT_edge_t edge, void(*fptr)(void));



#endif /* PIR_H_ */