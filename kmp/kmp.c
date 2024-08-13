#include "kmp.h"

bool Kmp(String *t, String *p){
    int n = t->length, m = p->length;
    String *fita = concatenar(t, p);
    char *ponteiro = &(fita->str[0]);
    Pilha pilha;
    while(*ponteiro != '$'){ 
        empilhar(&pilha, *ponteiro);
        ponteiro++;
    }
    while(*ponteiro != '\0'){
        ponteiro++;
    }
    ponteiro--;
    int tamanho = 0;
    for(int i = 0; i < n; i++){
        if(desempilhar(&pilha) == *ponteiro){
            ponteiro--; tamanho++;
        }else{
            ponteiro += tamanho;
            tamanho = 0;
        }
        if(tamanho == m) return true;
    }
    return false;
}