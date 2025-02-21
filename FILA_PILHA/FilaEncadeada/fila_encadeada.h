#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H

typedef struct No {
    int id;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} FilaCR7;

// Inicializa a fila
void Inicializa_filaCR7(FilaCR7* f);

// Adiciona um fã na fila
int EnfileiraCR7(FilaCR7* f, int id);

// Remove o fã na frente da fila
int DesenfileiraCR7(FilaCR7* f, int* id);

// Verifica se a fila está vazia
int E_vaziaCR7(FilaCR7* f);

// Mostra a fila
void ExibeCR7(FilaCR7* f);

#endif
