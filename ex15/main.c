/*Escreva um programa com rotinas recursivas para ler uma matriz 5 X 5, encontrar e imprimir a posição (linha X coluna) do maior e menor elemento.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 5

int matriz[T][T];

void readMatriz();
int biggerElement(int, int, int);
int smallerElement(int, int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    readMatriz();
    printf("O maior elemnto é o %d\n", biggerElement(0, 0, matriz[0][0]));
    printf("O menor elemnto é o %d\n", smallerElement(0, 0, matriz[0][0]));

    system("pause");
    return 0;
}

void readMatriz(int row, int column, int lastNumber) {
    printf("\n\n");
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < T; ++j) {
            matriz[i][j] = rand() % 50;
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int biggerElement(int row, int column, int bigger) {
    if (row < T && column < T) {
        if (matriz[row][column] > bigger) {
            bigger = matriz[row][column];
        }

        int result;

        if (column == T - 1) {
            result = biggerElement(row + 1, 0, bigger);
        } else {
            result = biggerElement(row, column + 1, bigger);
        }
        return result;
    }

    return bigger;
}

int smallerElement(int row, int column, int smaller) {
    if (row < T && column < T) {
        if (matriz[row][column] < smaller) {
            smaller = matriz[row][column];
        }

        int result;

        if (column == T - 1) {
            result = smallerElement(row + 1, 0, smaller);
        } else {
            result = smallerElement(row, column + 1, smaller);
        }
        return result;
    }

    return smaller;
}