/*
 * led.h
 *
 * Created: 9/21/2016 10:25:33 AM
 *  Author: Maxian Nicu
 */ 


#ifndef LED_H_
#define LED_H_
#include <avr/io.h>

struct LedDevice {
	uint8_t pinIndex;
	volatile uint8_t *ddr;
	volatile uint8_t *port;
};

void LedInit(struct LedDevice *device);
void LedOn(struct LedDevice *device);
void LedOff(struct LedDevice *device);

#endif /* LED_H_ */