#include <stdio.h>

int tabuada(int valor){
  for(int i=0; i<11; i++){
    printf("%d X %d = %d\n", valor, i, valor * i);
  }
}

int main(void) {
  int valor;

  printf("Informe o valor da tabuada: ");
  scanf("%d", &valor);  
  tabuada(valor);
}