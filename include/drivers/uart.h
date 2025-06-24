#ifndef __UART_H 
#define __UART_H

#include "../arch/kernel/platform.h"

void uart_putchar(char c) ;
void uart_puts(const char *s) ;

#endif
