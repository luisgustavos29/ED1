#include <stdio.h>
#include <stdlib.h>
#include "lladae.h"

Lista* Insere_poeta(Lista* Ptl, int id, char nome[], char poema[]) {
    Lista *Ptnodo, *aux;
    Ptnodo = (Lista*)malloc(sizeof(struct no));
    if (Ptnodo == NULL)
       return Ptl;

    // Alocar memória para o nome e poema dinamicamente
    Ptnodo->info.id = id;
    Ptnodo->info.nome = (char *)malloc(strlen(nome) + 1);
    strcpy(Ptnodo->info.nome, nome);
    Ptnodo->info.poema = (char *)malloc(strlen(poema) + 1);
    strcpy(Ptnodo->info.poema, poema);

    if (Ptl == NULL) // lista vazia
    {
        Ptl = Ptnodo;
        Ptnodo->prox = Ptl;
    }
    else //lista nao esta vazia, insere no final
     {
        Ptnodo->prox = Ptl->prox;
        Ptl->prox = Ptnodo;
        Ptl = Ptnodo;
     }
    return Ptl;
}

// Remove um Poeta da lista
Lista* Remove_poeta(Lista* Ptl, int id) {
  Lista *ant, *atual, *aux;

  if (Ptl == NULL) //lista vazia
    return Ptl;

  atual = Ptl->prox;
  ant = Ptl;

  while (atual!= Ptl && atual->info.id != id)
  {
     ant = atual;
     atual = atual->prox;
  }

  if (atual->info.id == id)
  {
     if (atual == ant)
            Ptl = NULL;
     else {
           ant->prox = atual->prox;
           if (atual == Ptl) //ultimo nodo a ser removido
             Ptl = ant;
          }

    free(atual->info.nome); // Libera a memória do nome
    free(atual->info.poema); // Libera a memória do poema
    free(atual);
  }

  return Ptl;
}

// Consulta o Poeta em uma posição específica da lista
int Consulta_nodo(Lista* Ptl, int pos, Poeta *poeta) {
       int cont;
       Lista *pt;
       if( Ptl == NULL || pos <= 0)
         return 0;

       cont = 1;
       pt = Ptl->prox;
       while(pt != Ptl && cont < pos)
       {
           pt=pt->prox;
           cont++;
       }

if (cont == pos)
       {
         *poeta = pt->info;
         return 1;
       }
       else return 0;
}
