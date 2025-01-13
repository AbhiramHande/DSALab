#include "linked_list.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct Stack {
    LIST list;
};

Stack *newStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    LIST l = createNewList();
    s->list = l; 
    return s;
}

Element newElement(int i_val, float f_val) {
    Element *e = (Element *)malloc(sizeof(Element));
    if(e != NULL)
        e->int_value = i_val;
        e->float_value = f_val;
    return *e;
}

bool push(Stack *s, Element e) {
    insertNodeIntoList(createNewNode(e), s->list);
    return true;
}

bool isEmpty(Stack *s) {
    return isLinkedListEmpty(s->list);
}

Element *pop(Stack *s) {
    if(isEmpty(s))
        return NULL;
    Element *head = &(s->list->head->data);
    removeFirstNode(s->list);
    return head;
}

Element *top(Stack *s) {
    if(isEmpty(s))
        return NULL;
    Element *head = &(s->list->head->data);
    return head;
}

void freeStack(Stack *s) {
    destroyList(s->list);
    free(s);
}
