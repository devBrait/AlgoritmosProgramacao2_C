#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int valor_sorteado, valor_tentativa;
  srand(time(NULL));

  valor_sorteado = rand() % 100 + 1;


  for(int i = 0; i < 5; i++){
    printf("\nTente advinhar o valor sorteado de 1 a 100: ");
    scanf("%d", &valor_tentativa);
    if(valor_sorteado > valor_tentativa){
      printf("O valor sorteado é maior que o valor tentado!\n");
    }else if (valor_sorteado < valor_tentativa){
      printf("O valor sorteado é menor que o valor tentado!\n");
    }
  }
  printf("\nSuas tentativas acabaram!!! O valor sorteado era %d!", valor_sorteado);
  return 0;
}
