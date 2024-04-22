/*Escreva um programa que calcule os 20 primeiros números primos e armazene em um arquivo direto. Números primos são aqueles divisíveis somente por um e por ele mesmo.*/

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
    arq = fopen("primos.dat", "r+");
    if (arq == NULL) {
        arq = fopen("primos.dat", "w+");
        if (arq == NULL) {
            printf("Erro na abertura do arquino");
            return false;
        }
    }
    return true;
}

void calculate() {
    int total = 0;
    for (int i = 1; total < 20; ++i) {
        int divisionsNumber = 0;
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                divisionsNumber++;
            }
        }

        if (divisionsNumber == 2) {
            total++;
            var_arq = i;
            fwrite(&var_arq, sizeof(var_arq), 1, arq);
        }
    }
}

void show() {
    fseek(arq, 0, SEEK_SET);

    printf("20 PRIMEIROS NÚMEROS PRIMOS\n");
    while (fread(&var_arq, sizeof(var_arq), 1, arq)) {
        printf("%d  ", var_arq);
    }
}
