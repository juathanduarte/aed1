#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTION (sizeof(int))
#define TOTALPEOPLE (sizeof(int))
#define AUX_SEARCH (sizeof(int) * 10)

#define NNAME (sizeof(int))
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

    pBuffer = malloc(OPTION + TOTALPEOPLE + AUX_SEARCH);

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
    if (*(int *)(pBuffer + OPTION) == 10) {
        printf("Lista cheia!");
    } else {
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
            for (*(int *)(pBuffer + OPTION + TOTALPEOPLE) = 0 ; *(int *)(pBuffer + OPTION + TOTALPEOPLE) < ((*(int*)(pBuffer) + OPTION)) ; *(int *)(pBuffer + OPTION + TOTALPEOPLE) += 1){
                printf("Nname [%d]\n", *(int *)(pBuffer + OPTION + TOTALPEOPLE) + 1);
                printf("Nome: %s\n", (pessoas + (*(int *)pBuffer + OPTION)) -> name);
                printf("Idade: %d\n", (pessoas + (*(int *)pBuffer + OPTION)) -> age);
                printf("Numero: %d\n\n", (pessoas + (*(int *)pBuffer + OPTION)) -> telephone);
            }
        }
}

void search(void *pBuffer){
    int totalPeople;
    int i;
    char aux_nome[10];
    
    printf("Digite o nome que queira buscar: \n");
    scanf("%s", aux_nome);
    getchar();

    totalPeople = *(int *)pBuffer;

    for(i = 0; i < totalPeople; i++){
        if(strcmp((char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * i ,aux_nome) == 0){
            printf("\nName: %s\n", (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * i);
            printf("\nIdade: %d\n", *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * i));
            printf("\nNumero: %d\n", *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * i));
            return;
        }
    }
    printf("Nome não encontrado!!\n");
    return;
}

void *removed(void *pBuffer){
    int totalPeople, j, i;
    char aux_nome[10];

    totalPeople = *(int *)pBuffer;

    if (totalPeople == 0){
        printf("Agenda esta vazia, insira algo!\n\n");
    } else {
        printf("Digite o nome que queira remover: ");
        scanf("%s", aux_nome);
        getchar();

        for(i = 0; i < totalPeople; i++){
            if(strcmp((char *)pBuffer + NNAME + ((NAME + AGE + NUMBER) * i), aux_nome) == 0) {
                for(j = i; j < totalPeople; j++){
                    strcpy((char *)pBuffer + NNAME + ((NAME + AGE + NUMBER) * j), (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * (j + 1));
                    *(int *)(pBuffer + NNAME + NAME + ((NAME + AGE + NUMBER) * j)) = *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * (j + 1));
                    *(int *)(pBuffer + NNAME + NAME + AGE + ((NAME + AGE + NUMBER * j))) = *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * (j + 1));
                }
                *(int *)pBuffer = totalPeople - 1;
                pBuffer = realloc(pBuffer, NNAME + (NAME + AGE + NUMBER) * (totalPeople - 1));
                return pBuffer;
            }
        }
        printf("Nome não encontrado!\n\n");
    }
    return pBuffer;
}