// Escreva um programa que dado uma frase (string com espaços) e uma palavra, busque a quantidade de
// vezes que a palavra aparece na frase desconsiderando diferenças entre letras minúsculas e maiúsculas (use tolower ou toupper).


// Tutorial que utilizei como base para criar código: https://petbcc.ufscar.br/ctypefuncoes/
// Tutorial que utilizei como base para criar código: https://wagnergaspar.com/como-converter-uma-string-em-maiusculo-ou-minusculo-em-qualquer-so-com-a-linguagem-c/
//  Tutorial que utilizei como base para criar código: https://www.guj.com.br/t/resolvido-como-comparar-strings-em-c/283211
//  Tutorial que utilizei como base para criar código: https://www.clubedohardware.com.br/forums/topic/1499727-recursividade-comparar-caracteres-de-duas-strings/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void minusculo(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0') {
        s2[i] = tolower(s1[i]); 
        i++;
    }
    s2[i] = '\0'; 
}

int main() {
    char frase[500], palavra[50];
    char frase_minuscula[500], palavra_minuscula[50];
    int cont = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';  // Remove o '\n' da entrada

    printf("Digite a palavra para buscar: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';  

    minusculo(frase, frase_minuscula);
    minusculo(palavra, palavra_minuscula);

    char *palavra_frase = strtok(frase_minuscula, " ");
    while (palavra_frase != NULL) {
        if (strcmp(palavra_frase, palavra_minuscula) == 0) {
            cont++; 
        }
        palavra_frase = strtok(NULL, " ");
    }

    printf("A palavra '%s' aparece %d vezes na frase.\n", palavra, cont);

    return 0;
}
