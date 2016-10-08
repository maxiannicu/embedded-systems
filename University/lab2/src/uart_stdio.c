/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Stdio demo, UART implementation
 *
 * $Id: uart.c 1008 2005-12-28 21:38:59Z joerg_wunsch $
 */
#include "uart_stdio.h"

FILE uart_str = FDEV_SETUP_STREAM(uart_PutChar, NULL, _FDEV_SETUP_WRITE);

void uart_stdio_Init(void)
{
#if F_CPU < 2000000UL && defined(U2X)
	UCSRA = _BV(U2X);             /* improve baud rate error by using 2x clk */
	UBRRL = (F_CPU / (8UL * UART_BAUD)) - 1;
#else
	UBRRL = (F_CPU / (16UL * UART_BAUD)) - 1;
#endif
	UCSRB = _BV(TXEN) | _BV(RXEN); /* tx/rx enable */
  
	stdout = &uart_str;
}

int uart_PutChar(char c, FILE *stream)
{

	if (c == '\a')
	{
		fputs("*ring*\n", stderr);
		return 0;
	}

	if (c == '\n')
		uart_PutChar('\r', stream);

	
	while(~UCSRA & (1 << UDRE));
	UDR = c;


	return 0;
}

