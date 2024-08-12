#include "listaEncadeada.h"

List* criarLista(){
    List * list = (List*)malloc(sizeof(List));

    if(list != NULL){
        list->head = NULL;
        list->length = 0;
    }else{
        exit(1);
    }

    return list;
}

void inserChar(List*list, char c){
    if(list == NULL){
        exit(1);
    }
    
    Node* no = (Node*)malloc(sizeof(Node));
    if(no == NULL){
        exit(2);
    }

    no->data = c;
    no->next = NULL;
    
    if(list->head == NULL){
        list->head = no;
    }
    else{
        Node * curr = list->head;

        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = no;

    } 

    list->length++;
}

void imprimieLista(List* list){
    if(list == NULL){
        printf("Não é possível imprimir lista [NULL]\n");
    }
    if(list->head == NULL){
        printf("Não é possível imprimir lista [VAZIA]\n");
    }

    Node* curr = list->head;
    while(curr != NULL){
        printf("%c", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void desalocarLista(List*list){
    if(list == NULL){
        exit(1);
    }
    Node*curr = list->head;
    
    Node*temp = curr;
    while(curr != NULL){
        curr = curr->next;
        free(temp);
        temp = curr;
    }

    free(list);
}