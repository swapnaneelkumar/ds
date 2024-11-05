#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    char arr[MAX];
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

void push(Stack* s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow: Cannot push %c\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Cannot pop from empty stack\n");
        return '\0';
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
        printf("%c ", s->arr[i]);
    }
    printf("\n");
}

int isPalindrome(const char* str) {
    Stack s;
    initStack(&s);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (pop(&s) != str[i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

int main() {
    Stack s;
    initStack(&s);

    // Check for palindrome
    const char* testStr = "ABBA";
    if (isPalindrome(testStr)) {
        printf("%s is a palindrome.\n", testStr);
    } else {
        printf("%s is not a palindrome.\n", testStr);
    }

    // Demonstrating overflow
    for (int i = 0; i < MAX + 1; i++) {
        push(&s, 'X');
    }

    // Display the status of the stack
    display(&s);

    // Demonstrating underflow
    for (int i = 0; i < 5; i++) {
        pop(&s);
    }
    display(&s);

    // Attempt to pop from an empty stack
    for (int i = 0; i < 5; i++) {
        pop(&s);
    }

    return 0;
}
