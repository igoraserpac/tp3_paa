#include "kmp.h"
#include "../string/string.h"

//Pré-processamento do padrão P
void init_next(string *p, int *next){
    for(int i = 0; i < p->fim; i++){
        next[i] = 0;
    }
    int idx = 0, j = 1;
    while(j < p->fim){
        if(p->str[idx] == p->str[j]){
            idx++;
            next[j] = idx;
            j++;
        }else if (idx > 0) {
            idx = next[idx - 1];
        }else {
            j++;
        }
    }

}

bool Kmp(string *t, string *p){
    int i = t->inicio, j = 0, n = t->fim, m = p->fim;
    int *next = (int*)malloc(m*sizeof(int));
    init_next(p, next);
    while (i < n && j < m) {
        if (t->str[i] == p->str[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = next[j - 1];
        } else {
            i++;
        }
    }
    if (j == m)
        return true;
    return false;
}