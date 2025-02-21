#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int i;
    printf("Insira a quantidade de posições no vetor: ");
    scanf("%d", &i);
    int vet[i];

    for (i = 0; i < sizeof(vet)/sizeof(vet[0]); i++) {
        printf("Valor da posição [%d] = ", i + 1);
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < sizeof(vet)/sizeof(vet[0]) / 2; i++) {
        int temp = vet[i];
        vet[i] = vet[sizeof(vet)/sizeof(vet[0]) - i - 1];
        vet[sizeof(vet)/sizeof(vet[0]) - i - 1] = temp;
    }

    printf("\nValores Invertidos: ");

    for (i = 0; i < sizeof(vet)/sizeof(vet[0]); i++) {
        printf("\n[%d] = %d ", i + 1, vet[i]);
    }

    return 0;
}

