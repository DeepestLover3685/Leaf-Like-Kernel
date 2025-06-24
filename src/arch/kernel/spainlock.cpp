#include "../../../include/arch/kernel/spainlock.h"

void llk_push_off(void){
    int old = intr_get() ;

    intr_off() ;
    if(llk_get_cpu()->noff == 0)
        llk_get_cpu()->intena = old ;

    llk_get_cpu()->noff += 1 ;
}

void llk_pop_off(void){

}


