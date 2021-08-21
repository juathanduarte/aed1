// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void *addPerson(void *pBuffer);
// // void *removed(void *pBuffer);
// void list(void *pBuffer);
// // void *search(void *pBuffer);

// int main()
// {
//     void *pBuffer = NULL;
//     pBuffer = malloc(sizeof(int)); //nNomes
//     *(int *)pBuffer = 0;

//     if (!pBuffer){
//         printf("Erro ao alocar memoria.\n");
//         exit(1);
//     }

//     int option;

//     do{
//         printf("1- AddPerson:\n");
//         printf("2- Removed:\n");
//         printf("3- List:\n");
//         printf("4- Search: \n");
//         printf("5- Exit:\n");
//         scanf("%d", &option);
//         switch (option){
//         case 1:
//             pBuffer = addPerson(pBuffer);
//             break;
//         // case 2:
//         //     pBuffer = removed(pBuffer);
//         //     break;
//         case 3:
//             list(pBuffer);
//             break;
//         // case 4:
//         //     search(pBuffer);
//         //     break;
//         case 5:
//             free(pBuffer);
//             break;
//         }
//     } while (option != 5);
// }

// void *addPerson(void *pBuffer){
//     char name[10];
//     int age;
//     int number;

//     getchar();

//     // for (i = 0; i < 10; i++){
//     //     name[i] = NULL;
//     // }

//     // printf("digite o nome:\n ");
//     // scanf("%s", name);
    
//     pBuffer = realloc(pBuffer, sizeof(int) + (((10 * sizeof(char)) + sizeof(int) + sizeof(int))  * ((*(int*)pBuffer) + 1)));

//     if (!pBuffer){
//         printf("Memoria insuficiente");
//         exit (1);
//     }

//     // *(char *)(pBuffer + sizeof(int) + i) = name[i];
//     // getchar();

//     // printf("Digite a idade:\n ");
//     // scanf("%d", &age);
    
//     // *(int *)(pBuffer + sizeof(int) + sizeof(char) * 10) = age;
//     // getchar();
   
//     // printf("Digite o telefone:\n ");
//     // scanf("%d", &number);
    
//     // *(int *)(pBuffer + sizeof(int) * 2 + sizeof(char) * 10) = number;
//     // getchar();

//     // printf("%d", &number);

//     printf("\nInsira um nome: \n");
//     scanf("%s", &name);   // scanf do nome[10];
//     *(char *)pBuffer + sizeof(int) + (((10 * sizeof(char)) + sizeof(int) + sizeof(int)) * (*(int*)pBuffer)) = name;
//     getchar();

//     printf("Insira a Idade: \n");
//     scanf("%d", &age); // scanf da idade
//     *(int *)(pBuffer + sizeof(int) + (10 * sizeof(char)) + (((10 * sizeof(char)) + sizeof(int) + sizeof(int)) * (*(int*)pBuffer))) = age;
//     getchar();

//     printf("Insira o Telefone: \n");
//     scanf("%d", &number); // scanf do telefone
//     *(int *)(pBuffer + sizeof(int) + (10 * sizeof(char)) + sizeof(int) + (((10 * sizeof(char)) + sizeof(int) + sizeof(int)) * (*(int*)pBuffer))) = number;
//     getchar();


//     *(int *)pBuffer = *(int *)pBuffer + 1;

//     return pBuffer;
// }

// void list(void *pBuffer){
//     int i;
    
//     if (*(int*)pBuffer == 0){
//         printf("Lista vazia\n");
//     } else {
//         for (i = 0; i < *(int *)pBuffer; i++){
//             printf("\nNome: %s;\n", (char *)pBuffer + sizeof(int) + (((10 * sizeof(char)) + sizeof(int) + sizeof(int)) * i));
//             printf("Idade: %d;\n", *(int *)(pBuffer + sizeof(int) + (10 * sizeof(char)) + (((10 * sizeof(char)) + sizeof(int) + sizeof(int)) * i)));
//             printf("Telefone: %d;\n", *(int *)(pBuffer + sizeof(int) + (10 * sizeof(char)) + sizeof(int) + (((10 * sizeof(char)) + sizeof(int) + sizeof(int)) * i)));
//         }
//     }


//     // int contador, i, j;

//     // contador = *(int *)pBuffer;



