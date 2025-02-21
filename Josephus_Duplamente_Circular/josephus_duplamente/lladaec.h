#ifndef LLADAEC_H
#define LLADAEC_H

struct pessoa {
    struct pessoa *prox;
    struct pessoa *ant;
    char nome[50];
    int posicao;
};

typedef struct pessoa Pessoa;

Pessoa* Cria_lista(void);
Pessoa* Insere_elem(Pessoa* Ptl, char *nome);
void Exibir_lista(Pessoa* Ptl);
Pessoa* Remove_elem(Pessoa* Ptl, int jogador, int *posicao);
Pessoa *Libera_lista(Pessoa *Ptl);
void Salvar_relacionados(Pessoa *Ptl, const char *nome, const char *tipo);
int Tamanho_Lista(Pessoa* Ptl);
void Salvar_Ganhador(Pessoa *Ptl);

#endif

