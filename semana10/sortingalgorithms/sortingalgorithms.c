#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void orderVetor(int *pVetor, int sizeVetor);
int *copyVetor(int *pVetor, int sizeVetor);
void printVetor(int *pVetor, int sizeVetor);
void insertionSort(int *pVetor, int sizeVetor);
void selectionSort(int *pVetor, int sizeVetor);
void quickSort(int *pVetor, int left, int right);
void mergeSort(int *pVetor, int left, int right);
void merge(int *pVetor, int left, int middle, int right);

int main (){
  int sizeVetor = 0, option, i;
  int *pVetor = NULL;
  int *pVetorAux = NULL;
  struct timeval begin, end;

  printf ("Digite o size do vetor: ");
  scanf("%d", &sizeVetor);
  getchar();

  pVetor = malloc(sizeVetor * sizeof(int));

  srand(time(NULL));

  for (i = 0; i < sizeVetor; i++){
    pVetor[i] = rand() % 100000000;
  }

  do {
    printf("\n\nLista de Exercicios 5 - Juathan | Algoritmos de ordenacao.\n\n");
    printf("\t1) Insertion Sort\n");
    printf("\t2) Selection Sort\n");
    printf("\t3) Quick Sort\n");
    printf("\t4) Merge Sort\n");
    printf("\t5) Sair\n");
    printf("\t- Opcao: ");
    scanf("%d", &option);
    getchar();

    switch (option) {
      case 1:
        system("clear || cls");
        printf("\n\n-- INSERTION SHORT --\n\n");
        pVetorAux = copyVetor(pVetor, sizeVetor);
        printf("- Vetor antes do Insertion Short: ");
        printVetor(pVetorAux, sizeVetor);
        orderVetor(pVetorAux, sizeVetor);

        gettimeofday(&begin, 0);
        insertionSort(pVetorAux, sizeVetor);
        gettimeofday(&end, 0);

        printf("\n- Vetor depois do Insertion Short: ");
        printVetor(pVetorAux, sizeVetor);
        orderVetor(pVetorAux, sizeVetor);

        printf("\nTempo para ordenar com o Insertion Short: %.3f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec)* 1e-6));
        free(pVetorAux);
        break;
      case 2:
        system("clear || cls");
        printf("\n\n-- SELECTION SORT --\n\n");
        pVetorAux = copyVetor(pVetor, sizeVetor);
        printf("- Vetor antes do Selection Sort: ");
        printVetor(pVetorAux, sizeVetor);
        orderVetor(pVetorAux, sizeVetor);

        gettimeofday(&begin, 0);
        selectionSort(pVetorAux, sizeVetor);
        gettimeofday(&end, 0);

        printf("\n- Vetor depois do Selection Sort: ");
        printVetor(pVetorAux, sizeVetor);
        orderVetor(pVetorAux, sizeVetor);

        printf("\nTempo para ordenar com o Selection Sort: %.3f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec)* 1e-6));
        free(pVetorAux);
        break;
      case 3:
        system("clear || cls");
        printf("\n\n-- QUICK SORT --\n\n");
        pVetorAux = copyVetor(pVetor, sizeVetor);
        printf("- Vetor antes do Quick Sort: ");
        printVetor(pVetorAux, sizeVetor);
        orderVetor(pVetorAux, sizeVetor);

        gettimeofday(&begin, 0);
        quickSort(pVetorAux, 0, sizeVetor - 1);
        gettimeofday(&end, 0);

        printf("\n- Vetor depois do Quick Sort: ");
        printVetor(pVetorAux, sizeVetor);
        orderVetor(pVetorAux, sizeVetor);

        printf("\nTempo para ordenar com o Quick Sort: %.3f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec)* 1e-6));
        free(pVetorAux);
        break;
      case 4:
        system("clear || cls");
        printf("\n\n-- MERGE SORT --\n\n");
        pVetorAux = copyVetor(pVetor, sizeVetor);
        printf("- Vetor antes do Merge Sort: ");
        printVetor(pVetorAux, sizeVetor);
        orderVetor(pVetorAux, sizeVetor);

        gettimeofday(&begin, 0);
        mergeSort(pVetorAux, 0, sizeVetor - 1);
        gettimeofday(&end, 0);

        printf("\n- Vetor depois do Merge Sort: ");
        printVetor(pVetorAux, sizeVetor);
        orderVetor(pVetorAux, sizeVetor);

        printf("\nTempo para ordenar com o Merge Sort: %.3f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec)* 1e-6));
        free(pVetorAux);
        break;
      case 5:
        system("clear || cls");
        free(pVetor);
        exit(1);
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

void selectionSort(int *pVetor, int sizeVetor){
  int lowerValue, aux, counter, secondCounter, lowerValue_id;

  for (counter = 0; counter < (sizeVetor - 1); counter++){
    lowerValue = pVetor[counter];
    for(secondCounter = (counter + 1); secondCounter < sizeVetor; secondCounter++){
      if(pVetor[secondCounter] < lowerValue){
        lowerValue = pVetor[secondCounter];
        lowerValue_id = secondCounter;
      }
    }
    aux = pVetor[counter];
    pVetor[counter] = pVetor[lowerValue_id];
    pVetor[lowerValue_id] = aux;
    lowerValue_id = counter + 1;
  }
}

void quickSort(int *pVetor, int left, int right){
  int mid, aux, auxLeft, auxRight;

  auxLeft = left;
  auxRight = right;
  mid = pVetor[(left + right) / 2];

  do {
    while(pVetor[auxLeft] < mid){
      auxLeft++;
    }
    while(pVetor[auxRight] > mid){
      auxRight--;
    }
    if (auxLeft <= auxRight){
      aux = pVetor[auxLeft];
      pVetor[auxLeft] = pVetor[auxRight];
      pVetor[auxRight] = aux;
      auxLeft++;
      auxRight--;
    }
  } while (auxLeft <= auxRight);
  if (left < auxRight){
    quickSort(pVetor, left, auxRight);
  }
  if (auxLeft < right){
    quickSort(pVetor, auxLeft, right);
  }
}

void mergeSort(int *pVetor, int left, int right){
  int middle;

  if (left < right){
    middle = (left + right) / 2;
    mergeSort(pVetor, left, middle);
    mergeSort(pVetor, middle + 1, right);
    merge(pVetor, left, middle, right);
  }
}

void merge(int *pVetor, int left, int middle, int right){
  int *aux, auxLeft, auxRight, size, firstCount, secondCount, thirdCount;
	int endOne = 0, endTwo = 0;

	size = right - left + 1;
	auxLeft = left;
	auxRight = middle + 1;
	aux = (int *)malloc(size * sizeof(int));

	if (aux != NULL){
		for (firstCount = 0; firstCount < size; firstCount++){
			if (!endOne && !endTwo){
				if (pVetor[auxLeft] < pVetor[auxRight]){
					aux[firstCount] = pVetor[auxLeft++];
        } else {
					aux[firstCount] = pVetor[auxRight++];
        }
				if (auxLeft > middle){
					endOne = 1;
        }
				if (auxRight > right){
					endTwo = 1;
        }
			} else {
				if (!endOne){
					aux[firstCount] = pVetor[auxLeft++];
        } else {
					aux[firstCount] = pVetor[auxRight++];
        }
			}
		}
		for (secondCount = 0, thirdCount = left; secondCount < size; secondCount++, thirdCount++){
			pVetor[thirdCount] = aux[secondCount];
    }
	}
	free(aux);
}

void orderVetor(int *pVetor, int sizeVetor){
  int counter;

  for (counter = 0; counter < (sizeVetor - 1); counter++){
    if (pVetor[counter] > pVetor[counter + 1]){
      printf("\nN??o esta ordenado!\n");
      return;
    }
  }
  printf("\nEsta ordenado!");
}

int *copyVetor(int *pVetor, int sizeVetor){
  int counter, *pVetorAux = NULL;
  pVetorAux = malloc(sizeof(int) * sizeVetor);

  for(counter = 0; counter < sizeVetor; counter++) {
      pVetorAux[counter] = pVetor[counter];
  }

  return pVetorAux;
}

void printVetor(int *pVetor, int sizeVetor){
  for (int counter = 0; counter < sizeVetor; counter++){
    printf("%d ", pVetor[counter]);
  }
}