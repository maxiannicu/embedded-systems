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
	return ConvertValueFromToRange(ADC_GetVoltage(),0.3,2.48,130,-55);
}
