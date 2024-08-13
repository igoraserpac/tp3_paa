#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>

typedef long long ll;

typedef struct no No;

typedef struct pilha {
    ll tamanho;
    No *topo;
} Pilha;

struct no {
    char valor;
    No* proximo;
};

Pilha* criarPilha();

char empilhar(Pilha* p, char valor);

char desempilhar(Pilha* p);

void imprimirPilha(FILE *__restrict __stream, Pilha* p);

// void imprimirValoresCorrespondentes(FILE *__restrict __stream, Pilha* p, ll arr[]);

void destruirPilha(Pilha *p);

#endif