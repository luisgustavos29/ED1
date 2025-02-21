#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    Fila* fila = Cria_fila();
    Fila* fila3 = Cria_fila();
    Fila* fila2 = Cria_fila();
    Fila* fila4 = Cria_fila();
    int opcao, elem;
    int tamanho_fila;

    if (fila == NULL || fila3 == NULL || fila2 == NULL || fila4 == NULL) {
        printf("Erro ao criar a fila!\n");
        return 1;
    }

    printf("Digite o tamanho da fila: ");
    scanf("%d", &tamanho_fila);

    printf("Digite os elementos da fila (separados por espaços): ");
    for (int i = 0; i < tamanho_fila; i++) {
        scanf("%d", &elem);
        Enfileira(fila, elem);
    }

    printf("Fila F (Original): ");
    Exibe(fila);

    while (!E_vazia(fila)) {
        if (Desenfileira(fila, &elem)) {
            if (elem % 3 == 0) {
                Enfileira(fila3, elem);
            }
            if (elem % 2 == 0) {
                Enfileira(fila2, elem);
            }
            if (elem % 2 != 0 && elem % 3 != 0) {
                Enfileira(fila4, elem);
            }
        }
    }

    printf("Fila F3 (Múltiplos de 3): ");
    Exibe(fila3);

    printf("Fila F2 (Múltiplos de 2): ");
    Exibe(fila2);

    printf("Fila F4 (Outros): ");
    Exibe(fila4);

    Libera_fila(fila);
    Libera_fila(fila2);
    Libera_fila(fila3);
    Libera_fila(fila4);
    return 0;
}
