#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* Cria_fila(void) {
    Fila* Ptf = (Fila*)malloc(sizeof(Fila));
    if (Ptf != NULL) {
        Ptf->IF = NULL;
        Ptf->FF = NULL;
        Ptf->tamanho = 0;
    }
    return Ptf;
}

void Libera_fila(Fila* f) {
    No* atual = f->IF;
    No* aux;
    while (atual != NULL) {
        aux = atual;
        atual = atual->prox;
        free(aux);
    }
    free(f);
}

int E_vazia(Fila* f) {
    return f->IF == NULL;
}

int E_cheia(Fila* f) {
    return 0;
}

void Enfileira(Fila* f, int elem) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) return;

    novo_no->info = elem;
    novo_no->prox = NULL;

    if (E_vazia(f)) {
        f->IF = novo_no;
    } else {
        f->FF->prox = novo_no;
    }
    f->FF = novo_no;
    f->tamanho++;
}

int Desenfileira(Fila* f, int* elem) {
    if (E_vazia(f)) return 0;

    No* aux = f->IF;
    *elem = aux->info;
    f->IF = aux->prox;

    if (f->IF == NULL) {
        f->FF = NULL;
    }

    free(aux);
    f->tamanho--;
    return 1;
}

int Consulta_fila(Fila* f, int* elem) {
    if (E_vazia(f)) return 0;

    *elem = f->IF->info;
    return 1;
}

void Exibe(Fila* f) {
    if (E_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    No* atual = f->IF;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}
