#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_poetas.h"

ListaPoetas* Cria_lista(void) {
    ListaPoetas* lista = (ListaPoetas*)malloc(sizeof(ListaPoetas));
    if (lista == NULL) {
        printf("Erro ao alocar memória para a lista!\n");
        exit(1);
    }
    lista->inicio = NULL;
    return lista;
}

ListaPoetas* Libera_lista(ListaPoetas* lista) {
    if (lista != NULL) {
        NoPoeta *atual = lista->inicio;
        NoPoeta *proximo;
        while (atual != NULL) {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
        free(lista);
    }
    return NULL;
}

ListaPoetas* Insere_poeta(ListaPoetas* lista, Poetas poeta) {
    if (lista == NULL) {
        return lista;
    }

    NoPoeta *novo = (NoPoeta*)malloc(sizeof(NoPoeta));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o novo nó!\n");
        exit(1);
    }
    novo->poeta = poeta;
    novo->prox = lista->inicio;
    lista->inicio = novo;

    return lista;
}

ListaPoetas* Remove_poeta(ListaPoetas* lista, int id) {
    if (lista == NULL || lista->inicio == NULL) {
        return lista;
    }

    NoPoeta *atual = lista->inicio;
    NoPoeta *anterior = NULL;

    while (atual != NULL && atual->poeta.id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            lista->inicio = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
    }

    return lista;
}

Poetas* Consulta_poeta(ListaPoetas* lista, int id) {
    if (lista == NULL || lista->inicio == NULL) {
        return NULL;
    }

    NoPoeta *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->poeta.id == id) {
            return &atual->poeta;
        }
        atual = atual->prox;
    }
    return NULL;
}

void Exibe_lista(ListaPoetas* lista) {
    if (lista == NULL || lista->inicio == NULL) {
        printf("Lista de poetas vazia!\n");
        return;
    }

    printf("Lista de Poetas:\n");
    NoPoeta *atual = lista->inicio;
    while (atual != NULL) {
        printf("ID: %d\n", atual->poeta.id);
        printf("Nome: %s\n", atual->poeta.nome);
        printf("Poesia: %s\n\n", atual->poeta.poema);
        atual = atual->prox;
    }
}

int E_vazia(ListaPoetas* lista) {
    if (lista == NULL) {
        return -1;
    }
    return (lista->inicio == NULL);
}

void CombSort(ListaPoetas* lista) {
    if (lista == NULL || lista->inicio == NULL) {
        return;
    }

    int gap = 0;
    int trocou = 1;
    NoPoeta *atual;
    NoPoeta *proximo;

    for (gap = 1; gap < 10; gap = gap * 10 / 13);

    while (gap > 1 || trocou) {
        trocou = 0;
        atual = lista->inicio;

        for (int i = 0; atual->prox != NULL; i++) {
            proximo = atual->prox;
            if (i + gap < 10 && proximo != NULL) {
                if (atual->poeta.id > proximo->poeta.id) {
                    Poetas temp = atual->poeta;
                    atual->poeta = proximo->poeta;
                    proximo->poeta = temp;
                    trocou = 1;
                }
            }
            atual = atual->prox;
        }
        if (gap > 1) {
            gap = gap * 10 / 13;
        }
    }
}

ListaPoetas* Mescla_listas(ListaPoetas* lista1, ListaPoetas* lista2) {
    if (lista1 == NULL && lista2 == NULL) {
        return NULL;
    }

    ListaPoetas* lista_mesclada = Cria_lista();
    NoPoeta *atual1 = lista1->inicio;
    NoPoeta *atual2 = lista2->inicio;

    while (atual1 != NULL) {
        lista_mesclada = Insere_poeta(lista_mesclada, atual1->poeta);
        atual1 = atual1->prox;
    }

    while (atual2 != NULL) {
        lista_mesclada = Insere_poeta(lista_mesclada, atual2->poeta);
        atual2 = atual2->prox;
    }

    CombSort(lista_mesclada);
    return lista_mesclada;
}
