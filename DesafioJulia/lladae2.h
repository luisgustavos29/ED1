#ifndef INGRESSOS_H
#define INGRESSOS_H

#define MAX_FILMES 10
#define MAX_ASSENTOS 10

typedef struct Filme Filme;
typedef struct Ingresso Ingresso;
typedef struct No No;

struct Filme {
    char nome[50];
    int lotacao;
    No *ingressosDisponiveis;
    Filme *proximo;
};

struct Ingresso {
    int filme;
    int assento;
};

struct No {
    Ingresso ingresso;
    No *proximo;
};

Filme* criarFilme(char nome[], int lotacao);
void inserirFilme(Filme **listaFilmes, Filme *novoFilme);
void exibirFilmes(Filme *listaFilmes);
Filme* encontrarFilme(Filme *listaFilmes, char nome[]);

No* criarNo(int filme, int assento);
void inserirNo(No **listaIngressos, No *novoNo);
void removerNo(No **listaIngressos, int filme, int assento);
void exibirNos(No *listaNos);
No* encontrarNo(No *listaNos, int assento);

void venderIngresso(Filme *listaFilmes);
void cancelarIngresso(Filme *listaFilmes);
void listarIngressosDisponiveis(Filme *listaFilmes);
void exibirIngressosVendidos(No *listaIngressosVendidos);

#endif
