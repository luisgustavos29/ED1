#ifndef JULIA_H
#define JULIA_H

#include <stdbool.h>

#define MAX_FILMES 5
#define MAX_LOTACAO 10

struct Ingresso {
    char filme[50];
    int assento;
    struct Ingresso *proximo;
    struct Ingresso *anterior;
};
typedef struct Ingresso Ingresso;


extern const char *filmes[MAX_FILMES];

Ingresso *inicializarFilmes(Ingresso *listaDisponiveis);
Ingresso *adicionarIngressoVendido(Ingresso *listaVendidos, char *filme, int assento);
Ingresso *cancelarIngresso(Ingresso *listaVendidos, Ingresso *listaDisponiveis, char *filme, int assento);
void listarIngressosDisponiveis(Ingresso *listaDisponiveis, char *filme);
void listarIngressosVendidos(Ingresso *listaVendidos);
Ingresso *inserirNaLista(Ingresso *lista, char *filme, int assento);
Ingresso *removerDaLista(Ingresso *lista, char *filme, int assento);
bool ingressoDisponivel(Ingresso *listaDisponiveis, char *filme, int assento);
void mostrarAssentosDisponiveis(Ingresso *listaDisponiveis, char *filme);

#endif
