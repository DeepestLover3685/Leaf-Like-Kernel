#include "../../include/arch/kernel/list.h"

void llk_threadlist_init(llk_thread_list *thread_list){
    thread_list->nextNode = thread_list->prevNode = thread_list ;
}


void llk_threadlist_insert_before(llk_thread_list *thread_list, llk_thread_list *thread_node){
    thread_list->nextNode->prevNode = thread_node ;
    thread_node->nextNode = thread_list->nextNode ;
    thread_list->nextNode = thread_node ;
    thread_node->prevNode = thread_list ;
}

void llk_threadlist_insert_after(llk_thread_list *thread_list, llk_thread_list *thread_node){
    thread_list->prevNode->nextNode = thread_node ;
    thread_node->prevNode = thread_list->prevNode ;
    thread_list->prevNode = thread_node ; 
    thread_node->nextNode = thread_list ;
}

void llk_threadlist_delete(llk_thread_list *thread_list){
    thread_list->nextNode->prevNode = thread_list->prevNode ;
    thread_list->prevNode->nextNode = thread_list->nextNode ;
    thread_list->nextNode = thread_list->prevNode = thread_list ; 
}



