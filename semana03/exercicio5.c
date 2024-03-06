#include <stdio.h>

int main() {
    int valor, divisores = 0;

    printf("Digite um número para ver se ele é perfeito: ");
    scanf("%d", &valor);

    for (int i = 1; i <= valor / 2; i++) {
        if (valor % i == 0) {
            divisores += i;
        }
    }
    if (divisores == valor) {
        printf("%d é um número perfeito.\n", valor);
    } else {
        printf("%d não é um número perfeito.\n", valor);
    }

    return 0;
}