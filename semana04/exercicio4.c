#include <stdio.h>


int divisor(int n, int d){
    if(n % d == 0){
      return 1;
    }
    return 0;
}

int quantidadeDivisores(int m){
  int cont = 0;
  for(int i = 1; i <= m; i++){
    if(divisor(m, i) == 1){
      cont++;
    }
  }
  printf("A quantidade de divisores de %d é %d", m, cont);
  return 0;
}


int main(void) {
  int m;
  printf("Informe os valores solicitados: ");
  scanf("%d", &m);
  quantidadeDivisores(m);
}