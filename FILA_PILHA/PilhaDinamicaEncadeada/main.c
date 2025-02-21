#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "padae.h"

int main() {
    Pilha pilha;
    Cria_pilha(&pilha);

    double insertionTime, listingTime, removalTime;

    // Inserção
    double start = (double)clock();
    for (int i = 0; i < 25000; i++) {
        Push(&pilha, i);
    }
    double finish = (double)clock();
    insertionTime = finish - start;

    // Listagem
    start = (double)clock();
    Listar_pilha(&pilha);
    finish = (double)clock();
    listingTime = finish - start;

    // Remoção
    int elem;
    start = (double)clock();
    for (int i = 0; i < 25000; i++) {
        Pop(&pilha, &elem);
    }
    finish = (double)clock();
    removalTime = finish - start;

    Libera_pilha(&pilha);

    // Relatório
    printf("\nRelatório de Tempo:\n");
    printf("Inserção: %f clocks\n", insertionTime);
    printf("Listagem: %f clocks\n", listingTime);
    printf("Remoção: %f clocks\n", removalTime);


    return 0;
}
