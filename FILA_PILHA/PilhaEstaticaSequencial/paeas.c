#include <stdio.h>
#include "paeas.h"

void Cria_pilha(Pilha *Ptp) {
    Ptp->topo = -1; // Inicializa o topo da pilha
}

int E_vazia(Pilha *Ptp) {
    return (Ptp->topo == -1);
}

int E_cheia(Pilha *Ptp) {
    return (Ptp->topo == MAX - 1);
}

// Insere um elemento na pilha
int Push(Pilha *Ptp, int elem) {
    if (E_cheia(Ptp)) {
        return 0; // Pilha cheia
    } else {
        Ptp->topo++;
        Ptp->pilha[Ptp->topo] = elem;
        printf("A��o com ID %d inserido na pilha.\n", elem);
        return 1;
    }
}

// Remove o elemento do topo da pilha
int Pop(Pilha *Ptp, int *elem) {
    if (E_vazia(Ptp)) {
        return 0; // Pilha vazia
    } else {
        *elem = Ptp->pilha[Ptp->topo];
        Ptp->topo--;
        printf("A��o com ID %d removido da pilha.\n", *elem);
        return 1;
    }
}

// Retorna o elemento do topo da pilha sem remov�-lo
int Top(Pilha *Ptp, int *elem) {
    if (E_vazia(Ptp)) {
        return 0; // Pilha vazia
    } else {
        *elem = Ptp->pilha[Ptp->topo];
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
    for (int i = Ptp->topo; i >= 0; i--) {
        printf("%d ", Ptp->pilha[i]);
    }
    printf("\n");
}
