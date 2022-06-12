// Leia o PDF ou MD antes de iniciar este exercício!

// Faça os includes necessários aqui
// #include ...
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

typedef struct {
    sem_t *s1;
    sem_t *s2;
} sems;

void *thread1(void *_arg) {
    // envolve B C e D
    sems *s = (sems *) _arg;  // cria uma variavel do tipo do arg recebido e faz o casting 
    printf("A\n");
    sem_post(s->s2); // POST - sinaliza pra outro
    sem_post(s->s2); // POST - sinaliza pra outro
    sem_post(s->s2); // POST - sinaliza pra outro

    sem_wait(s->s1); // SEM_WAIT DE SI MESMO
    sem_wait(s->s1); // SEM_WAIT DE SI MESMO
    sem_wait(s->s1); // SEM_WAIT DE SI MESMO

    printf("E\n");

    return NULL;
}

void *thread2(void *_arg) {
    sems *s = (sems *) _arg;
    
    sem_wait(s->s2); // SEM_WAIT DE SI MESMO

    printf("B\n");

    // sinaliza que acabou
    sem_post(s->s1);

    return NULL;
}

void *thread3(void *_arg) {
    sems *s = (sems *) _arg;

    sem_wait(s->s2); // SEM_WAIT DE SI MESMO

    printf("C\n");
    
    // sinaliza que acabou
    sem_post(s->s1);

    return NULL;
}

void *thread4(void *_arg) {
    sems *s = (sems *) _arg;

    sem_wait(s->s2); // SEM_WAIT DE SI MESMO

    printf("D\n");
    
    // sinaliza que acabou
    sem_post(s->s1);

    return NULL;
}

int main(int argc, char *argv[]) {

    // Crie TODAS as threads em um laço. Voce deve utilizar semaforos para sincronizacao.
    pthread_t *tids = malloc(sizeof(pthread_t)*4);

    sem_t s1;
    sem_init(&s1, 0, 0);
    sem_t s2;
    sem_init(&s2, 0, 0);

    sems *s = malloc(sizeof(sems)*4); // cria struct

    // preenche struct com pointer
    s->s1 = &s1;
    s->s2 = &s2;

    // cria threads na main
    pthread_create(&tids[0], NULL, thread1, s);
    pthread_create(&tids[1], NULL, thread2, s);
    pthread_create(&tids[2], NULL, thread3, s);
    pthread_create(&tids[3], NULL, thread4, s);

    // Espere por TODAS as threads
    for (int i = 0; i < 4; i++)
        pthread_join(tids[i], NULL);
    
    sem_destroy(&s1);
    sem_destroy(&s2);
    free(tids);
    free(s);

    return 0;
}