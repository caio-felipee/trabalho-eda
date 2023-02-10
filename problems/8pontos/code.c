#include <stdio.h>

#include <stdlib.h>

typedef int Item;

typedef struct Linked_list {
    Item item;
    struct Linked_list *next;
} Linked_list;

typedef struct {
    struct Linked_list *top;
    int size;
} Stack;

Stack *createStack() {
    Stack *s = malloc(sizeof(Stack));

    s->top = NULL;
    s->size = 0;

    return s;
}

Item top(Stack *s) {
    if(!s->size)
        return -1;

    return s->top->item;
}

void pop(Stack *s) {
    if(!s->size)
        return;
    
    Linked_list *aux = s->top;
    
    s->top = s->top->next;
    s->size--;

    free(aux);
}

void push(Stack *s, Item item) {
    Linked_list *aux = malloc(sizeof(Linked_list));

    aux->item = item;
    aux->next = s->top;

    s->top = aux;
    s->size++;
}

int main(void) {
    int N;

    while(scanf(" %d", &N) != EOF && N) {
        Item mobiles[N + 1], ans = 1;
        Stack *stack = createStack();

        for(int i = 0; i < N; i++)
            scanf(" %d", &mobiles[i]);
        
        Item queue = 1;
        int i = 0;

        while(queue <= N) {
            int t = top(stack);

            if(t == queue) {
                queue++;
                pop(stack);
            }

            else if(mobiles[i] != queue) {
                if(t != -1 && mobiles[i] > t) {
                    ans = 0;
                    break;
                }

                push(stack, mobiles[i++]);
            }

            else {
                i++;
                queue++;
            }
        }

        printf("%s\n", ans ? "yes" : "no");
    }
}