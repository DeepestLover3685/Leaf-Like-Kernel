#ifndef __TIME_H
#define __TIME_H

#include "../kernel/list.h"
#include "../../lib/error.h"
#include "../kernel/riscv.h"
#include "../kernel/platform.h"

#define LLK_TIMER_FLAG_DEACTIVATED           0x0                                         /**< timer is deactive */
#define LLK_TIMER_FLAG_ACTIVATED             0x1                                         /**< timer is active */

#define LLK_TIMER_FLAG_ONE_SHOT              0x0                                         /**< one shot timer */
#define LLK_TIMER_FLAG_PERIODIC              0x2                                         /**< periodic timer */

#define LLK_TIMER_FLAG_HARD_TIMER            0x0                                         /**< hard timer,the timer's callback function will be called in tick isr. */
#define LLK_TIMER_FLAG_SOFT_TIMER            0x4                                         /**< soft timer,the timer's callback function will be called in timer thread. */

#define LLK_TIMER_CTRL_SET_TIME              0x0                                         /**< set timer control command */
#define LLK_TIMER_CTRL_GET_TIME              0x1                                         /**< get timer control command */
#define LLK_TIMER_CTRL_SET_ONESHOT           0x2                                         /**< change timer to one shot */
#define LLK_TIMER_CTRL_SET_PERIODIC          0x3                                         /**< change timer to periodic */
#define LLK_TIMER_CTRL_GET_STATE             0x4                                         /**< get timer run state active or deactive*/
#define LLK_TIMER_CTRL_GET_REMAIN_TIME       0x5                                         /**< get the remaining hang time */
#define LLK_TIMER_CTRL_GET_FUNC              0x6                                         /**< get timer timeout func  */
#define LLK_TIMER_CTRL_SET_FUNC              0x7                                         /**< set timer timeout func  */
#define LLK_TIMER_CTRL_GET_PARM              0x8                                         /**< get timer parameter  */
#define LLK_TIMER_CTRL_SET_PARM              0x9                                         /**< set timer parameter  */

#define LLK_TIMER_SKIP_LIST_LEVEL            1

class llk_timer{
public:
    llk_err_t llk_timer_create(){
        
        return ERR_OK ;
    }

    llk_err_t init( const char  *name,
                    uint8       flag){
        // llk_obj_init() ;
        // _rt_timer_init() ;

        return ERR_OK ;
    }

// private:
    llk_object          timer_object ;
    llk_time_list       row[LLK_TIMER_SKIP_LIST_LEVEL] ;                                 // skip list

    void                (*timeout_func)(void *parameter) ;
    void                *parameter ;

    llk_tick_t          init_tick ;                                                     // The actual delay time required by the timer
    llk_tick_t          timeout_tick ;                                                  // The number of system beats when the timer actually times out
} ;

void llk_hw_timer_init(void) ;
void llk_system_timer_init(void) ;
void llk_hw_timer_load(int interval) ;
void llk_hw_timer_handler(void) ;

#endif
