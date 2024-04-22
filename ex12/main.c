/*Escreva um programa com rotinas recursivas que determine a soma dos elementos na diagonal secundária de uma matriz quadrada de n>0 linhas e colunas.
Exemplo: A soma dos elementos da diagonal secundária da matriz é 4 + 1 + 0 + 3 = 8.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 5

int matriz[T][T];

void readMatriz();

int diagonalSum(int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    readMatriz();

    printf("A soma da diagonal secundária é %d", diagonalSum(T));

    system("pause");
    return 0;
}

void readMatriz() {
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < T; ++j) {
            matriz[i][j] = rand() % 50;
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int diagonalSum(int row) {
    if (row == T) {
        --row;
    }

    int result = 0;

    if (row >= 0) {
        for (int i = 0; i < T; ++i) {
            if (row + i == T - 1) {
                result = matriz[row][i] + diagonalSum(row - 1);
            }
        }
    }
    return result;
}
