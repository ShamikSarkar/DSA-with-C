// 1 Write a Menu driven C program to accomplish the following functionalities in doubly
// linked list.
// a) Create a doubly linked list.
// b) Display the elements of a doubly linked list.
// c) Insert a node at the beginning of a doubly linked list.
// d) Insert a node at the end of a doubly linked list.
// e) Insert a node before a given node of a doubly linked list.
// f) Insert a node after a given node of a doubly linked list.
// g) Delete a node from the beginning of a doubly linked list.
// h) Delete a node from the end of a doubly linked list.
// i) Delete a node after a given node of a doubly linked list.
// j) Delete the entire doubly linked list.


#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

// Function prototypes
void createList(int data);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertBeforeNode(int data, int key);
void insertAfterNode(int data, int key);
void deleteFromBeginning();
void deleteFromEnd();
void deleteAfterNode(int key);
void deleteEntireList();

int main() {
    int choice, data, key;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert Before Node\n");
        printf("6. Insert After Node\n");
        printf("7. Delete from Beginning\n");
        printf("8. Delete from End\n");
        printf("9. Delete After Node\n");
        printf("10. Delete Entire List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to create list: ");
                scanf("%d", &data);
                createList(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter key (node data) to insert before: ");
                scanf("%d", &key);
                insertBeforeNode(data, key);
                break;
            case 6:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter key (node data) to insert after: ");
                scanf("%d", &key);
                insertAfterNode(data, key);
                break;
            case 7:
                deleteFromBeginning();
                break;
            case 8:
                deleteFromEnd();
                break;
            case 9:
                printf("Enter key (node data) to delete after: ");
                scanf("%d", &key);
                deleteAfterNode(key);
                break;
            case 10:
                deleteEntireList();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function definitions
void createList(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    head = newNode;
    printf("List created with first node: %d\n", data);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("List elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    printf("Node inserted at beginning: %d\n", data);
}

void insertAtEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted at end: %d\n", data);
}

void insertBeforeNode(int data, int key) {
    Node* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) {
        printf("Key not found.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev)
        temp->prev->next = newNode;
    else
        head = newNode;
    temp->prev = newNode;

    printf("Node inserted before %d: %d\n", key, data);
}

void insertAfterNode(int data, int key) {
    Node* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) {
        printf("Key not found.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;

    printf("Node inserted after %d: %d\n", key, data);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    printf("Node deleted from beginning: %d\n", temp->data);
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    if (temp->prev)
        temp->prev->next = NULL;
    else
        head = NULL;
    printf("Node deleted from end: %d\n", temp->data);
    free(temp);
}

void deleteAfterNode(int key) {
    Node* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp || !temp->next) {
        printf("No node exists after the given key.\n");
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next)
        toDelete->next->prev = temp;
    printf("Node deleted after %d: %d\n", key, toDelete->data);
    free(toDelete);
}

void deleteEntireList() {
    Node* temp = head;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Entire list deleted.\n");
}
