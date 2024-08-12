#include "my_string.h"

void tempListToString(TempList* tempList, String* string) {
    string->length = tempList->length;
    string->str = (char*)malloc((string->length + 1) * sizeof(char));
    
    if (!string->str) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    Node* current = tempList->head;
    for (int i = 0; i < string->length; i++) {
        string->str[i] = current->data;
        current = current->next;
    }
    string->str[string->length] = '\0';
}

// Função para ler a string da entrada padrão e preencher TempList
void readTempList(TempList* tempList) {
    tempList->head = NULL;
    tempList->length = 0;
    Node* current = NULL;
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        printf("aqui\n");
        Node* newNode = (Node*)malloc(sizeof(Node));
        
        if (!newNode) {
            printf("Erro de alocação de memória.\n");
            exit(1);
        }
        newNode->data = ch;
        newNode->next = NULL;

        if (tempList->head == NULL) {
            tempList->head = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;
        tempList->length++;
    }
}


// Função para liberar a memória da TempList
void freeTempList(TempList* tempList) {
    Node* current = tempList->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(tempList);
    tempList->head = NULL;
    tempList->length = 0;
}

// Função principal solicitada
String* readString() {
    TempList *tempList = (TempList*)malloc(sizeof(TempList));
    String* string = (String*)malloc(sizeof(String));
    if (!string) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    readTempList(tempList);
    tempListToString(tempList, string);
    freeTempList(tempList);
    free(tempList);
    return string;
}



// Node* createNode(char data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (newNode == NULL) {
//         fprintf(stderr, "Erro ao alocar memória para um novo nó.\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// String* createString() {
//     String* string = (String*)malloc(sizeof(String));
//     if (string == NULL) {
//         fprintf(stderr, "Erro ao alocar memória para a String.\n");
//         exit(1);
//     }
//     string->head = NULL;
//     string->length = 0;
//     return string;
// }

// void appendChar(String* string, char data) {
//     Node* newNode = createNode(data);
//     if (string->head == NULL) {
//         string->head = newNode;
//     } else {
//         Node* temp = string->head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
//     if(data != '\0') (string->length)++;
// }

// void readString(String* string) {
//     char ch = getchar();
//     while (ch != '\n' && ch != EOF) {
//         appendChar(string, ch);
//         ch = getchar();
//     }
//     appendChar(string, '\0');
// }

// void printString(const String* string) {
//     Node* temp = string->head;
//     while (temp != NULL) {
//         putchar(temp->data);
//         temp = temp->next;
//     }
//     putchar('\n');
// }

// void freeString(String* string) {
//     Node* current = string->head;
//     Node* next;
//     while (current != NULL) {
//         next = current->next;
//         free(current);
//         current = next;
//     }
//     free(string);
// }

// String* substring(String* s, int i, int j) {
//     if (i < 0 || j > s->length || i > j) {
//         fprintf(stderr, "Índices inválidos.\n");
//         return NULL;
//     }

//     String* subStr = createString();
//     Node* current = s->head;
//     int index = 0;

//     while (current != NULL && index < j) {
//         if (index >= i && index < j) {
//             appendChar(subStr, current->data);
//         }
//         current = current->next;
//         index++;
//     }

//     appendChar(subStr, '\0');
//     return subStr;
// }