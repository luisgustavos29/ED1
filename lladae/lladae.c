#include <stdio.h>
#include <stdlib.h>
#include "lladae.h"

Lista* Cria_lista(void)
{

    return NULL;
}

Lista* Libera_lista(Lista *Ptl)
{
  Lista*   aux;

  while (Ptl!= NULL)
  {
    aux = Ptl;
    Ptl = Ptl->prox;
    free(aux);
  }

  return Ptl;
}

int E_vazia(Lista* Ptl)
{
   if (Ptl == NULL)
     return 1;
   else return 0;
}

int E_cheia(Lista* Ptl)
{
   return 0;
}

Lista* Insere_elem(Lista *Ptl, int elem) {
    Lista* Ptnodo;
    Ptnodo = (Lista*)malloc(sizeof(Lista));
    if (Ptnodo == NULL) {
       return Ptl;
    }
    Ptnodo->info = elem;

    if (Ptl == NULL) {
        Ptnodo->prox = NULL;
        return Ptnodo;
    }

    Lista *ultimo = Ptl;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }

    ultimo->prox = Ptnodo;
    Ptnodo->prox = NULL;

    return Ptl;
}

Lista* Remove_elem(Lista *Ptl, int elem) {
  Lista *ant, *atual;
  if (Ptl == NULL) {
    return Ptl;
  }

  atual = Ptl;
  ant = NULL;

  while (atual != NULL && atual->info != elem) {
    ant = atual;
    atual = atual->prox;
  }

  if (atual == NULL) {
    printf("Elemento %d não encontrado na lista.\n", elem);
    printf("Insira um elemento presente na lista: ");
    scanf("%d", &elem);
    return Remove_elem(Ptl, elem);
  }

  if (ant == NULL) {
    Ptl = atual->prox;
  } else {
    ant->prox = atual->prox;
  }

  free(atual);
  return Ptl;
}

int Tamanho_lista(Lista* Ptl)
{
  Lista* pt;
  int cont;
  pt = Ptl;
  cont = 0;
  while (pt != NULL)
  {
     cont++;
     pt = pt->prox;
  }
  return cont;
}

int Consulta_nodo(Lista* Ptl, int pos,int *elem)
{
       int cont = 1;
       Lista* pt;
       pt = Ptl;
       if (pos <= 0 || pt == NULL)
         return 0;
       while(pt != NULL && cont < pos)
        {
           pt=pt->prox;
           cont++;
       }
       if (pt == NULL)
         return 0;
       else {
               *elem = pt->info;
               return 1;
            }
    }
