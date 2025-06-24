#ifndef __THREAD_H
#define __THREAD_H

#include "../../include/lib/types.h"
#include "../kernel/platform.h"
#include "../../lib/error.h"
#include "../sched/timer.h"
#include "../kernel/list.h"
#include "../kernel/spainlock.h"

// thread state enum
enum class llk_thread_state{    
    READY ,
    RUNNING ,
    BLOCKED ,
    SLEEPING ,
    TERMINATED
} ;

// thread class
class llk_thread{
public:
    void setState(llk_thread_state stateTarget) {this->state = stateTarget ; }  // set thread state
    llk_thread_state getState(void) { return state; }                           // get thread state 

    // create thread stack

    // create thread
    llk_err_t init( void   (*entry)(void *),
                    void   *parameter,  
                    void   *stackAddr,
                    uint32 stackSize ){
        this->entry = entry ;
        this->parameter = parameter ;
        this->stack_addr = stackAddr ;
        this->stack_size = stackSize ;

        this->sp = llk_threadstack_init( entry, 
                                         parameter,
                                         stackAddr,
                                         stackSize );

        return ERR_OK ;
    } ; 

private:

    llk_object              thread_object ;

    llk_spainlock           spainlock ;             // thread spainlock

    void                    *sp ;                   // stack point  
    void                    (*entry)(void *) ;      // entry thread func
    void                    *parameter ;            // entry thread parameter
    void                    *stack_addr;            // stack top address

    uint32                  stack_size;             // stack size
    llk_list_node           *threadNode;            // thread list node
    llk_thread_state        state ;                 // thread state   

    uint16                  tid ;

    uint32                  timeSlice ;

    llk_timer               thread_timer ;
} ;

void* llk_threadstack_init( void (*entry)(void *), 
                            void *parameter, 
                            void *stack_addr, 
                            uint32 stack_size ) ;

#endif
