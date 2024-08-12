#include "forca_bruta.h"

bool ForcaBruta(char *t, char *p, int n, int m){
    int i, j, k;
    for(i = 0; i < n-m; i++){
        k = i; j = 0;
        while(k < n && j < m && t[k] == p[j]){
            j++; k++;
        }
        if(j >= m) return true;
    }
    return false;
}