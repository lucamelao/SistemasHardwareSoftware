#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

// linha de compilação: 

/* declarar tarefas aqui e lançar no main */
/* cada bloco na figura deverá ser representado por um print com sua letra */


// struct de semaforos
// vamos usar um semaforo para cada thread
typedef struct {
    sem_t *s1;
    sem_t *s2;
    sem_t *s3;
    sem_t *s4;
} sems;


// threads que serao lancadas na main
void *thread1(void *arg) {
    // envolve A e B
    sems *s = (sems *) arg;  // cria uma variavel do tipo do arg recebido e faz o casting 
    printf("A\n");
    sem_post(s->s2); // POST - sinaliza pra outro
    sem_wait(s->s1); // SEM_WAIT DE SI MESMO
    printf("C\n");
    return NULL;
}

// esse esta no meio entre as duas
void *thread2(void *arg) {
    sems *s = (sems *) arg;
    printf("B\n");

    // sinaliza que acabou
    sem_post(s->s1);
    sem_post(s->s3);
    sem_post(s->s4);

    // espera os outros
    sem_wait(s->s2);
    sem_wait(s->s2);
    sem_wait(s->s2);

    printf("D\n");
    return NULL;
}

void *thread3(void *arg) {
    sems *s = (sems *) arg;
    printf("E\n");
    
    // sinaliza pra B e G que acabou
    sem_post(s->s2);
    sem_post(s->s4);

    // 2 waits pois espera B e G sinalizarem
    sem_wait(s->s3);
    sem_wait(s->s3);
    printf("F\n");
    return NULL;
}

void *thread4(void *arg) {
    sems *s = (sems *) arg;
    printf("G\n");

    sem_post(s->s2);
    sem_post(s->s3);

    sem_wait(s->s4);
    sem_wait(s->s4);

    printf("H\n");
    return NULL;
}

int main() {
    pthread_t *tids = malloc(sizeof(pthread_t)*4);

    sem_t s1;
    sem_init(&s1, 0, 0);
    sem_t s2;
    sem_init(&s2, 0, 0);
    sem_t s3;
    sem_init(&s3, 0, 0);
    sem_t s4;
    sem_init(&s4, 0, 0);

    sems *s = malloc(sizeof(sems)*4); // cria struct

    // preenche struct com pointer
    s->s1 = &s1;
    s->s2 = &s2;
    s->s3 = &s3;
    s->s4 = &s4;

    // cria threads na main
    pthread_create(&tids[0], NULL, thread1, s);
    pthread_create(&tids[1], NULL, thread2, s);
    pthread_create(&tids[2], NULL, thread3, s);
    pthread_create(&tids[3], NULL, thread4, s);

    for (int i = 0; i < 4; i++)
        pthread_join(tids[i], NULL);
    
    sem_destroy(&s1);
    sem_destroy(&s2);
    sem_destroy(&s3);
    sem_destroy(&s4);
    free(tids);
    free(s);

    return 0;
}
