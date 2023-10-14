#include <stdio.h>
#include <stdlib.h>

// Defines a stack structure.
typedef struct stack
{
    char *data; // Array to store the stack elements.
    int top;    // Index of the top element in the stack.
    int size;   // Size of the stack.
} Stack;

// Initializes the stack.
void initStack(Stack *stack)
{
    // Allocate memory for the stack array.
    stack->data = malloc(100 * sizeof(char));

    // Initialize the top index of the stack.
    stack->top = -1;

    // Set the size of the stack.
    stack->size = 100;
}

// Pushes an element onto the stack.
void push(Stack *stack, char element)
{
    // Increment the top index of the stack.
    stack->top++;

    // Store the element at the top of the stack.
    stack->data[stack->top] = element;
}

// Checks if the stack is empty.
int isEmpty(Stack *stack)
{
    // Return true if the top index of the stack is -1, false otherwise.
    return stack->top == -1;
}

// Pops an element from the stack.
char pop(Stack *stack)
{
    // Check if the stack is empty.
    if (isEmpty(stack))
    {
        // Return 0 to indicate an empty stack.
        return 0;
    }

    // Decrement the top index of the stack.
    stack->top--;

    // Return the element at the top of the stack.
    return stack->data[stack->top + 1];
}

// Checks if the parentheses in the given expression are balanced.
int isBalanced(char *str)
{
    // Create a stack to store the opening parentheses.
    Stack stack;
    initStack(&stack);

    // Iterate over the input string.
    for (int i = 0; str[i] != '\0'; i++)
    {
        // If the current character is an opening parenthesis, push it onto the stack.
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(&stack, str[i]);
        }

        // If the current character is a closing parenthesis, check if the stack is empty.
        // If it is empty, then the parentheses are not balanced.
        // If the stack is not empty, pop the top element from the stack and compare it with the current character.
        // If the two characters do not match, then the parentheses are not balanced.
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            // Handle empty parentheses.
            if (str[i] == ')' && stack.top == -1)
            {
                continue;
            }

            if (isEmpty(&stack))
            {
                return 0;
            }

            char poppedElement = pop(&stack);
            if (poppedElement != '(' && poppedElement != '{' && poppedElement != '[')
            {
                return 0;
            }
        }
    }

    // If the iteration over the input string is complete and the stack is empty, then the parentheses are balanced.
    return isEmpty(&stack);
}

int main()
{
    // Declare a character array to store the input expression.
    char str[100];

    // Prompt the user to enter the expression.
    // Prompt the user to enter the expression.
    printf("Enter the expression: ");
    if (scanf("%99s", str) != 1)
    {
        printf("Input error.\n");
        return 1; // Exit with an error code.
    }

    // Check if the parentheses in the expression are balanced.
    if (isBalanced(str))
    {
        // Print a message indicating that the parentheses are balanced.
        printf("The parentheses are balanced.\n");
    }
    else
    {
        // Print a message indicating that the parentheses are not balanced.
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
