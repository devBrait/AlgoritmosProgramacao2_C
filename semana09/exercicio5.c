#include <stdio.h>

int numReverso(int num, int reversedNum){
    if (num == 0) {
        return reversedNum;
    } else {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        return numReverso(num / 10, reversedNum);
    }

  return reversedNum;
}

int main() {
    int num;

    printf("Entre com um número inteiro: ");
    scanf("%d", &num);
    
    printf("Número original: %d\n", num);
    printf("Número reverso : %d\n", numReverso(num, 0));

    return 0;
}
