#include "linked_list.h"

LIST createNewList(){
    LIST linked_list = (LIST)malloc(sizeof(list));
    linked_list->count = 0;
    linked_list->head = NULL;
    return linked_list;
}

NODE createNewNode(student* data){
    NODE node = (NODE)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAtStart(LIST list, NODE node){
    NODE head = list->head;
    list->head = node;
    node->next = head;
    list->count++;
    return;
}

void insertAtEnd(LIST list, NODE node){
    //Case 1: List is empty
    if(list->head == NULL){
        list->head = node;
        node->next = NULL;
        list->count++;
        return;
    }

    //Case 2: List is not empty
    else{
        NODE ptr = list->head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = node;
        node->next = NULL;
        list->count++;
        return;
    }    
}

bool insertAt(LIST list, NODE node, int position){

}

NODE returnNode(LIST list, int position){
    NODE ptr = list->head;
    while(ptr != NULL){
        if(position == 1)
            return ptr;
        ptr = ptr->next;
        position--;
    }
    return NULL;
}

bool removeFromBeginning(LIST list){
    if(list->head == NULL)
        return false;
    
    NODE head = list->head;
    list->head = head->next;
    head->next = NULL;
    free(head->data);
    free(head);
    list->count--;
    return true;
}

void destoryList(LIST list){
    while(removeFromBeginning(list));
}