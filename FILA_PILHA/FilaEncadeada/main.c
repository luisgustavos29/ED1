#include <stdio.h>
#include <time.h>
#include "fila_encadeada.h"

int main() {
    FilaCR7 fila;
    Inicializa_filaCR7(&fila);

    double insertionTime, listingTime, removalTime;

    // Inserção
    double start = (double)clock();
    for (int i = 0; i < 1000; i++) {
        EnfileiraCR7(&fila, i);
    }
    double finish = (double)clock();
    insertionTime = finish - start;

    // Listagem
    start = (double)clock();
    ExibeCR7(&fila);
    finish = (double)clock();
    listingTime = finish - start;

    // Remoção
    int id;
    start = (double)clock();
    for (int i = 0; i < 1000; i++) {
        DesenfileiraCR7(&fila, &id);
    }
    finish = (double)clock();
    removalTime = finish - start;

    // Relatório
    printf("\nRelatório de Tempo:\n");
    printf("Inserção: %f clocks\n", insertionTime);
    printf("Listagem: %f clocks\n", listingTime);
    printf("Remoção: %f clocks\n", removalTime);

    return 0;
}
