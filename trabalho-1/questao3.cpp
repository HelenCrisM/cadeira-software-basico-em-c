// Implemente um programa que compute o tempo de execução de cada uma das funções abaixo:
// int func 1 ( int n ){
// i f ( n == 0 ) return 1 ;
// return func 1 ( n−1) + func 1 ( n−1);
// }
// int func 2 ( int n ){
// i f ( n == 0 ) return 1 ;
// return 2∗ func 1 ( n−1);
// }
// int func 3 ( int n ){
// i f ( n == 0 ) return 1 ;
// int v al o r = func 3 ( n / 2 ) ;
// i f ( n%2 == 0 ) return v al o r ∗ v al o r ;
// e l s e return 2 ∗ v al o r ∗ v al o r ;
// }
// Teste seu algoritmo utilizando valores de n menores ou iguais a 20.


// Tutorial que utilizei como base para criar código: https://wurthmann.blogspot.com/2015/04/medir-tempo-de-execucao-em-c.html#:~:text=Fun%C3%A7%C3%A3o%20clock()%20e%20a,o%20tempo%20final%20da%20execu%C3%A7%C3%A3o.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t


int func1(int n) {
  if (n == 0) return 1;
  return func1(n-1) + func1(n-1);
}

int func2(int n) {
  if (n == 0) return 1;
  return 2*func1(n-1);
}

int func3(int n) {
  if (n == 0) return 1;
  int valor = func3(n/2);
  if(n%2 == 0) return valor * valor;
  else return 2 * valor * valor;
}

int main(){
  clock_t tempo; 


  //Verificando tempo de execução da func1
  tempo = clock(); //armazena tempo
  func1(20);
  tempo = clock() - tempo; //tempo final - tempo inicial
  //imprime o tempo na tela
  printf("Tempo de execucao da func1: %lf\n", ((double)tempo)/((CLOCKS_PER_SEC/1000))); //conversão para double

  //Verificando tempo de execução da func2
  tempo = clock(); //armazena tempo
  func2(20);
  tempo = clock() - tempo; //tempo final - tempo inicial
  //imprime o tempo na tela
  printf("Tempo de execucao da func2: %lf\n", ((double)tempo)/((CLOCKS_PER_SEC/1000))); //conversão para double
 
  //Verificando tempo de execução func3
  tempo = clock(); //armazena tempo
  func3(10);
  tempo = clock() - tempo; //tempo final - tempo inicial
  //imprime o tempo na tela
  printf("Tempo de execucao da func3: %lf\n", ((double)tempo)/((CLOCKS_PER_SEC/1000))); //conversão para double
}
