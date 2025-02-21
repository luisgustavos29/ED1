#ifndef LLADAE_H
#define LLADAE_H

typedef struct no Lista;

struct no {
    int info;
    struct no* prox;
};

Lista* Cria_lista(void);
Lista* Libera_lista(Lista* Ptl);
int E_vazia(Lista* Ptl);
Lista* Insere_elem(Lista* Ptl, int elem);
Lista* Remove_elem(Lista* Ptl, int elem);
int Tamanho_lista(Lista* Ptl);
int Consulta_nodo(Lista* Ptl, int pos, int* elem);
Lista* Ordena_lista(Lista* Ptl);
Lista* Intersecao_listas(Lista* Ptl1, Lista* Ptl2);

void Exibe_lista(Lista* Ptl);
void Salva_lista(Lista* Ptl, char* nome_arquivo);

#endif
