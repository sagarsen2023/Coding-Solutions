#include <stdio.h>
#include <stdlib.h>

int n = 10, top = 0;

// Define the structure for a stack node
struct Stack
{
    int value;
    struct Stack *next;
};

// The head pointer will help us access the linked list globally
struct Stack *head = NULL;

// Function to display the elements in the stack
void display()
{
    struct Stack *ptr = head;
    while (ptr != NULL)
    {
        printf("%d, ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n\n");
}

// Function to push an element onto the stack
void push()
{
    if (top == n)
        printf("Stack Overflow\n\n");
    else
    {
        struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
        printf("Enter the integer value you want to add: ");
        scanf("%d", &newNode->value);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Stack *ptr = head;
            // Traverse to the end of the linked list
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        top++; // Increment the top pointer
    }
}

// Function to pop an element from the stack
void pop()
{
    if (head == NULL)
    {
        printf("Stack Underflow.\n\n");
    }
    else
    {
        struct Stack *ptr = head;
        struct Stack *prev = NULL;
        
        // Traverse to the end of the linked list
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        
        // If there's only one element in the stack
        if (prev == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            prev->next = NULL;
            free(ptr);
        }
        top--; // Decrement the top pointer
    }
}

int main()
{
    printf("A stack of size 10 is created.\n\n");

    int selection;
    printf("1. Push an element.\n2. Pop an element.");
    printf("\n3. Display the stack.\n0. Exit\nEnter your selection: ");
    scanf("%d", &selection);
    
    while (selection != 0)
    {
        switch (selection)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 0:
            // Free the memory allocated for the linked list nodes
            struct Stack *ptr = head;
            while (ptr != NULL)
            {
                struct Stack *temp = ptr;
                ptr = ptr->next;
                free(temp);
            }
            exit(1);
            break;
        default:
            printf("You have entered wrong input\n");
        }
        printf("1. Push an element.\n2. Pop an element.");
        printf("\n3. Display the stack.\n0. Exit\nEnter your selection: ");
        scanf("%d", &selection);
    }
    return 0;
}
