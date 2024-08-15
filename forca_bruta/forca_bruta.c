#include "forca_bruta.h"

bool ForcaBruta(string *t, string *p){
    int i, j, k;
    int n = t->fim, m = p->fim;

    //variavel de laço é inicializada com a posição correta considerando o início do intervalo
    for(i = t->inicio; i < n-m+1; i++){
        k = i; j = 0;
        while(k < n && j < m && t->str[k] == p->str[j]){
            j++; k++;
        }
        if(j >= m) return true;
    }
    
    return false;
}