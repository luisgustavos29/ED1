typedef struct no Lista;

struct no {
              int info;
              struct no* prox;
           };

Lista* Cria_lista(void);
Lista* Libera_lista(Lista* Ptl);
int E_vazia(Lista* Ptl);
int E_cheia(Lista* Ptl);
Lista* Insere_elem(Lista* Ptl, int elem);
Lista* Remove_elem(Lista* Ptl, int elem);
int Tamanho_lista(Lista* Ptl);
int Consulta_nodo(Lista* Ptl, int pos, int *elem);
