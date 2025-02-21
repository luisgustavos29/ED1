#include <stdio.h>
#include <time.h>
#include "fila_encadeada.h"

int main() {
    FilaCR7 fila;
    Inicializa_filaCR7(&fila);

    double insertionTime, listingTime, removalTime;

    // Inser��o
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

    // Remo��o
    int id;
    start = (double)clock();
    for (int i = 0; i < 1000; i++) {
        DesenfileiraCR7(&fila, &id);
    }
    finish = (double)clock();
    removalTime = finish - start;

    // Relat�rio
    printf("\nRelat�rio de Tempo:\n");
    printf("Inser��o: %f clocks\n", insertionTime);
    printf("Listagem: %f clocks\n", listingTime);
    printf("Remo��o: %f clocks\n", removalTime);

    return 0;
}
