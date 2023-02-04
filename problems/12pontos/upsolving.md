# Upsolving - Ada and Queue

Consiste em um problema que envolve a Estrutura de Dados chamada fila, com algumas modificações. O principal desafio da questão estava em criar um método "reversível", no qual os últimos da fila se tornariam os primeiros e vice-versa. 

Para a resolução, utilizamos alocação dinâmica. Porém, isto é algo totalmente opcional, uma vez que são dados o número de queries realizadas e, portanto, o tamanho máximo da fila.

No decorrer da questão, enfrentamos alguns problemas pelo método que decidimos seguir. Um deles, por exemplo, foi o erro da chamada de uma função implícita. As funções, ao depender da reversibilidade, chamavam umas as outras e para isto, elas devem estar definidas logo no início.

```c
typedef int Item;

void push_back(Queue *queue, Item data, char called_directly);
void append(Queue *queue, Item data, char called_directly);
void reverse(Queue *queue);
Item front(Queue *queue, char called_directly);
Item back(Queue *queue, char called_directly);
```

Ademais, possuindo uma implementação de fila e pensando num algoritmo de baixa complexidade e de fácil acesso, o resto do processo foi tranquilo.

```c
typedef struct {
    int size;
    char reversed;
    struct node *first;
    struct node *last;
} Queue;
```