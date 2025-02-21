#ifndef FILA2_H
#define FILA2_H
#define TAM_MAX 10

typedef struct {
    int info[TAM_MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void Inicializa_fila(Fila* f);
int E_vazia(Fila* f);
int E_cheia(Fila* f);
void Enfileira(Fila* f, int elem);
int Desenfileira(Fila* f, int* elem);
int Consulta_fila(Fila* f, int* elem);
void Exibe(Fila* f);

#endif
