/*
 * adc.c
 *
 * Created: 10/5/2016 6:54:49 AM
 *  Author: Maxian Nicu
 */ 

#include "adc.h"
#include "../utils.h"

void ADC_Init(){
	ADCSRA = (1 << ADEN)
			|(1 << ADSC)
			|(0 << ADATE)
			|(0 << ADIF)
			|(0 << ADIE)
			|(1 << ADPS2)
			|(1 << ADPS1)
			|(0 << ADPS0);
	
	ADMUX = 0x03;
}

int ADC_GetData(){
	ADCSRA |= (1 << ADSC);
	while(ADCSRA && ADIF == 0);
	
	return ADC;
}

float ADC_GetVoltage(){
	return ConvertValueFromToRange(ADC_GetData(),0,1023,0,5);
}
