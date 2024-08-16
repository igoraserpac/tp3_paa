#ifndef STRING_H
#define STRING_H

#define MAX 1e3

#include <stdio.h>
#include <stdlib.h>

typedef struct string
{
    char* str;
    long long capacidade;
    long long inicio;
    long long fim;
}string;

string* lerString();
void desalocarString(string*s);
string* cortar(string* s, long long a, long long b);

#endif