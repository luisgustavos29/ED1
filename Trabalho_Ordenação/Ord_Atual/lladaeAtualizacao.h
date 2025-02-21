#ifndef LLADADEATUALIZACAO_H
#define LLADADEATUALIZACAO_H

struct no {
    struct no* ant;
    int info;
    struct no* prox;
};

typedef struct no Lista;

Lista* Cria_lista(void);
Lista* Libera_lista(Lista* Ptl);
int E_vazia(Lista* Ptl);
Lista* Insere_elem(Lista* Ptl, int elem);
int Tamanho_lista(Lista* Ptl);
Lista* CombSort(Lista* Pt1);
Lista* Junta_listas(Lista* lista1, Lista* lista2);
void Imprime_lista(Lista* Ptl);

#endif
