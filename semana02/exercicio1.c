#include <stdio.h>

int main(){
    int a, b, soma, subtracao, mult, divi;

    printf("Informe os dois valores: \n");
    scanf("%d %d", &a, &b);


    soma = a + b;
    subtracao = a - b;
    mult = a * b;
    divi = a / b;

    printf("A soma disso é: %d\n", soma);
    printf("A subtração disso é: %d\n", subtracao);
    printf("A multiplicação disso é: %d\n", mult);
    printf("A divisão disso é: %d\n", divi);

    return 0;
}