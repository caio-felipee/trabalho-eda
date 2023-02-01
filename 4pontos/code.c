#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct Linked_list {
    Item *item;
    Linked_list *next;
} Linked_list;

typedef struct {
    Linked_list *top;
    int size;
} Stack;

Linked_list *top(Stack *s) {
    if(!s->size)
        return NULL;

    return s->top;
}

void pop(Stack *s) {
    if(!s->size)
        return;
    
    
    
    s->top = s->top->next;
}

void push(Stack *s, Item *item) {
    
}