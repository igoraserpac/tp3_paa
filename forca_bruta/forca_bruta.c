#include "forca_bruta.h"

bool ForcaBruta(String *t, String *p){
    int i, j, k;
    int n = t->length, m = p->length;
    for(i = 0; i < n-m+1; i++){
        k = i; j = 0;
        while(k < n && j < m && t->str[k] == p->str[j]){
            j++; k++;
        }
        if(j >= m) return true;
    }
    return false;
}