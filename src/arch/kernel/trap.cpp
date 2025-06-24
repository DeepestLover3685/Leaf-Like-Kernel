#include "../../../include/arch/kernel/trap.h"

extern void time_interrupt_func(void) ;

void llk_trap_init(void){
    // w_mtvec((llk_reg_t)time_interrupt_func) ;
}

// llk_reg_t llk_trap_handle(llk_reg_t epc, llk_reg_t cause){
//     llk_reg_t return_pc = epc ;

// }

void time_interrupt_func(void){
    
}

