/*Escreva um programa com rotinas recursivas para ler uma matriz 3 X 4, transpor a matriz lida e imprimir o resultado.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLUMNS 4

int matriz[ROWS][COLUMNS];
int transpose[COLUMNS][ROWS];

void readMatriz(int, int);
void show(int, int);
void showTranspose(int, int);
void transposeMatriz(int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    readMatriz(0, 0);
    printf("Matriz original\n\n");
    show(0, 0);
    transposeMatriz(0, 0);
    printf("Matriz transposta\n\n");
    showTranspose(0, 0);

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

void showTranspose(int row, int column) {
    if (row < COLUMNS && column < ROWS) {
        printf("%3d", transpose[row][column]);

        if (column == ROWS - 1) {
            printf("\n");
            showTranspose(row + 1, 0);
        } else {
            showTranspose(row, column + 1);
        }
    } else {
        printf("\n\n");
    }
}

void transposeMatriz(int row, int column) {
    if (row < ROWS && column < COLUMNS) {
        transpose[column][row] = matriz[row][column];

        if (column == COLUMNS - 1) {
            transposeMatriz(row + 1, 0);
        } else {
            transposeMatriz(row, column + 1);
        }
    }
}
