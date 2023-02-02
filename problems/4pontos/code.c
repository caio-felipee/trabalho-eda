#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct Linked_list {
    Item *item;
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

int strcmp(char *str1, char *str2) {
    int index = 0;

    while(str1[index] == str2[index]) {
        if(str1[index++] == '\0')
            return 1;
    }

    return 0;
}

Item *top(Stack *s) {
    if(!s->size)
        return NULL;

    return s->top->item;
}

void pop(Stack *s) {
    if(!s->size)
        return;
    
    Linked_list *aux = s->top;
    
    s->top = s->top->next;
    s->size--;

    free(aux->item);
    free(aux);
}

void push(Stack *s, Item *item) {
    Linked_list *aux = malloc(sizeof(Linked_list));

    aux->item = item;
    aux->next = s->top;

    s->top = aux;
    s->size++;
}

int main(void) {
    Stack *stack = createStack();
    char action[9];

    while(scanf("%s%*c", action) != EOF) {
        if(strcmp(action, "inserir")) {
            int index = 0;

            Item *str = malloc(sizeof(Item) * 101);

            while(scanf("%c", &str[index]) != EOF && str[index] != '\n')
                ++index;

            str[index] = '\0';

            /* 
            * Usamos o método do scanf para acessar rapidamente o tamanho da string,
            * uma vez que possui espaços para utilizar o `%s` e a função fgets
            * não ignoraria a quebra de linha.
            */

            push(stack, str);
        }

        else {
            Item *value = top(stack);

            if(value == NULL)
                printf("NULL\n");
            else
                printf("%s\n", value);
            
            pop(stack);
        }
    }

    return 0;
}