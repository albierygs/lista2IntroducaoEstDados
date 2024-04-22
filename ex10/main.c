/*Escreva um programa com uma função recursivo para calcular e imprimir os 20 primeiros números primos.*/

#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void primos(int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    printf("20 primeiros números primos: ");
    primos(0, 1);

    system("pause");
    return 0;
}

void primos(int number, int total) {
    bool find = false;

    if (total > 20) {
        return;
    }

    for (int i = number + 1; find != true; ++i) {
        int divisionsNumber = 0;
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                divisionsNumber++;
            }
        }
        if (divisionsNumber == 2) {
            printf("%d ", i);
            primos(i, ++total);
            find = true;
        }
    }
}
