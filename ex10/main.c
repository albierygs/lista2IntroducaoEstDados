/*Escreva um programa com uma função recursivo para calcular e imprimir os 20 primeiros números primos.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void primos(int, int, int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    printf("20 primeiros números primos: ");
    primos(1, 1, 0, 0);

    system("pause");
    return 0;
}

void primos(int number, int divisor, int divisionNumber, int total) {
    if (total < 20) {
        if (divisor > number) {
            if (divisionNumber == 2) {
                printf("%3d", number);
                primos(number + 1, 1, 0, ++total);
            } else {
                primos(number + 1, 1, 0, total);
            }
        } else {
            if (number % divisor == 0) {
                divisionNumber++;
            }
            primos(number, divisor + 1, divisionNumber, total);
        }
    }
}
