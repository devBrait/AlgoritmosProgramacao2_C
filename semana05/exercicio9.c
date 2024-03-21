#include <stdio.h>

int diferenca(int v1[], int v2[], int tam1, int tam2){

  for(int i = 0; i < tam1; i++){
    int igual = 0;
    for(int x = 0; x < tam2; x++){
      if(v1[i] == v2[x]){
          igual = 1;
      }
    }
    if(!igual){
      printf("%d ", v1[i]);
    }
  }  

  return 0;
}

int main(void) {

  int tam1, tam2;

  printf("Digite o tamanho do vetor 1: ");
  scanf("%d", &tam1);
  printf("Digite o tamanho do vetor 2: ");
  scanf("%d", &tam2);

  int v1[tam1], v2[tam2];

  for(int i = 0; i < tam1; i++){
    printf("Informe %d valor para o vetor 1: \n", i+1);
    scanf("%d", &v1[i]);
  }

  for(int x = 0; x < tam2; x++){
    printf("Informe %d valor para o vetor 2: \n", x+1);
    scanf("%d", &v2[x]);
  }

  diferenca(v1, v2, tam1, tam2);

  
  return 0;
}