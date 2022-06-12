#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define CHARACTERS_LIMIT 2000

char *proxima_linha(int fd) {
    char buf[1]; // guarda dados lidos
    int i = 0;
    char *line = malloc(i); // tamanho arbitrario de linha

    while (1){
        int end = read(fd, buf, 1); // read retorna zero quando termina de ler o arquivo
        if(end == 0){

            // checa se nao leu nada
            if (i == 0){
                return NULL;
            }
            else
                break;
            }

            // quebra de linha
            if (*buf == '\n'){
                break;
            }


            i++;
            line = realloc(line, i);
            strncat(line, buf, i);
        }
        return line;
}


int main() {
    int fd = open("p3.txt", O_RDONLY);
    
    char* linha;
    
    linha = proxima_linha(fd);
    while (linha != NULL) {
        // checa se e maiuscula - ASCII
        if (linha[0] > 64 && linha[0] < 91)
        printf("Linha: %s\n", linha);
        linha = proxima_linha(fd);
    }
    close(fd);
    return 0;
}
