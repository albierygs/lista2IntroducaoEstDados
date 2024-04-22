/*Escreva um programa com rotinas recursivas para preencher uma matriz 3x4 com valores decrescentes digitados via teclado. Se o valor digitado não estiver na ordem decrescente este deve ser desconsiderado. Em seguida, imprima na tela a soma de todos os elementos por coluna da matriz.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLUMNS 4

int matriz[ROWS][COLUMNS];

void readMatriz(int, int, int);
void showMatriz();
void calculateColumns(int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    readMatriz(0, 0, 0);
    showMatriz();
    calculateColumns(0);

    system("pause");
    return 0;
}

void readMatriz(int row, int column, int lastNumber) {
    if (row < ROWS && column < COLUMNS) {
        int number;
        if (row == 0 && column == 0) {
            printf("Digite o número da posiição [%d][%d]: ", row + 1, column + 1);
            scanf("%d", &number);
            fflush(stdin);
            system("cls");
        } else {
            printf("Digite o número da posiição [%d][%d]: ", row + 1, column + 1);
            scanf("%d", &number);
            fflush(stdin);
            system("cls");
            if (number >= lastNumber) {
                do {
                    printf("O número deve ser manor que o anterior (%d)\n", lastNumber);
                    printf("Digite o número da posiição [%d][%d]: ", row + 1, column + 1);
                    scanf("%d", &number);
                    fflush(stdin);
                    system("cls");
                } while (number >= lastNumber);
            }
        }
        matriz[row][column] = number;

        if (column == COLUMNS - 1) {
            readMatriz(row + 1, 0, number);
        } else {
            readMatriz(row, column + 1, number);
        }
    }
}

void showMatriz() {
    printf("\n\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void calculateColumns(int column) {
    if (column < COLUMNS) {
        int sum = 0;

        for (int i = 0; i < ROWS; ++i) {
            sum += matriz[i][column];
        }

        printf("A soma da coluna %d é %d\n", column + 1, sum);

        calculateColumns(column + 1);
    }
}
