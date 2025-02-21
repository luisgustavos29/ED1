#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");
    struct no* raiz = NULL;

    // Inserir valores na �rvore
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("�rvore ap�s inser��es:\n");
    imprimir_arvore(raiz, 0);

    espelhar_arvore(raiz);

    printf("\n�rvore espelhada:\n");
    imprimir_arvore(raiz, 0);


    // Contar n�s
    printf("N�mero total de n�s: %d\n", contar_nos(raiz));
    printf("N�mero de n�s n�o folha: %d\n", contar_nos_nao_folha(raiz));
    printf("N�mero de n�s folha: %d\n", contar_nos_folha(raiz));
    printf("Altura da �rvore: %d\n", altura(raiz));
    printf("Maior valor na �rvore: %d\n", maior(raiz));

    // Remover um valor
    raiz = remover(raiz, 70);
    printf("\n�rvore ap�s remover 70:\n");
    imprimir_arvore(raiz, 0);

    // Testar remo��es adicionais
    raiz = remover(raiz, 30);
    printf("\n�rvore ap�s remover 30:\n");
    imprimir_arvore(raiz, 0);

    // Testar remo��o de um n� folha
    raiz = remover(raiz, 20);
    printf("\n�rvore ap�s remover 20:\n");
    imprimir_arvore(raiz, 0);


    return 0;
}
