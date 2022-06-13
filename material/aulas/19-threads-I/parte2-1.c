#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


pthread_mutex_t mutex_multiplicacao = PTHREAD_MUTEX_INITIALIZER;

typedef struct{
    int a, b;
    int *c;
}inteiros;

// declara variavel e da print no seu conteud
void *minha_thread(void *_arg) {
    // pointer de struct so funciona com flecha
    inteiros *i = (inteiros *) _arg;
    
    pthread_mutex_lock(&mutex_multiplicacao); 
    *i->c = i->a * i->b;
    printf("A: %d\n", i->a);
    printf("B: %d\n", i->b);
    printf("Resultado: %d\n\n", *i->c);
    pthread_mutex_unlock(&mutex_multiplicacao); 
    
    return NULL;
}

int main() {


    // vetor com 4 threads
    pthread_t *tids = malloc(sizeof(pthread_t)*4);
    inteiros *inte = malloc(sizeof(inteiros)*1);
    
    //inte->mutex_multiplicacao = &mutex_multiplicacao;
    inte->c = malloc(sizeof(int)); 
    
    for (int i = 0; i < 4; i++) {
        // quero q o ponteiro aponte para...
        inte->a = i;
        inte->b = 5;
        pthread_create(&tids[i], NULL, minha_thread, inte);
        // passa como ultimo arg o endereco do elemento correspondente de vi
        //printf("[MAIN] Resultado: %d\n\n", *inte->c);
    }
    
    
    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], NULL);
        // espera pelo fim da thread
    }

    free(inte);
    free(tids);
    free(inte->c);
    return 0;
}
