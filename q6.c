#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    if (!isFull(s)) {
        s->arr[++(s->top)] = value;
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return 0;
}

int evaluatePostfix(const char* expression) {
    Stack s;
    initStack(&s);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&s, expression[i] - '0');
        } else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (expression[i]) {
                case '+': push(&s, operand1 + operand2); break;
                case '-': push(&s, operand1 - operand2); break;
                case '*': push(&s, operand1 * operand2); break;
                case '/': push(&s, operand1 / operand2); break;
                case '%': push(&s, operand1 % operand2); break;
                case '^': push(&s, (int)pow(operand1, operand2)); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char expression[MAX];

    printf("Enter a suffix expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = 0;

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
