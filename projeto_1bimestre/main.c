#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include<stdbool.h>

void mostraDecoracao(){
    printf("|                                                               |\n");
    printf("|   $$\\      $$\\                           $$\\ $$\\              |\n");
    printf("|   $$ | $\\  $$ |                          $$ |$$ |             |\n");
    printf("|   $$ |$$$\\ $$ | $$$$$$\\   $$$$$$\\   $$$$$$$ |$$ | $$$$$$\\     |\n");
    printf("|   $$ $$ $$\\$$ |$$  __$$\\ $$  __$$\\ $$  __$$ |$$ |$$  __$$\\    |\n");
    printf("|   $$$$  _$$$$ |$$ /  $$ |$$ |  \\__|$$ /  $$ |$$ |$$$$$$$$ |   |\n");
    printf("|   $$$  / \\$$$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |$$   ____|   |\n");
    printf("|   $$  /   \\$$ |\\$$$$$$  |$$ |      \\$$$$$$$ |$$ |\\$$$$$$$\\    |\n");
    printf("|   \\__/     \\__| \\______/ \\__|       \\_______|\\__| \\_______|   |\n");
    printf("|                                                               |\n");

   printf("\nSeja muito Bem-vindo ao jogo!!!\n");
}

// Verifica se o a palavra informada pelo jogador é igual a palavra sorteada
int verificaPalavra(char palpite[], char palavraSecreta[]) {
    int i, x, acertouTudo = 1;
    printf("\n");
    for (i = 0; i < palpite[i]; i++) {
      printf("%c ", palpite[i]);
    }
    printf("\n");
    for (i = 0; palavraSecreta[i] != '\0'; i++) {
    int encontrouLetra = 0;
        if (palpite[i] == palavraSecreta[i]) {
            printf("^ "); // Letra correta e na posição correta
        } else {
            for (x = 0; palavraSecreta[x] != '\0'; x++) {
                if (palpite[i] == palavraSecreta[x]) {
                    encontrouLetra = 1;
                    break;
                }
            }
            if (encontrouLetra) {
                acertouTudo = 0; 
                printf("! "); // Letra certa mas na posição errada
            } else {
                acertouTudo = 0; 
                printf("x "); // Letra errada
            }
        }
    }
    printf("\n");
    return acertouTudo; 
}



/*
^ faz parte da polavra e está na posição correta
X não faz parte da palavra
! faz parte da palavra mas não está na posição correta
*/

int main() {
    // Informa para o programa a linguagem padrão como a Língua Portuguesa
    setlocale(LC_ALL, "Portuguese");

    // Declaração de variáveis
    FILE *arquivoPalavras;
    FILE *scores;
    char palpite[100];
    char palavraSorteada[1000][1000];
    char linha[1000];
    char vencedores[100];
    int numPalavras = 0;
    int tentativas = 0;
    bool acertou = false;
    int sorteado;
    clock_t inicio, fim;

    mostraDecoracao();

    // Abre os arquivos .txt
    scores = fopen("scores.txt", "a");
    arquivoPalavras = fopen("sem_acentos.txt", "r");

    // Verificação se os arquivos foram abertos da maneira correta
    if (arquivoPalavras == NULL || scores == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê as palavras do arquivo e armazena no vetor, essa função pega no máximo 1000         palavras que contenham 5 letras
    while (fgets(linha, sizeof(linha), arquivoPalavras) && numPalavras < 1000) {
      linha[strcspn(linha, "\n")] = 0;
      if (strlen(linha) == 5) { // verifica se a palavra tem 5 letras
          strcpy(palavraSorteada[numPalavras], linha);
          numPalavras++;
      }
    }

    // Realiza o sorteio da palavra para o jogo
    srand(time(NULL));
    sorteado = rand() % numPalavras;

    // Imprimir a palavra sorteada para testes
    printf("A palavra sorteada é: %s\n", palavraSorteada[sorteado]);
    
    inicio = clock();
    while(tentativas < 6 && !acertou){
        printf("\nDigite seu palpite da palavra sorteada: ");
        scanf("%s", palpite);
        
      
      if (strlen(palpite) != 5) 
      {
          printf("Você deve digitar uma palavra com 5 letras por favor!\n");
      }
      else if (verificaPalavra(palpite, palavraSorteada[sorteado]))
      {
          printf("\nParabéns, você acertou!\n");
          fim = clock();
          double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
          printf("Insira seu nome para adicionar você ao ranking de vencedores: ");
          scanf("%s", vencedores);
          fprintf(scores, "Jogador: %s/ Tentativas: %d/ Palavra: %s /Tempo até acertar em segundos: %lf\n", vencedores, tentativas+1, palavraSorteada[sorteado], tempo);
          printf("\nMuito obrigado por jogar, %s!<3\n", vencedores);
          acertou = true;
      } 
      else 
      {
          tentativas++;
      }

    }

    if (tentativas == 6) 
    {
        printf("\nVocê perdeu!!! A palavra sorteada nessa rodada foi: %s\n",     
        palavraSorteada[sorteado]);
    }


    // Fecha os arquivos .txt
    fclose(arquivoPalavras);
    fclose(scores);
    return 0;
}

