#include <stdio.h>

int main(){
    double altura, valorIMC, peso;

    printf("Informe o peso em kg: \n");
    scanf("%lf", &peso);
    printf("Informe a altura em m: \n");
    scanf("%lf", &altura);

    valorIMC = peso/(altura*altura);

    printf("\nO IMC de uma pessoa com pes %.2lf kg e altura %.2lf m é igual a %.2lf.\n", peso, altura, valorIMC);