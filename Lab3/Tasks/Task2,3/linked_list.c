#include "element.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

LIST createNewList() {
    LIST l = (LIST)malloc(sizeof(linked_list));
    if(l != NULL) {
        l->count = 0;
        l->head = NULL;
    }
    return l;
}

NODE createNewNode(Element e) {
    NODE n = (NODE)malloc(sizeof(node));
    if(n != NULL) {
        n->data = e;
        n->next = NULL;
    }
    return n;
}

void insertNodeIntoList(NODE n, LIST l) {
    NODE temp = l->head;
    l->head = n;
    n->next = temp;
    l->count++;
}

void removeFirstNode(LIST l) {
    if(l->head == NULL)
        return;

    NODE temp = l->head;
    l->head = temp->next;
    temp->next = NULL;
    free(temp);
    l->count--;
}

bool isLinkedListEmpty(LIST l) {
    if(l->head == NULL)
        return true;
    else
        return false;
}

void destroyList(LIST l) {
    while(!isLinkedListEmpty(l)){
        removeFirstNode(l);
    }
    free(l);
}