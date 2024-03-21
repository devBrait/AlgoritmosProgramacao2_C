#include <stdio.h>

int uniao(int v1[], int v2[], int tam1, int tam2) {
    int uniao[20];
    int tamUniao = 0;
  
    for (int i = 0; i < tam1; i++) {
        uniao[tamUniao++] = v1[i];
    }
    for (int i = 0; i < tam2; i++) {
        uniao[tamUniao++] = v2[i];
    }
    for (int i = 0; i < tamUniao; i++) {
        for (int x = i + 1; x < tamUniao;) {
            if (uniao[x] == uniao[i]) {
                for (int k = x; k < tamUniao - 1; k++) {
                    uniao[k] = uniao[k + 1];
                }
                tamUniao--;
            } else {
                x++;
            }
        }
    }
    printf("Uniao dos elementos: ");
    for (int i = 0; i < tamUniao; i++) {
        printf("%d ", uniao[i]);
    }
    printf("\n");
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

  uniao(v1, v2, tam1, tam2);
}
