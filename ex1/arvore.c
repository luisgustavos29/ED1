#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Fun��o para criar uma nova �rvore
struct arvore* criar_arvore() {
    struct arvore* arv = (struct arvore*) malloc(sizeof(struct arvore));
    if (arv == NULL) {
        printf("Erro na aloca��o de mem�ria.\n");
        exit(1);
    }
    arv->raiz = -1;
    arv->tamanho = 0;
    return arv;
}

// Fun��o para inserir um valor na �rvore
void inserir(struct arvore* arv, char info) {
    if (arv->tamanho == MAX_NOS) {
        printf("�rvore cheia.\n");
        return;
    }

    if (arv->raiz == -1) {
        arv->nos[0].info = info;
        arv->nos[0].esq = -1;
        arv->nos[0].dir = -1;
        arv->raiz = 0;
        arv->tamanho++;
        return;
    }

    int atual = arv->raiz;
    while (1) {
        if (info < arv->nos[atual].info) {
            if (arv->nos[atual].esq == -1) {
                arv->nos[atual].esq = arv->tamanho;
                arv->nos[arv->tamanho].info = info;
                arv->nos[arv->tamanho].esq = -1;
                arv->nos[arv->tamanho].dir = -1;
                arv->tamanho++;
                return;
            } else {
                atual = arv->nos[atual].esq;
            }
        } else if (info > arv->nos[atual].info) {
            if (arv->nos[atual].dir == -1) {
                arv->nos[atual].dir = arv->tamanho;
                arv->nos[arv->tamanho].info = info;
                arv->nos[arv->tamanho].esq = -1;
                arv->nos[arv->tamanho].dir = -1;
                arv->tamanho++;
                return;
            } else {
                atual = arv->nos[atual].dir;
            }
        } else {
            printf("Valor j� existente.\n");
            return;
        }
    }
}

// Fun��o para buscar um valor na �rvore
int buscar(struct arvore* arv, char info) {
    if (arv->raiz == -1) {
        return 0; // Valor n�o encontrado
    }

    int atual = arv->raiz;
    while (1) {
        if (arv->nos[atual].info == info) {
            return 1; // Valor encontrado
        } else if (info < arv->nos[atual].info) {
            if (arv->nos[atual].esq == -1) {
                return 0; // Valor n�o encontrado
            } else {
                atual = arv->nos[atual].esq;
            }
        } else if (info > arv->nos[atual].info) {
            if (arv->nos[atual].dir == -1) {
                return 0; // Valor n�o encontrado
            } else {
                atual = arv->nos[atual].dir;
            }
        }
    }
}

// Fun��o para imprimir em ordem infixa
void imprimir_infix(struct arvore* arv, int posicao) {
    if (posicao != -1) {
        imprimir_infix(arv, arv->nos[posicao].esq);
        printf("%c", arv->nos[posicao].info);
        imprimir_infix(arv, arv->nos[posicao].dir);
    }
}

// Fun��o para imprimir em ordem prefixa
void imprimir_prefix(struct arvore* arv, int posicao) {
    if (posicao != -1) {
        printf("%c", arv->nos[posicao].info);
        imprimir_prefix(arv, arv->nos[posicao].esq);
        imprimir_prefix(arv, arv->nos[posicao].dir);
    }
}

// Fun��o para imprimir em ordem posfixa
void imprimir_posfix(struct arvore* arv, int posicao) {
    if (posicao != -1) {
        imprimir_posfix(arv, arv->nos[posicao].esq);
        imprimir_posfix(arv, arv->nos[posicao].dir);
        printf("%c", arv->nos[posicao].info);
    }
}
