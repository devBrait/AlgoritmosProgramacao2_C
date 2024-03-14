#include <stdio.h>
#include <math.h>


float calculaSomatorio(int valor){
  int k = 1, sinal = 1;
  float soma = 0;
  
  for(int i=1; i <= valor; i++){
    soma += sinal * (k / pow(k, 2));
    sinal = sinal * (-1);
    k++;
  }
  printf("%f", soma);
}

int main(void) {

  int valor;
  printf("Digite o valor de n: ");
  scanf("%d", &valor);
  calculaSomatorio(valor);
  
  return 0;
}