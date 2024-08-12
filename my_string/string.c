#include "string.h"

List* lerEntrada(){
    List* list = criarLista();

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF){
        inserChar(list, ch);
    }

    return list;
}

String* criarString(List *list){
    String *s = (String*)malloc(sizeof(String));
    if(s == NULL)
        printf("[ERRO DE ALOCAÇÃO] variavel s\n");

    s->str = (char*)malloc((list->length + 1) * sizeof(char));
    if(s->str == NULL)
        printf("[ERRO DE ALOCAÇÃO] variavel s->str\n");
    s->length = list->length;

   
    Node*curr = list->head;
    int i = 0;
    while (curr != NULL){
        s->str[i] = curr->data;
        curr = curr->next;
        i++;
    }
    s->str[i] = '\0';
 
    return s;
}

void desalocarString(String *s){
    if(s == NULL){
        printf("[ERRO DE DESALOCAÇÃO]\n");
        return;
    }

    free(s->str);
    free(s);
}

String* lerString(){
    List* list = lerEntrada();
    String *s = criarString(list);
    desalocarLista(list);

    return s;
}