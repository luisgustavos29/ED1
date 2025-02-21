#ifndef LISTA_POETAS_H
#define LISTA_POETAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    char poema[500];
} Poetas;

typedef struct NoPoeta {
    Poetas poeta;
    struct NoPoeta *prox;
} NoPoeta;

typedef struct {
    NoPoeta *inicio;
} ListaPoetas;

ListaPoetas* Cria_lista(void);
ListaPoetas* Libera_lista(ListaPoetas* lista);
ListaPoetas* Insere_poeta(ListaPoetas* lista, Poetas poeta);
ListaPoetas* Remove_poeta(ListaPoetas* lista, int id);
Poetas* Consulta_poeta(ListaPoetas* lista, int id);
void Exibe_lista(ListaPoetas* lista);
int E_vazia(ListaPoetas* lista);
void CombSort(ListaPoetas* lista);
ListaPoetas* Mescla_listas(ListaPoetas* lista1, ListaPoetas* lista2);

#endif
