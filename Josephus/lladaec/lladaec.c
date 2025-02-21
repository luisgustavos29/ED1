#include "lladaec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

Pessoa *Cria_lista(void) {
    return NULL;
}

int E_vazia(Pessoa *Ptl) {
    return (Ptl == NULL);
}

Pessoa* Insere_elem(Pessoa* Ptl, char *nome) {
    Pessoa *Ptno;
    Ptno = (Pessoa*)malloc(sizeof(Pessoa));
    if (Ptno == NULL) {
        return Ptl;
    }
    int num = Tamanho_Lista(Ptl) + 1;
    Ptno->posicao = num;
    strcpy(Ptno->nome, nome);
    if (Ptl == NULL) {
        Ptl = Ptno;
        Ptno->prox = Ptno;
    } else {
        Ptno->prox = Ptl->prox;
        Ptl->prox = Ptno;
        Ptl = Ptno;
    }
    return Ptl;
}

Pessoa* Remove_elem(Pessoa* Ptl, int jogador, int *posicao) {
    if (Ptl == NULL) {
        printf("A Lista está vazia!\n");
        return Ptl;
    }

    Pessoa *ant, *atual;
    atual = Ptl->prox;
    ant = Ptl;
    int cont_pos = 1;

    while (cont_pos < jogador) {
        ant = atual;
        atual = atual->prox;
        cont_pos++;
    }

    printf("Eliminado: %s\n", atual->nome);
    Salvar_relacionados(Ptl, atual->nome, "eliminado");

    if (atual == Ptl && atual->prox == Ptl) {
        free(atual);
        return NULL;
    } else {
        ant->prox = atual->prox;
        if (atual == Ptl) {
            Ptl = ant;
        }
        free(atual);
    }
    return Ptl;
}

int Tamanho_Lista(Pessoa* Ptl) {
    if (E_vazia(Ptl)) return 0;
    int cont = 1;
    for (Pessoa *pt = Ptl->prox; pt != Ptl; pt = pt->prox) {
        cont++;
    }
    return cont;
}
void Salvar_relacionados(Pessoa *Ptl, const char *nome, const char *tipo) {
    FILE *file;
    file = fopen("relacionadosJosephus.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (strcmp(tipo, "eliminado") == 0) {
        fprintf(file, "Eliminado: %s\n", nome);
    } else if (strcmp(tipo, "perdedor") == 0) {
        fprintf(file, "Perdedor: %s\n", nome);
    }

    fclose(file);
}

void Exibir_lista(Pessoa* Ptl) {
    if (Ptl == NULL) {
        printf("Nenhuma pessoa na lista.\n");
        return;
    }
    printf("\n\nRelacionados nessa rodada:\n\n");
    Pessoa *pt = Ptl->prox;
    do {
        printf("Nome: %s --> Posição:[%d]\n\n", pt->nome, pt->posicao);
        pt = pt->prox;
    } while (pt != Ptl->prox);
}

Pessoa *Libera_lista(Pessoa *Ptl) {
    Pessoa *pt, *aux;
    if (Ptl == NULL)
        return NULL;
    pt = Ptl->prox;
    while (pt != Ptl) {
        aux = pt;
        pt = pt->prox;
        free(aux);
    }
    free(Ptl);
    return NULL;
}
