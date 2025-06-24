#ifndef __RISCV_H
#define __RISCV_H

#include "./platform.h"
#include "../../lib/types.h"

/*
    sstatus(Supervisor Status Register)
*/
#define SSTATUS_SPP             (1L << 8)   // Previous mode, 1=Supervisor, 0=User
#define SSTATUS_SPIE            (1L << 5)   // Supervisor Previous Interrupt Enable
#define SSTATUS_UPIE            (1L << 4)   // User Previous Interrupt Enable
#define SSTATUS_SIE             (1L << 1)   // Supervisor Interrupt Enable
#define SSTATUS_UIE             (1L << 0)   // User Interrupt Enable

static inline llk_reg_t r_sstatus() {
  llk_reg_t x;
  asm volatile("csrr %0, sstatus" : "=r" (x) );
  return x;
}

static inline void w_sstatus(llk_reg_t x) {
  asm volatile("csrw sstatus, %0" : : "r" (x));
}

/*
    tp(thread pointer)
*/
static inline llk_reg_t r_tp() {
  llk_reg_t x;
  asm volatile("mv %0, tp" : "=r" (x) );
  return x;
}

static inline void w_tp(llk_reg_t x){
  asm volatile("mv tp, %0" : : "r" (x));
}

static inline llk_reg_t r_ra(){
  llk_reg_t x;
  asm volatile("mv %0, ra" : "=r" (x) );
  return x;
}

static inline int llk_get_cpuid(void){
    int cpuid = r_tp() ;
    return cpuid ;
}

llk_cpu *llk_get_cpu(void){
    int cpuid = llk_get_cpuid() ;
    llk_cpu *cpu = &cpus[cpuid] ;
    return cpu ;
}

/*
    mstatus(Machine Status Register)
*/
#define MSTATUS_MPP_MASK        (3L << 11)  // previous mode.
#define MSTATUS_MPP_M           (3L << 11)
#define MSTATUS_MPP_S           (1L << 11)
#define MSTATUS_MPP_U           (0L << 11)
#define MSTATUS_MIE             (1L << 3)   // machine-mode interrupt enable.

static inline llk_reg_t r_mstatus(){    
    llk_reg_t x ;
    asm volatile("csrr %0, mstatus" : "=r" (x)) ;
    return x ;
}

static inline void w_mstatus(llk_reg_t x){
	asm volatile("csrw mstatus, %0" : : "r" (x));
}

/*
    Machine-mode Interrupt Vector
*/
static inline void w_mtvec(llk_reg_t x){
	asm volatile("csrw mtvec, %0" : : "r" (x));
}

/*
    Machine-mode Interrupt Enable(mie)
*/
#define MIE_MEIE                (1 << 11)   // external
#define MIE_MTIE                (1 << 7)    // timer
#define MIE_MSIE                (1 << 3)    // software

static inline llk_reg_t r_mie(){
    llk_reg_t x ;
    asm volatile("csrr %0, mie" : "=r" (x)) ;
    return x ;
}

static inline void w_mie(llk_reg_t x){
	asm volatile("csrw mie, %0" : : "r" (x));
}

// Machine-mode Cause Masks


// 



// enable device interrupts
static inline void intr_on(){
    w_sstatus(r_sstatus() | SSTATUS_SIE);
}

// disable device interrupts
static inline void intr_off(){
    w_sstatus(r_sstatus() & ~SSTATUS_SIE);
}

// are device interrupts enabled?
static inline int intr_get() {
    llk_reg_t x = r_sstatus();
    return (x & SSTATUS_SIE) != 0;
}


#endif 
