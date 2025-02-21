#include <stdio.h>
#include <stdlib.h>
#include "lladae.h"

Lista* Cria_lista(void) {
    return NULL;
}

Lista* Insere_elem(Lista* Ptl, int elem) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return Ptl;
    }
    novo->info = elem;
    novo->prox = Ptl;
    return novo;
}

Lista* Remove_elem(Lista* Ptl, int elem) {
    Lista* ant = NULL, *atual = Ptl;

    while (atual != NULL && atual->info != elem) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Elemento %d não encontrado na lista.\n", elem);
        return Ptl;
    }

    if (ant == NULL) {
        Ptl = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    return Ptl;
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
    return Ptl == NULL;
}

int E_cheia(Lista* Ptl) {
    return 0; // A lista nunca fica "cheia" na alocação dinâmica
}

int Tamanho_lista(Lista* Ptl) {
    int cont = 0;
    Lista* pt = Ptl;
    while (pt != NULL) {
        cont++;
        pt = pt->prox;
    }
    return cont;
}

int Consulta_nodo(Lista* Ptl, int pos, int* elem) {
    int cont = 1;
    Lista* pt = Ptl;
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

Lista* Mescla_listas(Lista* L1, Lista* L2) {
    Lista* L3 = Cria_lista();
    Lista* aux = L3;

    while (L1 != NULL && L2 != NULL) {
        if (L1->info < L2->info) {
            aux->prox = L1;
            L1 = L1->prox;
        } else if (L2->info < L1->info) {
            aux->prox = L2;
            L2 = L2->prox;
        } else {
            aux->prox = L1;
            L1 = L1->prox;
            L2 = L2->prox;
        }
        aux = aux->prox;
    }

    while (L1 != NULL) {
        aux->prox = L1;
        L1 = L1->prox;
        aux = aux->prox;
    }

    while (L2 != NULL) {
        aux->prox = L2;
        L2 = L2->prox;
        aux = aux->prox;
    }

    return L3->prox;
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

// Inserir em posição específica
Lista* Insere_elem_pos(Lista* Ptl, int elem, int pos) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return Ptl;
    }
    novo->info = elem;

    if (pos == 1) { // Insere no início
        novo->prox = Ptl;
        return novo;
    }

    Lista* ant = Ptl;
    int cont = 1;
    while (ant != NULL && cont < pos - 1) { // Encontra o nó anterior à posição desejada
        ant = ant->prox;
        cont++;
    }

    if (ant == NULL) { // Posição inválida
        printf("Posição inválida!\n");
        free(novo); // Libera a memória alocada
        return Ptl;
    }

    novo->prox = ant->prox; // Conecta o novo nó
    ant->prox = novo;
    return Ptl;
}

// Remover por posição
Lista* Remove_elem_pos(Lista* Ptl, int pos) {
    if (pos <= 0 || Ptl == NULL) {
        printf("Posição inválida!\n");
        return Ptl;
    }

    if (pos == 1) { // Remove o primeiro elemento
        Lista* aux = Ptl;
        Ptl = Ptl->prox;
        free(aux);
        return Ptl;
    }

    Lista* ant = Ptl;
    int cont = 1;
    while (ant != NULL && cont < pos - 1) { // Encontra o nó anterior à posição desejada
        ant = ant->prox;
        cont++;
    }

    if (ant == NULL || ant->prox == NULL) { // Posição inválida
        printf("Posição inválida!\n");
        return Ptl;
    }

    Lista* atual = ant->prox;
    ant->prox = atual->prox;
    free(atual);
    return Ptl;
}

// Ordenar a lista (usando bubble sort)
Lista* Ordena_lista(Lista* Ptl) {
    if (Ptl == NULL || Ptl->prox == NULL) { // Lista vazia ou com um elemento
        return Ptl;
    }

    int trocou;
    Lista* atual, *proximo;
    do {
        trocou = 0;
        atual = Ptl;
        proximo = atual->prox;
        while (proximo != NULL) {
            if (atual->info > proximo->info) {
                int temp = atual->info;
                atual->info = proximo->info;
                proximo->info = temp;
                trocou = 1;
            }
            atual = proximo;
            proximo = proximo->prox;
        }
    } while (trocou);
    return Ptl;
}

// Interseção de listas ordenadas
Lista* Intersecao_listas(Lista* L1, Lista* L2) {
    Lista* L3 = Cria_lista();
    Lista* aux = L3;

    while (L1 != NULL && L2 != NULL) {
        if (L1->info < L2->info) {
            L1 = L1->prox;
        } else if (L2->info < L1->info) {
            L2 = L2->prox;
        } else {
            aux->prox = (Lista*)malloc(sizeof(Lista));
            if (aux->prox == NULL) {
                printf("Erro de alocação de memória!\n");
                return L3;
            }
            aux->prox->info = L1->info;
            aux->prox->prox = NULL;
            aux = aux->prox;
            L1 = L1->prox;
            L2 = L2->prox;
        }
    }

    return L3->prox;
}

// Salvar em arquivo
void Salva_lista(Lista* Ptl, char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", nome_arquivo);
        return;
    }

    while (Ptl != NULL) {
        fprintf(arquivo, "%d\n", Ptl->info);
        Ptl = Ptl->prox;
    }

    fclose(arquivo);
    printf("Lista salva com sucesso em %s!\n", nome_arquivo);
}
