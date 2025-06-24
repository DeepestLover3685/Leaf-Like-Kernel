#include "../../include/drivers/uart.h"

void uart_putchar(char c){
    *(volatile char *)UART0 = c ;
}

void uart_puts(const char *s) {
    while (*s) uart_putchar(*s++);
}

