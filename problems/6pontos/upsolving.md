# Upsolving - Gomercindo detetive

Foi um problema bem simples de resolver, envolvia uma lista encadeada simples com o principal desafio de conseguir anexar um nó com o outro utilizando os seus índices. Como estes índices teriam o valor máximo confirmado de `5000`, não foi necessário utilizar um algoritmo de ordenação para fazer as buscas.

## Busca O(1) para cada nó

Para uma fácil busca, de complexidade constante, basta apenas criar uma variável que os índices de busca são os valores criados pela questão e seus valores, os ponteiros dos nós.

```c
typedef unsigned int Item;

typedef struct node {
    Item value;
    struct node *next;
} node;

node *identifiers[5001] = { NULL };
```
