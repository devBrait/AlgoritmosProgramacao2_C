#include <stdio.h>

int buscaBinariaRecursiva(int array[], int inicio, int fim, int palpite) {
    if (inicio > fim) {
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;

    if (array[meio] == palpite) {
        return meio;
    } else if (array[meio] > palpite) {
        return buscaBinariaRecursiva(array, inicio, meio - 1, palpite); 
    } else {
        return buscaBinariaRecursiva(array, meio + 1, fim, palpite);
    }
}

int main() {
    int array[] = {2, 5, 8, 12, 16, 25};
    int tamanho = sizeof(array) / sizeof(array[0]);
    int palpite;
  
      printf("{ ");
    for(int i = 0; i < tamanho; i++){
      printf("%d ", array[i]);
    }
   printf("}");
  
    printf("\nEntre com o valor que deseja buscar: ");
    scanf("%d", &palpite);

    int indice = buscaBinariaRecursiva(array, 0, tamanho - 1, palpite);

    if (indice != -1) {
        printf("Elemento encontrado na posição %d.\n", indice);
    } else {
        printf("Informe um elemento que está dentro do array.\n");
    }

    return 0;
}
