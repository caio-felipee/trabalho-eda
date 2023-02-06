# Upsolving - Torre de observação

O problema é bem simples e envolve uma array em duas dimensões para a criação de um mapa. Os principais desafios desta questão é ter a visão de como contornar um ponto em um sistema cartesiano e a criação de um método dinâmico para acesso das torres, uma vez que para a alocação deste, não temos a informação de quanto espaço teremos que guardar na memória. Por conta disto, foi criado uma lista encadeada simples.

```c
typedef struct Tower {
    int line;
    int column;
    struct Tower *next;
} Tower;

typedef struct {
    int size;
    struct Tower *first;
    struct Tower *last;
} Linked_list;
```