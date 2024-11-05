Design, Develop and Implement a Program in C/C++ for converting an Infix Expression to Postfix
Expression. Program should support for both parenthesized and free parenthesized expressions with
the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.

  #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    char arr[MAX];
    int top;
} Stack;

// Function prototypes
void initStack(Stack* s);
int isFull(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, char value);
char pop(Stack* s);
char peek(Stack* s);
int precedence(char op);
int isOperator(char ch);
void infixToPostfix(const char* infix, char* postfix);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove newline character

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Stack functions
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
    if (!isFull(s)) {
        s->arr[++(s->top)] = value;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}

char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

// Function to define operator precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

// Function to convert infix to postfix
void infixToPostfix(const char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j = 0; // Index for postfix expression

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isalnum(current)) { // If the character is an operand, add it to postfix
            postfix[j++] = current;
        } else if (current == '(') { // If the character is '(', push it to stack
            push(&s, current);
        } else if (current == ')') { // If the character is ')', pop and output from the stack
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Pop '(' from stack
        } else if (isOperator(current)) { // If the character is an operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(current)) {
                postfix[j++] = pop(&s);
            }
            push(&s, current);
        }
    }

    // Pop all the operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // Null terminate the postfix expression
}
