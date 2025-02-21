#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lladae2.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    Lista* lista1 = Cria_lista();
    Lista* lista2 = Cria_lista();
    int opcao, elemento;

    do {
        printf("\n\n\n---------------------------------------------------");
        printf("\nMENU PARA MANIPULAR A ORDENAÇÃO POR COMB SORT\n");
        printf("---------------------------------------------------\n");
        printf("\n1. Inserir na lista 1.\n");
        printf("2. Inserir na lista 2.\n");
        printf("3. Mostrar listas.\n");
        printf("4. Ordenar listas.\n");
        printf("5. Juntar listas.\n");
        printf("6. Sair.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Insira os elementos na lista 1 (-1 para encerrar):\n");
                while (1) {
                    printf("Insira: ");
                    scanf("%d", &elemento);
                    if (elemento == -1) break;
                    lista1 = Insere_elem(lista1, elemento);
                }
                printf("Inserção na lista 1 finalizada.\n");
                break;
            case 2:
                printf("Insira os elementos na lista 2 (-1 para parar):\n");
                while (1) {
                    printf("Insira: ");
                    scanf("%d", &elemento);
                    if (elemento == -1) break;
                    lista2 = Insere_elem(lista2, elemento);
                }
                printf("Inserção na lista 2 finalizada.\n");
                break;
            case 3:
                printf("\nLista 1: ");
                Imprime_lista(lista1);
                printf("Lista 2: ");
                Imprime_lista(lista2);
                break;
            case 4:
                    lista1 = CombSort(lista1);
                    lista2 = CombSort(lista2);
                    printf("\nLista 1 ordenada: ");
                    Imprime_lista(lista1);
                    printf("Lista 2 ordenada: ");
                    Imprime_lista(lista2);

                break;
            case 5: {
                Lista* lista_unida = Junta_listas(lista1, lista2);
                printf("\nListas unidas e ordenadas: ");
                Imprime_lista(lista_unida);
                Libera_lista(lista_unida);
                break;
            }
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);

    Libera_lista(lista1);
    Libera_lista(lista2);

    return 0;
}
