#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lladae.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
    Lista* lista = Cria_lista();
    Lista* l2 = Cria_lista(); // Segunda lista para a interse��o
    int opcao, elem, pos, valor_removido;
    char nome_arquivo[50];

    // Insere elementos na segunda lista (l2) para teste
    l2 = Insere_elem(l2, 1);
    l2 = Insere_elem(l2, 3);
    l2 = Insere_elem(l2, 5);
    l2 = Insere_elem(l2, 7);

    do {
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Exibir\n");
        printf("4. Salvar\n");
        printf("5. Acessar um determinado elemento\n");
        printf("6. Ordenar\n");
        printf("7. Mesclar Listas\n");
        printf("8. Sair do programa\n");
        printf("Digite a op��o desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elem);
                lista = Insere_elem(lista, elem);
                break;

            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &valor_removido);
                lista = Remove_elem(lista, valor_removido);
                break;

            case 3:
                Exibe_lista(lista);
                break;

            case 4:
                printf("Digite o nome do arquivo para salvar a lista: ");
                scanf("%s", nome_arquivo);
                Salva_lista(lista, nome_arquivo);
                break;

            case 5:
                printf("Digite a posi��o do elemento a ser acessado: ");
                scanf("%d", &pos);
                if (Consulta_nodo(lista, pos, &elem)) {
                    printf("Elemento na posi��o %d: %d\n", pos, elem);
                } else {
                    printf("Posi��o inv�lida.\n");
                }
                break;

            case 6:
                lista = Ordena_lista(lista); // Fun��o para ordenar a lista (implementada posteriormente)
                printf("Lista ordenada!\n");
                break;

            case 7:
                // Implementar a fun��o para mesclar listas (Intersecao_listas)
                lista = Ordena_lista(lista); // Ordena a lista principal
                Lista* lista_intersecao = Intersecao_listas(lista, l2);
                printf("Lista resultante da interse��o:\n");
                Exibe_lista(lista_intersecao);
                lista_intersecao = Libera_lista(lista_intersecao); // Libera a lista da interse��o
                break;

            case 8:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Op��o inv�lida.\n");
        }
    } while (opcao != 8);

    lista = Libera_lista(lista);
    l2 = Libera_lista(l2); // Libera a segunda lista

    return 0;
}
