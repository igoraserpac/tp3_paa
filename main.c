#include "my_string/string.h"
#include "forca_bruta/forca_bruta.h"
#include "kmp/kmp.h"
#include "bmh/bmh.h"
#include "bmhs/bmhs.h"

int main() {

    String *t = lerString();
    String *p = lerString();

    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        String *t_sub = cortar(t, a, b);
        // printf("%s %d %s\n", t_sub->str, t_sub->length, p->str);
        if(Kmp(t_sub, p)) printf("sim\n"); 
        else printf("nao\n");
        desalocarString(t_sub);
    }


    // if(Bmh(t, p)) printf("sim\n"); 
    // else printf("nao\n");
    // if(Bmhs(t, p)) printf("sim\n"); 
    // else printf("nao\n");
    // if(ForcaBruta(t, p)) printf("sim\n"); 
    // else printf("nao\n");
    
    desalocarString(t);
    desalocarString(p);


    return 0;
}