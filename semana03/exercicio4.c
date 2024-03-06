#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int valor;

  printf("Informe um valor para verificar seus divisores: ");
  scanf("%d", &valor);

  for (int i = 1; i <= valor; i++){
    if (valor % i == 0){
      printf("%d é divisor de %d\n", i, valor);
    }
  }

  return  0;
}