#include "bmh.h"

bool Bmh(string *t, string *p) {
    int n = t->fim, m = p->fim;
    int i, j, k;
    int d[256];
    
    // Inicializa a tabela de deslocamento
    for(j = 0; j < 256; j++) {
        d[j] = m;
    }
    for(j = 1; j < m; j++) {
        d[p->str[j-1]] = m-j;
    }

    // Inicializa i com a posição correta considerando o início do intervalo
    i = m + t->inicio;
    
    while(i <= n) {
        k = i; j = m;
        while(t->str[k-1] == p->str[j-1] && j > 0) {
            k--; j--;
        }
        if(j == 0) {
            return true;
        }
        i += d[t->str[i-1]];
    }
    return false;
}