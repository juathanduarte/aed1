#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int idade;
    int altura;
} Pessoa;

int main(){
    int option;

    do {
        printf("\nExercicio 5 - Juathan | Programa que armazene a informação de várias pessoas [Struct]\n\n");
        printf("\t1) Adicionar nome: \n");
        printf("\t2) Sair: \n");
        printf("\t- Opcao: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                addName();
                break;
            case 2:
                exitProgram();
                break;
            default:
                system("clear || cls");
                printf("\nOpcao invalida, digite novamente!\n");
                break;
        }
    } while ((option >= 1) || (option <= 2));
}

void addName(){
    printf("NOME VAI SER ADICIONADO");
}

void exitProgram(){
    printf("VAI LISTAR E SAIR");
}