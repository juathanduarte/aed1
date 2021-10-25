#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void orderVetor(int *pVetor, int sizeVetor);
void insertionSort(int *pVetor, int sizeVetor);

int main (){
  int sizeVetor = 0, random, option, i;

  int *pVetor = NULL;

  printf ("Digite o tamanho do vetor: ");
  scanf("%d", &sizeVetor);
  getchar();

  pVetor = malloc(sizeVetor * sizeof(int));

  srand(time(NULL));

  for (i = 0; i < sizeVetor; i++){
    random = rand() % 100;
    pVetor[i] = random;
    printf("%d ", pVetor[i]);
  }

  do {
    printf("\n\nLista de Exercicios 5 - Juathan | Algoritmos de ordenacao.\n\n");
    printf("\t1) Insertion Sort \n");
    printf("\t2) Selection Sort: \n");
    printf("\t3) Quick Sort \n");
    printf("\t4) Merge Sort \n");
    printf("\t4) Sair \n");
    printf("\t- Opcao: ");
    scanf("%d", &option);
    getchar();

    switch (option) {
      case 1:
        system("clear || cls");
        printf("\n\n-- INSERTION SHORT --\n\n");
        printf("- Vetor antes do Insertion Short: ");
        for (i = 0; i < sizeVetor; i++){
          printf("%d ", pVetor[i]);
        }
        orderVetor(pVetor, sizeVetor);
        insertionSort(pVetor, sizeVetor);
        printf("\n- Vetor depois do Insertion Short: ");
        for (i = 0; i < sizeVetor; i++){
          printf("%d ", pVetor[i]);
        }
        orderVetor(pVetor, sizeVetor);
        break;
      case 2:
        system("clear || cls");
        // SELECTION SORT
        break;
      case 3:
        system("clear || cls");
        // QUICK SORT
        break;
      case 4:
        system("clear || cls");
        // MERGE SORT
        break;
      case 5:
        system("clear || cls");
        // SAIR
        break;
      default:
          system("clear || cls");
          printf("\nOpcao invalida, digite novamente!\n");
          break;
        }
    } while ((option >= 1) || (option <= 5));

}

void insertionSort(int *pVetor, int sizeVetor){
  int auxNumber, auxCounter, counter;

  for (counter = 1; counter < sizeVetor; counter++){
    auxCounter = counter - 1;
    auxNumber = pVetor[counter];
    while((auxCounter >= 0) && (auxNumber < pVetor[auxCounter])){
      pVetor[auxCounter + 1] = pVetor[auxCounter];
      auxCounter--;
    }
    pVetor[auxCounter + 1] = auxNumber;
  }
}

void orderVetor(int *pVetor, int sizeVetor){
  int counter;

  for (counter = 0; counter < (sizeVetor - 1); counter++){
    if (pVetor[counter] > pVetor[counter + 1]){
      printf("\nNão esta ordenado!\n");
      return;
    }
  }
  printf("\nEsta ordenado!");
}