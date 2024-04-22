/*A expressão em C, m % n, resulta o resto de m ao dividir por n. Defina o máximo divisor comum (MDC) de dois inteiros, x e y, por:
mdc( x, y) = y se ((y <= x) && ((x % y) == 0))
mdc( x, y) = mdc( y, x) se (x < y)
mdc( x, y) = mdc( y, x % y) caso contrario*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int mdc(int, int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int number1, number2;

    printf("Digite um número: ");
    scanf("%d", &number1);
    printf("Digite outro número: ");
    scanf("%d", &number2);

    printf("O MDC entre %d e %d é %d\n", number1, number2, mdc(number1, number2));

    system("pause");
    return 0;
}

int mdc(int x, int y) {
    int result;
    if (y <= x && x % y == 0) {
        result = y;
    } else if (x < y) {
        result = mdc(y, x);
    } else {
        result = mdc(y, x % y);
    }
    return result;
}
