#ifndef LLADADE2D_H
#define LLADADE2D_H

    struct no {
        struct no* ant;
        int info;
        struct no* prox;
    };

    typedef struct no Lista;

    Lista* Cria_lista(void);
    Lista* Libera_lista(Lista* Ptl);
    int E_vazia(Lista* Ptl);
    int E_cheia(Lista* Ptl);
    Lista* Insere_elem(Lista* Ptl, int elem);
    Lista* Remove_elem(Lista* Ptl, int elem);
    int Tamanho_lista(Lista *Ptl);
    int Consulta_nodo(Lista *Ptl, int elem);
    Lista* CombSort(Lista* Ptl);
    Lista* Junta_listas(Lista* lista1, Lista* lista2);
    void Imprime_lista(Lista* Ptl);

    #endif
