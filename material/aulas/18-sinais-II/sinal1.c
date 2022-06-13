#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int c = 0;
void sig_handler(int num) {
    printf("Chamou Ctrl+C\n");
    if(c == 2) {
        exit(0);
    }
    c++;

}

int main() {
    /* TODO: registre a função sig_handler
     * como handler do sinal SIGINT
     */
    struct sigaction s;
    s.sa_handler = sig_handler; // aqui vai a função a ser executada
    // s.sa_handler = SIG_DFL; // RESTAURA COMPORTAMENTO ORIGINAL DO CTRL+C
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;
    sigaction(SIGINT, &s, NULL);

    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}
