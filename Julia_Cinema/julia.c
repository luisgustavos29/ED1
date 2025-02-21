#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "julia.h"

const char *filmes[MAX_FILMES] = {
    "BATMAN O CAVALHEIRO DAS TREVAS",
    "ILHA DO MEDO",
    "A ORIGEM",
    "DEADPOOL X WOLVERINE",
    "HOMEM ARANHA SEM VOLTA PRA CASA"
};

Ingresso *inserirNaLista(Ingresso *lista, char *filme, int assento) {
    Ingresso *novoIngresso = (Ingresso *)malloc(sizeof(Ingresso));
    strcpy(novoIngresso->filme, filme);
    novoIngresso->assento = assento;
    novoIngresso->proximo = lista;
    novoIngresso->anterior = NULL;

    if (lista != NULL) {
        lista->anterior = novoIngresso;
    }
    return novoIngresso;
}

Ingresso *removerDaLista(Ingresso *lista, char *filme, int assento) {
    Ingresso *atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->filme, filme) == 0 && atual->assento == assento) {
            if (atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo;
            } else {
                lista = atual->proximo;
            }
            if (atual->proximo != NULL) {
                atual->proximo->anterior = atual->anterior;
            }
            free(atual);
            return lista;
        }
        atual = atual->proximo;
    }
    return lista;
}

Ingresso *adicionarIngressoVendido(Ingresso *listaVendidos, char *filme, int assento) {
    return inserirNaLista(listaVendidos, filme, assento);
}

Ingresso *cancelarIngresso(Ingresso *listaVendidos, Ingresso *listaDisponiveis, char *filme, int assento) {
    listaVendidos = removerDaLista(listaVendidos, filme, assento);
    return inserirNaLista(listaDisponiveis, filme, assento);
}

void listarIngressosDisponiveis(Ingresso *listaDisponiveis, char *filme) {
    Ingresso *atual = listaDisponiveis;
    printf("Ingressos disponíveis para %s:\n", filme);
    while (atual != NULL) {
        if (strcmp(atual->filme, filme) == 0) {
            printf("Assento: %d\n", atual->assento);
        }
        atual = atual->proximo;
    }
}

void listarIngressosVendidos(Ingresso *listaVendidos) {
    if (listaVendidos == NULL) {
        printf("Nenhum ingresso vendido até o momento.\n");
        return;
    }

    Ingresso *atual = listaVendidos;
    printf("Ingressos vendidos:\n");
    while (atual != NULL) {
        printf("Filme: %s, Assento: %d\n", atual->filme, atual->assento);
        atual = atual->proximo;
    }
}

bool ingressoDisponivel(Ingresso *listaDisponiveis, char *filme, int assento) {
    Ingresso *atual = listaDisponiveis;
    while (atual != NULL) {
        if (strcmp(atual->filme, filme) == 0 && atual->assento == assento) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

Ingresso *inicializarFilmes(Ingresso *listaDisponiveis) {
    for (int i = 0; i < MAX_FILMES; i++) {
        for (int j = 1; j <= MAX_LOTACAO; j++) {
            listaDisponiveis = inserirNaLista(listaDisponiveis, filmes[i], j);
        }
    }
    return listaDisponiveis;
}

void mostrarAssentosDisponiveis(Ingresso *listaDisponiveis, char *filme) {
    printf("Assentos disponíveis para %s:\n", filme);
    for (int i = 1; i <= MAX_LOTACAO; i++) {
        if (ingressoDisponivel(listaDisponiveis, filme, i)) {
            printf("Assento %d está disponível.\n", i);
        }
    }
}
