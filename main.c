#include "forca_bruta/forca_bruta.h"
#include "my_string/string.h"

int main() {

    String *s = lerString();
    printf("%s\n", s->str);
    desalocarString(s);

    return 0;
}