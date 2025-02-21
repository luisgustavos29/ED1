#ifndef LLADAE_H
#define LLADAE_H

typedef struct no {
    int id;
    char *nome;
    char *poema;
    struct no* prox;
} Poeta;

typedef Poeta* Lista;

Lista Cria_lista(void);
Lista Libera_lista(Lista Ptl);
int E_vazia(Lista Ptl);
int E_cheia(Lista Ptl);
Lista Insere_poeta(Lista Ptl, int id, char nome[], char poema[]);
Lista Remove_poeta(Lista Ptl, int id);
Poeta* Consulta_poeta(Lista Ptl, int id);
void Exibe_lista(Lista Ptl);
int Tamanho_lista(Lista Ptl);
int Consulta_nodo(Lista Ptl, int pos, Poeta *poeta);

#endif
