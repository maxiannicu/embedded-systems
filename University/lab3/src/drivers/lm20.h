/*
 * lm20.h
 *
 * Created: 10/5/2016 6:36:59 AM
 *  Author: Maxian Nicu
 */ 


#ifndef LM20_H_
#define LM20_H_
#include "adc.h"

void LM20_Init();
int LM20_GetTemperature();

#endif /* LM20_H_ */