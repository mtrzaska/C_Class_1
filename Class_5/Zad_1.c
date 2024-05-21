#include <stdio.h>
#include <stdlib.h>

// Definicja struktury węzła listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do dodawania elementu na początek listy
void add_first(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
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
    
    add_first(&head, 10);
    add_first(&head, 20);
    add_first(&head, 30);
    
    print_list(head);
    
    return 0;
}