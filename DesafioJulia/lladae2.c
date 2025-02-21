#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lladae2.h"

Filme* criarFilme(char nome[], int lotacao) {
    Filme *novoFilme = (Filme*) malloc(sizeof(Filme));
    strcpy(novoFilme->nome, nome);
    novoFilme->lotacao = lotacao;
    novoFilme->ingressosDisponiveis = NULL;
    novoFilme->proximo = NULL;
    return novoFilme;
}

void inserirFilme(Filme **listaFilmes, Filme *novoFilme) {
    novoFilme->proximo = *listaFilmes;
    *listaFilmes = novoFilme;
}

void exibirFilmes(Filme *listaFilmes) {
    int i = 1;
    if (listaFilmes == NULL) {
        printf("Nenhum filme cadastrado.\n");
        return;
    }
    printf("Filmes disponíveis:\n");
    while (listaFilmes != NULL) {
        printf("%d - %s\n", i, listaFilmes->nome);
        listaFilmes = listaFilmes->proximo;
        i++;
    }
}

Filme* encontrarFilme(Filme *listaFilmes, char nome[]) {
    while (listaFilmes != NULL) {
        if (strcmp(listaFilmes->nome, nome) == 0) {
            return listaFilmes;
        }
        listaFilmes = listaFilmes->proximo;
    }
    return NULL;
}

No* criarNo(int filme, int assento) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->ingresso.filme = filme;
    novoNo->ingresso.assento = assento;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNo(No **listaIngressos, No *novoNo) {
    novoNo->proximo = *listaIngressos;
    *listaIngressos = novoNo;
}

void removerNo(No **listaIngressos, int filme, int assento) {
    No *aux = *listaIngressos;
    No *anterior = NULL;

    while (aux != NULL) {
        if (aux->ingresso.filme == filme && aux->ingresso.assento == assento) {
            if (anterior == NULL) {
                *listaIngressos = aux->proximo;
            } else {
                anterior->proximo = aux->proximo;
            }
            free(aux);
            return;
        }
        anterior = aux;
        aux = aux->proximo;
    }
}

void exibirNos(No *listaNos) {
    if (listaNos == NULL) {
        printf("Nenhum ingresso encontrado.\n");
        return;
    }
    while (listaNos != NULL) {
        printf("Filme: %d, Assento: %d\n", listaNos->ingresso.filme, listaNos->ingresso.assento);
        listaNos = listaNos->proximo;
    }
}

No* encontrarNo(No *listaNos, int assento) {
    while (listaNos != NULL) {
        if (listaNos->ingresso.assento == assento) {
            return listaNos;
        }
        listaNos = listaNos->proximo;
    }
    return NULL;
}

void venderIngresso(Filme *listaFilmes) {
    char nomeFilme[50];
    int assento;
    Filme *filme;

    exibirFilmes(listaFilmes);
    printf("Digite o nome do filme: ");
    scanf(" %[^\n]", nomeFilme);

    filme = encontrarFilme(listaFilmes, nomeFilme);
    if (filme == NULL) {
        printf("Filme não encontrado.\n");
        return;
    }

    printf("Assentos disponíveis: ");
    for (int i = 1; i <= filme->lotacao; i++) {
        if (encontrarNo(filme->ingressosDisponiveis, i) == NULL) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Digite o número do assento: ");
    scanf("%d", &assento);

    if (assento < 1 || assento > filme->lotacao) {
        printf("Assento inválido.\n");
        return;
    }

    if (encontrarNo(filme->ingressosDisponiveis, assento) != NULL) {
        printf("Assento já está ocupado.\n");
        return;
    }

    No *novoNo = criarNo(filme->nome, assento);
    inserirNo(&filme->ingressosDisponiveis, novoNo);

    printf("Ingresso vendido com sucesso!\n");
}

void cancelarIngresso(Filme *listaFilmes) {
    char nomeFilme[50];
    int assento;
    Filme *filme;

    exibirFilmes(listaFilmes);
    printf("Digite o nome do filme: ");
    scanf(" %[^\n]", nomeFilme);

    filme = encontrarFilme(listaFilmes, nomeFilme);
    if (filme == NULL) {
        printf("Filme não encontrado.\n");
        return;
    }

    printf("Digite o número do assento a ser cancelado: ");
    scanf("%d", &assento);

    if (assento < 1 || assento > filme->lotacao) {
        printf("Assento inválido.\n");
        return;
    }

    removerNo(&filme->ingressosDisponiveis, filme->nome, assento);

    printf("Ingresso cancelado com sucesso!\n");
}

void listarIngressosDisponiveis(Filme *listaFilmes) {
    char nomeFilme[50];
    Filme *filme;

    exibirFilmes(listaFilmes);
    printf("Digite o nome do filme: ");
    scanf(" %[^\n]", nomeFilme);

    filme = encontrarFilme(listaFilmes, nomeFilme);
    if (filme == NULL) {
        printf("Filme não encontrado.\n");
        return;
    }

    printf("Ingressos disponíveis para %s:\n", filme->nome);
    exibirNos(filme->ingressosDisponiveis);
}

void exibirIngressosVendidos(No *listaIngressosVendidos) {
    if (listaIngressosVendidos == NULL) {
        printf("Nenhum ingresso vendido.\n");
        return;
    }
    printf("Ingressos vendidos em ordem de compra:\n");
    exibirNos(listaIngressosVendidos);
}
