#include <avr/io.h>
#include <util/delay.h>
#include "drivers/button.h"
#include "drivers/led.h"
#include "drivers/lcd/lcd.h"

uint8_t i = 0;
struct ButtonDevice buttonDevice;
struct LedDevice ledDevice;

void turnOn(){
	LCDWriteString("ON");
	LedOn(&ledDevice);	
}

void turnOff(){
	LCDWriteString("OFF");
	LedOff(&ledDevice);	
}

void main() {
	buttonDevice.pin = &PINA;
	buttonDevice.pinIndex = 0;
	buttonDevice.ddr = &DDRA;
	
	ledDevice.ddr = &DDRC;
	ledDevice.pinIndex = 4;
	ledDevice.port = &PORTC;
	
	ButtonInit(&buttonDevice);
	LedInit(&ledDevice);
	LCDInit(LS_ULINE);
	
	while(1){
		LCDClear();
		if(ButtonPressed(&buttonDevice)){
			turnOn();
		} else {
			turnOff();
		}		
		_delay_ms(100);
	}	
}
