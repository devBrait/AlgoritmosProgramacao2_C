#include <stdio.h>

int retornaSoma(float a, float b, float c){
  float soma;
  soma = a + b + c;
  printf("A soma dos valores é %.2f", soma);
  return 0; 
}

int main(void) {
  float valorA, valorB, valorC;

  printf("Informe os valores para serem somados: \n");
  scanf("%f %f %f", &valorA, &valorB, &valorC);

  retornaSoma(valorA, valorB, valorC);
}

