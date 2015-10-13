#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

void printl(List* l) {
    Node* n;

    printf("l -> ");

    for (n = l->head; n; n = n->next) {
        printf("[%d]%s", n->data, n->next ? "->" : "¬");
    }

    printf("\n");
}

void printe(Node* n) {
    if (n != NULL) {
        printf("[%d]%s", n->data, n->next ? "->#\n" : "¬\n");
    }
}

void helper(void) {
    printf("uso: PROG [argumentos]\n"
        "\nonde os argumentos são:"
        "\n\t i n   : Insere o número 'n' na posição 'i' da lista."
        "\n\t-i     : Remove o elemento na posição 'i' da lista."
        "\n\t f n   : Busca o primeiro 'n' na lista e o imprime."
        "\n\t c n   : Imprime a quantidade de ocorrências de 'n' na lista."
        "\n\t r     : Inverte a ordem dos elementos na lista."
        "\n\t print : Imprime a lista.\n");
}

int main(int argc, char** argv) {
    if (argc < 2) {
        helper();
        return PARAM_E;
    }

    int i;
    List *l = list_create();

    if (l == NULL) {
        return MEMORY_E;
    }

    for (i = 1; i < argc; i++) {
        switch (argv[i][0]) {
            case 'f':
                printe(list_find(l, atoi(argv[++i])));
            break;

            case 'c':
                printf("%d\n", list_count(l, atoi(argv[++i])));
            break;

            case 'p':
                if (!strcmp(argv[i], "print")) {
                    printl(l);
                }
            break;

            case '-':
                list_remove(l, -atoi(argv[i]));
            break;

            case 'r':
                list_reverse(l);
            break;

            default:
                list_insert(l, atoi(argv[i]), atoi(argv[i+1]));
                i++;
            break;
        }
    }

    list_destroy(l);

    return SUCCESS;
}
