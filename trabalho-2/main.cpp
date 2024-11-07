// Baseado no exemplo feito em aula da soma de vetor usando Threads, implemente o produto vetorial
// usando Threads. Utilize a funçao abaixo.
// int P r o d u t oV e t o ri al ( int i n i c i o , int fim ){
// int soma = 0 ;
// for ( int i = i n i c i o ; i < fim ; i ++){
// soma += v e t o r 1 [ i ] ∗ v e t o r 2 [ i ] ;
// }
// return soma ;
// }

// Tutorial que utilizei como base para criar código: O arquivo disponivel no sava chamado "Código Soma Vetor Usando Threads"


#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define TAM_VETOR   100000

int vetor1[TAM_VETOR];
int vetor2[TAM_VETOR];
int resultado = 0;
pthread_mutex_t mutex;

int ProdutoVetorial(int inicio, int fim) {
    int soma = 0;
    for (int i = inicio; i < fim; i++) {
        soma += vetor1[i] * vetor2[i];
    }
    return soma;
}

void * produto(void *arg) {
    int id = *((int *)arg);
    int intervalo = TAM_VETOR / NUM_THREADS;
    int inicio = id * intervalo;
    int fim = (id + 1) * intervalo;
    int soma_parcial = ProdutoVetorial(inicio, fim);
    
    pthread_mutex_lock(&mutex);
    resultado += soma_parcial;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < TAM_VETOR; i++) {
      vetor1[i] = 1;
      vetor2[i] = 2;
    }
    
    pthread_t threads[NUM_THREADS];
    int id[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; i++) {
      id[i] = i;
      pthread_create(&threads[i], NULL, produto, &id[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
      pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    
    printf("Resultado: %d\n", resultado);

    return 0;
}
