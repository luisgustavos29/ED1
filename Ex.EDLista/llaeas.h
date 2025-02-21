#ifndef _LLAEAS_H
#define _LLAEAS_H

#define MAX 10

typedef struct lista Lista;

struct lista {
    int FL;
    int dados[MAX];
};

Lista* Cria_lista(void);
Lista* Libera_lista(Lista* Ptl);
Lista* Insere_elem(Lista* Ptl, int elem);
Lista* Remove_elem(Lista* Ptl, int elem);
Lista* Remove_elem_mov(Lista* Ptl, int elem);
int Consulta_nodo(Lista* Ptl, int pos, int* info);

int Tamanho_lista(Lista* Ptl);
int E_cheia(Lista* Ptl);
int E_vazia(Lista* Ptl);

#endif




