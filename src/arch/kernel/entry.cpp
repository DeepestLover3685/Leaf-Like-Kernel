#include "../../../include/arch/sched/timer.h" 
#include "../../../include/drivers/uart.h"

extern "C" void start(void) ;

const  char* llk_logo[] = 
{

    "\e[92m\e[1m    __                 ____        __     _  __            __ __                          __", 
    "   / /   ___   ______ / __/       / /    (_)/ /__ ___     / //_/___   _____ ____   ___   / /", 
    "  / /   / _ \\ / __  // /_ ______ / /    / // //_// _ \\   / ,<  / _ \\ / ___// __ \\ / _ \\ / /",
    " / /___/  __// /_/ // __//_____// /___ / // ,<  /  __/  / /| |/  __// /   / / / //  __// / ", 
    "/_____/\\___/ \\____//_/         /_____//_//_/|_| \\___/  /_/ |_|\\___//_/   /_/ /_/ \\___//_/ ",
    "\e[32m\e[0m"
};

void uart_putchar(char c){
    *(volatile char *)UART0 = c ;
}

void uart_puts(const char *s) {
    while (*s) uart_putchar(*s++);
}

void show_logo() {
    const char **p = llk_logo;
    while (*p) {
        uart_puts(*p++);
        uart_putchar('\n');
    }
}

void start(void){

    llk_system_timer_init() ;

    show_logo() ;
    while(1) ;
}  
                                                                                            