#ifndef LISTA_POETAS_H
#define LISTA_POETAS_H
#define MAX 1

typedef struct {
    int id;
    char nome[50];
    char poema[500];
} Poetas;

typedef struct {
    Poetas poetas[MAX];
    int FL;
} ListaPoetas;

ListaPoetas* Cria_lista(void);
ListaPoetas* Libera_lista(ListaPoetas* lista);
ListaPoetas* Insere_poeta(ListaPoetas* lista, Poetas poeta);
ListaPoetas* Remove_poeta(ListaPoetas* lista, int id);
Poetas* Consulta_poeta(ListaPoetas* lista, int id);
void Exibe_lista(ListaPoetas* lista);
int E_cheia(ListaPoetas* lista);
int E_vazia(ListaPoetas* lista);

#endif
