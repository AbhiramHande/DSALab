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

void insertAfter(int searchEle, NODE n1, LIST l1) {
    if(l1->head==NULL) {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }

    else {
        NODE temp = l1->head;
        NODE prev = temp;
        while(temp!=NULL) {
            if (temp->ele == searchEle)
                break;
            prev = temp;
            temp = temp->next;
        }

        if(temp==NULL) {
        printf("Element not found\n");
        return;
        }

        else {
            if(temp->next == NULL) {
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            }

            else {
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
            return;
        }
    }
    return;
}

void printList(LIST l1) {
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while(temp != NULL) {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }   
    printf(" [NULL]\n");
    return;
}

// Task 7b. Inserts a new node at the starting position of the linked list.
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

// Task 7c. Deletes the node at the starting position of the linked list.
void deleteFirst(LIST l1) {
    if(l1->head==NULL) {
        printf("Nothing to delete \n");
    }

    else {
        NODE temp = l1->head;
        l1->head = temp->next;
        temp->next = NULL;
        free(temp);
        l1->count--;
    }
}

// Task 7a. Deletes the node at the specified position.
void deleteAt(int n, LIST l1) {
    if(n == 1){
        deleteFirst(l1);
        return;
    }
    
    NODE prev_temp = l1->head;
    NODE curr_temp = prev_temp->next;

    for(int ct = 2; ct < n; ct++) {
        if(curr_temp->next == NULL){
            printf("Index out of bounds \n");
            return;
        }
        prev_temp->next = curr_temp;
        curr_temp = curr_temp->next;
        
    }

    prev_temp->next = curr_temp->next;
    curr_temp->next = NULL;

    free(curr_temp);
    free(prev_temp);
}

// Task 7d. Scans through the linked list for a specific value and returns the position of the node where the data is found
NODE search(int value, LIST l1){
    if(l1->head == NULL){
        printf("List is empty \n");
        NODE n = createNewNode(0);
        return n;
    }

    NODE output = l1->head;
    for(; output->next != NULL; output = output->next){
        if(output->ele == value) {
            return output;
        }
    }

    if(output->ele == value) {
        return output;
    }
    else
        printf("Element not found \n");
        NODE n = createNewNode(0);
        return n;
}

void deleteList(LIST list){
    NODE ptr = list->head;
    while(ptr != NULL){
        list->head = ptr->next;
        free(ptr);
        ptr = list->head;
    }
    free(list);
    return;
}

int main() {
    LIST l = createNewList();
    for(int i=1; i<6; i++) {
        NODE n = createNewNode(i);
        insertFirst(n, l);
    }

    LIST l2 = createNewList();
    NODE n1 = createNewNode(1);
    insertFirst(n1, l2);
    printList(l);
    deleteFirst(l);
    printList(l);
    deleteList(l); 
    deleteList(l2);
}