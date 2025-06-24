#ifndef __ATOMIC_
#define __ATOMIC_

#include "include/lib/types.h"
#include <stdatomic.h>

static inline uint32 Atomic_Add(uint32 *ptr, uint32 val){
    return atomic_fetch_add(ptr, val) ;
}

static inline uint32 Atomic_Sub(uint32 *ptr, uint32 val){
    return atomic_fetch_sub(ptr, val) ;
}

static inline uint32 Atomic_Or(uint32 *ptr, uint32 val){
    return atomic_fetch_or(ptr, val) ;
}

static inline uint32 Atomic_Xor(uint32 *ptr, uint32 val){
    return atomic_fetch_xor(ptr, val) ;
}

static inline uint32 Atomic_And(uint32 *ptr, uint32 val){
    return atomic_fetch_and(ptr, val) ;
}

#endif

