#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines a stack structure.
typedef struct stack {
    char *data; // Array to store the stack elements.
    int top;    // Index of the top element in the stack.
    int size;   // Size of the stack.
} Stack;

// Initializes the stack.
void initStack(Stack *stack, int size) {
    // Allocate memory for the stack array.
    stack->data = (char *)malloc(size * sizeof(char));

    // Initialize the top index of the stack.
    stack->top = -1;

    // Set the size of the stack.
    stack->size = size;
}

// Pushes an element onto the stack.
void push(Stack *stack, char element) {
    // Increment the top index of the stack.
    stack->top++;

    // Store the element at the top of the stack.
    stack->data[stack->top] = element;
}

// Pops an element from the stack.
char pop(Stack *stack) {
    // Check if the stack is empty.
    if (stack->top == -1) {
        return '\0'; // Return null character to indicate an empty stack.
    }

    // Decrement the top index of the stack.
    stack->top--;

    // Return the element at the top of the stack.
    return stack->data[stack->top + 1];
}

// Returns the precedence of an operator.
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Converts infix expression to postfix notation.
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    int len = strlen(infix);
    initStack(&stack, len);

    int j = 0; // Index for the postfix expression.

    for (int i = 0; i < len; i++) {
        char token = infix[i];

        if (token >= 'a' && token <= 'z') {
            // If it's an operand, add it to the postfix expression.
            postfix[j++] = token;
        } else if (token == '(') {
            // Push opening parenthesis onto the stack.
            push(&stack, token);
        } else if (token == ')') {
            // Pop and add operators from the stack to the postfix expression until a matching '(' is found.
            while (stack.top != -1 && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop the '(' from the stack.
        } else {
            // It's an operator, pop and add operators with higher precedence to the postfix expression.
            while (stack.top != -1 && precedence(token) <= precedence(stack.data[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token); // Push the current operator onto the stack.
        }
    }

    // Pop any remaining operators from the stack to the postfix expression.
    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression.
}

// Reverses a string.
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Converts infix expression to prefix notation.
void infixToPrefix(char *infix, char *prefix) {
    // Reverse the infix expression.
    reverseString(infix);

    // Replace '(' with ')' and vice versa in the reversed expression.
    int len = strlen(infix);
    for (int i = 0; i < len; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Convert the reversed expression to postfix.
    char postfix[len + 1];
    infixToPostfix(infix, postfix);

    // Reverse the postfix expression to get the prefix expression.
    reverseString(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[100];
    char postfix[100];
    char prefix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);

    return 0;
}
