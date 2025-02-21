#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main() {
 struct arvore* arv = criar_arvore();
    char comando[10];
    char info;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &info);
            inserir(arv, info);
        } else if (strcmp(info, "INFIXA") == 0) {
            imprimir_infix(arv, arv->raiz);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            imprimir_prefix(arv, arv->raiz);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            imprimir_posfix(arv, arv->raiz);
            printf("\n");
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &info);
            if (buscar(arv, info)) {
                printf("%c existe\n", info);
            } else {
                printf("%c nao existe\n", info);
            }
        }
    }

    free(arv);
    return 0;
}
