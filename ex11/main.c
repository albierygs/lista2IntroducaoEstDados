/*Escreva um programa com uma função ou procedimento recursiva que ordene um vetor*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define T 5

int vetor[T];

void readVector(int);
void show(int);
void orderVector(int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    readVector(0);
    show(0);

    orderVector(0, 1);

    show(0);

    system("pause");
    return 0;
}

void readVector(int position) {
    if (position < T) {
        printf("Posição [%d]: ", position);
        scanf("%d", &vetor[position]);
        fflush(stdin);
        system("cls");

        readVector(position + 1);
    }
}

void show(int position) {
    if (position < T) {
        printf("%3d", vetor[position]);
        show(position + 1);
    } else {
        printf("\n");
    }
}

void orderVector(int i, int j) {
    if (i < T - 1) {
        if (j < T) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
            orderVector(i, ++j);
        } else {
            orderVector(++i, i + 1);
        }
    }
}
