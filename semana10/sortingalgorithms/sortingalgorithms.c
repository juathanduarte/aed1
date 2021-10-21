#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
  }

  do {
    printf("\Lista de Exercicios 5 - Juathan | Algoritmos de ordenacao.\n\n");
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
        // INSERTION SORT
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