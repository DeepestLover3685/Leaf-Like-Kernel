#include "../../include/arch/thread/thread.h"

void* llk_threadstack_init( void (*entry)(void *), 
                            void *parameter, 
                            void *stack_addr, 
                            uint32 stack_size ){
    struct context  *context ;
    uint8           *stack_top ;

    stack_top = (uint8 *)stack_addr + sizeof(uint32); // get stack point adress
    stack_top = (uint8 *)((uint32)stack_top & ~0xF);
    stack_top -= sizeof(struct context) ; // reserve space for the context structure

    context = (struct context *)stack_top ;

    for(int i = 0 ; i < sizeof(context)/sizeof(uint64); i ++){ 
        ((uint32*) context)[i] = 0xDEADBEEF ;
    }

    // set essential fields
    context->ra = (uint64)0 ;
    context->pc = (uint64)entry ;
    context->a0 = (uint64)parameter ;
    context->mstatus = 0x1880 ; //?
    
    return stack_top;
}
