#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    char data;
    struct Node* next;
} Node;

typedef struct tlist{
    Node* head;
    int length;
} TempList;

typedef struct {
    char* str;
    int length;
} String;

// Função para ler a string da entrada padrão e preencher TempList
void readTempList(TempList* tempList);

// Função para transferir os dados da TempList para a String
void tempListToString(TempList* tempList, String* string);

// Função para liberar a memória da TempList
void freeTempList(TempList* tempList);

// Função principal solicitada
String* readString();

// Node* createNode(char data);

// String* createString();

// void appendChar(String* string, char data);

// void readString(String* string);

// void printString(const String* string);

// void freeString(String* string);

#endif