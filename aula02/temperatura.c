#include <stdio.h>

int main(){
    double celsius, fahrenheit;

  printf("Digite a temperatura no ambiente em graus Celsius: \n");
  scanf("%lf", &celsius);

  fahrenheit = (celsius*9/5)+32;

  printf("A temperatura do ambiente é %.2lf fahrenheit", fahrenheit);
}