#ifndef LLADAE_H
#define LLADAE_H

typedef struct no Lista;

struct no {
    int info;
    struct no* prox;
};

Lista* Cria_lista(void);
Lista* Insere_elem(Lista* Ptl, int elem);
Lista* Remove_elem(Lista* Ptl, int elem);
Lista* Libera_lista(Lista* Ptl);
int E_vazia(Lista* Ptl);
int E_cheia(Lista* Ptl);
int Tamanho_lista(Lista* Ptl);
int Consulta_nodo(Lista* Ptl, int pos, int* elem);
Lista* Mescla_listas(Lista* L1, Lista* L2);
void Exibe_lista(Lista* Ptl);
Lista* Insere_elem_pos(Lista* Ptl, int elem, int pos);
Lista* Remove_elem_pos(Lista* Ptl, int pos);
Lista* Ordena_lista(Lista* Ptl);
Lista* Intersecao_listas(Lista* L1, Lista* L2);
void Salva_lista(Lista* Ptl, char* nome_arquivo);

#endif
