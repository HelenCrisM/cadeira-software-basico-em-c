// Implemente um algoritmo que capture a hora atual e apresente ela em segundos, ou seja, converta horas
// e minutos para segundos. Lembre-se que 1 hora = 60 minutos e 1 minuto = 60 segundos.

// Tutorial que utilizei como base para criar código: https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/
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
  
  int segundo_atual = funcao_hora_atual-> tm_sec;

  int i, hora_atual_em_minutos, hora_atual_em_segundos, minuto_atual_em_segundos, soma_dos_segundos;

  for (i = 0; i <= hora_atual; i++) {
    hora_atual_em_minutos = hora_atual * 60;
    hora_atual_em_segundos = hora_atual_em_minutos *60;
  }
  
  for (i = 0; i <= minuto_atual; i++) {
      minuto_atual_em_segundos = minuto_atual *60;
  }
  
  soma_dos_segundos = hora_atual_em_segundos + minuto_atual_em_segundos + segundo_atual;
  
  printf("\nHora ........: %d:%d:%d ", hora_atual, minuto_atual, segundo_atual);
  printf("Soma de todos os segundos: %d", soma_dos_segundos);

  return 0;
}
