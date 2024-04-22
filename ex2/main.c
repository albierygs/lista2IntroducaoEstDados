/* Seja PROGRAMADORES um arquivo direto, composto dos campos CPF, NOME, IDADE e PROFISSÃO. Escreva um programa com uma rotina para recuperar os registros salvos no disco, outra para inserir registros nesse arquivo e outra que exclua todas as informações existentes sobre os programadores com idade entre 25 e 50 anos. */


#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>


typedef struct Programmers {
    int cpf;
    char name[30];
    int age;
    char profession[30];
} t_programmers;
t_programmers var_arq;
FILE *arq;

void openFile();
void insert();
void list();
void exclude();
void menu();
bool search(int);

int main() {
    setlocale(LC_ALL, "Portuguese");

    openFile();

    if (arq != NULL)
    {
        menu();
    }

    fclose(arq);

    system("pause");
}


void openFile() {
    arq = fopen("Programadores.dat", "r+");
    if (arq == NULL)
    {
        arq = fopen("Programadores.dat", "w+");
        if (arq == NULL)
        {
            printf("Erro na abertura do arquivo\n");
        }
    }
}

void menu() {
    int option;

    do
    {
        printf("MENU\n");
        printf("1 - INSERIR PROGRAMADOR\n2 - LISTAR PROGRAMADORES\n3 - EXCLUIR PROGRAMADORES ENTRE 25 E 50 ANOS\n4 - SAIR\n\n");
        printf("Escolha a opção: ");
        scanf("%d", &option);
        fflush(stdin);

        system("cls");

        switch (option)
        {
        case 1:
            insert();
            break;

        case 2:
            list();
            break;

        case 3:
            exclude();
            break;

        case 4:
            break;

        default:
            printf("Opção inválida!\n");
        }
    } while (option != 4);
}

bool search(int cpf) {
    fseek(arq, 0, SEEK_SET);

    while (fread(&var_arq, sizeof(var_arq), 1, arq))
    {
        if (cpf == var_arq.cpf)
        {
            return true;
        }
    }
    return false;
}

void insert() {
    int cpf;
    fseek(arq, 0, SEEK_END);

    printf("CPF: ");
    scanf("%d", &cpf);
    fflush(stdin);

    if (search(cpf))
    {
        printf("CPF já registrado\n");
    }
    else
    {
        var_arq.cpf = cpf;
        printf("Nome: ");
        gets(var_arq.name);
        printf("Idade:");
        scanf("%d", &var_arq.age);
        fflush(stdin);
        printf("Profissão: ");
        gets(var_arq.profession);
        fflush(stdin);

        if (fwrite(&var_arq, sizeof(var_arq), 1, arq) != 1)
        {
            printf("Erro de gravação\n");
        }
        else
        {
            printf("Inclusão realizada com sucesso!\n");
        }
    }
}

void list() {
    fseek(arq, 0, SEEK_SET);

    printf("PROGRAMADORES REGISTRADOS\n");

    while (fread(&var_arq, sizeof(var_arq), 1, arq))
    {
        printf("NOME: %s  CPF: %d  IDADE: %d  PROFISSÃO: %s\n", strupr(var_arq.name), var_arq.cpf, var_arq.age, var_arq.profession);
    }
}

void exclude() {
    FILE *temp;
    temp = fopen("temp.dat", "w+");
    if (temp == NULL)
    {
        printf("Erro na abertura do arquivo auxiliar\n");
        return;
    }

    fseek(arq, 0, SEEK_SET);

    while (fread(&var_arq, sizeof(var_arq), 1, arq))
    {
        if (!(var_arq.age >= 25 && var_arq.age <= 50))
        {
            fwrite(&var_arq, sizeof(var_arq), 1, temp);
        }
    }

    fclose(arq);
    remove("Programadores.dat");
    openFile();
    fseek(temp, 0, SEEK_SET);

    while (fread(&var_arq, sizeof(var_arq), 1, temp)) {
        fwrite(&var_arq, sizeof(var_arq), 1, arq);
    }

    fclose(temp);
    remove("temp.dat");
}