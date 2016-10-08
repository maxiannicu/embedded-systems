/*
 * adc.h
 *
 * Created: 10/5/2016 6:54:38 AM
 *  Author: Maxian Nicu
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>

void ADC_Init();
int ADC_GetData();
float ADC_GetVoltage();

#endif /* ADC_H_ */