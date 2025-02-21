#include <stdio.h>
#include "fila2.h"

int main() {
    Fila F1, F2, F;
    Inicializa_fila(&F1);
    Inicializa_fila(&F2);
    Inicializa_fila(&F);

    int elem, num_elementos_f1, num_elementos_f2;
    int elem1, elem2;

    printf("Digite o número de elementos para a fila F1 (max %d): ", TAM_MAX);
    scanf("%d", &num_elementos_f1);

    printf("Digite os elementos da fila F1 (separados por espaços): ");
    for (int i = 0; i < num_elementos_f1; i++) {
        scanf("%d", &elem);
        Enfileira(&F1, elem);
    }

    printf("Digite o número de elementos para a fila F2 (max %d): ", TAM_MAX);
    scanf("%d", &num_elementos_f2);

    printf("Digite os elementos da fila F2 (separados por espaços): ");
    for (int i = 0; i < num_elementos_f2; i++) {
        scanf("%d", &elem);
        Enfileira(&F2, elem);
    }

    printf("Fila F1: ");
    Exibe(&F1);

    printf("Fila F2: ");
    Exibe(&F2);

    while (!E_vazia(&F1) || !E_vazia(&F2)) {
        if (!E_vazia(&F1) && !E_vazia(&F2)) {
            Consulta_fila(&F1, &elem1);
            Consulta_fila(&F2, &elem2);

            if (elem1 > elem2) {
                Desenfileira(&F1, &elem1);
                Enfileira(&F, elem1);
            } else {
                Desenfileira(&F2, &elem2);
                Enfileira(&F, elem2);
            }
        } else if (!E_vazia(&F1)) {
            Desenfileira(&F1, &elem1);
            Enfileira(&F, elem1);
        } else if (!E_vazia(&F2)) {
            Desenfileira(&F2, &elem2);
            Enfileira(&F, elem2);
        }
    }

    printf("Fila F (Maiores valores): ");
    Exibe(&F);

    return 0;
}
