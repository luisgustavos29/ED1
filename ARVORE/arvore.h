#ifndef _ARVORE_H_
#define _ARVORE_H_

// Estrutura do n� da �rvore
struct no {
    int info;
    struct no* esq;
    struct no* dir;
    struct no* pai; // Para facilitar a implementa��o do espelho
};

// Fun��o para criar um novo n�
struct no* criar(int info);

// Fun��o para inserir um valor na �rvore
struct no* inserir(struct no* raiz, int info);

// Fun��o para encontrar o n� com o valor m�nimo na sub�rvore
struct no* minimo(struct no* no);

// Fun��o para remover um valor da �rvore
struct no* remover(struct no* raiz, int info);

// Fun��es adicionais

// Fun��o para contar o n�mero de n�s da �rvore
int contar_nos(struct no* raiz);

// Fun��o para contar o n�mero de n�s n�o folha da �rvore
int contar_nos_nao_folha(struct no* raiz);

// Fun��o para contar o n�mero de n�s folha da �rvore
int contar_nos_folha(struct no* raiz);

// Fun��o para calcular a altura da �rvore
int altura(struct no* raiz);

// Fun��o para encontrar o maior n�mero da �rvore
int maior(struct no* raiz);

// Fun��o para imprimir a �rvore (opcional)
void imprimir_arvore(struct no* raiz, int espaco);

// Fun��o para espelhar a �rvore
void espelhar_arvore(struct no* raiz);

#endif
