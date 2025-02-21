#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lladae.h"

int main() {
    Lista lista = Cria_lista();
    setlocale(LC_ALL, "Portuguese");

    int opcao, id;
    char nome[100], poema[500]; // Tamanho máximo dos arrays

    do {
        printf("\n---------- RODA DE POESIA AMOR E AFETO ----------\n");
        printf("\n1. Cadastrar poeta.\n");
        printf("2. Remover poeta.\n");
        printf("3. Consultar poeta.\n");
        printf("4. Exibir lista de poetas cadastrados.\n");
        printf("5. Sair.\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                setbuf(stdin, NULL);
                printf("\nDigite o ID do poeta: ");
                scanf("%d", &id);
                getchar();

                if (Consulta_poeta(lista, id) != NULL) {
                    printf("Erro: ID de poeta já está cadastrado!\n");
                    break;
                }

                printf("Digite o nome do poeta: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite o poema:\n");
                fgets(poema, 500, stdin);
                poema[strcspn(poema, "\n")] = '\0';

                lista = Insere_poeta(lista, id, nome, poema);
                printf("Poeta inserido com sucesso!\n");
                break;

            case 2:
                printf("\nDigite o ID do poeta a remover: ");
                scanf("%d", &id);
                if (Consulta_poeta(lista, id) != NULL) {
                    lista = Remove_poeta(lista, id);
                    printf("Poeta removido com sucesso!\n");
                } else {
                    printf("ID de poeta não cadastrado.\n");
                }
                break;

            case 3:
                printf("\nDigite o ID do poeta a consultar: ");
                scanf("%d", &id);
                Poeta* poeta_encontrado = Consulta_poeta(lista, id);
                if (poeta_encontrado != NULL) {
                    printf("ID: %d\n", poeta_encontrado->id);
                    printf("Nome: %s\n", poeta_encontrado->nome);
                    printf("Poema: \n%s\n", poeta_encontrado->poema);
                } else {
                    printf("Poeta não encontrado!\n");
                }
                break;

            case 4:
                Exibe_lista(lista);
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 5);

    lista = Libera_lista(lista);

    return 0;
}
