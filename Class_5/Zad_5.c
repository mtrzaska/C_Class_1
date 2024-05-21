#include <stdio.h>
#include <stdlib.h>

// Definicja struktury węzła listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do usuwania pierwszego elementu z określoną wartością
void remove_by_value(struct Node** head, int value) {
    if (*head == NULL) return;
    
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Funkcja do wyświetlania listy
void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Przykładowe użycie funkcji
int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;
    
    print_list(head);
    remove_by_value(&head, 20);
    print_list(head);
    
    return 0;
}