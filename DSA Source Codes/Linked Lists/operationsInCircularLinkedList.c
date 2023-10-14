#include <stdio.h>
#include <stdlib.h>

// Creating the structure of each node
struct singlyCircularLinkedList
{
    int value;
    struct singlyCircularLinkedList *next;
};

struct singlyCircularLinkedList *head; // Creating the head globally so that the list can be available globally.

// Creating the functions to print the values.
void printList(struct singlyCircularLinkedList *p)
{ // Iterating through the list
    struct singlyCircularLinkedList *current = p;
    if (current == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    do
    {
        printf("The value is %d, available at address %p\n", current->value, current);
        current = current->next;
    } while (current != p);
}

void insertion()
{
    int value, position;
    printf("Enter the value you want to insert: ");
    scanf("%d", &value);
    printf("Enter the position: ");
    scanf("%d", &position);
    struct singlyCircularLinkedList *newNode = malloc(sizeof(struct singlyCircularLinkedList));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    { // Insert into an empty list
        head = newNode;
        newNode->next = head;
    }
    else if (position <= 1)
    { // Insert at the beginning
        struct singlyCircularLinkedList *current = head;
        while (current->next != head)
            current = current->next;
        current->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct singlyCircularLinkedList *current = head;
        int currentPosition = 1;
        while (current->next != head && currentPosition < position - 1)
        {
            current = current->next;
            currentPosition++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("Here is the updated list:\n");
    printList(head);
}

void deletion()
{
    if (head == NULL)
    {
        printf("List is empty. No nodes to delete.\n");
        return;
    }
    int position;
    printf("Enter the position: ");
    scanf("%d", &position);
    if (position <= 1)
    { // Delete the first node
        struct singlyCircularLinkedList *temp = head;
        if (head->next == head)
        { // Only one node in the list
            head = NULL;
        }
        else
        {
            struct singlyCircularLinkedList *current = head;
            while (current->next != head)
                current = current->next;
            current->next = head->next;
            head = head->next;
        }
        free(temp); // Deallocating the node
    }
    else
    {
        struct singlyCircularLinkedList *current = head;
        struct singlyCircularLinkedList *previous = NULL;
        int currentPosition = 1;
        while (current->next != head && currentPosition < position)
        {
            previous = current;
            current = current->next;
            currentPosition++;
        }
        previous->next = current->next;
        free(current);
    }

    printf("Here is the updated list:\n");
    printList(head);
}

int main()
{
    int n, selection;
    printf("Enter how many nodes you want: ");
    scanf("%d", &n);
    struct singlyCircularLinkedList *list[n]; // creating the list of type: struct singlyCircularLinkedList
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value at index %d: ", i);
        list[i] = malloc(sizeof(struct singlyCircularLinkedList)); // allocating memory
        scanf("%d", &list[i]->value);
    }

    // Assigning the pointers
    head = list[0]; // Assigning the first node
    for (int i = 0; i < n - 1; i++)
        list[i]->next = list[i + 1];
    list[n - 1]->next = head;

    do
    {
        printf("\n\nEnter 1 to traverse the elements.\n");
        printf("Enter 2 to delete an element.\n");
        printf("Enter 3 to add one element.\n");
        printf("Enter 0 to exit the program.\n");
        printf("Enter your selection: ");
        scanf("%d", &selection);
        switch (selection)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("\nPrinting the values:\n");
            printList(head);
            break;
        case 2:
            deletion();
            break;
        case 3:
            insertion();
            break;
        default:
            printf("Enter a valid option.\n");
            break;
        }
    } while (selection != 0);

    // Deallocating all the dynamically allocated memory.
    for (int i = 0; i < n; i++)
    {
        free(list[i]);
    }
    return 0;
}
