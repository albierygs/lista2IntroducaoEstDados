/*Escreva um programa com rotinas recursivas para ler uma matriz 3 X 4, transpor a matriz lida e imprimir o resultado.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLUMNS 4

int matriz[ROWS][COLUMNS];
int transpose[COLUMNS][ROWS];

void readMatriz();
void show();
void transposeMatriz(int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    readMatriz();
    transposeMatriz(0, 0);
    show();

    system("pause");
    return 0;
}

void readMatriz() {
    printf("Matriz original\n\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            matriz[i][j] = rand() % 50;
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void show() {
    printf("Matriz transposta\n\n");
    for (int i = 0; i < COLUMNS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            printf("%4d", transpose[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
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
