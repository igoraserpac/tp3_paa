#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->tamanho = 0;
    p->topo = NULL;
    return p;
}

char empilhar(Pilha* p, char valor){
    No *n = (No*)malloc(sizeof(No));
    n->proximo = p->topo;
    n->valor = valor;
    p->topo = n;
    (p->tamanho)++;
    return p->tamanho;
}

char desempilhar(Pilha* p){
    ll valor = p->topo->valor;
    No *aux = p->topo;
    p->topo = p->topo->proximo;
    free(aux);
    (p->tamanho)--;
    return valor;
}

void imprimirPilha(FILE *__restrict __stream, Pilha* p){
    No *atual = p->topo;
    while(atual != NULL){
        fprintf(__stream, "%c ", atual->valor);
        atual = atual->proximo;
    }
}

// void imprimirValoresCorrespondentes(FILE *__restrict __stream, Pilha* p, ll arr[]){
//     No *atual = p->topo;
//     while(atual != NULL){
//         fprintf(__stream, "%lld ", arr[atual->valor]);
//         atual = atual->proximo;
//     }
// }

void destruirPilha(Pilha *p){
    while(p->topo != NULL) desempilhar(p);
    free(p);
}