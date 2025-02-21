#include <stdio.h>
#include <stdlib.h>
#include "lladae.h"

int main() {
    Lista* lista1 = Cria_lista();
    Lista* lista2 = Cria_lista();
    int opcao, elem, pos, lista_escolhida;
    char nome_arquivo[100];

    do {
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Exibir\n");
        printf("4. Salvar\n");
        printf("5. Acessar elemento\n");
        printf("6. Ordenar\n");
        printf("7. Mesclar listas\n");
        printf("8. Interseção de listas\n"); // Adicionando opção de interseção
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Em qual lista você deseja inserir (1 ou 2)? ");
                scanf("%d", &lista_escolhida);
                printf("Digite o elemento a inserir: ");
                scanf("%d", &elem);

                if (lista_escolhida == 1) {
                    lista1 = Insere_elem(lista1, elem);
                } else if (lista_escolhida == 2) {
                    lista2 = Insere_elem(lista2, elem);
                } else {
                    printf("Opção de lista inválida!\n");
                }

                break;
            case 2:
                printf("Em qual lista você deseja remover (1 ou 2)? ");
                scanf("%d", &lista_escolhida);

                if (lista_escolhida == 1) {
                    printf("Digite o elemento a remover: ");
                    scanf("%d", &elem);
                    lista1 = Remove_elem(lista1, elem);
                } else if (lista_escolhida == 2) {
                    printf("Digite o elemento a remover: ");
                    scanf("%d", &elem);
                    lista2 = Remove_elem(lista2, elem);
                } else {
                    printf("Opção de lista inválida!\n");
                }

                break;
            case 3:
                printf("Exibir lista 1: \n");
                Exibe_lista(lista1);
                printf("Exibir lista 2: \n");
                Exibe_lista(lista2);
                break;
            case 4:
                printf("Digite o nome do arquivo para salvar a lista 1: ");
                scanf("%s", nome_arquivo);
                Salva_lista(lista1, nome_arquivo);

                printf("Digite o nome do arquivo para salvar a lista 2: ");
                scanf("%s", nome_arquivo);
                Salva_lista(lista2, nome_arquivo);
                break;
            case 5:
                printf("Em qual lista você deseja acessar o elemento (1 ou 2)? ");
                scanf("%d", &lista_escolhida);
                printf("Digite a posição do elemento: ");
                scanf("%d", &pos);

                if (lista_escolhida == 1) {
                    if (Consulta_nodo(lista1, pos, &elem)) {
                        printf("O elemento na posição %d da lista 1 é: %d\n", pos, elem);
                    } else {
                        printf("Posição inválida.\n");
                    }
                } else if (lista_escolhida == 2) {
                    if (Consulta_nodo(lista2, pos, &elem)) {
                        printf("O elemento na posição %d da lista 2 é: %d\n", pos, elem);
                    } else {
                        printf("Posição inválida.\n");
                    }
                } else {
                    printf("Opção de lista inválida!\n");
                }
                break;
            case 6:
                printf("Ordenar lista 1: \n");
                lista1 = Ordena_lista(lista1);
                printf("Ordenar lista 2: \n");
                lista2 = Ordena_lista(lista2);
                break;
            case 7:
                printf("Mesclando listas 1 e 2...\n");
                Lista* lista_mesclada = Mescla_listas(lista1, lista2);
                printf("Lista mesclada: \n");
                Exibe_lista(lista_mesclada);
                Libera_lista(lista_mesclada);
                break;
            case 8:
                printf("Calculando a interseção das listas 1 e 2...\n");
                Lista* lista_intersecao = Intersecao_listas(lista1, lista2);
                printf("Lista interseção: \n");
                Exibe_lista(lista_intersecao);
                Libera_lista(lista_intersecao);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    Libera_lista(lista1);
    Libera_lista(lista2);
    return 0;
}
