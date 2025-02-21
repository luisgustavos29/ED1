#ifndef PADAE_H
#define PADAE_H

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void Cria_pilha(Pilha *Ptp);
int E_vazia(Pilha *Ptp);
int Push(Pilha *Ptp, int elem);
int Pop(Pilha *Ptp, int *elem);
int Top(Pilha *Ptp, int *elem);
void Listar_pilha(Pilha *Ptp);
void Libera_pilha(Pilha *Ptp);

#endif
