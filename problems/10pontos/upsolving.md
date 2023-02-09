# Upsolving - Menores Placas

Este problema consiste mais em treinar a lógica do programador, uma vez que utiliza apenas um algoritmo de ordenação. Algo que é essencial prestar atenção: 

`• Ti (quantidade de placas a imprimir) 1 ≤ Ti ≤ 100`

O item supracitado te permite criar um vetor de 100 inteiros sem necessidade de se preocupar com as *placas* maiores que o centésimo número ordenado.

## Straight Insertion Sort

Para cada inserção, utilizamos o Straight Insertion Sort. O algoritmo é bem semelhante ao *Insertion Sort*, a única mudança é que ao invés de ordenar cada elemento do vetor, ordenaremos apenas o último (por conta da inserção de um item em um vetor já ordenado).

```c
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
}```