/*Escreva um programa que calcule os 7 (***OBS: só tem 4) primeiros números perfeitos e armazene em um arquivo direto. Considere números perfeitos, os números que a soma de seus divisores de o próprio número.
Exemplo: 6 é perfeito porque 1 + 2 + 3 = 6.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int var_arq;
FILE *arq;

void calculate();
bool openFile();
void show();

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    if (openFile()) {
        calculate();
        show();
    }

    fclose(arq);

    system("pause");
}

bool openFile() {
    arq = fopen("numerosPerfeitos.dat", "r+");
    if (arq == NULL) {
        arq = fopen("numerosPerfeitos.dat", "w+");
        if (arq == NULL) {
            printf("Erro na abertura do arquino");
            return false;
        }
    }
    return true;
}

void calculate() {
    int total = 0;
    for (int i = 1; total < 4; ++i) {
        int sum = 0;
        for (int j = 1; j < i; ++j) {
            if (i % j == 0) {
                sum += j;
            }
        }

        if (sum == i) {
            total++;
            var_arq = i;
            fwrite(&var_arq, sizeof(var_arq), 1, arq);
        }
    }
}

void show() {
    fseek(arq, 0, SEEK_SET);

    printf("4 PRIMEIROS NÚMEROS PERFEITOS\n");
    while (fread(&var_arq, sizeof(var_arq), 1, arq)) {
        printf("%d  ", var_arq);
    }
}
