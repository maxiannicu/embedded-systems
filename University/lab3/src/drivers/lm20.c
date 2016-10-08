/*
 * lm20.c
 *
 * Created: 10/5/2016 6:37:10 AM
 *  Author: Maxian Nicu
 */ 
#include "lm20.h"
#include "../utils.h"

void LM20_Init(){
	ADC_Init();
}

int LM20_GetTemperature(){
	int t = ADC_GetVoltage();
	t = ConvertValueFromToRange(t,0,2.4,130,-55);

	return t;
}
