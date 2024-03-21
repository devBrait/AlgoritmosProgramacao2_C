#include <stdio.h>

int verificaInterseccao(int v1[], int v2[], int tam1, int tam2) {

  int cont = 0;
  int valoresComuns[5];

  for (int i = 0; i < tam1; i++) {
    for (int x = 0; x < tam2; x++) {
      if (v1[i] == v2[x]) {
        valoresComuns[cont++] = v1[i];
      }
    }
  }

  if (cont == 0) {
    printf("{}");
  } else {
    for (int z = 0; z < cont; z++) {
      printf("%d ", valoresComuns[z]);
    }
  }

  return 0;
}

int main(void) {
  int tam1, tam2;

  printf("Digite o tamanho do vetor 1: ");
  scanf("%d", &tam1);
  printf("Digite o tamanho do vetor 2: ");
  scanf("%d", &tam2);

  int v1[tam1], v2[tam2];

  for (int i = 0; i < tam1; i++) {
    printf("Informe %d valor para o vetor 1: \n", i + 1);
    scanf("%d", &v1[i]);
  }

  for (int x = 0; x < tam2; x++) {
    printf("Informe %d valor para o vetor 2: \n", x + 1);
    scanf("%d", &v2[x]);
  }

  verificaInterseccao(v1, v2, tam1, tam2);
}