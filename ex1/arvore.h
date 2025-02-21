#ifndef _ARVORE_H_
#define _ARVORE_H_
#define MAX_NOS 100 // Define o tamanho m�ximo da �rvore

// Estrutura do n� da �rvore
struct no {
    char info;
    int esq;
    int dir;
};

// Estrutura da �rvore
struct arvore {
    struct no nos[MAX_NOS];
    int raiz;
    int tamanho;
};

// Fun��o para criar uma nova �rvore
struct arvore* criar_arvore();

// Fun��o para inserir um valor na �rvore
void inserir(struct arvore* arv, char info);

// Fun��o para buscar um valor na �rvore
int buscar(struct arvore* arv, char info);

// Fun��es para imprimir em diferentes ordens
void imprimir_infix(struct arvore* arv, int posicao);
void imprimir_prefix(struct arvore* arv, int posicao);
void imprimir_posfix(struct arvore* arv, int posicao);

#endif
