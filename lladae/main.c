#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lladae.h"

void Exibe_lista(Lista* Ptl) {
    if (E_vazia(Ptl)) {
        printf("A lista está vazia.\n");
        return;
    }
    Lista* pt = Ptl;
    printf("Lista: ");
    while (pt != NULL) {
        printf("%d ", pt->info);
        pt = pt->prox;
    }
    printf("\n");
}

void Salva_lista(Lista* Ptl, char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    Lista* pt = Ptl;
    while (pt != NULL) {
        fprintf(arquivo, "%d ", pt->info);
        pt = pt->prox;
    }
    fclose(arquivo);
    printf("Lista salva em %s.\n", nome_arquivo);
}

int main() {
    Lista* lista = Cria_lista();
    setlocale(LC_ALL,"Portuguese");
    int elem;


    printf("Digite os elementos da lista (-1 para finalizar):\n");
    scanf("%d", &elem);
    while (elem != -1) {
        lista = Insere_elem(lista, elem);
        scanf("%d", &elem);
    }


    printf("\nLista após as inserções:\n");
    Exibe_lista(lista);


    int valor_removido;
    printf("\nDigite o valor a ser removido da lista: ");
    scanf("%d", &valor_removido);
    lista = Remove_elem(lista, valor_removido);


    printf("\nLista após a remoção do nó:\n");
    Exibe_lista(lista);


    char nome_arquivo[50];
    printf("\nDigite o nome do arquivo para salvar a lista: ");
    scanf("%s", nome_arquivo);
    Salva_lista(lista, nome_arquivo);


    lista = Libera_lista(lista);

    return 0;
}
