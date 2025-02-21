#include <stdio.h>
#include <stdlib.h>
#include "llaeas.h"

Lista* Cria_lista(void) {
    Lista* pt = (Lista*)malloc(sizeof(Lista));
    if (pt != NULL) {
        pt->FL = 0;
    }
    return pt;
}

Lista* Libera_lista(Lista* Ptl) {
    free(Ptl);
    return NULL;
}

Lista* Insere_elem(Lista* Ptl, int elem) {
    if (Ptl == NULL || Ptl->FL == MAX) {
        return Ptl;
    }
    Ptl->dados[Ptl->FL] = elem;
    Ptl->FL++;
    return Ptl;
}

Lista* Remove_elem(Lista* Ptl, int elem) {
    int i;
    if (Ptl != NULL) {
        i = 0;
        while (i < Ptl->FL && Ptl->dados[i] != elem) {
            i++;
        }
        if (i == Ptl->FL) {
            return Ptl;
        }

        Ptl->dados[i] = Ptl->dados[Ptl->FL - 1];
        Ptl->FL--;
    }
    return Ptl;
}

Lista* Remove_elem_mov(Lista* Ptl, int elem) {
    int i, k;
    if (Ptl == NULL || Ptl->FL == 0)
        return Ptl;

    i = 0;
    while (i < Ptl->FL && Ptl->dados[i] != elem)
        i++;

    if (i == Ptl->FL)
        return Ptl;

    for (k = i; k < Ptl->FL - 1; k++)
        Ptl->dados[k] = Ptl->dados[k + 1];

    Ptl->FL--;
    return Ptl;
}

int Consulta_nodo(Lista* Ptl, int pos, int* info) {
    if (Ptl == NULL)
        return 0;
    if (pos <= 0 || pos > Ptl->FL)
        return 0;

    *info = Ptl->dados[pos - 1];
    return 1;
}

int Tamanho_lista(Lista* Ptl) {
    if (Ptl == NULL)
        return -1;
    else
        return Ptl->FL;
}

int E_cheia(Lista* Ptl) {
    if (Ptl == NULL)
        return -1;
    if (Ptl->FL == MAX)
        return 1;
    return 0;
}

int E_vazia(Lista* Ptl) {
    if (Ptl == NULL)
        return -1;
    if (Ptl->FL == 0)
        return 1;
    return 0;
}
