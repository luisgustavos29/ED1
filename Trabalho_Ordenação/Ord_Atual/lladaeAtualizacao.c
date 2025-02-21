#include <stdio.h>
#include <stdlib.h>
#include "lladaeAtualizacao.h"

    Lista* Cria_lista(void) {
        return NULL;
    }

    Lista* Libera_lista(Lista *Ptl) {
        struct no *aux;
        while (Ptl != NULL) {
            aux = Ptl;
            Ptl = Ptl->prox;
            free(aux);
        }
        return NULL;
    }

    int E_vazia(Lista *Ptl) {
        return (Ptl == NULL);
    }

    int E_cheia(Lista *Ptl) {
        return 0;
    }

    Lista* Insere_elem(Lista *Ptl, int elem) {
        struct no *Ptnodo = (struct no*)malloc(sizeof(struct no));
        if (Ptnodo == NULL)
            return Ptl;
        Ptnodo->info = elem;
        Ptnodo->prox = Ptl;
        Ptnodo->ant = NULL;
        if (Ptl != NULL)
            Ptl->ant = Ptnodo;
        Ptl = Ptnodo;
        return Ptl;
    }

    Lista* Remove_elem(Lista *Ptl, int elem) {
        struct no *atual;
        if (Ptl == NULL)
            return Ptl;

        atual = Ptl;
        while (atual != NULL && elem != atual->info) {
            atual = atual->prox;
        }
        if (atual == NULL)
            return Ptl;

        if (atual == Ptl)
            Ptl = atual->prox;
        else
            atual->ant->prox = atual->prox;

        if (atual->prox != NULL)
            atual->prox->ant = atual->ant;

        free(atual);
        return Ptl;
    }

    int Tamanho_lista(Lista *Ptl) {
        struct no *pt = Ptl;
        int cont = 0;
        while (pt != NULL) {
            cont++;
            pt = pt->prox;
        }
        return cont;
    }

    int Consulta_nodo(Lista *Ptl, int elem) {
        struct no *pt = Ptl;

        while (pt != NULL) {
            if (pt->info == elem) {
                return 1;
            }
            pt = pt->prox;
        }

        return 0;
    }

Lista* CombSort(Lista* Pt1) {
    if (E_vazia(Pt1)) return Pt1;

    int trocou;
    int gap = Tamanho_lista(Pt1);
    float fator = 1.3;

    do {
        printf("Passou");
        gap = (int)(gap / fator);
        if (gap < 1) gap = 1;
        trocou = 0;
        struct no *atual = Pt1;

        for (int i = 0; i + gap < Tamanho_lista(Pt1); i++) {
            struct no *proximo = atual;

            for (int j = 0; j < gap; j++) {
                if (proximo == NULL) break; // Verifica se proximo � NULL
                proximo = proximo->prox;
            }

            if (proximo != NULL && atual->info > proximo->info) {
                // Troca os n�s atual e proximo
                struct no *tempAtualAnt = atual->ant;
                struct no *tempAtualProx = atual->prox;
                struct no *tempProximoAnt = proximo->ant;
                struct no *tempProximoProx = proximo->prox;

                // Atualiza os ponteiros do n� anterior
                if (tempAtualAnt) tempAtualAnt->prox = proximo;
                if (tempProximoAnt) tempProximoAnt->prox = atual;

                // Atualiza os ponteiros do n� seguinte
                if (tempAtualProx) tempAtualProx->ant = proximo;
                if (tempProximoProx) tempProximoProx->ant = atual;

                // Troca as refer�ncias do n� atual e do n� pr�ximo
                proximo->ant = tempAtualAnt;
                proximo->prox = tempAtualProx;
                atual->ant = tempProximoAnt;
                atual->prox = tempProximoProx;

                if (atual == Pt1) {
                    Pt1 = proximo;
                }

                atual = proximo; // Atualiza atual para proximo
                trocou = 1;
            } else {
                atual = atual->prox;
            }
        }
    } while (trocou || gap > 1);

    return Pt1;
}

    Lista* Junta_listas(Lista* lista1, Lista* lista2) {
        Lista* nova_lista = Cria_lista();
        struct no *atual1 = lista1;
        struct no *atual2 = lista2;

        while (atual1 != NULL) {
            if (!Consulta_nodo(nova_lista, atual1->info)) {
                nova_lista = Insere_elem(nova_lista, atual1->info);
            }
            atual1 = atual1->prox;
        }

        while (atual2 != NULL) {
            if (!Consulta_nodo(nova_lista, atual2->info)) {
                nova_lista = Insere_elem(nova_lista, atual2->info);
            }
            atual2 = atual2->prox;
        }

        nova_lista = CombSort(nova_lista);

        return nova_lista;
    }

    void Imprime_lista(Lista* Ptl) {
        struct no* atual = Ptl;
        if (E_vazia(Ptl)) {
            printf("A lista est� vazia.\n");
            return;
        }
        while (atual != NULL) {
            printf("%d ", atual->info);
            atual = atual->prox;
        }
        printf("\n");
    }
