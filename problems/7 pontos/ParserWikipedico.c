#include <stdio.h>
#include <stdlib.h>
#define SIZE 50000

int top = -1;

void push(char *stack, int *top, char item) {
    *top = *top + 1;

    stack[*top] = item;
}

void pop(char *stack, int *top) {
    *top = *top - 1;
}

int main(void) {
    int N;

    scanf("%d%*c", &N);

    char *stack = malloc(sizeof(char) * SIZE), tmp;
    while(N--) {

        while(scanf("%c", &tmp) != EOF && tmp != '\n') {
            if(tmp == '*' || tmp == '_' || tmp == '/')
                if(stack[top] == tmp)
                    pop(stack, &top);
                else
                    push(stack, &top, tmp);
        }
    }

    if(top == -1)
        printf("C\n");
    else
        printf("E\n");

    return 0;
}