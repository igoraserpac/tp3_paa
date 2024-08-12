#include "forca_bruta/forca_bruta.h"
#include "my_string/my_string.h"

int main() {
    // String *string = createString(), *string2 = createString();
    // printf("Digite uma string: ");
    // readString(string);
    // printf("Digite outra string: ");
    // readString(string2);
    // if(ForcaBruta(*string, *string2)){
    //     printf("SIM\n");
    // }else{
    //     printf("NÃO\n");
    // }
    // freeString(string);
    // freeString(string2);

    String *str = readString();
    printf("%s\n", str->str);
    free(str);

    // TempList *tp = (TempList*)malloc(sizeof(TempList));
    // readTempList(tp);
    // freeTempList(tp);
    return 0;
}