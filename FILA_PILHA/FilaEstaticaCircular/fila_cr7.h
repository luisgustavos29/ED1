#ifndef FILA_CR7_H
#define FILA_CR7_H
#define TAM_MAX 1000

typedef struct {
    int ids[TAM_MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaCR7;

// Inicializa a fila
void Inicializa_filaCR7(FilaCR7* f);

// Adiciona um f� na fila
int EnfileiraCR7(FilaCR7* f, int id);

// Remove o f� na frente da fila
int DesenfileiraCR7(FilaCR7* f, int* id);

// Verifica se a fila est� vazia
int E_vaziaCR7(FilaCR7* f);

// Verifica se a fila est� cheia
int E_cheiaCR7(FilaCR7* f);

// Mostra a fila
void ExibeCR7(FilaCR7* f);

#endif
