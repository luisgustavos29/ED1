#include <stdio.h>
#include <stdlib.h>
#include "llaeas.h"
#include <string.h>
#include <locale.h>

void Exibe_lista(Lista* Ptl) {
    if (Ptl == NULL) {
        printf("Lista inválida!\n");
        return;
    }
    if (E_vazia(Ptl)) {
        printf("Lista vazia!\n");
        return;
    }
    printf("Elementos da lista: ");
    for (int i = 0; i < Ptl->FL; i++) {
        printf("%d ", Ptl->dados[i]);
    }
    printf("\n");
}

void Grava_lista(Lista* Ptl, char* nome_arquivo) {
    if (Ptl == NULL) {
        printf("Lista inválida!\n");
        return;
    }
    FILE* arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arquivo);
        return;
    }
    for (int i = 0; i < Ptl->FL; i++) {
        fprintf(arquivo, "%d ", Ptl->dados[i]);
    }
    fclose(arquivo);
    printf("Lista gravada no arquivo %s!\n", nome_arquivo);
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    Lista* lista = Cria_lista();

    if (lista == NULL) {
        printf("Erro ao criar a lista!\n");
        return 1;
    }

    int elem;
    printf("Digite os elementos da lista (digite -1 para finalizar):\n");
    do {
        scanf("%d", &elem);
        if (elem != -1) {
            lista = Insere_elem(lista, elem);
        }
    } while (elem != -1);

    printf("\nLista após as inserções:\n");
    Exibe_lista(lista);

    int elemento_remover;
    printf("Digite o elemento a ser removido: ");
    scanf("%d", &elemento_remover);
    lista = Remove_elem(lista, elemento_remover);

    printf("\nLista após a remoção:\n");
    Exibe_lista(lista);

    char nome_arquivo[100];
    printf("Digite o nome do arquivo para salvar a lista: ");
    scanf("%s", nome_arquivo);
    Grava_lista(lista, nome_arquivo);

    Libera_lista(lista);

    return 0;
}
