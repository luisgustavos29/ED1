#ifndef PAEAS_H
#define PAEAS_H
#define MAX 1000

typedef struct {
    int pilha[MAX];
    int topo;
} Pilha;

void Cria_pilha(Pilha *Ptp);
int E_cheia(Pilha *Ptp);
int E_vazia(Pilha *Ptp);
int Push(Pilha *Ptp, int elem);
int Pop(Pilha *Ptp, int *elem);
int Top(Pilha *Ptp, int *elem);
void Listar_pilha(Pilha *Ptp);

#endif
