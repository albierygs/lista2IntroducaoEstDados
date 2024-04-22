/*Escreva um programa com uma função ou procedimento recursiva que ordene um vetor*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 8

int vetor[T];

void readVector();
void orderVector(int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    readVector();
    orderVector(T);

    for (int i = 0; i < T; ++i) {
        printf("%3d", vetor[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}

void readVector() {
    for (int i = 0; i < T; ++i) {
        vetor[i] = rand() % 50;
        printf("%3d", vetor[i]);
    }
    printf("\n");
}

void orderVector(int size) {
    if (size == T) {
        --size;
    }
    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            if (vetor[size] < vetor[i]) {
                int temp = vetor[size];
                vetor[size] = vetor[i];
                vetor[i] = temp;
            }
        }
        orderVector(size - 1);
    }
}
