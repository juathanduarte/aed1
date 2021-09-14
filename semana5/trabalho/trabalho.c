#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTION (sizeof(int))
#define COUNTER (sizeof(int))

#define AGE (sizeof(int))
#define NUMBER (sizeof(int))
#define NAME (sizeof(char) * 10)

void *addPerson(void *pBuffer, void *linkedList, void *first, void *prox, void *anterior);
// void list(void *pBuffer, void *linkedList);
// void *removed(void *pBuffer, void *linkedList);
// void search(void *pBuffer, void *linkedList);

int main(){
    void *pBuffer = NULL;
    void *linkedList = NULL;

    void *first = NULL;
    void *prox = NULL;
    void *anterior = NULL;

    pBuffer = malloc(OPTION + COUNTER);
    linkedList = malloc(NAME + AGE + NUMBER);

    if (!pBuffer){
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
            pBuffer = addPerson(pBuffer, linkedList, first, prox, anterior);
            break;
        case 2:
            // pBuffer = removed(pBuffer, linkedList);
            break;
        case 3:
            // list(pBuffer, linkedList);
            break;
        case 4:
            // search(pBuffer, linkedList);
            break;
        case 5:
            free(pBuffer);
            exit(0);
            break;
        default:
            printf("\nOpcao invalida, tente novamente!\n");
            break;
        }
    } while ((*(int *)(pBuffer) >= 1) || (*(int *)(pBuffer) <= 5));
}

void *addPerson(void *pBuffer, void *linkedList, void *first, void *prox, void *anterior){
    int *counter = (int *)(pBuffer + OPTION);

    prox = malloc(NAME + AGE + NUMBER);

    if (!prox){
        printf("Memoria insuficiente");
        exit (1);
    }
 
    printf("Digite o nome:\n ");
    scanf("%s", (char *)(prox));
    //getchar();

    printf("\nDigite a idade:\n ");
    scanf("%d", (int *)(prox + AGE));
    //getchar();
   
    printf("\nDigite o telefone:\n ");
    scanf("%d", (int *)(prox + AGE + NUMBER));
    //getchar();

    *counter += 1;

    if (*counter == 0){
        first = prox;
        prox = NULL;
    } else {
        //NÃO VAI SER A PRIMEIRA
    }

    printf("%s %d %d", (char *)(first), *(int *)(first + AGE), *(int *)(first + AGE + NUMBER));

    return linkedList, pBuffer;
}

// void list(void *pBuffer, void *linkedList){
//         int totalPeople;
//         int i;
     
//         totalPeople = *(int *)pBuffer;
        
//         if(totalPeople == 0){
//             printf("Agenda esta vazia, insira algo!\n\n");
//         } else {
//             for(i = 0 ; i < totalPeople ; i++){
//                 printf("Nname [%d]\n", i + 1);
//                 printf("Nome: %s\n", (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * i);
//                 printf("Idade: %d\n", *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * i));
//                 printf("Numero: %d\n\n", *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * i));
//             }
//         }
// }

// void search(void *pBuffer, void *linkedList){
//     int totalPeople;
//     int i;
//     char aux_nome[10];
    
//     printf("Digite o nome que queira buscar: \n");
//     scanf("%s", aux_nome);
//     getchar();

//     totalPeople = *(int *)pBuffer;

//     for(i = 0; i < totalPeople; i++){
//         if(strcmp((char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * i ,aux_nome) == 0){
//             printf("\nName: %s\n", (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * i);
//             printf("\nIdade: %d\n", *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * i));
//             printf("\nNumero: %d\n", *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * i));
//             return;
//         }
//     }
//     printf("Nome não encontrado!!\n");
//     return;
// }

// void *removed(void *pBuffer, void *linkedList){
//     int totalPeople, j, i;
//     char aux_nome[10];

//     totalPeople = *(int *)pBuffer;

//     if (totalPeople == 0){
//         printf("Agenda esta vazia, insira algo!\n\n");
//     } else {
//         printf("Digite o nome que queira remover: ");
//         scanf("%s", aux_nome);
//         getchar();

//         for(i = 0; i < totalPeople; i++){
//             if(strcmp((char *)pBuffer + NNAME + ((NAME + AGE + NUMBER) * i), aux_nome) == 0) {
//                 for(j = i; j < totalPeople; j++){
//                     strcpy((char *)pBuffer + NNAME + ((NAME + AGE + NUMBER) * j), (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * (j + 1));
//                     *(int *)(pBuffer + NNAME + NAME + ((NAME + AGE + NUMBER) * j)) = *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * (j + 1));
//                     *(int *)(pBuffer + NNAME + NAME + AGE + ((NAME + AGE + NUMBER * j))) = *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * (j + 1));
//                 }
//                 *(int *)pBuffer = totalPeople - 1;
//                 pBuffer = realloc(pBuffer, NNAME + (NAME + AGE + NUMBER) * (totalPeople - 1));
//                 return pBuffer;
//             }
//         }
//         printf("Nome não encontrado!\n\n");
//     }
//     return pBuffer;
// }