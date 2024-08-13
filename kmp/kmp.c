#include "kmp.h"

void init_next(String *p, int *next){
    int i = 0, j = -1, m = p->length;
    next[0] = -1;
    while(i < m){
        if ((j == -1) || (p->str[i] == p->str[j])) {
            i++; j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

bool Kmp(String *t, String *p){
    int i=0, j=0, n = t->length, m = p->length;
    int *next = (int*)malloc(m*sizeof(int));
    init_next (p, next);
    while ((i < n) && (j < m)){
        if ((j == -1) || (t->str[i] == p->str[j])) {
            i++; j++;
        }else{
            j = next[j];
        }
    }
    if (j == m) return true;
    return false;
    // int n = t->length, m = p->length;
    // String *fita = concatenar(t, p);
    // char *ponteiro = &(fita->str[0]);
    // Pilha pilha;
    // while(*ponteiro != '$'){ 
    //     empilhar(&pilha, *ponteiro);
    //     ponteiro++;
    // }
    // while(*ponteiro != '\0'){
    //     ponteiro++;
    // }
    // ponteiro--;
    // int tamanho = 0;
    // char curr;
    // for(int i = 0; i < n; i++){
    //     curr = pilha.topo->valor;
    //     printf("comparando: %c %c\n", curr, *ponteiro);
    //     if(curr == *ponteiro){
    //         ponteiro--; tamanho++;
    //         printf("Iguais %d\n", tamanho);
    //     }else{
    //         ponteiro += tamanho;
    //         tamanho = 0;
    //         printf("Diferentes %d\n", tamanho);
    //     }
    //     if(tamanho == m){
    //         printf("Casou\n");
    //         desalocarString(fita);
    //         return true;
    //     }
    // }
    // desalocarString(fita);
    // return false;
}