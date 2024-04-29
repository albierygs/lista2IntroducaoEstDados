/*Escreva um programa com rotinas recursivas para ler uma matriz 5 X 5, encontrar e imprimir a posição (linha X coluna) do maior e menor elemento.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 4

int matriz[T][T];

void readMatriz(int, int);
void show(int, int);
int biggerElement(int, int, int);
int smallerElement(int, int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    readMatriz(0, 0);
    show(0, 0);
    printf("O maior elemnto é o %d\n", biggerElement(0, 0, matriz[0][0]));
    printf("O menor elemnto é o %d\n", smallerElement(0, 0, matriz[0][0]));

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