#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lista_poetas.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
    ListaPoetas* lista1 = Cria_lista();
    ListaPoetas* lista2 = Cria_lista();
    ListaPoetas* lista_mesclada = NULL;

    int opcao;
    Poetas novo_poeta;
    char nome_arquivo[100];

    printf("Digite o nome do arquivo para carregar os dados: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arquivo);
    } else {
        while (fscanf(arquivo, "%d;%[^;];%[^\n]\n", &novo_poeta.id, novo_poeta.nome, novo_poeta.poema) != EOF) {
            if (Consulta_poeta(lista1, novo_poeta.id) == NULL && Consulta_poeta(lista2, novo_poeta.id) == NULL) {
                lista1 = Insere_poeta_fim(lista1, novo_poeta);
            }
        }
        fclose(arquivo);
    }

    do {
        printf("\n---------- RODA DE POESIA AMOR E AFETO ----------\n");
        printf("\n1- Gerenciar cadastro de poetas para roda de poesia nacional (Lista 1):\n");
        printf("2- Gerenciar cadastro de poetas para roda de poesia internacional (Lista 2):\n");
        printf("3- Mesclar Listas (Lista 3):\n");
        printf("4- Exibir todas as listas (1, 2 e 3):\n");
        printf("5- Salvar.\n");
        printf("6- Sair.\n");
        printf("\nDigite a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nGerenciando lista 1 (poetas nacionais):\n");
                printf("    a) Incluir.\n");
                printf("    b) Remover.\n");
                printf("    c) Consultar.\n");
                printf("    d) Ordenar.\n");
                printf("    e) Exibir.\n");
                printf("Digite a opção: ");
                char opcao_lista1;
                scanf(" %c", &opcao_lista1);

                switch (opcao_lista1) {
                    case 'a':
                        setbuf(stdin, NULL);
                        printf("\nDigite o ID do poeta: ");
                        scanf("%d", &novo_poeta.id);
                        getchar();

                        if (Consulta_poeta(lista1, novo_poeta.id) != NULL) {
                            printf("Erro: ID de poeta já está cadastrado!\n");
                            break;
                        }

                        printf("Digite o nome do poeta: ");
                        gets(novo_poeta.nome);
                        novo_poeta.nome[strcspn(novo_poeta.nome, "\n")] = '\0';

                        printf("Digite o poema:\n");
                        gets(novo_poeta.poema);
                        novo_poeta.poema[strcspn(novo_poeta.poema, "\n")] = '\0';

                        lista1 = Insere_poeta_fim(lista1, novo_poeta);
                        printf("Poeta inserido com sucesso na lista 1!\n");
                        break;

                    case 'b':
                        printf("\nDigite o ID do poeta a remover da lista 1: ");
                        scanf("%d", &novo_poeta.id);
                        if (Consulta_poeta(lista1, novo_poeta.id) != NULL) {
                            lista1 = Remove_poeta(lista1, novo_poeta.id);
                            printf("Poeta removido com sucesso da lista 1!\n");
                        } else {
                            printf("ID de poeta não cadastrado na lista 1.\n");
                        }
                        break;

                    case 'c':
                        printf("\nDigite o ID do poeta a consultar na lista 1: ");
                        scanf("%d", &novo_poeta.id);
                        Poetas* poeta_encontrado = Consulta_poeta(lista1, novo_poeta.id);
                        if (poeta_encontrado != NULL) {
                            printf("ID: %d\n", poeta_encontrado->id);
                            printf("Nome: %s\n", poeta_encontrado->nome);
                            printf("Poema: \n%s\n", poeta_encontrado->poema);
                        } else {
                            printf("Poeta não encontrado na lista 1!\n");
                        }
                        break;

                    case 'd':
                        Ordena_lista_id(lista1);
                        printf("Lista 1 ordenada por ID!\n");
                        break;

                    case 'e':
                        Exibe_lista(lista1);
                        break;

                    default:
                        printf("Opção inválida!\n");
                }
                break;

            case 2:
                printf("\nGerenciando lista 2 (poetas internacionais):\n");
                printf("    a) Incluir.\n");
                printf("    b) Remover.\n");
                printf("    c) Consultar.\n");
                printf("    d) Ordenar.\n");
                printf("    e) Exibir.\n");
                printf("Digite a opção: ");
                char opcao_lista2;
                scanf(" %c", &opcao_lista2);

                switch (opcao_lista2) {
                    case 'a':
                        setbuf(stdin, NULL);
                        printf("\nDigite o ID do poeta: ");
                        scanf("%d", &novo_poeta.id);
                        getchar();

                        if (Consulta_poeta(lista2, novo_poeta.id) != NULL) {
                            printf("Erro: ID de poeta já está cadastrado!\n");
                            break;
                        }

                        printf("Digite o nome do poeta: ");
                        gets(novo_poeta.nome);
                        novo_poeta.nome[strcspn(novo_poeta.nome, "\n")] = '\0';

                        printf("Digite o poema:\n");
                        gets(novo_poeta.poema);
                        novo_poeta.poema[strcspn(novo_poeta.poema, "\n")] = '\0';

                        lista2 = Insere_poeta_fim(lista2, novo_poeta);
                        printf("Poeta inserido com sucesso na lista 2!\n");
                        break;

                    case 'b':
                        printf("\nDigite o ID do poeta a remover da lista 2: ");
                        scanf("%d", &novo_poeta.id);
                        if (Consulta_poeta(lista2, novo_poeta.id) != NULL) {
                            lista2 = Remove_poeta(lista2, novo_poeta.id);
                            printf("Poeta removido com sucesso da lista 2!\n");
                        } else {
                            printf("ID de poeta não cadastrado na lista 2.\n");
                        }
                        break;

                    case 'c':
                        printf("\nDigite o ID do poeta a consultar na lista 2: ");
                        scanf("%d", &novo_poeta.id);
                        Poetas* poeta_encontrado2 = Consulta_poeta(lista2, novo_poeta.id);
                        if (poeta_encontrado2 != NULL) {
                            printf("ID: %d\n", poeta_encontrado2->id);
                            printf("Nome: %s\n", poeta_encontrado2->nome);
                            printf("Poema: \n%s\n", poeta_encontrado2->poema);
                        } else {
                            printf("Poeta não encontrado na lista 2!\n");
                        }
                        break;

                    case 'd':
                        Ordena_lista_id(lista2);
                        printf("Lista 2 ordenada por ID!\n");
                        break;

                    case 'e':
                        Exibe_lista(lista2);
                        break;

                    default:
                        printf("Opção inválida!\n");
                }
                break;

            case 3:
                if (lista_mesclada != NULL) {
                    Libera_lista(lista_mesclada);
                }
                lista_mesclada = Mescla_listas(lista1, lista2);
                printf("\nLista mesclada (interseção):\n");
                Exibe_lista(lista_mesclada);
                break;

            case 4:
                printf("\nLista 1 (poetas nacionais):\n");
                Exibe_lista(lista1);
                printf("\nLista 2 (poetas internacionais):\n");
                Exibe_lista(lista2);
                if (lista_mesclada != NULL) {
                    printf("\nLista mesclada (interseção):\n");
                    Exibe_lista(lista_mesclada);
                }
                break;

            case 5:
                printf("\nDigite o nome do arquivo para salvar as listas: ");
                scanf("%s", nome_arquivo);


                if (Salva_lista(lista1, nome_arquivo)) {
                    printf("Lista 1 salva com sucesso em %s!\n", nome_arquivo);
                } else {
                    printf("Erro ao salvar a lista 1!\n");
                }


                if (Salva_lista(lista2, nome_arquivo)) {
                    printf("Lista 2 salva com sucesso em %s!\n", nome_arquivo);
                } else {
                    printf("Erro ao salvar a lista 2!\n");
                }


                if (lista_mesclada != NULL) {
                    if (Salva_lista(lista_mesclada, nome_arquivo)) {
                        printf("Lista mesclada salva com sucesso em %s!\n", nome_arquivo);
                    } else {
                        printf("Erro ao salvar a lista mesclada!\n");
                    }
                }
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 6);

    Libera_lista(lista1);
    Libera_lista(lista2);
    if (lista_mesclada != NULL) {
        Libera_lista(lista_mesclada);
    }

    return 0;
}
