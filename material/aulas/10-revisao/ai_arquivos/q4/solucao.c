// Questao 04
// Implemente aqui uma funcao chamada ex4_solucao

int ex4_solucao (int *v1, int *v2, int a) {
    for (int i = 0; i < a; i++){
        int ret = a - i - 1;
        if (v1[i] != v2[ret]){
            return ret;
        }
    }
    return -1;
}