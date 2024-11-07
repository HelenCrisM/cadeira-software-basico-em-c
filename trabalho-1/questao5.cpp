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
