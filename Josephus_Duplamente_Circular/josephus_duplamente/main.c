#include "lladaec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int opcao, jogador, posicao = 0;
    char nome[50];
    Pessoa *lista_jogadores;
    lista_jogadores = Cria_lista();

    do {
        printf("\n\---------- BEM VINDO AO DESAFIO DO JOSEPHUS ----------\n\n");
        printf("Escolha uma opção:\n");
        printf("1 - Adicionar Jogador\n");
        printf("2 - Ver Lista de Jogadores\n");
        printf("3 - Iniciar Jogo\n");
        printf("4 - Sair\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nInsira um participante: ");
                setbuf(stdin, NULL);
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;
                lista_jogadores = Insere_elem(lista_jogadores, nome);
                printf("Jogador adicionado com sucesso!\n");
                break;

            case 2:
                Exibir_lista(lista_jogadores);
                break;

            case 3:
                if (Tamanho_Lista(lista_jogadores) < 2) {
                    printf("\nNeste desafio, é necessário ter pelo menos 2 jogadores para iniciar o jogo.\n");
                    break;
                }
                printf("\n\n-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-");
                printf("\nVai começar o grande jogo. Boa sorte aos participantes! \n");
                printf("-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-");

                while (Tamanho_Lista(lista_jogadores) > 1) {
                    Exibir_lista(lista_jogadores);

                    jogador = rand() % Tamanho_Lista(lista_jogadores) + 1;
                    printf("----------");
                    printf("\nSorteando...");
                    printf("\n----------");
                    printf("\nO sorteado foi: %d \n", jogador);

                    lista_jogadores = Remove_elem(lista_jogadores, jogador, &posicao);
                }

                printf("\nO jogador que sobrou foi %s! \n", lista_jogadores->nome);
                printf("E ele terá que comer uma fruta envenenada!\n");
                Salvar_relacionados(lista_jogadores, lista_jogadores->nome, "perdedor");
                break;

            case 4:
                printf("\nSaindo... \n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    Libera_lista(lista_jogadores);

    return 0;
}
