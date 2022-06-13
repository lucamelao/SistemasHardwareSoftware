// Questao 03
// Implemente aqui uma funcao chamada ex3_solucao

void ex3_solucao (short *a, short *b, short *c){
    int temp = *b;
    *b = *a;
    *a = temp;
    *c = *a * 5 + *b * 3;
}

int edx = *rdi;
int eax = *rsi;

*rdi = eax;
*rsi = edx;

eax = *rdi;

eax = 5*eax;
edx = 3*edx;

eax += edx;

*rdx = eax;