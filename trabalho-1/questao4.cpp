// Escreva um programa que dado trˆes strings, imprima as trˆes strings na ordem lexicogr ́afica (alfab ́etica)
// usando a fun ̧c ̃ao strcmp.


// Tutorial que utilizei como base para criar código: https://www.vivaolinux.com.br/topico/C-C++/como-visualizar-por-ordem-alfabetica

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
char nomes[10][15], aux[15];
int qtde, i, j;

qtde = 3;
	
printf("Digite 3 nomes para ordenar: \n");

for(i=0; i<qtde; i++)
	scanf("%s", nomes[i]);

for(i=0; i<qtde; i++) {
    for(j=0; j<qtde; j++) {
      if(strcmp(nomes[i], nomes[j]) < 0) {
      strcpy(aux, nomes[i]);
      strcpy(nomes[i], nomes[j]);
      strcpy(nomes[j], aux);
      }
    }
} 
  
printf("\n-nomes ordenados-\n");
for(i=0; i<qtde; i++)
	printf("%s\n", nomes[i]);

return 0;
}