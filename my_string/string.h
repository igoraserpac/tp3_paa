#ifndef _STRING_H
#define _STRING_H

#include "listaEncadeada.h"

typedef struct {
    char* str;
    int length;
} String;

String* lerString();
void desalocarString(String *s);

#endif