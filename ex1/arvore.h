#ifndef _ARVORE_H_
#define _ARVORE_H_
#define MAX_NOS 100 // Define o tamanho máximo da árvore

// Estrutura do nó da árvore
struct no {
    char info;
    int esq;
    int dir;
};

// Estrutura da árvore
struct arvore {
    struct no nos[MAX_NOS];
    int raiz;
    int tamanho;
};

// Função para criar uma nova árvore
struct arvore* criar_arvore();

// Função para inserir um valor na árvore
void inserir(struct arvore* arv, char info);

// Função para buscar um valor na árvore
int buscar(struct arvore* arv, char info);

// Funções para imprimir em diferentes ordens
void imprimir_infix(struct arvore* arv, int posicao);
void imprimir_prefix(struct arvore* arv, int posicao);
void imprimir_posfix(struct arvore* arv, int posicao);

#endif
