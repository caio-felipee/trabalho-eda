#include <stdio.h>
#define swap(A, B) { int t = A; A = B; B = t; }

int plates[100] = { -1 }, index = 0;

void insert_plate(int plate) {
    int aux = index;

    if(index == 100)
        if(plate > plates[index - 1])
            return;
        else
            aux--;
    else
        index++;

    plates[aux] = plate;

    while(aux > 0 && (plates[aux - 1] == -1 || plates[aux - 1] > plates[aux])) {
        swap(plates[aux], plates[aux - 1]);
        
        aux--;
    }
}

int main(void) {
    int action, aux;

    while(scanf(" %d %d", &action, &aux) != EOF)
        if(action == 2)
            for(int i = 0; i < aux; i++)
                printf("%d%c", plates[i], i + 1 < aux ? ' ' : '\n');
        else
            insert_plate(aux);

    return 0;
}