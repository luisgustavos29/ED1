#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");
    struct no* raiz = NULL;

    // Inserir valores na árvore
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Árvore após inserções:\n");
    imprimir_arvore(raiz, 0);

    espelhar_arvore(raiz);

    printf("\nÁrvore espelhada:\n");
    imprimir_arvore(raiz, 0);


    // Contar nós
    printf("Número total de nós: %d\n", contar_nos(raiz));
    printf("Número de nós não folha: %d\n", contar_nos_nao_folha(raiz));
    printf("Número de nós folha: %d\n", contar_nos_folha(raiz));
    printf("Altura da árvore: %d\n", altura(raiz));
    printf("Maior valor na árvore: %d\n", maior(raiz));

    // Remover um valor
    raiz = remover(raiz, 70);
    printf("\nÁrvore após remover 70:\n");
    imprimir_arvore(raiz, 0);

    // Testar remoções adicionais
    raiz = remover(raiz, 30);
    printf("\nÁrvore após remover 30:\n");
    imprimir_arvore(raiz, 0);

    // Testar remoção de um nó folha
    raiz = remover(raiz, 20);
    printf("\nÁrvore após remover 20:\n");
    imprimir_arvore(raiz, 0);


    return 0;
}
