/*Escreva um programa com uma função recursiva que imprima na tela a sequência de Fibonacci (1, 1, 2, 3, 5, 8, ...) até seu 20º elemento.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void fibonacci(int, int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    printf("20 primeiros números da sequência fibonacii: ");
    fibonacci(0, 0, 1);

    system("pause");
    return 0;
}

void fibonacci(int number, int previusNumber, int total) {
    printf("%d ", number);

    if (total >= 20) {
        return;
    }

    if (number == 0) {
        number++;
        fibonacci(number, previusNumber, ++total);
    } else {
        int temp = number;
        number += previusNumber;
        previusNumber = temp;
        fibonacci(number, previusNumber, ++total);
    }
}
