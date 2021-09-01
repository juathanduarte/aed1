#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTION (sizeof(int))
#define TOTALPEOPLE (sizeof(int))
#define AUX_LIST (sizeof(int))
#define AUX_SEARCH (sizeof(char) * 10)
#define AUX_COUNTER (sizeof(int))
#define AUX_COUNTER1 (sizeof(int))
#define AUX_REMOVED (sizeof(char) * 10)

#define AGE (sizeof(int))
#define NUMBER (sizeof(int))
#define NAME (sizeof(char) * 10)

void *addPerson(void *pBuffer);
void list(void *pBuffer);
void *removed(void *pBuffer);
void search(void *pBuffer);

typedef struct{
    char name[10];
    int age;
    int telephone;
} Pessoa;

Pessoa pessoas[10];

int main(){

    void *pBuffer = NULL;

    pBuffer = malloc(OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED + AUX_COUNTER1);

    if (!pBuffer){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    *(int *)(pBuffer + OPTION) = 0;

    do{
        printf("\t1-) Adicionar nome:\n");
        printf("\t2-) Remover nome:\n");
        printf("\t3-) Listar nomes:\n");
        printf("\t4-) Buscar nome: \n");
        printf("\t5-) Sair do programa:\n");
        printf("\t- Opcao: ");
        scanf("%d", (int *)(pBuffer));
        getchar();
        printf("\n");

        switch (*(int *)(pBuffer)) {
            case 1:
                system("clear || cls");
                pBuffer = addPerson(pBuffer);
                break;
            case 2:
                system("clear || cls");
                pBuffer = removed(pBuffer);
                break;
            case 3:
                system("clear || cls");
                list(pBuffer);
                break;
            case 4:
                system("clear || cls");
                search(pBuffer);
                break;
            case 5:
                system("clear || cls");
                free(pBuffer);
                exit(0);
                break;
            default:
                system("clear || cls");
                printf("\nOpcao invalida, tente novamente!\n");
                break;
        }
    } while ((OPTION >= 1) || (OPTION <= 5));
}

void *addPerson(void *pBuffer){
    if (*(int *)(pBuffer + OPTION) >= 10) {
        printf("Lista cheia!\n\n");
        return pBuffer;
    } else {
        printf("\n---ADICIONAR NOME---\n\n");
        printf("Digite o nome:\n ");
        scanf("%s", (pessoas + *(int *)(pBuffer + OPTION)) -> name);
        getchar();

        printf("\nDigite a idade:\n ");
        scanf("%d", &(pessoas + *(int *)(pBuffer + OPTION)) -> age);
        getchar();
    
        printf("\nDigite o telefone:\n ");
        scanf("%d", &(pessoas + *(int *)(pBuffer + OPTION)) -> telephone);
        getchar();

        *(int *)(pBuffer + OPTION) = *(int *)(pBuffer + OPTION) + 1; //CONTADOR DE PESSOAS++
    }

    return pBuffer;
}

void list(void *pBuffer){
    if (*(int *)(pBuffer + OPTION) == 0) {
        printf("Agenda esta vazia, insira algo!\n\n");
    } else {
        printf("\n---LISTA DE NOMES---\n\n");
        for (*(int *)(pBuffer + OPTION + TOTALPEOPLE) = 0 ; *(int *)(pBuffer + OPTION + TOTALPEOPLE) < *(int*)(pBuffer + OPTION) ; *(int *)(pBuffer + OPTION + TOTALPEOPLE) += 1){
            printf("Nname [%d]\n", *(int *)(pBuffer + OPTION + TOTALPEOPLE) + 1);
            printf("Nome: %s\n", (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE)) -> name);
            printf("Idade: %d\n", (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE)) -> age);
            printf("Numero: %d\n\n", (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE)) -> telephone);
        }
    }
}

void search(void *pBuffer){    
    printf("Digite o nome que queira buscar: \n");
    scanf("%s", (char *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST));
    getchar();

    for(*(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH) = 0; *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH) <  *(int*)(pBuffer + OPTION); *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH) += 1){
        if(strcmp((char *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST), (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH)) -> name ) == 0){
            printf("\n---NOME BUSCADO---\n\n");
            printf("Nome: %s\n", (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH)) -> name);
            printf("Idade: %d\n", (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH)) -> age);
            printf("Numero: %d\n\n", (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH)) -> telephone);
            return;
        }
    }
    printf("Nome não encontrado!!\n");
    return;
}

void *removed(void *pBuffer){
    if (*(int *)(pBuffer + OPTION) == 0){
        printf("Agenda esta vazia, insira algo!\n\n");
    } else {
        printf("Digite o nome que queira remover: ");
        scanf("%s", (char *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER)); //Aux removed char[10]
        getchar();

        for(*(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH) = 0; *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH) < *(int *)(pBuffer + OPTION); *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH) += 1){ // Aux Counter + 1
            if(strcmp((char *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER), (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH)) -> name ) == 0) { // Se o nome digitado estiver na lista entra aqui
                 for(*(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED) = *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH); *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED) < *(int *)(pBuffer + OPTION); *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED) += 1){
                    strcpy((pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED)) -> name, (pessoas + 1 + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED)) -> name);
                    (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED)) -> age = (pessoas + 1 + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED)) -> age;
                    (pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED)) -> telephone = (pessoas + 1 + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_LIST + AUX_SEARCH + AUX_COUNTER + AUX_REMOVED)) -> telephone;
                }
                *(int *)(pBuffer + OPTION) = *(int *)(pBuffer + OPTION) - 1;
                return pBuffer;
            }
        }
        printf("Nome não encontrado!\n\n");
    }
    return pBuffer;
}