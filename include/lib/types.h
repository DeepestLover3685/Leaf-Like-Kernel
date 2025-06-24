#ifndef __TYPES_H
#define __TYPES_H

// #include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>

typedef  unsigned char              uint8 ;
typedef  signed   char              sint8 ;
typedef  unsigned short             uint16 ;
typedef  signed   short             sint16 ;
typedef  unsigned int               uint32 ;
typedef  signed   int               sint32 ;
typedef  unsigned long long         uint64 ;
typedef  signed   long long         sint64 ;    

typedef  uint32                     RV32 ;
typedef  uint64                     RV64 ;
typedef  RV64                       RV ;

// object
class llk_object{
    char            name[sizeof(uint32)] ;
    uint8           type ;
    uint8           flag ;
    void            *module_id ;
} ;

// mem typedef
typedef RV                          llk_reg_t ;
typedef RV                          llk_ptr_t ;

// error typedef
typedef sint16                      llk_err_t ;

// clock & time typedef
typedef RV                          llk_time_t ;
typedef RV                          llk_tick_t ; 

// spainlock typedef
typedef RV                          llk_spainlock_t ;


#endif
