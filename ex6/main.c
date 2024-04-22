/*Escreva um programa com uma rotina recursiva que possa multiplicar um número por outro através de somas consecutivas. Exemplo: 5 * 4 = 5 + 5 + 5 +5*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int soma(int, int);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int number1, number2;

    printf("Digite um número: ");
    scanf("%d", &number1);
    printf("Digite outro número: ");
    scanf("%d", &number2);

    printf("%d X %d = %d\n", number1, number2, soma(number1, number2));

    system("pause");
    return 0;
}

int soma(int n1, int n2) {
    int result;

    if (n2 == 0 || n1 == 0) {
        result = 0;
    } else if (n2 > 0) {
        result = n1 + soma(n1, (n2 - 1));
    }
    return result;
}
