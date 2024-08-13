#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    char data;
    struct Node* next;
} Node;

typedef struct List{
    Node* head;
    int length;
}List;

List* criarLista();
void inserChar(List*list, char c);
void desalocarLista(List*list);
void imprimieLista(List* list);
#endif