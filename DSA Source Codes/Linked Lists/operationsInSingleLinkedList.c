#include <stdio.h>
#include <stdlib.h>

// Creating a structure to store the value and address to the next node
struct ageLinkedList
{
    int age;
    struct ageLinkedList *ptr;   // This will help us to store address to the next node
};

// Assigning the first pointer globally, so that the linked list can be accessed from anywhere from the program.
struct ageLinkedList *head = NULL;

// Function to print the linked list
void printing(struct ageLinkedList *p)
{
    while (p != NULL) // Until the last pointer points to NULL, the loop will continue
    {
        printf("The value is %d at address %u.\n", p->age, p->ptr);
        p = p->ptr;   // Assigning the pointer to the address of next node
    }
}

// Function to delete a node from anywhere in the linked list
void deleteNode(struct ageLinkedList **head)
{
    int position;
    printf("Enter the position you want to delete: ");
    scanf("%d", &position);

    // returns from the function if the  list is already empty. 
    // Which means the head pointer is pointing to a null pointer
    if (*head == NULL)
    {
        printf("The linked list is already empty.\n\n");
        return;
    }

    // Creating two pointer which will help us to traverse through the list
    struct ageLinkedList *previous = *head;
    struct ageLinkedList *current = *head;
    if (current == NULL)
    {
        // Error handled if the user enters wrong input
        printf("Invalid position for deletion.\n\n");
        return;
    }
    if (position == 1)
    {
        // if the user wants to delete a value available in the first position of the list
        *head = current->ptr;
        free(current);
    }
    else
    {
        // When the user enters a valid input
        while (position != 1 && current != NULL)
        {
            previous = current;
            current = current->ptr;
            position--;
        }
        previous->ptr = current->ptr;
        free(current);
    }
    printf("\n");
    printing(*head); // Printing the list after a successfull operation
    printf("\n");
}

void insertNode(struct ageLinkedList **head, struct ageLinkedList *p)
{
    int value, position;
    printf("Enter the value: ");
    scanf("%d", &value);
    printf("Enter the position: ");
    scanf("%d", &position);
    // Creating and assigning the values to the new node.
    struct ageLinkedList *newNode = malloc(sizeof(struct ageLinkedList));
    newNode->age = value;
    newNode->ptr = NULL;
    if (*head == NULL && position == 1)
    {
        // If the user wants to insert at the first position.
        *head = newNode;
        printf("\n");
        return;
    }
    if (*head == NULL && position != 1)
    {
        // Error handled if the user enters different position while the list is empty
        printf("The linked list is empty. Cannot insert at the specified position.\n");
        printf("In the next try enter the position: 1.\n\n");
        return;
    }
    struct ageLinkedList *current = *head;
    for (int i = 1; i < position - 1; i++)
    {
        // Inserting the value in a different position
        if (current->ptr == NULL)
        {
            printf("Invalid position for insertion.\n\n");
            return;
        }
        current = current->ptr;
    }

    // When all conditions are correct, finally adding the new node
    newNode->ptr = current->ptr;
    current->ptr = newNode;
    printf("\n");
    printing(*head);
    printf("\n");
}

int n;
int main()
{
    int x;
    printf("Enter how many nodes you want: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Number of nodes should be a positive integer.\n");
        return 1;
    }

    // Creating the list
    struct ageLinkedList *list[n];
    for (int i = 0; i < n; i++)
    {
        list[i] = malloc(sizeof(struct ageLinkedList));
        printf("Enter age at %d: ", i);
        scanf("%d", &list[i]->age);
        list[i]->ptr = NULL;
    }

    // Assigning the pointers to the next node
    head = list[0];
    for (int i = 0; i < n - 1; i++)
    {
        list[i]->ptr = list[i + 1];
    }

    printing(head);
    // Not more error handled 
    do
    {
        printf("Enter 1 to delete a node.\n");
        printf("Enter 2 to insert a node.\n");
        printf("Enter 3 to view the current linked list.\n");
        printf("Enter 0 to exit.\n");
        printf("Enter your selection: ");
        scanf("%d", &x);
        switch (x)
        {
        case 0:
            break;
        case 1:
            deleteNode(&head);
            break;
        case 2:
            insertNode(&head, list[n - 1]);
            break;
        case 3:
            printf("\n");
            printing(head);
            printf("\n");
            break;
        default:
            printf("Sorry, wrong input.\n");
            break;
        }
    } while (x != 0);

    // It is a good practice to free all the allocated memory.
    for (int i = 0; i < n; i++)
    {
        free(list[i]);
    }
    return 0;
}
