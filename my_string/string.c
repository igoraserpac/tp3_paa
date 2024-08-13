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

String* concatenar(String *s1, String *s2){
    int n = s1->length, m = s2->length;
    String *ret = (String*)malloc(sizeof(String));
    ret->str = (char*)malloc((n+m+3)*sizeof(char));
    ret->str[0] = '#';
    for(int i = 0; i < n; i++){
        ret->str[i+1] = s1->str[i];
    }
    ret->str[n+1] = '$';
    for(int i = 0;i < m; i++){
        ret->str[n+2+i] = s2->str[i];
    }
    ret->str[m+n+2] = '\0';
    return ret;
}