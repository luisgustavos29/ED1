#include <stdio.h>
#include "fila_cr7.h"

    // Inicializa a fila
    void Inicializa_filaCR7(FilaCR7* f) {
        f->inicio = 0;
        f->fim = 0;
        f->tamanho = 0;
    }

    // Adiciona um fã na fila
    int EnfileiraCR7(FilaCR7* f, int id) {
        if (E_cheiaCR7(f)) {
            printf("Fila cheia!\n");
            return 0; // Falha ao enfileirar
        }
        f->ids[f->fim] = id;
        f->fim = (f->fim + 1) % TAM_MAX;
        f->tamanho++;
        printf("Fã com ID %d adicionado à fila!\n", id);
        return 1; // Sucesso ao enfileirar
    }

    // Remove o fã na frente da fila
    int DesenfileiraCR7(FilaCR7* f, int* id) {
        if (E_vaziaCR7(f)) return 0;

        *id = f->ids[f->inicio];
        f->inicio = (f->inicio + 1) % TAM_MAX;
        f->tamanho--;
        printf("Fã removido da fila: %d\n", *id);
        return 1;
    }

    // Verifica se a fila está vazia
    int E_vaziaCR7(FilaCR7* f) {
        return f->tamanho == 0;
    }

    // Verifica se a fila está cheia
    int E_cheiaCR7(FilaCR7* f) {
        return f->tamanho == TAM_MAX;
    }

    // Mostra a fila
    void ExibeCR7(FilaCR7* f) {
        if (E_vaziaCR7(f)) {
            printf("Fila vazia!\n");
            return;
        }

        int count = 0;
        int i = f->inicio;
        while (count < f->tamanho) { //conta os elementos até o tamanho da fila
            printf("%d ", f->ids[i]);
            i = (i + 1) % TAM_MAX;
            count++;
        }
        printf("\n");
    }
