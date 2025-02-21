#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_poetas.h"


ListaPoetas* Cria_lista(void) {
    ListaPoetas* lista = (ListaPoetas*)malloc(sizeof(ListaPoetas));
    if (lista == NULL) {
        printf("Erro ao alocar memoria para a lista!\n");
        exit(1);
    }
    lista->FL = 0;
    return lista;
}

ListaPoetas* Libera_lista(ListaPoetas* lista) {
    if (lista != NULL) {
        free(lista);
    }
    return NULL;
}

ListaPoetas* Insere_poeta(ListaPoetas* lista, Poetas poeta) {
    if (lista == NULL) {
        return lista;
    }

    lista->poetas[lista->FL] = poeta;
    lista->FL++;
    return lista;
}

ListaPoetas* Remove_poeta(ListaPoetas* lista, int id) {
    if (lista == NULL || E_vazia(lista) == 1) {
        return lista;
    }

    int i, j;
    for (i = 0; i < lista->FL; i++) {
        if (lista->poetas[i].id == id) {
            for (j = i; j < lista->FL - 1; j++) {
                lista->poetas[j] = lista->poetas[j + 1];
            }
            lista->FL--;
            return lista;
        }
    }

    return lista;
}
Poetas* Consulta_poeta(ListaPoetas* lista, int id) {
    if (lista == NULL || E_vazia(lista) == 1) {
        return NULL;
    }

    int i;
    for (i = 0; i < lista->FL; i++) {
        if (lista->poetas[i].id == id) {
            return &lista->poetas[i];
        }
    }

    return NULL;
}

void Exibe_lista(ListaPoetas* lista) {
    if (E_vazia(lista) == 1) {
        printf("Lista de poetas vazia!\n");
        return;
    }

    printf("Lista de Poetas:\n");
    for (int i = 0; i < lista->FL; i++) {
        printf("ID: %d\n", lista->poetas[i].id);
        printf("Nome: %s\n", lista->poetas[i].nome);
        printf("Poesia: %s\n\n", lista->poetas[i].poema);
    }
}
int E_cheia(ListaPoetas* lista) {
    if (lista == NULL) {
        return -1;
    }
    if (lista->FL == MAX) {
        return 1;
    }
    return 0;
}
int E_vazia(ListaPoetas* lista) {
    if (lista == NULL) {
    return -1;
    }
    if (lista->FL == 0) {
    return 1;
    }
    return 0;
}



