// 1 Write a Menu driven C program to accomplish the following functionalities in single
// linked list.
// a) Create a single linked list.
// b) Display the elements of a single linked list.
// c) Insert a node at the beginning of a single linked list.
// d) Insert a node at the end of a single linked list.
// e) Insert a node before a given node of a single linked list.
// f) Insert a node after a given node of a single linked list.
// g) Delete a node from the beginning of a single linked list.
// h) Delete a node from the end of a single linked list.
// i) Delete a node after a given node of a single linked list.
// j) Delete the entire single linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a single linked list
struct Node* createList(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to insert a node before a given node
struct Node* insertBefore(struct Node* head, int target, int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        printf("List is empty.\n");
        return head;
    }
    if (head->data == target) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next && temp->next->data != target) {
        temp = temp->next;
    }
    if (!temp->next) {
        printf("Target node not found.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

// Function to insert a node after a given node
struct Node* insertAfter(struct Node* head, int target, int data) {
    struct Node* temp = head;
    while (temp && temp->data != target) {
        temp = temp->next;
    }
    if (!temp) {
        printf("Target node not found.\n");
        return head;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return head;
    }
    if (!head->next) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node after a given node
struct Node* deleteAfter(struct Node* head, int target) {
    struct Node* temp = head;
    while (temp && temp->data != target) {
        temp = temp->next;
    }
    if (!temp || !temp->next) {
        printf("No node to delete after the target node.\n");
        return head;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Function to delete the entire linked list
struct Node* deleteEntireList(struct Node* head) {
    struct Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("List deleted.\n");
    return NULL;
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, target;

    do {
        printf("\nMenu:\n");
        printf("1. Create a single linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert before a node\n");
        printf("6. Insert after a node\n");
        printf("7. Delete from the beginning\n");
        printf("8. Delete from the end\n");
        printf("9. Delete after a node\n");
        printf("10. Delete entire list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = createList(head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                printf("Enter target node data: ");
                scanf("%d", &target);
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertBefore(head, target, data);
                break;
            case 6:
                printf("Enter target node data: ");
                scanf("%d", &target);
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAfter(head, target, data);
                break;
            case 7:
                head = deleteFromBeginning(head);
                break;
            case 8:
                head = deleteFromEnd(head);
                break;
            case 9:
                printf("Enter target node data: ");
                scanf("%d", &target);
                head = deleteAfter(head, target);
                break;
            case 10:
                head = deleteEntireList(head);
                break;
            case 11:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 11);

    return 0;
}
