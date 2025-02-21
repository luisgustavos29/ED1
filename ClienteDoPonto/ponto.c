#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto {
  float x;
  float y;
};

Ponto* pto_cria (float x, float y)
{
   Ponto* p = (Ponto*) malloc(sizeof(Ponto));
   if (p != NULL)
   {
      p->x = x;
      p->y = y;
   }

   return p;
}

Ponto* pto_libera (Ponto* p)
{
    free(p);
    p=NULL;
    return p;
}

void pto_acessa (Ponto* p, float* x, float* y)
{
  if (p != NULL)
  {
   *x = p->x;
   *y = p->y;
  }
}

void pto_atribui (Ponto* p, float x, float y)
{
  if(p != NULL)
  {
   p->x = x;
   p->y = y;
  }
}

float pto_distancia (Ponto* p1, Ponto* p2)
{
   float d = -1;
   float dx, dy;
   if (p1!=NULL && p2!=NULL)
   {
      dx = p2->x - p1->x;
      dy = p2->y - p1->y;
      d =  sqrt(dx*dx + dy*dy);
   }
   return d;
}
