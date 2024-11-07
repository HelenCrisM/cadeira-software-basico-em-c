// Escreva um programa que dado um arquivo de texto e uma palavra, busque a quantidade de vezes que a
// palavra aparece no arquivo desconsiderando diferenças entre letras minúsculas e maiúsculas (use tolower ou toupper).


// Tutorial que utilizei como base para criar código: https://linguagemc.com.br/arquivos-em-c-categoria-usando-arquivos/
// Tutorial que utilizei como base para criar código: https://www.freecodecamp.org/portuguese/news/manipulacao-de-arquivos-em-c-como-abrir-e-fechar-arquivos-e-escrever-algo-neles/
// Tutorial que utilizei como base para criar código: https://www.geeksforgeeks.org/c-file-io/

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
    char palavra[50], linha[500];
    char palavra_minuscula[50];
    int cont = 0;


    printf("Digite a palavra para buscar: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';  

    minusculo(palavra, palavra_minuscula);

    FILE *arquivo = fopen("file_exemplo.txt", "r");
    if (arquivo == NULL) {
        printf("O arquivo nao existe!\n");
        return 1; 
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_palavra_minuscula[500];
        minusculo(linha, linha_palavra_minuscula); 


        char *palavra_frase = strtok(linha_palavra_minuscula, " ");
        while (palavra_frase != NULL) {
            if (strcmp(palavra_frase, palavra_minuscula) == 0) {
                cont++; 
            }
            palavra_frase = strtok(NULL, " "); 
        }
    }

    fclose(arquivo);

    printf("A palavra '%s' aparece %d vezes\n", palavra, cont);

    return 0;
}
