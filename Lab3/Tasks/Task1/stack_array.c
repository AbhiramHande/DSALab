#include "element.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 1000

struct Stack {
    int top;
    Element data[STACK_SIZE];
};

Stack *newStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s != NULL)
        s->top = -1;
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
    if(s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}

bool isEmpty(Stack *s) {
    if(s->top == -1)
        return true;
    else 
        return false;
}

Element *pop(Stack *s) {
    if(isEmpty(s))
        return NULL;
    Element *e = &(s->data[(s->top)--]);
    return e;
}

Element *top(Stack *s) {
    if(isEmpty(s))
        return NULL;
    Element *e = &(s->data[(s->top)]);
    return e;
}

void freeStack(Stack *s) {
    s->top = -1; 
}

// void main() {
//     Stack *s = newStack();
//     for(int i=0; i < 10; i++){
//         Element e = newElement(i, i+2.34);
//         push(s, e);
//     }

//     Element *e = pop(s);
//     if(e != NULL)
//         printf("%d %f \n", e->int_value, e->float_value);
//     else
//         printf("Stack is Empty \n");

//     e = top(s);
//     if(e != NULL)
//         printf("%d %f \n", e->int_value, e->float_value);
//     else 
//         printf("Stack is Empty \n");

//     if(isEmpty(s))
//         printf("Stack is Empty \n");
//     else
//         printf("Stack is not empty \n");

//     freeStack(s);
//     if(isEmpty(s))
//         printf("Stack is Empty \n");
//     else
//         printf("Stack is not empty \n");

//     e = pop(s);
//     if(e != NULL)
//         printf("%d %f \n", e->int_value, e->float_value);
//     else
//         printf("Stack is Empty \n");
    
//     e = top(s);
//     if(e != NULL)
//         printf("%d %f \n", e->int_value, e->float_value);
//     else 
//         printf("Stack is Empty \n");
// }