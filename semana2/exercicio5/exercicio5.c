#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int idade;
    int altura;
} Pessoa;

void *addName(Pessoa *ponteiroPessoa, int listSize);
void exitProgram(Pessoa *ponteiroPessoa, int listSize);

void main(){

    int listSize = 0;
    Pessoa *ponteiroPessoa = NULL;

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
                system("clear || cls");
                ponteiroPessoa = addName(ponteiroPessoa, listSize);
                listSize = listSize + 1;
                break;
            case 2:
                system("clear || cls");
                exitProgram(ponteiroPessoa, listSize);
                free(ponteiroPessoa);
                exit(1);
                break;
            default:
                system("clear || cls");
                printf("\nOpcao invalida, digite novamente!\n");
                break;
        }
    } while ((option >= 1) || (option <= 2));
}

void *addName(Pessoa *ponteiroPessoa, int listSize){
    if(listSize != 0){ // se não é a primeira pessoa
        ponteiroPessoa = (Pessoa *)realloc(ponteiroPessoa, sizeof(Pessoa) * (listSize + 1));
    } else { // se for a primeira pessoa
        ponteiroPessoa = (Pessoa *)malloc(sizeof(Pessoa));
    }

    printf("\nDigite o nome da pessoa: \n");
    scanf("%s", (ponteiroPessoa + listSize) -> nome);
    getchar();

    printf("\nDigite a idade da pessoa: \n");
    scanf("%d", &(ponteiroPessoa + listSize) -> idade);
    getchar();

    printf("\nDigite a altura da pessoa:  \n");
    scanf("%d", &(ponteiroPessoa + listSize) -> altura);
    getchar();

    return ponteiroPessoa;
}

void exitProgram(Pessoa *ponteiroPessoa, int listSize){
    if (listSize > 0){
        printf("\n---Nomes adicionados---\n\n");
        for (int i = 0; i < listSize; i++){
            printf("Nome %s\n", (ponteiroPessoa + i) -> nome);
            printf("Idade: %d\n", (ponteiroPessoa + i) -> idade);
            printf("Altura: %d\n\n", (ponteiroPessoa + i) -> altura);
        }
    } else {
         printf("\nA lista esta vazia!\n");
    }
}