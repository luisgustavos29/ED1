#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_poetas.h"


ListaPoetas* Cria_lista(void) {
    ListaPoetas* lista = (ListaPoetas*)malloc(sizeof(ListaPoetas));
    if (lista == NULL) {
        printf("Erro ao alocar memoria para a lista!\n");
        exit(1);
    }
    lista->inicio = NULL;
    return lista;
}

ListaPoetas* Libera_lista(ListaPoetas* lista) {
    if (lista != NULL) {
        NoPoeta *atual = lista->inicio;
        NoPoeta *proximo;
        while (atual != NULL) {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
        free(lista);
    }
    return NULL;
}

ListaPoetas* Insere_poeta(ListaPoetas* lista, Poetas poeta) {
    if (lista == NULL) {
        return lista;
    }

    NoPoeta *novo = (NoPoeta*)malloc(sizeof(NoPoeta));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o novo no!\n");
        exit(1);
    }
    novo->poeta = poeta;
    novo->prox = lista->inicio;
    lista->inicio = novo;

    return lista;
}

ListaPoetas* Insere_poeta_fim(ListaPoetas* lista, Poetas poeta) {
    if (lista == NULL) {
        return lista;
    }

    NoPoeta *novo = (NoPoeta*)malloc(sizeof(NoPoeta));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o novo no!\n");
        exit(1);
    }
    novo->poeta = poeta;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        NoPoeta *atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }

    return lista;
}

ListaPoetas* Remove_poeta(ListaPoetas* lista, int id) {
    if (lista == NULL || lista->inicio == NULL) {
        return lista;
    }

    NoPoeta *atual = lista->inicio;
    NoPoeta *anterior = NULL;

    while (atual != NULL && atual->poeta.id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            lista->inicio = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
    }

    return lista;
}

Poetas* Consulta_poeta(ListaPoetas* lista, int id) {
    if (lista == NULL || lista->inicio == NULL) {
        return NULL;
    }

    NoPoeta *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->poeta.id == id) {
            return &atual->poeta;
        }
        atual = atual->prox;
    }
    return NULL;
}

void Exibe_lista(ListaPoetas* lista) {
    if (lista == NULL || lista->inicio == NULL) {
        printf("Lista de poetas vazia!\n");
        return;
    }

    printf("Lista de Poetas:\n");
    NoPoeta *atual = lista->inicio;
    while (atual != NULL) {
        printf("ID: %d\n", atual->poeta.id);
        printf("Nome: %s\n", atual->poeta.nome);
        printf("Poesia: %s\n\n", atual->poeta.poema);
        atual = atual->prox;
    }
}

int E_vazia(ListaPoetas* lista) {
    if (lista == NULL) {
        return -1;
    }
    return (lista->inicio == NULL);
}


void Ordena_lista_id(ListaPoetas* lista) {
    if (lista == NULL || lista->inicio == NULL) {
        return;
    }
    NoPoeta *i, *j, *anterior;
    int trocou;

    do {
        trocou = 0;
        anterior = NULL;
        i = lista->inicio;
        j = i->prox;

        while (j != NULL) {
            if (i->poeta.id > j->poeta.id) {
                if (anterior != NULL) {
                    anterior->prox = j;
                } else {
                    lista->inicio = j;
                }
                i->prox = j->prox;
                j->prox = i;
                anterior = j;
                trocou = 1;
                j = i->prox;
            } else {
                anterior = i;
                i = j;
                j = j->prox;
            }
        }
    } while (trocou);
}


ListaPoetas* Mescla_listas(ListaPoetas* lista1, ListaPoetas* lista2) {
    if (lista1 == NULL || lista2 == NULL) {
        return NULL;
    }

    ListaPoetas* lista_mesclada = Cria_lista();

    NoPoeta *atual1 = lista1->inicio;
    NoPoeta *atual2 = lista2->inicio;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->poeta.id < atual2->poeta.id) {
            atual1 = atual1->prox;
        } else if (atual1->poeta.id > atual2->poeta.id) {
            atual2 = atual2->prox;
        } else {
            lista_mesclada = Insere_poeta(lista_mesclada, atual1->poeta);
            atual1 = atual1->prox;
            atual2 = atual2->prox;
        }
    }

    return lista_mesclada;
}

int Salva_lista(ListaPoetas* lista, const char *nome_arquivo) {
    if (lista == NULL) {
        return 0;
    }

    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arquivo);
        return 0;
    }

    NoPoeta *atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arquivo, "%d;%s;%s\n", atual->poeta.id, atual->poeta.nome, atual->poeta.poema);
        atual = atual->prox;
    }

    fclose(arquivo);
    return 1;
}
