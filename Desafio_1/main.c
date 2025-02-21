#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

    int main() {
    setlocale(LC_ALL, "");
    int a, b;

    printf("\nInsira um Valor para a variável A: ");
    scanf("%d", &a);
    printf("\nInsira um Valor para a variável B: ");
    scanf("%d", &b);

    printf("\nAntes da troca:");
    printf("\nA = %d", a);
    printf("\nB = %d", b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("\nDepois da troca:");
    printf("\nA = %d", a);
    printf("\nB = %d", b);

    return 0;
}

