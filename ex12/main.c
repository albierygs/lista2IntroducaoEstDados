/*Escreva um programa com rotinas recursivas que determine a soma dos elementos na diagonal secundária de uma matriz quadrada de n>0 linhas e colunas.
Exemplo: A soma dos elementos da diagonal secundária da matriz é 4 + 1 + 0 + 3 = 8.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define T 4

int matriz[T][T];

void readMatriz(int, int);
void show(int, int);
void diagonalSum(int, int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    readMatriz(0, 0);
    show(0, 0);
    diagonalSum(0, 0, 0);

    system("pause");
    return 0;
}

void readMatriz(int row, int column) {
    if (row < T && column < T) {
        printf("Posição [%d][%d]: ", (row + 1), (column + 1));
        scanf("%d", &matriz[row][column]);
        fflush(stdin);
        system("cls");

        if (column == T - 1) {
            readMatriz(row + 1, 0);
        } else {
            readMatriz(row, column + 1);
        }
    }
}

void show(int row, int column) {
    if (row < T && column < T) {
        printf("%3d", matriz[row][column]);

        if (column == T - 1) {
            printf("\n");
            show(row + 1, 0);
        } else {
            show(row, column + 1);
        }
    } else {
        printf("\n\n");
    }
}

void diagonalSum(int row, int column, int sum) {
    if (row < T && column < T) {
        if (row + column == T -1) {
            sum += matriz[row][column];
        }

        if (column == T -1) {
            diagonalSum(row + 1, 0, sum);
        } else {
            diagonalSum(row, column + 1, sum);
        }
    } else {
        printf("A soma da diagonal secundária é %d\n", sum);
    }
}
