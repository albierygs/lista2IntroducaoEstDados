/*Escreva um programa com uma função ou procedimento recursiva que ordene um vetor*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define T 5

int vetor[T];

void readVector(int);
void show(int);
void orderVector(int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    readVector(0);
    show(0);

    for (int i = 0; i < T; ++i) {
        orderVector(0);
    }

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

void orderVector(int position) {
    if (position < T - 1) {
        if (vetor[position] > vetor[position + 1]) {
            int temp = vetor[position];
            vetor[position] = vetor[position + 1];
            vetor[position + 1] = temp;
            orderVector(position);
        } else {
            orderVector(position + 1);
        }
    }
}
