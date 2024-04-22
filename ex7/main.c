/*Escreva um programa com uma função recursiva que possa converter um número decimal em um número binário. Use o método das divisões sucessivas.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void binary(int);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int number;

    printf("Digite um número: ");
    scanf("%d", &number);

    printf("%d em binário: ", number);
    binary(number);

    system("pause");
    return 0;
}

void binary(int number) {
    if (number > 0) {
        binary(number / 2);
        printf("%d ", number % 2);
    }
}
