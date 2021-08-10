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
        exit (1);
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
                addName();
                break;
            case 2:
                removeName();
                break;
            case 3:
                listName();
                break;
            case 4:
                free(listNames); //Para não haver vazamento de memória
                exit(0);
                break;
            default:
                printf("Opcao invalida, tente novamente!");
                break;
        }
    } while (option != 4);
}

void addName(){

}

void removeName(){

}

void listName(){

}