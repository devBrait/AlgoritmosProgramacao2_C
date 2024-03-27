#include <stdio.h>

int somaMatrizes(int n, int m, int matrizA[n][m], int matrizB[n][m], int matrizC[n][m]){

  printf("\n");
  for(int i = 0; i < n; i++){
    for(int x = 0; x < m; x++){
      matrizC[i][x] = matrizA[i][x] + matrizB[i][x];
    }
  }

  for(int i = 0; i < n; i++){
    for(int x = 0; x < m; x++){
      printf("A soma dos valores é: %d\n", matrizC[i][x]);
    }
  }
}



int main() {
  int n, m;
  printf("Digite o tamanho da matriz A e B: ");
  scanf("%d %d", &n, &m);

  int matrizA[n][m];
  int matrizB[n][m];
  int matrizC[n][m];


  for(int i = 0; i < n; i++){
    for(int x = 0; x < m; x++){
      printf("Digite os valores da matriz A: ");
      scanf("%d", &matrizA[i][x]);
    }
  }

  for(int i = 0; i < n; i++){
    for(int x = 0; x < m; x++){
      printf("Digite os valores da matriz B: ");
      scanf("%d", &matrizB[i][x]);
    }
  }

  somaMatrizes(n, m, matrizA, matrizB,  matrizC);
  
  
  return 0;
}