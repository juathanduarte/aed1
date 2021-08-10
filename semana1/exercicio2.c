#include <stdio.h>
#include <stdlib.h>

void addName(void);
void removeName(void);
void listName(void);

char *listNames = NULL; //Inicializo o ponteiro com NULL, boa prática


int main(){

    listNames = malloc(sizeof(char)); //Aloco espaço de memória necessário para a lista de nomes

    if (listNames == NULL){ //Verifico se tem memória
        printf("Memoria insuficiente!");
        return -1;
    }

    int option;

    do{ //Opções de menu
        printf("Programa que armazena nomes\n");
        printf("\t1) Adicionar nome\n");
        printf("\t2) Remover nome\n");
        printf("\t3) Listar\n");
        printf("\t4) Sair\n");
        printf("\t- Opcao: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                system("cls || clear");
                printf("VAI ADICIONAR NOME AQUI");
                break;
            case 2:
                system("cls || clear");
                printf("VAI REMOVER NOME AQUI");
                break;
            case 3:
                system("cls || clear");
                printf("VAI LISTAR OS NOMES AQUI");
                break;
            case 4:
                system("cls || clear");
                exit(0);
                free(listNames); //Para não haver vazamento de memória
                break;
            default:
                system("cls || clear");
                printf("OPCAO INVALIDA! TENTE NOVAMENTE!");
        }
    } while (option);
}

void addName(){

}

void removeName(){

}

void listName(){

}