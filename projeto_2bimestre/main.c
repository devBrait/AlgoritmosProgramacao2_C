#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Alunos participantes:

- Eduardo Henrique de Souza Cruz 
- Guilherme Teodoro de Oliveira 
- Philipe Cortez Verissimo Cutis
- Vinícius Brait Lorimier

Turma: 02N11
*/

// Definimos o tamanho máximo de palavras dentro do dicionário e o tamanho máximo de cada palavra
#define MAX_PALAVRAS 1000
#define TAM_MAX 100

void exibeCabecalho(){
  printf("| /$$     /$$                    /$$       /$$$$$$$             /$$      \n");    
  printf("| $$$    /$$$                    |$$      | $$   $$            | $$      \n");
  printf("| $$$$  /$$$$ /$$$$$$   /$$$$$$$ |$$   /$$| $$  \\ $$   /$$$$$$  /$$$$$$   \n");
  printf("| $$ $$/$$ $$ |____ $$ /$$_____/ |$$  /$$/| $$$$$$$  /$$__  $$|_  $$_/   \n");  
  printf("| $$  $$$| $$ /$$$$$$$| $$       |$$$$$$/ | $$    $$| $$  \\ $$  | $$     \n");    
  printf("| $$\\  $  | $$ \\$$__ $$| $$       |$$_  $$ | $$  \\  $$| $$  | $$  | $$ /$$ \n");
  printf("| $$ \\/   | $$  $$$$$$$| $$$$$$$| |$$\\  $$ | $$$$$$$/|  $$$$$$/  | $$$$/  \n");
  printf("|__/     |__/ \\_______/ \\_______/ |__/  \\__/|_______/  \\______/    \\___/ \n");

  printf("\nSeja muito Bem-vindo ao leitor de dicionário - MackBot!!!\n\n");
}

// Deixo tudo minúsculo para resolver o problema de Case Sensitive
void deixaMinusculo(char *str) {
    for (int i = 0; str[i]; i++) 
    {
        str[i] = tolower(str[i]);
    }
}

// Função para remover caracteres indesejados como . / , ; : ! ?
void removeCaracteres(char *str) {
    char temp[TAM_MAX];
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (!ispunct((unsigned char)str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

int buscaBinariaRecursiva(char dicionario[][TAM_MAX], int left, int right, const char *palavra) {
    if (left > right) 
    {
      return -1; // Caso a palavra não seja encontrada
    }
    int meio = (left + right) / 2;
    int result = strcmp(dicionario[meio], palavra);
    if (result == 0) 
    {
      return meio; // Caso a palavra seja encontrada retornamos o índice
    } 
    else if (result < 0) 
    {
      return buscaBinariaRecursiva(dicionario, meio + 1, right, palavra);
    } 
    else 
    {
      return buscaBinariaRecursiva(dicionario, left, meio - 1, palavra);
    }
}

void incluiPalavra(char dicionario[][TAM_MAX], int *count, int *tamanho, const char *palavra) {
    int pos = *tamanho;
    while (pos > 0 && strcmp(dicionario[pos - 1], palavra) > 0) 
    {
        strcpy(dicionario[pos], dicionario[pos - 1]);
        count[pos] = count[pos - 1];
        pos--;
    }
    strcpy(dicionario[pos], palavra);
    count[pos] = 1;
    (*tamanho)++;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    FILE *file = fopen("dicionario.txt", "r");
    // Caso ocorra alguma erro durante a abertura do arquivo
    if (!file) 
    {
        return printf("Erro ao abrir o arquivo, verifique se o arquivo existe ou se o nome dele está correto.");
    }

    exibeCabecalho();

    // Declaração de variáveis 
    char dicionario[MAX_PALAVRAS][TAM_MAX];
    int count[MAX_PALAVRAS] = {0};
    int contaPalavras = 0;
    char linhas[MAX_PALAVRAS];

    while (fgets(linhas, sizeof(linhas), file)) 
    {
        char *token = strtok(linhas, " \t\n\r"); 
        // Fazemos isso para conseguir sempre ir até o final da linha
        while (token) 
        {
            char palavra[TAM_MAX];
            strncpy(palavra, token, TAM_MAX);
            palavra[TAM_MAX - 1] = '\0'; // Percorre a lista até o fim
            removeCaracteres(palavra);
            deixaMinusculo(palavra);

            int index = buscaBinariaRecursiva(dicionario, 0, contaPalavras - 1, palavra);

            if (index == -1) 
            {
                if (contaPalavras < MAX_PALAVRAS) 
                {
                    incluiPalavra(dicionario, count, &contaPalavras, palavra); 
                }
            } 
            else 
            {
                count[index]++;
            }
            token = strtok(NULL, " \t\n\r");
        }
    }

    fclose(file);
    // Loop para exibir todas as palavras que estão no dicionário
    if(contaPalavras == 0)
    {
      printf("Nenhuma palavra foi encontrada no dicionário.\n");
    }
    else // Printa todas as palavras que estão no dicionário
    {
      for (int i = 0; i < contaPalavras; i++) {
          printf("%s, %d\n", dicionario[i], count[i]);
      }
      printf("\nTotal de palavras diferentes no dicionario = %d\n", contaPalavras);
    }
    printf("Muito obrigado por utilizar do nosso leitor de dicionário, volte sempre!<3");

    return 0;
}
