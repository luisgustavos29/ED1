#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Fun��o para criar um novo n�
struct no* criar(int info) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    if (novo == NULL) {
        printf("Erro na aloca��o de mem�ria.\n");
        exit(1);
    }
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    return novo;
}

// Fun��o para inserir um valor na �rvore
struct no* inserir(struct no* raiz, int info) {
    struct no* atual = raiz;
    struct no* anterior = NULL;

    while (atual != NULL) {
        anterior = atual;
        if (info < atual->info) {
            atual = atual->esq;
        } else if (info > atual->info) { // Evitar inser��o de duplicados
            atual = atual->dir;
        } else {
            printf("Valor duplicado n�o pode ser inserido.\n");
            return raiz; // Valor duplicado, n�o insere
        }
    }

    struct no* novo = criar(info);
    if (anterior == NULL) {
        return novo;
    } else if (info < anterior->info) {
        anterior->esq = novo;
    } else {
        anterior->dir = novo;
    }
    novo->pai = anterior;
    return raiz;
}

// Fun��o para encontrar o n� com o valor m�nimo na sub�rvore
struct no* minimo(struct no* no) {
    while (no->esq != NULL) {
        no = no->esq;
    }
    return no;
}

// Fun��o para remover um valor da �rvore
struct no* remover(struct no* raiz, int info) {
    struct no* no = raiz;
    struct no* pai = NULL;

    while (no != NULL && no->info != info) {
        pai = no;
        if (info < no->info) {
            no = no->esq;
        } else {
            no = no->dir;
        }
    }

    if (no == NULL) {
        return raiz; // Valor n�o encontrado
    }

    if (no->esq == NULL && no->dir == NULL) {
        if (pai != NULL) {
            if (pai->esq == no) {
                pai->esq = NULL;
            } else {
                pai->dir = NULL;
            }
        } else {
            raiz = NULL;
        }
        free(no);

    } else if (no->esq == NULL || no->dir == NULL) {
        struct no* filho = (no->esq != NULL) ? no->esq : no->dir;
        if (pai != NULL) {
            if (pai->esq == no) {
                pai->esq = filho;
            } else {
                pai->dir = filho;
            }
            filho->pai = pai;
        } else {
            raiz = filho;
            filho->pai = NULL;
        }
        free(no);

    } else {
        struct no* sucessor = minimo(no->dir);
        no->info = sucessor->info;

        if (sucessor->pai != no) {
            sucessor->pai->esq = sucessor->dir;
            if (sucessor->dir != NULL) {
                sucessor->dir->pai = sucessor->pai;
            }
        } else {
            no->dir = sucessor->dir;
            if (sucessor->dir != NULL) {
                sucessor->dir->pai = no;
            }
        }
        free(sucessor);
    }

    return raiz;
}

// Fun��es adicionais

// Fun��o para contar o n�mero de n�s da �rvore
int contar_nos(struct no* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + contar_nos(raiz->esq) + contar_nos(raiz->dir);
    }
}

// Fun��o para contar o n�mero de n�s n�o folha da �rvore
int contar_nos_nao_folha(struct no* raiz) {
    if (raiz == NULL || (raiz->esq == NULL && raiz->dir == NULL)) {
        return 0;
    } else {
        return 1 + contar_nos_nao_folha(raiz->esq) + contar_nos_nao_folha(raiz->dir);
    }
}

// Fun��o para contar o n�mero de n�s folha da �rvore
int contar_nos_folha(struct no* raiz) {
    if (raiz == NULL) {
        return 0;
    } else if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    } else {
        return contar_nos_folha(raiz->esq) + contar_nos_folha(raiz->dir);
    }
}

// Fun��o para calcular a altura da �rvore
int altura(struct no* raiz) {
    if (raiz == NULL) {
        return -1; // Retorna -1 para �rvore vazia
    } else {
        int altura_esq = altura(raiz->esq);
        int altura_dir = altura(raiz->dir);
        // Retorna o maior entre as alturas do filho esquerdo e direito, mais 1 (para o n� atual)
        return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
    }
}

// Fun��o para encontrar o maior n�mero da �rvore
int maior(struct no* raiz) {
    if (raiz == NULL) {
        printf("A �rvore � vazia.\n");
        return -1; // Retorna -1 para indicar que a �rvore � vazia
    } else {
        struct no* atual = raiz;
        while (atual->dir != NULL) {
            atual = atual->dir;
        }
        return atual->info;
    }
}

// Fun��o para imprimir a �rvore (opcional)
void imprimir_arvore(struct no* raiz, int espaco) {
    if (raiz == NULL) return;

    espaco += 10; // Aumenta o espa�o entre os n�s

    // Processa o filho direito primeiro
    imprimir_arvore(raiz->dir, espaco);

    // Imprime o n� atual
    printf("\n");
    for (int i = 10; i < espaco; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->info);

    // Processa o filho esquerdo
    imprimir_arvore(raiz->esq, espaco);
}

// Fun��o para espelhar a �rvore
void espelhar_arvore(struct no* raiz) {
    if (raiz == NULL) {
        return;
    }

    // Troca os filhos esquerdo e direito do n� atual
    struct no* temp = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = temp;

    // Chama a fun��o recursivamente para os filhos
    espelhar_arvore(raiz->esq);
    espelhar_arvore(raiz->dir);
}
