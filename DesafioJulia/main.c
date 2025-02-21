#include <stdio.h>
#include <stdlib.h>
#include "lladae2.h"

int main() {
    Filme *listaFilmes = NULL;
    No *listaIngressosVendidos = NULL;

    inserirFilme(&listaFilmes, criarFilme("Star Wars: Epis�dio IV - Uma Nova Esperan�a", 10));
    inserirFilme(&listaFilmes, criarFilme("O Senhor dos An�is: A Sociedade do Anel", 10));

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Vender Ingresso a um filme\n");
        printf("2 - Cancelar Ingresso\n");
        printf("3 - Listar todos os ingressos dispon�veis para um filme espec�fico\n");
        printf("4 - Exibir todos os ingressos vendidos em ordem de compra\n");
        printf("5 - Sair do Sistema\n");
        printf("Digite a op��o desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                venderIngresso(listaFilmes);
                break;
            case 2:
                cancelarIngresso(listaFilmes);
                break;
            case 3:
                listarIngressosDisponiveis(listaFilmes);
                break;
            case 4:
                exibirIngressosVendidos(listaIngressosVendidos);
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Op��o inv�lida.\n");
        }
    } while (opcao != 5);

    return 0;
}
