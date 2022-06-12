// Leia o PDF ou MD antes de iniciar este exercício!

#include "macros_correcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *extrai_primeira_hashtag_user (char *tweet_completo) {
    int tag = 0;
    int start = 0;
    int end = 0;
    int i;

    // percorre o tweet ate o seu final
    for(i = 0; tweet_completo[i] != '\0'; i++){

        if (tag){
            // um espaco ou uma virgula encerram uma mencao
            if(tweet_completo[i] == ' ' || tweet_completo[i] == ','){
                end = i;
                break;
            }
        }

        // uma # ou um @ iniciam uma mencao
        if(tweet_completo[i] == '#' || tweet_completo[i] == '@'){
            start = i;
            tag = 1; // flag se achou a tag
        }

    }
    
    // atualiza o end
    if (start > end){
        end = i;
    }

    // ponteiro para char
    char *substring = malloc(sizeof(char) * (end - start + 1));
    
    // extrai a mencao/hashtag e coloca na substring
    for(int j = start; j < end; j++) {
        substring[j - start] = tweet_completo[j];
    }
    
    substring[end] = '\0';
    
    printf("-----------------------------------");
    printf("\nString extraida: %s \n", substring);
    return substring;
}

// Nao altere nada na Main!
int main () {
    printf("Testes D\n");
    printf("===================\n");

    {
        char *tweet = "comprei 10 crypto siscoin hoje";
        char *correto = "";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }

    {
        char *tweet = "comprei 10 crypto siscoin hoje, sou #baleia ou nao?!";
        char *correto = "#baleia";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }


    {
        char *tweet = "A crypto do momento é #siscoin que cresceu 20%% só hoje";
        char *correto = "#siscoin";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }


    {
        char *tweet = "A crypto do momento é #siscoin, bora comprar?";
        char *correto = "#siscoin";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }

    {
        char *tweet = "A Amazônia teve 2.308 focos de calor no mês passado #wwf #greenpeace #queimadas";
        char *correto = "#wwf";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }

    {
        char *tweet = "#cultura estreou nesta semana o filme 7 Prisioneiros.";
        char *correto = "#cultura";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }

    {
        char *tweet = "Either the well was very deep, or she fell very slowly, for she had plenty of time... #AliceinWonderland";
        char *correto = "#AliceinWonderland";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }


    {
        char *tweet = "@alice was beginning to get very tired of sitting by her sister on the bank";
        char *correto = "@alice";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }

    {
        char *tweet = "The @dursleys had everything they wanted, but they also had a secret";
        char *correto = "@dursleys";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }


    {
        char *tweet = "MR @dursley always sat with his back to the window in his #office on the ninth floor";
        char *correto = "@dursley";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }

    {
        char *tweet = "He had #forgotten all about the people in cloaks until he passed a group of them next to the @citybaker";
        char *correto = "#forgotten";
        char *primeira_hashtag_user = extrai_primeira_hashtag_user(tweet);

        printf("Testes: %s\n", tweet);
        assertExpr(primeira_hashtag_user != NULL, "Hashtag é NULL!");
        if (primeira_hashtag_user != NULL) {
            assertExpr(strcmp(primeira_hashtag_user, correto) == 0, "Hashtag tem valor incorreto!");
            free(primeira_hashtag_user);
        }
    }

    printSummary;
}
