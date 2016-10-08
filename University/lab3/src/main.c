#include <avr/io.h>
#include <avr/delay.h>
#include "uart_stdio.h"
#include "drivers/button.h"
#include "drivers/lm20.h"

#define DELAY_TIME_MS 1000

int CelsiusToKelvin(int celsius){
	return celsius+273;
}

int CelsiusToFarenheit(int celsius){
	return celsius*18/10 + 32;
}

void main() {
	struct ButtonDevice button1;
	struct ButtonDevice button2;
	button1.ddr = &DDRC;
	button1.pin = &PINC;
	button1.pinIndex = 0;
	
	button2.ddr = &DDRC;
	button2.pin = &PINC;
	button2.pinIndex = 1;
	
	// Initialization
	uart_stdio_Init();
	LM20_Init();
	ButtonInit(&button1);
	ButtonInit(&button2);
	
	int temperature;
	
	while(1){
		temperature = LM20_GetTemperature();
		if(ButtonPressed(&button1)){
			temperature = CelsiusToKelvin(temperature);
			printf("Kelvin : %d\n",temperature);
		} else {
			if (ButtonPressed(&button2))
			{
				temperature = CelsiusToFarenheit(temperature);
				printf("Farenheit: %d \n",temperature);
			} else {
				printf("Celsius: %d\n",temperature);
			}
		}
		_delay_ms(DELAY_TIME_MS);
	}
}
