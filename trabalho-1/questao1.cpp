/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


// Capture o tempo atual e imprima no formato hh : mm AM/PM.
// Tutorial que utilizei como base para criar código: https://linguagemc.com.br/exibindo-data-e-hora-com-time-h/

#include <stdio.h>
#include <time.h>

int main(void) {
  struct tm *funcao_hora_atual;     
  
  time_t segundos;
  
  time(&segundos);   
  
  funcao_hora_atual= localtime(&segundos);

  int hora_atual = funcao_hora_atual-> tm_hour;

  int minuto_atual = funcao_hora_atual-> tm_min;
  
  printf("\nHora ........: %d:%d ", hora_atual, minuto_atual);
  
  if (hora_atual >= 0 && hora_atual < 12) {
    printf("AM");
  } else {
    printf("PM");
  }

  
  return 0;
}