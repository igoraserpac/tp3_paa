#ifndef _STRING_H
#define _STRING_H

#include "../tads/listaEncadeada.h"

typedef struct {
    char* str;
    int length;
} String;

String* lerString();
void desalocarString(String *s);
String* concatenar(String *s1, String *s2);

#endif