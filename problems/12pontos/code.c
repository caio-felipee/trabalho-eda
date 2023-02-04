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
    char reversed;
    struct node *first;
    struct node *last;
} Queue;

/*
* Fixing implicit call function error
*/

void push_back(Queue *queue, Item data, char called_directly);
void append(Queue *queue, Item data, char called_directly);
void reverse(Queue *queue);
Item front(Queue *queue, char called_directly);
Item back(Queue *queue, char called_directly);

void push_back(Queue *queue, Item data, char called_directly) {
    if(called_directly && queue->reversed)
        return append(queue, data, 0);

    node *n = malloc(sizeof(node));

    n->data = data;
    n->prev = queue->last;
    n->next = NULL;

    if(queue->last != NULL)
        queue->last->next = n;

    queue->last = n;

    if(queue->first == NULL)
        queue->first = queue->last;
    
    queue->size++;
}

void append(Queue *queue, Item data, char called_directly) {
    if(called_directly && queue->reversed)
        return push_back(queue, data, 0);
    
    node *n = malloc(sizeof(node));

    n->data = data;
    n->prev = NULL;
    n->next = queue->first;

    if(queue->first != NULL)
        queue->first->prev = n;

    queue->first = n;

    if(queue->last == NULL)
        queue->last = queue->first;

    queue->size++;
}

void reverse(Queue *queue) {
    queue->reversed = queue->reversed ? 0 : 1;
}

Item front(Queue *queue, char called_directly) { // removes and returns the removed Item.
    if(called_directly && queue->reversed)
        return back(queue, 0);
    
    node *aux = queue->first;
    Item data = aux->data;

    queue->first = aux->next;
    queue->size--;
    
    if(queue->first != NULL)
        queue->first->prev = NULL;

    free(aux);

    return data;
}

Item back(Queue *queue, char called_directly) {
    if(called_directly && queue->reversed)
        return front(queue, 0);
    
    node *aux = queue->last;
    Item data = aux->data;

    queue->last = aux->prev;
    queue->size--;

    if(queue->last != NULL)
        queue->last->next = NULL;

    free(aux);

    return data;
}

int is_empty(Queue *queue) {
    return queue->size == 0;
}

Queue *create_queue() {
    Queue *q = malloc(sizeof(Queue));

    q->size = 0;
    q->reversed = 0;
    q->first = NULL;
    q->last = NULL;

    return q;
}

int strcmp(char *str1, char *str2) {
    int index = 0;

    while(str1[index] == str2[index]) {
        if(str1[index++] == '\0')
            return 1;
    }

    return 0;
}

int main(void) {
    Queue *queue = create_queue();

    char str[10];
    int N, tmp;

    scanf("%d", &N);

    while(N--) {
        scanf(" %s", str);

        if(strcmp(str, "toFront")) {
            scanf(" %d", &tmp);

            append(queue, tmp, 1);
        }

        else if(strcmp(str, "push_back")) {
            scanf(" %d", &tmp);

            push_back(queue, tmp, 1);
        }

        else if(strcmp(str, "reverse")) 
            reverse(queue);
        
        else {
            if(is_empty(queue))
                printf("No job for Ada?\n");
            
            else if(strcmp(str, "front"))
                printf("%d\n", front(queue, 1));
            
            else
                printf("%d\n", back(queue, 1));
        }
    }
}