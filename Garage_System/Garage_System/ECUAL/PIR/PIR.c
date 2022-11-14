/*
 * PIR.c
 *
 * Created: 11/14/2022 5:52:44 PM
 *  Author: omart
 */ 


#include "PIR.h"


/*****************************************************************************
* Function Name: PIR_init_exInt
* Purpose      : Initialize PIR with external interrupt pin
* Parameters   : External interrupt pin name, edge to work with and the function to ISR
* Return value : Void
*****************************************************************************/
void PIR_init_exInt(EX_INT_num_t exInt, EX_INT_edge_t edge, void(*fptr)(void)){
	EX_INTERRUPT_init(exInt, edge, fptr);
}


