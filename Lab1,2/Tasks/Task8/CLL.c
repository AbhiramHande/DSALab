#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODE;
typedef struct linked_list* LIST;

struct node{
    int ele;
    NODE next;
    NODE prev;
};

struct linked_list{
    int count;
    NODE head;
};

LIST createNewList() {
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    myList->head=NULL;
    return myList;
}

NODE createNewNode(int value) {
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->ele=value;
    myNode->next=NULL;
    myNode->prev=NULL;
    return myNode;
}

void printList(LIST l1) {
    NODE temp = l1->head;
    printf("[HEAD] ->");

    for(int i=0; i < l1->count; i++) {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }   
    printf(" [NULL]\n");
    return;
}

void insertFirst(NODE n1, LIST l1) {
    if(l1->head==NULL) {
        l1->head = n1;
        n1->next = NULL;
        n1->prev = NULL;
        l1->count++;
    }
    else if(l1->count == 1){
        NODE n0 = l1->head;
        l1->head = n1;
        n1->prev = n0;
        n1->next = n0;
        n0->prev = n1;
        n0->next = n1;
        l1->count++;
    }
    else {
        NODE temp = l1->head;
        l1->head = n1;
        temp->prev->next = n1;
        n1->prev = temp->prev;
        n1->next = temp;
        temp->prev = n1;
        l1->count++;
    }
}

void rotate(LIST l1){
    if(l1->count==0 || l1->count==1)
        return;
    else{
        NODE temp = l1->head;
        l1->head = temp->next;
    }
}

void rotateMultipleTimes(int k, LIST l1){
    for(int i=0; i<k; i++){
        rotate(l1);
    }
}

void deleteList(LIST list){
    NODE ptr = list->head;
    while(list->count != 0){
        NODE temp = ptr->next;
        free(ptr);
        ptr = temp;
        list->count--;
    }
    free(list);
}

int main() {
    LIST l = createNewList();
    for(int i=1; i<6; i++) {
        NODE n = createNewNode(i);
        insertFirst(n, l);
    }

    printList(l);
    rotate(l);
    printList(l);
    rotateMultipleTimes(3, l);
    printList(l);
    deleteList(l);
}
