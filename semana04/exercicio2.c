#include <stdio.h>


float converteParaCelsius(float temperaturaF){
  float celsius;
  celsius = (temperaturaF - 32) * 5/9;
  printf("A temperatura em Celsius é: %.2f", celsius);
}

float converteParaFaherenheit(float temperaturaC){
  float faherenheit;

  faherenheit = (temperaturaC * 9/5) + 32;
  printf("A temperatura em Fahrenheit é: %.2f\n", faherenheit);
}

int main(void) {

  float temperaturaF, temperaturaC;
  int opcao;

  printf("(1) Converter de Celsius para Fahrenheit\n");
  printf("(2) Converter de Fahrenheit para Celsius\n");
  printf("Digite a opção desejada: ");
  scanf("%d", &opcao);

  if(opcao == 2){
    printf("Qual a temperatura em Fahrenheit: \n");
    scanf("%f", &temperaturaF);
    converteParaCelsius(temperaturaF);
  }else if(opcao == 1){
    printf("Qual a temperatura em Celsius: \n");
    scanf("%f", &temperaturaC);
    converteParaFaherenheit(temperaturaC);
  }else{
    printf("Opção inválida!!!");
  }
  
}