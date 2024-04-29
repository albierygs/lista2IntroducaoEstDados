/*Escreva um programa com rotinas recursivas para preencher uma matriz 3x4 com valores decrescentes digitados via teclado. Se o valor digitado não estiver na ordem decrescente este deve ser desconsiderado. Em seguida, imprima na tela a soma de todos os elementos por coluna da matriz.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLUMNS 4

int matriz[ROWS][COLUMNS];

void readMatriz(int, int, int);
void showMatriz(int, int);
void calculateColumns(int, int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    readMatriz(0, 0, 0);
    showMatriz(0, 0);
    calculateColumns(0, 0, 0);

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

void showMatriz(int row, int column) {
    if (row < ROWS && column < COLUMNS) {
        printf("%3d", matriz[row][column]);

        if (column == COLUMNS - 1) {
            printf("\n");
            showMatriz(row + 1, 0);
        } else {
            showMatriz(row, column + 1);
        }
    } else {
        printf("\n\n");
    }
}

void calculateColumns(int row, int column, int sum) {
    if (column < COLUMNS) {
        sum += matriz[row][column];

        if (row == ROWS - 1) {
            printf("A soma da coluna %d é %d\n", column + 1, sum);
            calculateColumns(0, column + 1, 0);
        } else {
            calculateColumns(row + 1, column, sum);
        }
    }
}
