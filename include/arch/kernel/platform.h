#ifndef __PLATFORM_H
#define __PLATFORM_H

#include "../thread/thread.h"

// cpu
#define NCPU                        8 

// uart
#define UART0                       0x10000000L
#define UART0_IRQ                   10

// virtio
#define VIRTIO0                     0x10001000
#define VIRTIO0_IRQ                 1

// clint
#define CLINT_BASE                  0x20000000L
#define CLINT_MTIME                 (CLINT_BASE + 0xbff8)
#define CLINT_MTIMECMP(hartid)      (CLINT_BASE + 0x4000 + 8 * (hartid))
#define CLINT_MSIP(hartid)          (CLINT_BASE + 4 * (hartid))

// 10000000 ticks(cycles) per-second
#define CLINT_TIMEBASE_FREQ         10000000 

// Saved registers for kernel context switches
struct context {
  uint64 ra ;       // function return address
  uint64 sp ;       // stack point
  uint64 pc ;       // program counter (entry)
  uint64 mstatus;   // status
  uint64 a0 ;       // argument (parameter)

  // callee-saved
  uint64 s0;
  uint64 s1;
  uint64 s2;
  uint64 s3;
  uint64 s4;
  uint64 s5;
  uint64 s6;
  uint64 s7;
  uint64 s8;
  uint64 s9;
  uint64 s10;
  uint64 s11;
} ;

// cpu state
class llk_cpu {
public :
    llk_thread      thread ;            // thread running on this cpu
    struct context  context ;           // 
    int             noff ;              // depth of push_off() nesting
    int             intena ;            // 
} ;

extern llk_cpu cpus[NCPU];

#endif

