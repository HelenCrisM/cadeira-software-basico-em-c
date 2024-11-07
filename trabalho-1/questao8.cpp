// Crie uma struct Aluno(char nome[100], int matricula, double nota). Leia um arquivo onde possui dados
// de dez alunos, um por linha. As informações de nome, matricula e nota estão separados por ;
// Leia esse arquivo (utilize as funções strtok, atoi e atof para ler e separar as informações) e armazene as
// informações em um vetor de Alunos. Após isso, imprima utilizando printf as informações de cada aluno.


// Tutorial que utilizei como base para criar código: https://www.youtube.com/watch?v=Qm1J_WRlx-I
// Tutorial que utilizei como base para criar código: https://embarcados.com.br/cadeia-de-caracteres-funcoes-de-conversao/
// Tutorial que utilizei como base para criar código: https://petbcc.ufscar.br/stdlibfuncoes/
// Tutorial que utilizei como base para criar código: https://www.inf.ufpr.br/cursos/ci067/Docs/NotasAula/notas-21_Mais_sobre_tipos_convers.html
// Tutorial que utilizei como base para criar código: https://www.ic.unicamp.br/~cmartins/Cursos/mc102/slides/mc102z-a9-4pp.pdf


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
  char nome[200];
  int matricula;
  double nota;
};

int main() {
    FILE *arquivo_aluno;
    struct Aluno alunos[10];  
    char linha_arquivo[200];          
    int i = 0;

    arquivo_aluno = fopen("alunos.txt", "r");

    while (fgets(linha_arquivo, sizeof(linha_arquivo), arquivo_aluno) != NULL && i < 10) {
        linha_arquivo[strcspn(linha_arquivo, "\n")] = '\0';

        char *palavra = strtok(linha_arquivo, ";");
        if (palavra != NULL) {
            strcpy(alunos[i].nome, palavra); 
        }

        palavra = strtok(NULL, ";");
        if (palavra != NULL) {
            alunos[i].matricula = atoi(palavra); 
        }

        palavra = strtok(NULL, ";");
        if (palavra != NULL) {
            alunos[i].nota = atof(palavra);  
        }

        i++;  
    }

    fclose(arquivo_aluno);

    for (int j = 0; j < i; j++) {
        printf("Nome: %s\n", alunos[j].nome);
        printf("Matrícula: %d\n", alunos[j].matricula);
        printf("Nota: %.2f\n\n", alunos[j].nota);
    }

    return 0;
}
