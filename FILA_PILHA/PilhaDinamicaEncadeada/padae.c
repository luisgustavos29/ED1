#include <stdio.h>
#include <stdlib.h>
#include "padae.h"

// Inicializa a pilha
void Cria_pilha(Pilha *Ptp) {
    Ptp->topo = NULL;
}

// Verifica se a pilha est� vazia
int E_vazia(Pilha *Ptp) {
    return (Ptp->topo == NULL);
}

// Insere um elemento na pilha
int Push(Pilha *Ptp, int elem) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (!novo_no) {
        return 0; // Falha na aloca��o
    }
    novo_no->dado = elem;
    novo_no->proximo = Ptp->topo;
    Ptp->topo = novo_no;
    printf("A��o com ID %d inserido na pilha.\n", elem);
    return 1;
}

// Remove o elemento do topo da pilha
int Pop(Pilha *Ptp, int *elem) {
    if (E_vazia(Ptp)) {
        return 0; // Pilha vazia
    } else {
        No *temp = Ptp->topo;
        *elem = temp->dado;
        Ptp->topo = temp->proximo;
        free(temp);
        printf("A��o com ID %d removido da pilha.\n", *elem);
        return 1;
    }
}

// Retorna o elemento do topo da pilha sem remov�-lo
int Top(Pilha *Ptp, int *elem) {
    if (E_vazia(Ptp)) {
        return 0; // Pilha vazia
    } else {
        *elem = Ptp->topo->dado;
        return 1;
    }
}

// Fun��o para listar os elementos da pilha
void Listar_pilha(Pilha *Ptp) {
    if (E_vazia(Ptp)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("ID�s das a��es presentes na pilha:\n");
    No *atual = Ptp->topo;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

// Libera a mem�ria da pilha
void Libera_pilha(Pilha *Ptp) {
    while (!E_vazia(Ptp)) {
        int elem;
        Pop(Ptp, &elem);
    }
}
