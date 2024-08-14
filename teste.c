#include <stdio.h>

int main(){
    for(int i = 0; i < 100000; i++){
        printf("a");
    }
    printf("b\n");
    for(int i = 0; i < 1000; i++){
        printf("a");
    }
    printf("b\n");
    printf("100\n");
    for(int i = 0; i < 100; i++){
        printf("1 %d\n", (i+1)*1000);
    }
}