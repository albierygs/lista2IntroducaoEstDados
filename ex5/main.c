/*Escreva um programa que possa calcular, armazenar e mostrar a tabuada de multiplicação entre 0 e 10 de um determinado número qualquer.
Dica: Desenvolva um menu com as seguintes opções:
A) Mostrar a tabuada de um número lendo do arquivo
B) Calcular e gravar no arquivo a tabuada de um número
C) Fim do programa.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tabuada {
    int number;
    int result[11];
} t_tabuada;
t_tabuada var_arq;
FILE *arq;

void insert();
bool openFile();
void show();
void menu();
bool search(int);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    if (openFile()) {
        menu();
    }

    fclose(arq);

    system("pause");
}

void menu() {
    int option;

    do {
        printf("MENU\n");
        printf("1 - INSERIR TABUADA DE UM NÚMERO\n2 - VER TABUADA DE UM NÚMERO\n3 - SAIR\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        system("cls");

        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                show();
                break;
            case 3:
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 3);
}

bool openFile() {
    arq = fopen("tabuada.dat", "r+");
    if (arq == NULL) {
        arq = fopen("tabuada.dat", "w+");
        if (arq == NULL) {
            printf("Erro na abertura do arquivo\n");
            return false;
        }
    }
    return true;
}

bool search(int number) {
    fseek(arq, 0, SEEK_SET);

    while (fread(&var_arq, sizeof(var_arq), 1, arq)) {
        if (var_arq.number == number) {
            return true;
        }
    }
    return false;
}

void insert() {
    int number;

    printf("Número que deseja inserir a tabuada: ");
    scanf("%d", &number);

    if (search(number)) {
        printf("Tabuada já registrada\n");
    } else {
        var_arq.number = number;

        for (int i = 0; i <= 10; ++i) {
            var_arq.result[i] = number * i;
        }

        if (fwrite(&var_arq, sizeof(var_arq), 1, arq)) {
            printf("Tabuada salva!\n");
        }
    }
}

void show() {
    int number;

    printf("Número que deseja ver a tabuada: ");
    scanf("%d", &number);

    if (search(number)) {
        fseek(arq, 0, SEEK_SET);
        printf("TABUADA DE %d\n", number);

        while (fread(&var_arq, sizeof(var_arq), 1, arq)) {
            if (var_arq.number == number) {
                for (int i = 0; i <= 10; ++i) {
                    printf("%d X %d = %d\n", var_arq.number, i, var_arq.result[i]);
                }
            }
        }
    } else {
        printf("Tabuada não registrada\n");
    }
}

