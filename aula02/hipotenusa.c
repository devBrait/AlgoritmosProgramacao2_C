#include <stdio.h>
#include <math.h>

int main(){
  double catA, catB, hipotenusa;

  printf("Informe os valores dos catetos: \n");
  scanf("%lf %lf", &catA, &catB);

  hipotenusa = sqrt(catA*catA + catB*catB);

  printf("A hipotenusa é igual a %.2lf", hipotenusa);
}