#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Auxiliares
#define COUNTER (sizeof(int))
#define OPTION (sizeof(int))
#define AUX_POINTERPOINTER (sizeof(void **))

//Informações da Pessoa
#define NAME (sizeof(char) * 10)
#define AGE (sizeof(int))
#define NUMBER (sizeof(int))

//Finais da fila
#define FIRST_PERSON (sizeof(int))
#define LAST_PERSON (sizeof(int) + sizeof(void **))

//Antes e depois do nome
#define NEXT_PERSON (sizeof(char) * 10 + sizeof(int) + sizeof(int) + sizeof(void **))
#define PREVIOUS_PERSON (sizeof(char) * 10 + sizeof(int) + sizeof(int))

void addPerson(void *pBuffer, void *pAux);
void list(void *pBuffer, void *pAux);
void removed(void *pBuffer, void *linkedList, void *pRun);
void search(void *pBuffer, void *pAux, void *pRun);
void exitProgram(void *pAux);

int main(){
    void *pAux = NULL;
    pAux = malloc(COUNTER + AUX_POINTERPOINTER + AUX_POINTERPOINTER);

    *(int *)(pAux) = 0;

    void *pBuffer = NULL;
    pBuffer = malloc(OPTION + AUX_POINTERPOINTER);

    void *pRun = NULL;

    if (!pBuffer | !pAux){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    do{
        printf("Agenda [Juathan]\n");
        printf("\t1-) Adicionar nome:\n");
        printf("\t2-) Remover nome:\n");
        printf("\t3-) Listar nomes:\n");
        printf("\t4-) Buscar nome: \n");
        printf("\t5-) Sair do programa:\n");
        printf("\t- Opcao: ");
        scanf("%d", (int *)(pBuffer));
        getchar();
        printf("\n");
        switch (*(int *)(pBuffer)){
        case 1:
            system("clear || cls");
            addPerson(pBuffer, pAux);
            break;
        case 2:
            system("clear || cls");
            removed(pBuffer, pAux, pRun);
            break;
        case 3:
            system("clear || cls");
            list(pBuffer, pAux);
            break;
        case 4:
            system("clear || cls");
            search(pBuffer, pAux, pRun);
            break;
        case 5:
            system("clear || cls");
            exitProgram(pAux);
            free(pBuffer);
            free(pAux);
            exit(0);
            break;
        default:
            printf("\nOpcao invalida, tente novamente!\n");
            break;
        }
    } while ((*(int *)(pBuffer) >= 1) || (*(int *)(pBuffer) <= 5));
}

void addPerson(void *pBuffer, void *pAux){
    int *counter = (int *)(pAux);

    void *pPersonInfo = NULL;
    pPersonInfo = malloc(NAME + AGE + NUMBER + AUX_POINTERPOINTER + AUX_POINTERPOINTER);

    void *pPersonInfoAux = NULL;

    if (!pPersonInfo){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    printf("\nOpção [1] - Adicionar nome\n");

    printf("\nDigite o nome:\n ");
    scanf("%s", (char *)pPersonInfo);
    getchar();

    printf("\nDigite a idade:\n ");
    scanf("%d", &*(int *)(pPersonInfo + NAME));
    getchar();
   
    printf("\nDigite o telefone:\n ");
    scanf("%d", &*(int *)(pPersonInfo + NAME + AGE));
    getchar();

    *(void **)(pPersonInfo + NEXT_PERSON) = NULL;   
    *(void **)(pPersonInfo + PREVIOUS_PERSON) = NULL;

    if (*counter == 0){
        *(void **)(pAux + LAST_PERSON) = pPersonInfo;
        *(void **)(pAux + FIRST_PERSON) = pPersonInfo;
        
        *counter += 1;

        return;
    }

    pBuffer = *(void **)(pAux + FIRST_PERSON);

    while(pBuffer != NULL){
        if(strcmp((char *)pPersonInfo, (char *)pBuffer) < 0){
            *(void **)(pPersonInfo + PREVIOUS_PERSON) = *(void **)(pBuffer + PREVIOUS_PERSON);
            *(void **)(pPersonInfo + NEXT_PERSON) = pBuffer;

            if(*counter > 1 && *(void **)(pBuffer + PREVIOUS_PERSON) != NULL){
                pPersonInfoAux = *(void **)(pBuffer + PREVIOUS_PERSON);
                *(void **)(pPersonInfoAux + NEXT_PERSON) = pPersonInfo;
            }

            *(void **)(pBuffer + PREVIOUS_PERSON) = pPersonInfo;

            if(*(void **)(pPersonInfo + PREVIOUS_PERSON) == NULL){
                *(void **)(pAux + FIRST_PERSON) = pPersonInfo;
            }

            if(*counter == 1 && *(void **)(pBuffer + NEXT_PERSON) == NULL){
                *(void **)(pAux + LAST_PERSON) = pBuffer;
            }

            *counter += 1; 

            return;
        }

        if(*(void **)(pBuffer + NEXT_PERSON) == NULL){
            pPersonInfoAux = pBuffer;
        }

        pBuffer = *(void **)(pBuffer + NEXT_PERSON);
    }

    *(void **)(pPersonInfo + PREVIOUS_PERSON) = pPersonInfoAux;
    *(void **)(pPersonInfoAux + NEXT_PERSON) = pPersonInfo;
    *(void **)(pAux + LAST_PERSON) = pPersonInfo;

    *counter += 1;

    return;
}

void removed(void *pBuffer, void *pAux, void *pRun){
    int *counter = (int *)(pAux);

    if (*counter == 0){
        printf("\nOpção [2] - Remover nome\n");
        printf("\nAgenda esta vazia, insira algo!\n\n");
    } else {
        printf("\nOpção [2] - Remover nome\n");
        printf("\nO primeiro nome da lista foi removido!\n\n");
        pRun = *(void **)(pAux + FIRST_PERSON);
        *(void **)(pAux + FIRST_PERSON) = *(void **)(pRun + NEXT_PERSON);
        free(pRun);
        *(void **)(pBuffer + PREVIOUS_PERSON) = NULL;

        *counter -= 1;
    }
}

void list(void *pBuffer, void *pAux){
    void *pPersonInfo = NULL;
    pPersonInfo = *(void **)(pAux + FIRST_PERSON);

    int *counter = (int *)(pAux); // Contador

    if(*counter == 0){
        printf("\nOpção [3] - Listar nomes\n");
        printf("\nAgenda esta vazia, insira algo!\n\n");
    } else {
        printf("\nOpção [3] - Listar nomes\n\n");
        while(pPersonInfo != NULL){
            printf("Nome: %s\n", (char *)pPersonInfo);
            printf("Idade: %d\n", *(int *)(pPersonInfo + NAME));
            printf("Numero: %d\n\n", *(int *)(pPersonInfo + NAME + AGE));

            pPersonInfo = *(void **)(pPersonInfo + NEXT_PERSON);
        }
    }
}

void search(void *pBuffer, void *pAux, void *pRun){
    int *counter = (int *)(pAux);

    void *auxSearch = malloc(sizeof(char) * 10);

    pRun = *(void **)(pAux + FIRST_PERSON);

    if(*counter == 0){
        printf("\nOpção [4] - Buscar nome\n");
        printf("\nNão existem pessoas na lista!\n\n");

        free(auxSearch);

        return;
    } else {
        printf("\nOpção [4] - Buscar nome\n\n");

        printf("Digite o nome que queira buscar: \n");
        scanf("%s", (char *)auxSearch);
        getchar();

        while(pRun != NULL){
            if(strcmp(pRun ,(char *)auxSearch) == 0){
                printf("Nome: %s\n", (char *)pRun);
                printf("Idade: %d\n", *(int *)(pRun + NAME));
                printf("Numero: %d\n\n", *(int *)(pRun + NAME + AGE));

                free(auxSearch);
                
                return;
            }
            pRun = *(void **)(pRun + NEXT_PERSON);
        }
    }

    free(auxSearch);

    return;
}

void exitProgram(void *pAux){
    void *pFree = *(void **)(pAux + FIRST_PERSON);
    int *counter = (int *)(pAux);

    if ((int *)(pAux) == 0){
        printf("Lista vazia, até!");
    } else {
        while (*(void **)(pAux + FIRST_PERSON) != NULL) {
            pFree = *(void **)(pAux + FIRST_PERSON);
            *(void **)(pAux + FIRST_PERSON) = *(void **)(pFree + NEXT_PERSON);
            free(pFree);

            *counter -= 1;
        }
    }
}