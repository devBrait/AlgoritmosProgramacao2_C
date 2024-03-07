#include <stdio.h>
#include <math.h>

int main(){
  int raio;
  double areaCirculo;

  printf("Informe o valor do raio: \n");
  scanf("%d", &raio);

  areaCirculo = M_PI*(raio*raio);
  printf("A área do círculo é igual a %.2lf", areaCirculo);

  return 0;
}
