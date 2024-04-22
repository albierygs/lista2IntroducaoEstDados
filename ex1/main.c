/* Seja NOTAS um arquivo direto, composto dos campos Matricula, Nome, Nota1, Nota2 e Média. Escreva um programa com uma rotina para inserir registros nesse arquivo, outra rotina para ler os registros salvos no disco e outra rotina para contar o número de registros deste arquivo com o campo Média maior ou igual a 7,0 e exibir o total. */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

typedef struct Notes
{
    int registration;
    char name[30];
    double note[2];
    double average;
} t_notes;

t_notes var_arq;
FILE *arq;

bool openFile();
void menu();
bool search(int);
void insert();
void list();
void bigger7();

int main()
{
    setlocale(LC_ALL, "");

    if (openFile())
    {
        menu();
    }

    system("pause");
}


bool openFile() {
    arq = fopen("Notas.dat", "r+");
    if (arq == NULL)
    {
        arq = fopen("Notas.dat", "w+");
        if (arq == NULL)
        {
            printf("Erro na abertura do arquivo\n");
            return false;
        }
    }
    return true;
}

void menu() {
    int option;

    do
    {
        printf("MENU\n");
        printf("1 - INSERIR ALUNO\n2 - VER ALUNOS SALVOS\n3 - NÚMEROS DE ALUNOS COM MÉDIA MAIOR QUE 7\n4 - SAIR\n\n");
        printf("Escolha uma opção: ");
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
            bigger7();
            break;
        case 4:
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (option != 4);
}

bool search(int registration) {
    fseek(arq, 0, SEEK_SET);

    while (fread(&var_arq, sizeof(var_arq), 1, arq))
    {
        if (var_arq.registration == registration)
        {
            return true;
        }
    }
    return false;
}

void insert() {
    int registration;

    printf("Matrícula do aluno que deseja incluir: ");
    scanf("%d", &registration);
    fflush(stdin);

    if (search(registration))
    {
        printf("Aluno já registrado!\n");
        return;
    }
    else
    {
        var_arq.registration = registration;
        printf("Nome: ");
        gets(var_arq.name);
        printf("Nota 1: ");
        scanf("%lf", &var_arq.note[0]);
        fflush(stdin);
        printf("Nota 2: ");
        scanf("%lf", &var_arq.note[1]);
        fflush(stdin);
        var_arq.average = (var_arq.note[0] + var_arq.note[1]) / 2;

        if (fwrite(&var_arq, sizeof(var_arq), 1, arq)) {
            printf("Aluno registrado com sucesso!\n");
        }
    }
}

void list() {
    fseek(arq, 0, SEEK_SET);

    printf("ALUNOS REGISTRADOS\n");

    while (fread(&var_arq, sizeof(var_arq), 1, arq))
    {
        printf("NOME: %s  MATRÍCULA: %d  NOTA 1: %.1lf  NOTA 2: %.1lf  MÉDIA: %.1lf\n", strupr(var_arq.name), var_arq.registration, var_arq.note[0], var_arq.note[1], var_arq.average);
    }
    printf("\n");
}

void bigger7() {
    int number = 0;
    fseek(arq, 0, SEEK_SET);

    while (fread(&var_arq, sizeof(var_arq), 1, arq))
    {
        if (var_arq.average >= 7)
        {
            number++;
        }
    }
    printf("Existem %d alunos com média maior que 7\n", number);
}
