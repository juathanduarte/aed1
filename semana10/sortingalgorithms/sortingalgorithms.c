#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
  int sizeVetor = 0, random, i;

  int *pVetor = NULL;

  printf ("Digite o tamanho do vetor: ");
  scanf("%d", &sizeVetor);
  getchar();

  pVetor = malloc(sizeVetor * sizeof(int));

  srand(time(NULL));

  for (i = 0; i < sizeVetor; i++){
    random = rand() % 100;
    pVetor[i] = random;

    printf("%d\n", pVetor[i]);
  }


}