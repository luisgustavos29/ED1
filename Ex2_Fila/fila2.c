#include <stdio.h>
#include "fila2.h"

void Inicializa_fila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int E_vazia(Fila* f) {
    return f->tamanho == 0;
}

int E_cheia(Fila* f) {
    return f->tamanho == TAM_MAX;
}

void Enfileira(Fila* f, int elem) {
    if (E_cheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    f->info[f->fim] = elem;
    f->fim = (f->fim + 1) % TAM_MAX;
    f->tamanho++;
}

int Desenfileira(Fila* f, int* elem) {
    if (E_vazia(f)) return 0;

    *elem = f->info[f->inicio];
    f->inicio = (f->inicio + 1) % TAM_MAX;
    f->tamanho--;
    return 1;
}

int Consulta_fila(Fila* f, int* elem) {
    if (E_vazia(f)) return 0;

    *elem = f->info[f->inicio];
    return 1;
}

void Exibe(Fila* f) {
    if (E_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    int i = f->inicio;
    while (i != f->fim) {
        printf("%d ", f->info[i]);
        i = (i + 1) % TAM_MAX;
    }
    printf("\n");
}
