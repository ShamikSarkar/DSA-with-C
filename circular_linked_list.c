// 2 Write a Menu driven C program to accomplish the following functionalities in circular
// linked list.
// a) Create a circular linked list.
// b) Display the elements of a circular linked list.
// c) Insert a node at the beginning of a circular linked list.
// d) Insert a node at the end of a circular linked list.
// e) Delete a node from the beginning of a circular linked list.
// f) Delete a node from the end of a circular linked list.
// g) Delete a node after a given node of a circular linked list.
// h) Delete the entire circular linked list. 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* last = NULL;

// Function prototypes
void createCircularLinkedList();
void displayCircularLinkedList();
void insertAtBeginning();
void insertAtEnd();
void deleteFromBeginning();
void deleteFromEnd();
void deleteAfterNode();
void deleteEntireList();

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Display Circular Linked List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete After a Node\n");
        printf("8. Delete Entire List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createCircularLinkedList(); break;
            case 2: displayCircularLinkedList(); break;
            case 3: insertAtBeginning(); break;
            case 4: insertAtEnd(); break;
            case 5: deleteFromBeginning(); break;
            case 6: deleteFromEnd(); break;
            case 7: deleteAfterNode(); break;
            case 8: deleteEntireList(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);

    return 0;
}

void createCircularLinkedList() {
    int data, n, i;
    Node *temp, *newNode;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;

        if (last == NULL) {
            last = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
}

void displayCircularLinkedList() {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

void insertAtBeginning() {
    int data;
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertAtEnd() {
    int data;
    printf("Enter data to insert at the end: ");
    scanf("%d", &data);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void deleteFromBeginning() {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = last->next;

    if (last == last->next) {
        last = NULL;
    } else {
        last->next = temp->next;
    }

    free(temp);
    printf("Node deleted from the beginning.\n");
}

void deleteFromEnd() {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = last->next;
    if (last == last->next) {
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        free(last);
        last = temp;
    }
    printf("Node deleted from the end.\n");
}

void deleteAfterNode() {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }

    int key;
    printf("Enter the node value after which to delete: ");
    scanf("%d", &key);

    Node* temp = last->next;
    do {
        if (temp->data == key) {
            Node* delNode = temp->next;
            if (delNode == last) {
                last = temp;
            }
            temp->next = delNode->next;
            free(delNode);
            printf("Node deleted after %d.\n", key);
            return;
        }
        temp = temp->next;
    } while (temp != last->next);

    printf("Node with value %d not found.\n", key);
}

void deleteEntireList() {
    if (last == NULL) {
        printf("The list is already empty.\n");
        return;
    }

    Node* temp = last->next;
    while (temp != last) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(last);
    last = NULL;
    printf("Entire list deleted.\n");
}
