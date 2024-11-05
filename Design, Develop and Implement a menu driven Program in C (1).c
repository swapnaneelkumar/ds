Design, Develop and Implement a menu driven Program in C/C++ for the following operations on
Circular QUEUE of Characters
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit    in c



#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct CircularQueue {
    char arr[MAX];
    int front, rear;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

void insert(CircularQueue* q, char value) {
    if (isFull(q)) {
        printf("Queue Overflow: Cannot insert %c\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
}

char delete(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: Cannot delete from empty queue\n");
        return '\0';
    }
    char value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%c ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    char choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("a. Insert an Element\n");
        printf("b. Delete an Element\n");
        printf("c. Display the status of Circular Queue\n");
        printf("d. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter a character to insert: ");
                scanf(" %c", &value);
                insert(&q, value);
                break;
            case 'b':
                value = delete(&q);
                if (value != '\0') {
                    printf("Deleted element: %c\n", value);
                }
                break;
            case 'c':
                display(&q);
                break;
            case 'd':
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
