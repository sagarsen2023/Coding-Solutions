#include <stdio.h>
#include <stdlib.h>

int top = -1, arr[50];

// Function to display the elements in the stack
void display()
{
    if (top == -1)
        printf("The stack is empty.\n");
    else
    {
        // Loop through the elements in the stack and print them
        for (int i = 0; i <= top; i++)
        {
            printf("%d, ", arr[i]);
        }
    }
    printf("\n\n");
}

// Function to push an element onto the stack
void push()
{
    if (top == 50 - 1)
        printf("Stack Overflow");
    else
    {
        printf("Enter a value to push: ");
        top++;
        scanf("%d", &arr[top]);
    }
    printf("Stack after inserting an element: ");
    display();
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1)
        printf("Stack Underflow");
    else
    {
        // Clear the element at the top of the stack (not necessary, but can be done)
        arr[top] = 0;
        top--;
        printf("Stack after removing an element: ");
        display();
    }
}

int main()
{
    int selection;
    printf("1. Push an element.\n2. Pop an element.");
    printf("\n3. Display the stack.\n0. Exit\nEnter your selection: ");
    scanf("%d", &selection);
    
    while (selection != 0)
    {
        switch (selection)
        {
        case 0:
            exit(1);
            break;
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("Wrong input. Try again.\n\n");
            break;
        }
        
        // Prompt for the next user selection
        printf("1. Push an element.\n2. Pop an element.");
        printf("\n3. Display the stack.\n0. Exit\nEnter your selection: ");
        scanf("%d", &selection);
    }
    
    return 0;
}
