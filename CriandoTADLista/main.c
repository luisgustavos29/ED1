#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lista_poetas.h"

int main() {
    ListaPoetas* lista = Cria_lista();
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    Poetas novo_poeta;

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
                scanf("%d", &novo_poeta.id);
                getchar();

                if (Consulta_poeta(lista, novo_poeta.id) != NULL) {
                    printf("Erro: ID de poeta já está cadastrado!\n");
                    break;
                }

                printf("Digite o nome do poeta: ");
                gets(novo_poeta.nome);
                novo_poeta.nome[strcspn(novo_poeta.nome, "\n")] = '\0';

                printf("Digite o poema:\n");
                gets(novo_poeta.poema);
                novo_poeta.poema[strcspn(novo_poeta.poema, "\n")] = '\0';

                if (E_cheia(lista) == 1) {
                    printf("Lista de poetas cheia! Não é possível inserir mais poetas.\n");
                    break;
                }

                lista = Insere_poeta(lista, novo_poeta);
                printf("Poeta inserido com sucesso!\n");
                break;


            case 2:
                printf("\nDigite o ID do poeta a remover: ");
                scanf("%d", &novo_poeta.id);
                if (Consulta_poeta(lista, novo_poeta.id) != NULL) {
                    lista = Remove_poeta(lista, novo_poeta.id);
                    printf("Poeta removido com sucesso!\n");
                } else {
                    printf("ID de poeta não cadastrado.\n");
                }
                break;

            case 3:
                printf("\nDigite o ID do poeta a consultar: ");
                scanf("%d", &novo_poeta.id);
                Poetas* poeta_encontrado = Consulta_poeta(lista, novo_poeta.id);
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
