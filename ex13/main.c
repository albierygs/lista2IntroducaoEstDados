/*Escreva um programa com rotinas recursivas que determine o índice da coluna de uma matriz de inteiros, de 3 linhas e 4 colunas, com o maior valor de soma de elementos por coluna.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLUMNS 4

int matriz[ROWS][COLUMNS];

void readMatriz();

int biggerColumn(int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    readMatriz();

    printf("A coluna com maior soma é a %d\n", biggerColumn(COLUMNS, 0) + 1);

    system("pause");
    return 0;
}

void readMatriz() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            matriz[i][j] = rand() % 50;
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int biggerColumn(int position, int previousSum) {
    if (position == COLUMNS) {
        --position;
    }

    int bigger = position;

    if (position >= 0) {
        int sum = 0;

        for (int i = 0; i < ROWS; ++i) {
            sum += matriz[i][position];
        }

        if (previousSum > sum) {
            bigger = position + 1;
        } else {
            bigger = position;
        }

        int result = biggerColumn(position - 1, sum);
        int sumResult = 0;

        for (int i = 0; i < ROWS; ++i) {
            sumResult += matriz[i][result];
        }
        if (sumResult > sum) {
            bigger = result;
        }

    }
    return bigger;
}
