#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addName();
void removeName();
void listName();

char *listNames;
int listSize = 0;

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

  fgetc(stdin);
  printf("Digite o nome: ");

  if (listSize != 0) { //Separo os nomes por ,
    listNames = realloc(listNames, listSize * sizeof(char) + 2);
    strcat(listNames, ", ");
    listSize += 2;
  }

  for (i = listSize; ((listNames[i] = getchar()) != '\n') && listNames[i] != '\0'; i++) { // Adiciono nome da string
    listSize++;
    listNames = realloc(listNames, listSize * sizeof(char) + 2);
  }
  listNames[listSize] = '\0'; //Termino a string
}

void removeName() {
  getchar();
  char *removedName = (char *)malloc(sizeof(char) + 2);
  int removedNameSize = 0;
  int i, j, counterSize;

  if (!removedName) {
    printf("Memoria insuficiente!");
    exit(1);
  }

  printf("Digite o nome a ser removido: ");

  for (i = 0; ((removedName[i] = getchar()) != '\n') && removedName[i] != '\0'; i++) {
    removedNameSize++;
    removedName = realloc(removedName, removedNameSize * sizeof(char) + 2);
  }

  removedName[removedNameSize] = '\0';

  for (j = 0; j < listSize && listNames[j] != '\0'; j++) {
    if (j <= 2 || listNames[j - 2] == ',') { //Testa se é o primeiro nome
      if (j <= 2) { //Se for o primeiro nome o conteador utilizado vai ser o zerado
        counterSize = 0;
      } else {
        counterSize = j;
      }
    }

    for (; listNames[counterSize] != ',' && listNames[counterSize] != '\0'; counterSize++); //Conta o tamanho do nome na lista
    if ((counterSize - j) == removedNameSize || counterSize == removedNameSize) {
      int a, b, c;
      if (j <= 2) { //Caso seja o primeiro nome garante que as variáveis a serem utilizadas sejam 0
        a = 0;
        c = 0;
      } else {
        a = j;
        c = j;
      }

      for (b = 0; listNames[a] == removedName[b] && b < (counterSize - c); a++, b++); //Compara todas letras dos nomes
      if (b == removedNameSize) {
        if ((j == 0 || j <= 2) && !(listSize > removedNameSize)) { //Teste se é o primeiro da lista
          listSize = 0;
          listNames = realloc(listNames, sizeof(char));
          listNames[0] = '\0';
        } else if (listNames[counterSize] == '\0') { //Testa se é o último da lista
          listSize -= removedNameSize + 2;
          listNames = realloc(listNames, sizeof(char) * (listSize + 1));
          listNames[listSize] = '\0';
        } else {
          for (b = j; listNames[b + removedNameSize + 1] != '\0'; b++) { //Se estiver no meio da lista
            listNames[b] = listNames[b + removedNameSize + 2];
          }
          listSize -= (removedNameSize + 2);
          listNames = realloc(listNames, sizeof(char) * (listSize + 1));
          j--;
        }
      }
    }
    counterSize = 0;
  }
  free(removedName);
}

void listName() {
  if (listSize == 0) {
    printf("A lista esta vazia!\n");
  } else {
    printf("\nNomes listados: %s\n\n", listNames);
  }
}