#ifndef _ARVORE_H_
#define _ARVORE_H_

// Estrutura do nó da árvore
struct no {
    int info;
    struct no* esq;
    struct no* dir;
    struct no* pai; // Para facilitar a implementação do espelho
};

// Função para criar um novo nó
struct no* criar(int info);

// Função para inserir um valor na árvore
struct no* inserir(struct no* raiz, int info);

// Função para encontrar o nó com o valor mínimo na subárvore
struct no* minimo(struct no* no);

// Função para remover um valor da árvore
struct no* remover(struct no* raiz, int info);

// Funções adicionais

// Função para contar o número de nós da árvore
int contar_nos(struct no* raiz);

// Função para contar o número de nós não folha da árvore
int contar_nos_nao_folha(struct no* raiz);

// Função para contar o número de nós folha da árvore
int contar_nos_folha(struct no* raiz);

// Função para calcular a altura da árvore
int altura(struct no* raiz);

// Função para encontrar o maior número da árvore
int maior(struct no* raiz);

// Função para imprimir a árvore (opcional)
void imprimir_arvore(struct no* raiz, int espaco);

// Função para espelhar a árvore
void espelhar_arvore(struct no* raiz);

#endif
