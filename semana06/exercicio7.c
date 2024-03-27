#include <stdio.h>

int multiplicacaoMatrizes(int n, int m, int p, int matrizA[n][m], int matrizB[m][p], int matrizC[n][p]){
  printf("\n");
  if(m != p){
    char textoErro = printf("\nImpossível realizar essa operação!");
    return textoErro;
  }

    
  for(int i = 0; i < n; i++){
    for(int x = 0; x < p; x++){
      for(int k = 0; k < m; k++){
        matrizC[i][x] = matrizA[i][k] * matrizB[k][x];
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int x = 0; x < m; x++){
      printf("A multiplicação dos valores é: %d\n", matrizC[i][x]);
    }
  }
}



int main() {
  int n, m, p;
  printf("Digite o tamanho da matriz A e B e C: ");
  scanf("%d %d %d", &n, &m, &p);

  int matrizA[n][m];
  int matrizB[m][p];
  int matrizC[n][p];


  for(int i = 0; i < n; i++){
    for(int x = 0; x < m; x++){
      printf("Digite os valores da matriz A: ");
      scanf("%d", &matrizA[i][x]);
    }
  }

  for(int i = 0; i < m; i++){
    for(int x = 0; x < p; x++){
      printf("Digite os valores da matriz B: ");
      scanf("%d", &matrizB[i][x]);
    }
  }

    multiplicacaoMatrizes(n, m, p, matrizA, matrizB,  matrizC);


  return 0;
}