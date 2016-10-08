/*
 * button.c
 *
 * Created: 9/21/2016 10:26:00 AM
 *  Author: Maxian Nicu
 */ 

#include "button.h"


void ButtonInit(struct ButtonDevice *device){
	*(device->ddr) = ~(1<<device->pinIndex);
}

char ButtonPressed(struct ButtonDevice *device){
	if(~(*(device->pin))&(1<<device->pinIndex))
		return 1;
	else
		return 0;
}