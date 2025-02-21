#include <stdio.h>
#include <stdlib.h>
#include "fila_encadeada.h"

// Inicializa a fila
void Inicializa_filaCR7(FilaCR7* f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

// Adiciona um fã na fila
int EnfileiraCR7(FilaCR7* f, int id) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Falha ao alocar memória!\n");
        return 0; // Falha ao enfileirar
    }

    novoNo->id = id;
    novoNo->proximo = NULL;

    if (E_vaziaCR7(f)) {
        f->inicio = novoNo;
    } else {
        f->fim->proximo = novoNo;
    }
    f->fim = novoNo;
    f->tamanho++;
    printf("Fã com ID %d adicionado à fila!\n", id);
    return 1; // Sucesso ao enfileirar
}

// Remove o fã na frente da fila
int DesenfileiraCR7(FilaCR7* f, int* id) {
    if (E_vaziaCR7(f)) return 0;

    No* temp = f->inicio;
    *id = temp->id;
    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL; // A fila ficou vazia
    }

    free(temp);
    f->tamanho--;
    printf("Fã removido da fila: %d\n", *id);
    return 1;
}

// Verifica se a fila está vazia
int E_vaziaCR7(FilaCR7* f) {
    return f->tamanho == 0;
}

// Mostra a fila
void ExibeCR7(FilaCR7* f) {
    if (E_vaziaCR7(f)) {
        printf("Fila vazia!\n");
        return;
    }

    No* atual = f->inicio;
    while (atual != NULL) {
        printf("%d ", atual->id);
        atual = atual->proximo;
    }
    printf("\n");
}
