# Upsolving - ctrl-z

É uma questão bem simples que envolve a Estrutura de Dados chamada pilha, pois ela que utiliza o método LIFO (Last-In, First Out).
Não era necessário utilizar alocação dinâmica. Porém, foi feita para poder reaproveitar a estrutura em alguma outra ocasião.

Para um melhor gerenciamento do texto recebido, não utilizamos `%s`, pois a entrada permitia o uso de blankspace.
Também não foi utilizada a função `fgets` pois eventuais quebras de linha não seriam ignoradas.

```c
if(strcmp(action, "inserir")) {
            int index = 0;

            Item *str = malloc(sizeof(Item) * 101);

            while(scanf("%c", &str[index]) != EOF && str[index] != '\n')
                ++index;

            str[index] = '\0';

            push(stack, str);
        }
```