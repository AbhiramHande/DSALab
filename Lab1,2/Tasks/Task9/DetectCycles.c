#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODE;
typedef struct linked_list* LIST;

struct node{
    int ele;
    NODE next;
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
    return myNode;
}

void insertFirst(NODE n1, LIST l1) {
    if(l1->head==NULL) {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }

    else {
        NODE temp = l1->head;
        l1->head = n1;
        n1->next = temp;
        l1->count++;
    }
}

void createCircularLinkedList(LIST l1) {
    NODE temp = l1->head;
    for(;temp->next != NULL; temp = temp->next);
    temp->next = l1->head;
}

void printList(LIST l1) {
    NODE temp = l1->head;
    printf("[HEAD] ->");
    for(int i = 0;temp != NULL && i < 30; i++) {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }   
    printf(" [NULL]\n");
    return;
}

void hasCycles(LIST l) {
    NODE tort = l->head;
    NODE hare = l->head->next;

    while(hare->next != NULL && hare->next->next != NULL) {
        if(hare == tort) {
            printf("There is a loop. \n");
            return;
        }
        else{
            hare = hare->next->next;
            tort = tort->next;
        }
    }

    printf("There is no cycles in the linked list. \n");
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

    for(int i=1; i<10; i++) {
        NODE n = createNewNode(i);
        insertFirst(n, l);
    }
    createCircularLinkedList(l);

    printList(l);
    hasCycles(l);
    deleteList(l);
}