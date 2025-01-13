#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"

typedef struct node Node;
typedef struct node* NODE;
typedef struct list* LIST;
typedef struct list list;

struct node{
    student* data;
    NODE next;
};

struct list{
    int count;
    NODE head;
};

//Creates a new Linked list and returns a pointer to it
LIST createNewList();

//Creates a new node and returns a pointer to it
NODE createNewNode(student* data);

//Inserts the node into the beginning of the linked list
void insertAtStart(LIST list, NODE node);

//Inserts the node at the end of the linked list
void insertAtEnd(LIST list, NODE node);

//Inserts the node at the position specified by the user.
//If successful retuns true, else retuens false.
bool insertAt(LIST list, NODE node, unsigned int position);

//Removes the node at the beginning of the list and frees the memory allocated to it.
//Returns true if a node was removed else retuens false. 
//Unlike Array indexing, the head of the linked list will be position 1.
bool removeFromBeginning(LIST list);

//Retrives the pointer to the node at the given position
//Returns NULL if the poistion specified is invalid
//Unlike Array indexing, the head of the linked list will be position 1.
NODE returnNode(LIST list, int poisition);

//Destroys the contents of the linked list and the list itself.
//Frees all the memory allocated for each node and the list.
void destroyList(LIST list);

#endif
