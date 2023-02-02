#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct node {
    Item data;
    struct node *prev;
    struct node *next;
} node;

typedef struct {
    int size;
    struct node *first;
    struct node *last;
} Doubly_linked_list;

void push_after_node(Doubly_linked_list *list, node *aux, Item add) {
    node *n = malloc(sizeof(node));

    n->data = add;
    n->prev = aux;
    n->next = aux->next;

    if(n->next == NULL)
        list->last = n;

    aux->next = n;
    list->size++;
}

Doubly_linked_list *create_list() {
    Doubly_linked_list *list = malloc(sizeof(Doubly_linked_list));

    list->size = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}

void insert_first_node(Doubly_linked_list *list, Item add) {
    node *n = malloc(sizeof(node));

    if(list->first != NULL)
        list->first->prev = n;
    
    if(list->last == NULL)
        list->last = n;

    n->data = add;
    n->prev = NULL;
    n->next = list->first;

    list->first = n;
    list->size++;
}