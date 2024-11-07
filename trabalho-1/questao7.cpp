// Escreva um programa em C que, dado dois arquivos de texto contendo o mesmo número de linhas, onde
// cada linha possui um número inteiro, realize as seguintes tarefas:
// (a) Leia os valores de ambos os arquivos e armazene-os em dois vetores distintos.
// (b) Gere um terceiro vetor que armazene a soma dos valores correspondentes de cada posição dos dois
// primeiros vetores.
// (c) Armazene o conte ́udo desse terceiro vetor em um novo arquivo de texto, onde cada linha cont ́em a
// soma dos valores dos dois vetores.
// OBS: A primeira linha dos arquivos pode ser utilizada para indicar o número de linhas.

// Tutorial que utilizei como base para criar código: https://linguagemc.com.br/arquivos-em-c-categoria-usando-arquivos/
// Tutorial que utilizei como base para criar código: https://www.freecodecamp.org/portuguese/news/manipulacao-de-arquivos-em-c-como-abrir-e-fechar-arquivos-e-escrever-algo-neles/
// Tutorial que utilizei como base para criar código: https://www.geeksforgeeks.org/c-file-io/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *primeiro_arquivo, *segundo_arquivo, *resultado_soma_arquivo;
    int n, i;

    primeiro_arquivo = fopen("exemplo_file1.txt", "r");
    segundo_arquivo = fopen("exemplo_file2.txt", "r");

    if (primeiro_arquivo == NULL || segundo_arquivo == NULL) {
        printf("Os arquivos nao existem!\n");
        return 1;
    }

    fscanf(primeiro_arquivo, "%d", &n);
    fscanf(segundo_arquivo, "%d", &n); 

    int primeiro_vetor[n], segundo_vetor[n], vetor_resultado[n];

    for (i = 0; i < n; i++) {
      fscanf(primeiro_arquivo, "%d", &primeiro_vetor[i]);
      fscanf(segundo_arquivo, "%d", &segundo_vetor[i]);
    }

    fclose(primeiro_arquivo);
    fclose(segundo_arquivo);

    for (i = 0; i < n; i++) {
      vetor_resultado[i] = primeiro_vetor[i] + segundo_vetor[i];
    }

    resultado_soma_arquivo = fopen("resultado.txt", "w");
    if (resultado_soma_arquivo == NULL) {
        printf("Erro ao criar o arquivo 'resultado.txt'\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(resultado_soma_arquivo, "%d\n", vetor_resultado[i]);
    }

    fclose(resultado_soma_arquivo);

    printf("Soma dos vetores foi salva em 'resultado.txt'\n");

    return 0;
}
