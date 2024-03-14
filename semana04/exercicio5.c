#include <stdio.h>

int ehPrimo(int valor){
  for(int i = 2; i <= valor/2; i++){
    if(valor % i == 0){
      return 0;
    }
  }
    return 1;
}

int quantidadePrimos(int n1, int n2){
    for(int i = n1; i <= n2; i++){
      if(ehPrimo(i) == 1){
        printf("%d ", i);
      }
    }
}

int main(void) {

  int n1, n2;

  printf("Informe os valores solicitados: \n");
  scanf("%d %d", &n1, &n2);
  quantidadePrimos(n1, n2);
  return 0;
  
}