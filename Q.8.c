Design, Develop and Implement a menu driven Program in C/C++ for the following operations on
Singly Linked List (SLL)
a. Create a SLL.
b. Insert at Beginning
c. Insert at Last
d. Insert at any random location
e. Delete from Beginning
f. Delete from Last
g. Delete node after specified location
h. Search for an element
i. Show
j. Exit in


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void createList() {
    head = NULL;
    printf("Singly Linked List created.\n");
}

void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtLast(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteFromLast() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAfterPosition(int position) {
    if (head == NULL || position < 0) {
        printf("List is empty or invalid position.\n");
        return;
    }
    
    Node* temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after the specified position.\n");
        return;
    }
    
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void searchElement(int data) {
    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found at position %d.\n", data, index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("Element %d not found in the list.\n", data);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node* temp = head;
    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create SLL\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Last\n");
        printf("4. Insert at Any Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from Last\n");
        printf("7. Delete Node After Specified Position\n");
        printf("8. Search for an Element\n");
        printf("9. Show List\n");
        printf("10. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromLast();
                break;
            case 7:
                printf("Enter position after which to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(position);
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElement(data);
                break;
            case 9:
                displayList();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
