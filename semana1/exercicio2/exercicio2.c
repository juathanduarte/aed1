#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addName();
void removeName();
void listName();

//Declaro as variáveis globalmente
char *listNames;
char *auxRemovedName;
int listSize = 0;
char removedName[10];

int main() {

  listNames = malloc(sizeof(char)); //Aloco espaço de memória necessário para a lista de nomes

  if (listNames == NULL) { //Verifico se tem memória
      printf("Memoria insuficiente!");
      exit(1);
  }

  int option;

  do { //Opções de menu
      printf("Programa que armazena nomes\n");
      printf("\t1) Adicionar nome\n");
      printf("\t2) Remover nome\n");
      printf("\t3) Listar\n");
      printf("\t4) Sair\n");
      printf("\t- Opcao: ");
      scanf("%d", &option);

    switch (option) {
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
  } while ((option >= 1) || (option <= 4));
}

void addName() {
    int i;

    printf("Digite o nome: ");

    if (listSize != 0) { //Separo os nomes por espaço
          listNames = realloc(listNames, listSize * sizeof(char) + 1);
          strcat(listNames, " ");
          listSize++;
    }

    for (i = listSize; ((listNames[i] = getchar()) != '\n') && listNames[i] != '\0'; i++) { // Adiciono nome da string
          listSize++;
          listNames = realloc(listNames, listSize * sizeof(char) + 1);
    }
    listNames[listSize] = '\0'; //Termino a string
}

void removeName() {
      printf("Digite o nome para remover: ");
      scanf("%s", removedName);

      auxRemovedName = strstr(listNames, removedName); //Comparo a substring com a string principal para achar o endereço de memória inicial do nome a ser removido
      if (auxRemovedName) {
          for (int i = 0; i < strlen(removedName) + 1; i++) {
              memcpy(auxRemovedName, (auxRemovedName + 1), strlen(auxRemovedName + 1) + 1); //Copio diretamente os dados de onde to apontando para o destino
          }
      } else {
          printf("Nome nao encontrado!!\n");
      }

      listSize -= strlen(removedName) + 1; //Reduzo no tamanho da lista o nome que retirei
      listNames = (char *)realloc(listNames, (listSize) * sizeof(char)); //Faço o reallooc
}

void listName() {
  if (listSize == 0) { //Se a lista tiver vazia
      printf("A lista esta vazia!\n");
  } else {
      if (listNames == NULL){ //Se a lista estiver NULL (se formos apagando todos nomes fica NULL)
        printf("A lista esta vazia!\n");
    } else {
        printf("\nNomes listados: %s\n\n", listNames); //Printo toda lista
    }
  }
}