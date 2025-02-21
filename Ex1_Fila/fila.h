typedef struct no {
    int info;
    struct no* prox;
} No;

typedef struct {
    No* IF;
    No* FF;
    int tamanho;
} Fila;

Fila* Cria_fila(void);
void Libera_fila(Fila* f);
int E_vazia(Fila* f);
int E_cheia(Fila* f);
void Enfileira(Fila* f, int elem);
int Desenfileira(Fila* f, int* elem);
int Consulta_fila(Fila* f, int* elem);
void Exibe(Fila* f);
