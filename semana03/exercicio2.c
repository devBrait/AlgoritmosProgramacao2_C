#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int valor_sorteado, valor_tentativa, numero_tentativas = 0;
  srand(time(NULL));

  valor_sorteado = rand() % 100 + 1;

    printf("Tente advinhar o valor sorteado de 1 a 100: ");
    scanf("%d", &valor_tentativa);

    if(valor_tentativa < 1 || valor_tentativa > 100){
        printf("Valor inválido. Tente novamente.\n");
    }else{
        while(valor_sorteado != valor_tentativa){
            printf("Tente novamente: ");
            scanf("%d", &valor_tentativa);
            numero_tentativas++;
            if(valor_tentativa > valor_sorteado)
            {
            printf("O valor sorteado é menor que %d\n", valor_tentativa);
            }
            else if(valor_tentativa < valor_sorteado)
            {
            printf("O valor sorteado é maior que %d\n", valor_tentativa);
            }
        }
    }

    printf("Você acertou!\n");
    printf("Número de tentativas %d", numero_tentativas+1);
    return 0;
}