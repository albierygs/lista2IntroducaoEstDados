/*Escreva um programa com rotinas recursivas que determine o índice da coluna de uma matriz de inteiros, de 3 linhas e 4 colunas, com o maior valor de soma de elementos por coluna.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLUMNS 4

int matriz[ROWS][COLUMNS];

void readMatriz(int, int);
void show(int, int);
void findBiggerColumn(int, int, int, int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    readMatriz(0, 0);
    show(0, 0);
    findBiggerColumn(0, 0, 0, 0, 0);

    system("pause");
    return 0;
}

void readMatriz(int row, int column) {
    if (row < ROWS && column < COLUMNS) {
        printf("Posição [%d][%d]: ", (row + 1), (column + 1));
        scanf("%d", &matriz[row][column]);
        fflush(stdin);
        system("cls");

        if (column == COLUMNS - 1) {
            readMatriz(row + 1, 0);
        } else {
            readMatriz(row, column + 1);
        }
    }
}

void show(int row, int column) {
    if (row < ROWS && column < COLUMNS) {
        printf("%3d", matriz[row][column]);

        if (column == COLUMNS - 1) {
            printf("\n");
            show(row + 1, 0);
        } else {
            show(row, column + 1);
        }
    } else {
        printf("\n\n");
    }
}

void findBiggerColumn(int row, int column, int sum, int biggerSum, int biggerColumn) {
    if (column < COLUMNS) {
        sum += matriz[row][column];

        if (row == ROWS - 1) {
            if (sum > biggerSum) {
                biggerSum = sum;
                biggerColumn = column;
            }

            findBiggerColumn(0, column + 1, 0, biggerSum, biggerColumn);
        } else {
            findBiggerColumn(row + 1, column, sum, biggerSum, biggerColumn);
        }
    } else {
        printf("A coluna %d tem a maior soma (%d)\n", (biggerColumn + 1), biggerSum);
    }
}
