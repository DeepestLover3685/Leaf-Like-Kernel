#ifndef __LIST_H
#define __LIST_H

struct llk_list_node                                                                                    // create thread node
{   
    struct llk_list_node* prevNode ;
    struct llk_list_node* nextNode;
};

typedef struct llk_list_node llk_thread_list;                                                           // struct llk_list_node -> llk_thread_list
typedef struct llk_list_node llk_time_list ;                                                            // struct llk_list_node -> llk_time_list

void llk_threadlist_init(llk_thread_list *thread_list) ;                                                // thread list init
void llk_threadlist_insert_before(llk_thread_list *thread_list, llk_thread_list *thread_node) ;         // insert node before head
void llk_threadlist_insert_after(llk_thread_list *thread_list, llk_thread_list *thread_node) ;          // insert node after head
void llk_threadlist_delete(llk_thread_list *thread_list) ;                                              // delete node after head

#endif
