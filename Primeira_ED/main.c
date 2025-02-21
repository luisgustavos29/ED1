#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAMANHO_VETOR 100

void Insere_Elemento(int PAR[], int IMPAR[], int *quantidade_pares, int *quantidade_impares);
void Remove_Elemento(int PAR[], int IMPAR[], int *quantidade_pares, int *quantidade_impares);
void Consulta_Pos(int PAR[], int IMPAR[], int quantidade_pares, int quantidade_impares, int posicao);
void Exibe_Elementos(int PAR[], int IMPAR[], int quantidade_pares, int quantidade_impares);
void Grava_Elementos(int PAR[], int IMPAR[], int quantidade_pares, int quantidade_impares);
void Carrega_Elementos(int PAR[], int IMPAR[], int *quantidade_pares, int *quantidade_impares);
int main()
{
    setlocale(LC_ALL,"Portuguese");
    int op;
    int posicao;
    int PAR[TAMANHO_VETOR];
    int IMPAR[TAMANHO_VETOR];
    int quantidade_pares = 0;
    int quantidade_impares = 0;


    Carrega_Elementos(PAR, IMPAR, &quantidade_pares, &quantidade_impares);

    do{
        printf("\n---------- MENU DE OPÇÕES ----------\n\n");
        printf("Escolha uma opção: ");
        printf("\n1 - Inserir Elementos.");
        printf("\n2 - Remover Elementos.");
        printf("\n3 - Consultar Posição.");
        printf("\n4 - Exibir Elementos.");
        printf("\n5 - Gravar.");
        printf("\n6 - Carregar.");
        printf("\n7 - sair.");
        printf("\nInsira aqui a opção desejada: ");
        scanf("%d",&op);

        switch(op){
        case 1:
            Insere_Elemento(PAR, IMPAR, &quantidade_pares, &quantidade_impares);
            break;

        case 2:
            Remove_Elemento(PAR, IMPAR, &quantidade_pares, &quantidade_impares);
            break;

        case 3:
            do {
                printf("\nDigite a posição a ser consultada: ");
                scanf("%d", &posicao);
                Consulta_Pos(PAR, IMPAR, quantidade_pares, quantidade_impares, posicao);


                if (posicao >= quantidade_pares + quantidade_impares) {
                    printf("\nPosição inválida! Tente novamente.\n");
                }
            } while (posicao >= quantidade_pares + quantidade_impares);
            break;

            break;
        case 4:
             Exibe_Elementos(PAR, IMPAR, quantidade_pares, quantidade_impares);
            break;
        case 5:
            Grava_Elementos(PAR, IMPAR, quantidade_pares, quantidade_impares);
            break;
        case 6:
            Carrega_Elementos(PAR, IMPAR, &quantidade_pares, &quantidade_impares);
            break;
        default:
            printf("\n***** Opção incorreta, insira uma opção entre 1 e 7. *****");

        }


    } while(op != 7);


    return 0;
}

void Insere_Elemento(int PAR[], int IMPAR[], int *quantidade_pares, int *quantidade_impares) {
    int elemento;

    printf("Digite o elemento a ser inserido: ");
    scanf("%d", &elemento);

    if (elemento % 2 == 0) {

        if (*quantidade_pares < TAMANHO_VETOR) {
            PAR[*quantidade_pares] = elemento;
            (*quantidade_pares)++;
             printf("Elemento inserido no vetor PAR.\n");
        } else {
            printf("Vetor PAR cheio! Não é possível inserir mais elementos.\n");
        }
    } else {

         if (*quantidade_impares < TAMANHO_VETOR) {
            IMPAR[*quantidade_impares] = elemento;
            (*quantidade_impares)++;
            printf("Elemento inserido no vetor IMPAR.\n");
        } else {
            printf("Vetor IMPAR cheio! Não é possível inserir mais elementos.\n");
        }
    }
}

void Remove_Elemento(int PAR[], int IMPAR[], int *quantidade_pares, int *quantidade_impares){
    int valor_removido;

    printf("Digite o valor a ser removido: ");
    scanf("%d", &valor_removido);

    for (int i = 0; i < *quantidade_pares; i++) {
        if (PAR[i] == valor_removido) {

            for (int j = i; j < *quantidade_pares - 1; j++) {
                PAR[j] = PAR[j + 1];
            }
            (*quantidade_pares)--;
            printf("Elemento removido do vetor PAR.\n");
            return;
        }
    }


    for (int i = 0; i < *quantidade_impares; i++) {
        if (IMPAR[i] == valor_removido) {

            for (int j = i; j < *quantidade_impares - 1; j++) {
                IMPAR[j] = IMPAR[j + 1];
            }
            (*quantidade_impares)--;
            printf("Elemento removido do vetor IMPAR.\n");
            return;
        }
    }
    printf("O valor %d não foi encontrado em nenhum dos vetores.\n", valor_removido);
}

void Consulta_Pos(int PAR[], int IMPAR[], int quantidade_pares, int quantidade_impares, int posicao) {
    int indiceImpar;

    if (posicao < quantidade_pares) {
        printf("Elemento par na posição [%d] = %d\n", posicao, PAR[posicao]);
    } else {
        printf("Posição %d não preenchida no vetor par.\n", posicao);
    }


    if (posicao < quantidade_pares + quantidade_impares) {
        indiceImpar = posicao - quantidade_pares;
        printf("Elemento ímpar na posição [%d] = %d\n", posicao, IMPAR[indiceImpar]);
    } else {
        printf("Posição %d não preenchida no vetor ímpar.\n", posicao);
    }
}

void Exibe_Elementos(int PAR[], int IMPAR[], int quantidade_pares, int quantidade_impares) {
    printf("\nVetor PAR:");
    for (int i = 0; i < quantidade_pares; i++) {
        printf(" [%d]", PAR[i]);
    }

    printf("\nVetor IMPAR:");
    for (int i = 0; i < quantidade_impares; i++) {
        printf(" [%d]", IMPAR[i]);
    }
    printf("\n");
}

void Grava_Elementos(int PAR[], int IMPAR[], int quantidade_pares, int quantidade_impares) {
    char nome_arquivo[100];

    printf("Digite o nome do arquivo para gravar: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Vetor PAR:\n");
    for (int i = 0; i < quantidade_pares; i++) {
        fprintf(arquivo, "[%d] ", PAR[i]);
    }

    fprintf(arquivo, "\nVetor IMPAR:\n");
    for (int i = 0; i < quantidade_impares; i++) {
        fprintf(arquivo, "[%d] ", IMPAR[i]);
    }

    fclose(arquivo);
    printf("Elementos gravados no arquivo %s.\n", nome_arquivo);
}

void Carrega_Elementos(int PAR[], int IMPAR[], int *quantidade_pares, int *quantidade_impares) {
    char nome_arquivo[100];
    int elemento;

    printf("Digite o nome do arquivo para carregar: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];
    fgets(linha, 100, arquivo);

    *quantidade_pares = 0;
    while (fscanf(arquivo, "[%d] ", &elemento) == 1 && *quantidade_pares < TAMANHO_VETOR) {
        PAR[*quantidade_pares] = elemento;
        (*quantidade_pares)++;
    }

    fgets(linha, 100, arquivo);

    *quantidade_impares = 0;
    while (fscanf(arquivo, "[%d] ", &elemento) == 1 && *quantidade_impares < TAMANHO_VETOR) {
        IMPAR[*quantidade_impares] = elemento;
        (*quantidade_impares)++;
    }

    fclose(arquivo);
    printf("Elementos carregados do arquivo %s.\n", nome_arquivo);
}
