#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AGE (sizeof(int))
#define NUMBER (sizeof(int))
#define NNAME (sizeof(int))
#define NAME (sizeof(char) * 10)

void *addPerson(void *pBuffer);
void list(void *pBuffer);
void *removed(void *pBuffer);
void search(void *pBuffer);

int main(){

    void *pBuffer = NULL;

    pBuffer = malloc(NNAME); //nNome

    *(int *)pBuffer = 0; //nNome = 0

    if (!pBuffer){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    int option;

    do{
        printf("\t1-) Adicionar nome:\n");
        printf("\t2-) Remover nome:\n");
        printf("\t3-) Listar nomes:\n");
        printf("\t4-) Buscar nome: \n");
        printf("\t5-) Sair do programa:\n");
        printf("\t- Opcao: ");
        scanf("%d", &option);
        printf("\n");
        switch (option){
        case 1:
            pBuffer = addPerson(pBuffer);
            break;
        case 2:
            pBuffer = removed(pBuffer);
            break;
        case 3:
            list(pBuffer);
            break;
        case 4:
            search(pBuffer);
            break;
        case 5:
            free(pBuffer);
            exit(0);
            break;
        default:
            printf("\nOpcao invalida, tente novamente!\n");
            break;
        }
    } while ((option >= 1) || (option <= 5));
}

void *addPerson(void *pBuffer){
    int totalPeople;

    getchar();

    totalPeople = *(int *)pBuffer;

    pBuffer = realloc(pBuffer, NNAME + (NAME + AGE + NUMBER) * (totalPeople + 1));
     
    if (!pBuffer){
        printf("Memoria insuficiente");
        exit (1);
    }
 
    printf("Digite o nome:\n ");
    scanf("%s", (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * totalPeople);
    getchar();

    printf("\nDigite a idade:\n ");
    scanf("%d", (int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * totalPeople));
    getchar();
   
    printf("\nDigite o telefone:\n ");
    scanf("%d", (int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * totalPeople));
    getchar();

    *(int *)pBuffer = totalPeople + 1;

    return pBuffer;
}

void list(void *pBuffer){
        int totalPeople;
        int i;
     
        totalPeople = *(int *)pBuffer;
        
        if(totalPeople == 0){
            printf("Agenda esta vazia, insira algo!\n\n");
        } else {
            for(i = 0 ; i < totalPeople ; i++){
                printf("Nname [%d]\n", i + 1);
                printf("Nome: %s\n", (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * i);
                printf("Idade: %d\n", *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * i));
                printf("Numero: %d\n\n", *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * i));
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