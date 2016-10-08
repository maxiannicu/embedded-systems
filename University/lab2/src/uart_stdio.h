#ifndef _UART_STDIO_H
#define _UART_STDIO_H

#include "defines.h"
#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>

void uart_stdio_Init(void);

int	uart_PutChar(char c, FILE *stream);

#endif
