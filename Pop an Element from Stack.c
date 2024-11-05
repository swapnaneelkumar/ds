#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow: Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Cannot pop from empty stack\n");
        return -1; // Return -1 for underflow
    }
    return s->arr[(s->top)--];
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    // Push elements onto the stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    // Pop an element from the stack
    int poppedValue = pop(&s);
    if (poppedValue != -1) {
        printf("Popped element: %d\n", poppedValue);
    }
    display(&s);

    // Pop another element
    poppedValue = pop(&s);
    if (poppedValue != -1) {
        printf("Popped element: %d\n", poppedValue);
    }
    display(&s);

    // Attempt to pop from an empty stack
    pop(&s);
    pop(&s); // This should trigger underflow

    return 0;
}
