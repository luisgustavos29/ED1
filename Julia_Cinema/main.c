#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "julia.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
    Ingresso *listaDisponiveis = NULL;
    Ingresso *listaVendidos = NULL;
    int opcao, assento, filmeEscolhido;
    char filme[50];

    listaDisponiveis = inicializarFilmes(listaDisponiveis);

    do {
        printf("\nMenu:\n");
        printf("1. Vender Ingresso a um filme\n");
        printf("2. Cancelar Ingresso\n");
        printf("3. Listar Todos os Ingressos Disponíveis para um Filme Específico\n");
        printf("4. Exibir Todos os Ingressos Vendidos em Ordem de Compra\n");
        printf("5. Sair do Sistema\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nEscolha um filme:\n");
                for (int i = 0; i < MAX_FILMES; i++) {
                    printf("%d. %s\n", i + 1, filmes[i]);
                }
                printf("Escolha o número do filme: ");
                scanf("%d", &filmeEscolhido);


                if (filmeEscolhido < 1 || filmeEscolhido > MAX_FILMES) {
                    printf("Opção inválida! Tente novamente.\n");
                    break;
                }

                strcpy(filme, filmes[filmeEscolhido - 1]);
                mostrarAssentosDisponiveis(listaDisponiveis, filme);
                printf("Insira o número do assento (1 a 10): ");
                scanf("%d", &assento);


                if (assento < 1 || assento > MAX_LOTACAO) {
                    printf("Assento inválido! Insira um número entre 1 e %d.\n", MAX_LOTACAO);
                    break;
                }

                if (ingressoDisponivel(listaDisponiveis, filme, assento)) {
                    listaVendidos = adicionarIngressoVendido(listaVendidos, filme, assento);
                    listaDisponiveis = removerDaLista(listaDisponiveis, filme, assento);
                    printf("Ingresso vendido com sucesso!\n");
                } else {
                    printf("Assento já vendido ou inválido!\n");
                }
                break;

            case 2:
                printf("\nEscolha um filme:\n");
                for (int i = 0; i < MAX_FILMES; i++) {
                    printf("%d. %s\n", i + 1, filmes[i]);
                }
                printf("Escolha o número do filme: ");
                scanf("%d", &filmeEscolhido);


                if (filmeEscolhido < 1 || filmeEscolhido > MAX_FILMES) {
                    printf("Opção inválida! Tente novamente.\n");
                    break;
                }

                strcpy(filme, filmes[filmeEscolhido - 1]);
                printf("Insira o número do assento para cancelar: ");
                scanf("%d", &assento);


                if (assento < 1 || assento > MAX_LOTACAO) {
                    printf("Assento inválido! Insira um número entre 1 e %d.\n", MAX_LOTACAO);
                    break;
                }

                listaVendidos = cancelarIngresso(listaVendidos, listaDisponiveis, filme, assento);
                printf("Cancelamento realizado com sucesso!\n");
                break;

            case 3:
                printf("\nEscolha um filme:\n");
                for (int i = 0; i < MAX_FILMES; i++) {
                    printf("%d. %s\n", i + 1, filmes[i]);
                }
                printf("Escolha o número do filme: ");
                scanf("%d", &filmeEscolhido);


                if (filmeEscolhido < 1 || filmeEscolhido > MAX_FILMES) {
                    printf("Opção inválida! Tente novamente.\n");
                    break;
                }

                strcpy(filme, filmes[filmeEscolhido - 1]);
                listarIngressosDisponiveis(listaDisponiveis, filme);
                break;

            case 4:
                listarIngressosVendidos(listaVendidos);
                break;

            case 5:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
