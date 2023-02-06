#include <stdio.h>
#include <stdlib.h>

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

Linked_list *create_list() {
    Linked_list *l = malloc(sizeof(Linked_list));

    l->size = 0;
    l->first = NULL;
    l->last = NULL;

    return l;
}

void insert_tower(Linked_list *list, int line, int column) {
    Tower *tower = malloc(sizeof(Tower));

    tower->line = line;
    tower->column = column;
    tower->next == NULL;

    if(list->first == NULL)
        list->first = tower;
    
    else
        list->last->next = tower;

    list->last = tower;
    list->size++;
}

int main(void) {
    Linked_list *list_towers = create_list();

    int lines, columns, visible = 0;

    scanf("%d %d", &lines, &columns);

    char map[lines][columns];

    for(int i = 0; i < lines; i++) {
        for(int j = 0; j < columns; j++) {
            scanf(" %c", &map[i][j]);

            if(map[i][j] == 't')
                insert_tower(list_towers, i, j);
        }
    }

    Tower *aux = list_towers->first;
    int h;

    while(aux != NULL) {
        scanf(" %d", &h);

        for(int i = aux->line - h; i <= aux->line + h; i++) {
            if(i < 0 || i >= lines)
                continue;
            
            for(int j = aux->column - h; j <= aux->column + h; j++) {
                if(j < 0 || j >= columns || map[i][j] != '#')
                    continue;

                map[i][j] = '.';
                visible++;
            }
        }

        aux = aux->next;
    }
    
    printf("%d\n", visible);

    for(int i = 0; i < lines; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%c", map[i][j]);
        }

        printf("\n");
    }
}