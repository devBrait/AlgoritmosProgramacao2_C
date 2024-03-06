#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int valor_sorteado, valor_tentativa;
  srand(time(NULL));

  valor_sorteado = rand() % 100 + 1;

  printf("Tente advinhar o valor sorteado de 1 a 10: ");
  scanf("%d", &valor_tentativa);

  if(valor_tentativa < 1 || valor_tentativa > 100){
    printf("Valor inválido");
  }else if(valor_tentativa > valor_sorteado){
    printf("Você chutou muito alto! O valor correto é %d",           valor_sorteado);
  }else if(valor_tentativa < valor_sorteado){
      printf("Você chutou muito baixo! O valor correto é %d",           valor_sorteado);
  }else{
    printf("Parabéns!!! Você acertou!");
  }
  return 0;
}