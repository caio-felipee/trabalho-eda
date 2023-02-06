#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Item;

typedef struct node {
    Item value;
    struct node *next;
} node;

typedef struct {
    struct node *first;
} Linked_list;

node *identifiers[5001] = { NULL };

node *create_node(Item identifier, Item value, node *next) {
    node *n = malloc(sizeof(node));

    n->value = value;
    n->next = next;

    identifiers[identifier] = n;

    return n;
}

Linked_list *create_list() {
    Linked_list *l = malloc(sizeof(Linked_list));

    l->first = NULL;

    return l;
}

void create_or_update_node(Item identifier, Item value, node *next) {
    node *n = identifiers[identifier];

    if(n == NULL)
        n = create_node(identifier, value, next);
    else {
        n->value = value;
        n->next = next;
    }
}

int main(void) {
    Linked_list *list = create_list();
    node *next;

    int n, id, value, next_id;

    scanf("%d", &n);
    scanf(" %d %d %d", &id, &value, &next_id);

    if(next_id > 0)
        next = create_node(next_id, 0, NULL);
    else
        next = NULL;

    list->first = create_node(id, value, next);

    n--;

    while(n--) {
        scanf(" %d %d %d", &id, &value, &next_id);

        if(next_id > 0)
            next = identifiers[next_id];
        else
            next = NULL;

        if(next_id > 0 && next == NULL)
            next = create_node(next_id, 0, NULL);
        
        create_or_update_node(id, value, next);
    }

    node *aux = list->first;

    while(aux != NULL) {
        printf("%d\n", aux->value);

        aux = aux->next;
    }
}