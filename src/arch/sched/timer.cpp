#include "../../include/arch/sched/timer.h"

static volatile llk_tick_t llk_tick = 0 ;

static llk_time_list llk_timer_list[LLK_TIMER_SKIP_LIST_LEVEL] ; 

void llk_system_timer_init(void){
    // for (int i = 0; i < sizeof(llk_timer_list) / sizeof(llk_timer_list[0]); i++)
    //     llk_threadlist_init(llk_timer_list + i);


    w_mie(r_mie() | MIE_MTIE);   // Machine-mode time interrupt enable
    // w_mstatus(r_mstatus() | MSTATUS_MIE);
}

void llk_hw_timer_init(void) {
    
} 

// interrupt when (mtime = mtime + interval)
void llk_hw_timer_load(int interval){
    int id = 0 ;    // CPU ID
    *(uint64 *)CLINT_MTIMECMP(id) = *(uint64 *)CLINT_MTIME + interval ;
}

// hard ware timer handler
void llk_hw_timer_handler(void){
    llk_tick ++ ;

    // printf("llk_tick = %d", llk_tick) ;
    llk_hw_timer_load(CLINT_TIMEBASE_FREQ) ;
}


