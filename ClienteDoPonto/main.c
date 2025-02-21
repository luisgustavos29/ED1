#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ponto.h"

int main() {
    Ponto *pontos[10];
    int num_pontos = 0;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        pontos[i] = pto_cria(rand() % 100, rand() % 100);
        num_pontos++;
    }

    printf("Coordenadas dos pontos:\n");
    for (int i = 0; i < num_pontos; i++) {
        float x, y;
        pto_acessa(pontos[i], &x, &y);
        printf("Ponto %d: (%.2f, %.2f)\n", i, x, y);
    }

    printf("\nRemovendo o ponto 5...\n");
    pto_libera(pontos[5]);
    pontos[5] = NULL;
    num_pontos--;

    printf("Coordenadas dos pontos restantes:\n");
    for (int i = 0; i < num_pontos; i++) {
        if (pontos[i] != NULL) {
            float x, y;
            pto_acessa(pontos[i], &x, &y);
            printf("Ponto %d: (%.2f, %.2f)\n", i, x, y);
        }
    }

    printf("\nCalculando a distância entre o ponto 0 e o ponto 2...\n");
    float distancia = pto_distancia(pontos[0], pontos[2]);
    printf("Distância: %.2f\n", distancia);

    printf("\nAlterando as coordenadas do ponto 1 para (10.5, 20.5)...\n");
    pto_atribui(pontos[1], 10.5, 20.5);

    float x, y;
    pto_acessa(pontos[1], &x, &y);
    printf("Ponto 1: (%.2f, %.2f)\n", x, y);

    for (int i = 0; i < num_pontos; i++) {
        if (pontos[i] != NULL) {
            pto_libera(pontos[i]);
        }
    }

    return 0;
}
