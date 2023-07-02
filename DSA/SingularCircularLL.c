#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularLinkedList {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert element at the beginning of the list
void insertAtBeginning(struct CircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        struct Node* curr = list->head;
        while (curr->next != list->head) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = list->head;
        list->head = newNode;
    }
}

// Function to insert element at the end of the list
void insertAtEnd(struct CircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        struct Node* curr = list->head;
        while (curr->next != list->head) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = list->head;
    }
}

// Function to display the elements in the linked list
void display(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* curr = list->head;
        do {
            printf("%d ", curr->data);
            curr = curr->next;
        } while (curr != list->head);
        printf("\n");
    }
}

// Function to delete an element from the beginning of the list
void deleteFromBeginning(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
    } else if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        struct Node* curr = list->head;
        while (curr->next != list->head) {
            curr = curr->next;
        }
        struct Node* temp = list->head;
        list->head = list->head->next;
        curr->next = list->head;
        free(temp);
    }
}

int main() {
    struct CircularLinkedList list;
    list.head = NULL;

    // Insert elements at the beginning of the list
    insertAtBeginning(&list, 5);
    insertAtBeginning(&list, 4);
    insertAtBeginning(&list, 3);

    // Insert elements at the end of the list
    insertAtEnd(&list, 6);
    insertAtEnd(&list, 7);
    insertAtEnd(&list, 8);

    // Display the elements in the linked list
    printf("Elements in the linked list: ");
    display(&list);

    // Deletion of an element from the beginning of the list
    deleteFromBeginning(&list);
    deleteFromBeginning(&list);

    // Display the elements after deletion
    printf("Elements after deletion: ");
    display(&list);

    return 0;
}
