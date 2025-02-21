#include <stdio.h>
#include <stdlib.h>
#include "lladae.h"

Lista* Cria_lista(void) {
    return NULL;
}

Lista* Libera_lista(Lista* Ptl) {
    Lista* aux;

    while (Ptl != NULL) {
        aux = Ptl;
        Ptl = Ptl->prox;
        free(aux);
    }

    return Ptl;
}

int E_vazia(Lista* Ptl) {
    if (Ptl == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Lista* Insere_elem(Lista* Ptl, int elem) {
    Lista* Ptnodo;
    Ptnodo = (Lista*)malloc(sizeof(Lista));
    if (Ptnodo == NULL) {
        return Ptl;
    }
    Ptnodo->info = elem;

    if (Ptl == NULL) {
        Ptnodo->prox = NULL;
        return Ptnodo;
    }

    Lista* ultimo = Ptl;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }

    ultimo->prox = Ptnodo;
    Ptnodo->prox = NULL;

    return Ptl;
}

Lista* Remove_elem(Lista* Ptl, int elem) {
    Lista* ant, *atual;
    if (Ptl == NULL) {
        return Ptl;
    }

    atual = Ptl;
    ant = NULL;

    while (atual != NULL && atual->info != elem) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Elemento %d não encontrado na lista.\n", elem);
        printf("Insira um elemento presente na lista: ");
        scanf("%d", &elem);
        return Remove_elem(Ptl, elem);
    }

    if (ant == NULL) {
        Ptl = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    return Ptl;
}

int Tamanho_lista(Lista* Ptl) {
    Lista* pt;
    int cont;
    pt = Ptl;
    cont = 0;
    while (pt != NULL) {
        cont++;
        pt = pt->prox;
    }
    return cont;
}

int Consulta_nodo(Lista* Ptl, int pos, int* elem) {
    int cont = 1;
    Lista* pt;
    pt = Ptl;
    if (pos <= 0 || pt == NULL) {
        return 0;
    }
    while (pt != NULL && cont < pos) {
        pt = pt->prox;
        cont++;
    }
    if (pt == NULL) {
        return 0;
    } else {
        *elem = pt->info;
        return 1;
    }
}

Lista* Ordena_lista(Lista* Ptl) {
    if (Ptl == NULL || Ptl->prox == NULL) {
        return Ptl; // Lista vazia ou com um único elemento já está ordenada
    }

    Lista* atual = Ptl;
    Lista* proximo;
    int temp;

    while (atual != NULL) {
        proximo = atual->prox;
        while (proximo != NULL) {
            if (atual->info > proximo->info) {
                temp = atual->info;
                atual->info = proximo->info;
                proximo->info = temp;
            }
            proximo = proximo->prox;
        }
        atual = atual->prox;
    }

    return Ptl;
}

Lista* Intersecao_listas(Lista* Ptl1, Lista* Ptl2) {
    Lista* Ptl_intersecao = Cria_lista(); // Lista para armazenar a interseção
    Lista* pt1 = Ptl1;
    Lista* pt2 = Ptl2;

    while (pt1 != NULL && pt2 != NULL) {
        if (pt1->info < pt2->info) {
            pt1 = pt1->prox;
        } else if (pt1->info > pt2->info) {
            pt2 = pt2->prox;
        } else { // Os elementos são iguais, adiciona na lista de interseção
            Ptl_intersecao = Insere_elem(Ptl_intersecao, pt1->info);
            pt1 = pt1->prox;
            pt2 = pt2->prox;
        }
    }

    return Ptl_intersecao;
}

void Exibe_lista(Lista* Ptl) {
    if (E_vazia(Ptl)) {
        printf("A lista está vazia.\n");
        return;
    }
    Lista* pt = Ptl;
    printf("Lista: ");
    while (pt != NULL) {
        printf("%d ", pt->info);
        pt = pt->prox;
    }
    printf("\n");
}

void Salva_lista(Lista* Ptl, char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    Lista* pt = Ptl;
    while (pt != NULL) {
        fprintf(arquivo, "%d ", pt->info);
        pt = pt->prox;
    }
    fclose(arquivo);
    printf("Lista salva em %s.\n", nome_arquivo);
}