//     // if (contador != 0){
//     //     if (contador == 1){
//     //         printf("Nome: ");
//     //         for (j = 0; j < 10; j++){
//     //             printf("%c", *(char *)(pBuffer + sizeof(int) + j));
//     //         }
//     //         printf("\nIdade: %d\n", *(int *)(pBuffer + sizeof(int) + sizeof(char) * 10));
//     //         printf("Telefone: %d\n\n", *(int *)(pBuffer + sizeof(int) + (sizeof(char) * 10 + sizeof(int))));
//     //     } else {
//     //         for (i = 1; i < contador; i++){
//     //             for (j = 0; j < 10; j++){
//     //                 printf("%c", *(char *)(pBuffer + sizeof(int) + j * i));
//     //             }
//     //         printf("%d\n", *(int *)(pBuffer + sizeof(int) + sizeof(char) * 10 * i));
//     //         printf("%d\n\n", *(int *)(pBuffer + sizeof(int) + (sizeof(char) * 10 + sizeof(int)) * i));
//     //      }
//     //     }
//     // } else {
//     //     printf ("Nao existe nada na lista");
//     // }
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *addPerson(void *pBuffer);
// void *removed(void *pBuffer);
void list(void *pBuffer);
// void *search(void *pBuffer);

int main()
{
    void *pBuffer = NULL;
    pBuffer = malloc(sizeof(int)); //nNomes
    *(int *)pBuffer = 0;

    if (!pBuffer){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    int option;

    do{
        printf("1- AddPerson:\n");
        printf("2- Removed:\n");
        printf("3- List:\n");
        printf("4- Search: \n");
        printf("5- Exit:\n");
        scanf("%d", &option);
        switch (option){
        case 1:
            pBuffer = addPerson(pBuffer);
            break;
        // case 2:
        //     pBuffer = removed(pBuffer);
        //     break;
        case 3:
            list(pBuffer);
            break;
        // case 4:
        //     search(pBuffer);
        //     break;
        case 5:
            free(pBuffer);
            break;
        }
    } while (option != 5);
}

void *addPerson(void *pBuffer){
    char name[10];
    int age;
    int i;
    int number;
    int contador = 0;
    getchar();

    for (i = 0; i < 10; i++){
        name[i] = NULL;
    }
    contador ++;
    printf("digite o nome:\n ");
    scanf("%s", name);
    
    pBuffer = realloc(pBuffer, sizeof(int) + (((10 * sizeof(char)) + sizeof(int) + sizeof(int))  * ((*(int*)pBuffer) + 1)));

    if (!pBuffer){
        printf("Memoria insuficiente");
        exit (1);
    }
if(contador != 1)
{

       for (i = 0; i < 10; i++){
        *(char *)(pBuffer + (sizeof(int) + i) + 10) = name[i];
    }

    getchar();

    printf("Digite a idade:\n ");
    scanf("%d", &age);
    
    *(int *)(pBuffer + (sizeof(int) + sizeof(char) * 10)+ 12) = age;
    getchar();
   
    printf("Digite o telefone:\n ");
    scanf("%d", &number);
    
    *(int *)(pBuffer + (sizeof(int) * 2 + sizeof(char) * 10)+ 14) = number;
    getchar();




}
if(contador == 1){

     for (i = 0; i < 10; i++){
        *(char *)(pBuffer + (sizeof(int) + i)) = name[i];
    }

    getchar();

    printf("Digite a idade:\n ");
    scanf("%d", &age);
    
    *(int *)(pBuffer + (sizeof(int) + sizeof(char) * 10)) = age;
    getchar();
   
    printf("Digite o telefone:\n ");
    scanf("%d", &number);
    
    *(int *)(pBuffer + (sizeof(int) * 2 + sizeof(char) * 10)) = number;
    getchar();
}

    *(int *)pBuffer = *(int *)pBuffer + 1;

    return pBuffer;
}

void list(void *pBuffer){
  
    int contador, i, j;

    contador = *(int *)pBuffer;

    if (contador != 0){
        printf("Nome: ");
        for (j = 0; j < 10; j++){
            printf("%c", *(char *)(pBuffer + sizeof(int) + j));
        }
        printf("\nIdade: %d\n", *(int *)(pBuffer + sizeof(int) + sizeof(char) * 10));
        printf("Telefone: %d\n\n", *(int *)(pBuffer + sizeof(int) + (sizeof(char) * 10 + sizeof(int))));
        if(contador > 1){ 
            for (i = 1; i < contador; i++){
                for (j = 0; j < 10; j++){
                    printf("%c", *(char *)(pBuffer + sizeof(int) + j * i));
                }
            printf("\n%d\n", *(int *)(pBuffer + sizeof(int) + sizeof(char) * 10 * i));
            printf("%d\n\n", *(int *)(pBuffer + sizeof(int) + (sizeof(char) * 10 + sizeof(int)) * i));
            }
        }
    }
}