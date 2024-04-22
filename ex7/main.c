/*Escreva um programa com uma fun��o recursiva que possa converter um n�mero decimal em um n�mero bin�rio. Use o m�todo das divis�es sucessivas.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void binary(int);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int number;

    printf("Digite um n�mero: ");
    scanf("%d", &number);

    printf("%d em bin�rio: ", number);
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
