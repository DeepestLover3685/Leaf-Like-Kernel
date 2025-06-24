#ifndef __SPAINLOCK_H
#define __SPAINLOCK_H

#include "../../arch/kernel/riscv.h"
#include "./atomic.h"

class llk_spainlock{
public:
    llk_spainlock(char *name){
        this->name = name ;
        this->lock_flag =  0 ;
    }

    llk_spainlock_t get_spainlock_flag(void){
        return this->lock_flag ;
    }

    llk_cpu *get_spainlock_cpu(void){
        return this->cpu ;
    }

    // int holding(void){
    //     int result ;
    //     result = (this->lock_flag && this->cpu == llk_get_cpu()) ;
    //     return result ; 
    // }

    void spainlock_acquire(void){
        llk_push_off() ;    // disable interrupts
        // if(holding())
        //     ; 
        while(__sync_lock_test_and_set(&this->lock_flag, 1) != 0)    // wait for spainlock
            ; 
        __sync_synchronize() ;
        this->cpu = llk_get_cpu() ;
    }

    void spainlock_release(void){
        
    }

private:
    llk_spainlock_t             lock_flag ; 

    char                        *name ;
    llk_cpu                     *cpu ;
} ;

#endif
