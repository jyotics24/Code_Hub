#include "stdio.h"
#include "stdlib.h"
#include"math.h"

// Define the structure of a node
struct Node {
    int value;
    struct Node* next;
};

// Function to insert a new node at the beginning
void insertAtStart(struct Node** head, int newValue) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = newValue;
    newNode->next = *head;  // Point to the current head
    *head = newNode;        // Move head to the new node
}

// Function to delete the first node
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    struct Node* tempNode = *head;
    *head = (*head)->next;  // Move head to the next node
    free(tempNode);         // Free the old head node
}

// Function to display the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* headNode = NULL;  // Start with an empty list

    // Insert elements at the beginning
    insertAtStart(&headNode, 10);
    insertAtStart(&headNode, 20);
    insertAtStart(&headNode, 30);

    // Display the list
    printf("Linked list: ");
    printList(headNode);

    // Delete the first element
    deleteFirst(&headNode);

    // Display the list after deletion
    printf("Linked list after deletion: ");
    printList(headNode);

    return 0;
}