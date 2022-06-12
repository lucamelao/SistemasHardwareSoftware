// Leia o PDF ou MD antes de iniciar este exercício!

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    // confere a qtde de parametros
    if (argc != 4){
        printf("Quantidade de parametros incorreta.\n");
        return -1;
    }

    char *path;
    path = "./siscoin";

    int ret;
    int wst;

    do {
        if(fork() == 0) {
            // Construa a chamada do executavel siscoin. Veja enunciado.
            char *args[] = {path, argv[1], argv[2], argv[3], NULL};
            execvp(path, args);
        }
        // No pai, espere e trate o resultado
        wait(&wst);

        // se saiu sem erro
        if (WIFEXITED(wst)) {
            // DICA: ao atribuir o return do siscoin, faça casting para (char)
            ret = (char) WEXITSTATUS(wst);
        }

    } while (ret > 0); // Repita enquanto houver falha. 
                       // Para se tem problema com o valor ou a qtde de parâmetros
                       // Esta validação está sendo feita em siscoin

    printf("Transferencia feita!\n");
    return 0;
}