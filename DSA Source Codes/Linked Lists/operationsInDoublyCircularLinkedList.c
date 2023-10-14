#include <stdio.h>
#include <stdlib.h>

// Creating the structure of each node
struct doublyCircularLinkedList
{
    int value;
    struct doublyCircularLinkedList *previous;
    struct doublyCircularLinkedList *next;
};

struct doublyCircularLinkedList *head; // Creating the head globally so that the list can be available globally.

// Creating the functions to print the values.
void printListBynext(struct doublyCircularLinkedList *p)
{ // Iterating through the list using the next pointer
    struct doublyCircularLinkedList *current = p;
    do
    {
        printf("The value is %d, available at address %p\n", current->value, current);
        current = current->next;
    } while (current != p);
}

void printListByprevious(struct doublyCircularLinkedList *p)
{ // Iterating through the list using the previous pointer
    struct doublyCircularLinkedList *current = p;
    do
    {
        printf("The value is %d, available at address %p\n", current->value, current);
        current = current->previous;
    } while (current != p);
}

void insertion()
{
    int value, position;
    printf("Entrer the value you want to insert: ");
    scanf("%d",&value);
    printf("Enter the position: ");
    scanf("%d",&position);
    struct doublyCircularLinkedList *newNode = malloc(sizeof(struct doublyCircularLinkedList));
    newNode->value = value;
    newNode->previous = NULL;
    newNode->next = NULL;

    if (head == NULL)
    { // Insert into an empty list
        head = newNode;
        head->previous = head;
        head->next = head;
    }
    else if (position <= 1)
    { // Insert at the beginning
        newNode->next = head;
        newNode->previous = head->previous;
        head->previous->next = newNode;
        head->previous = newNode;
        head = newNode;
    }
    else
    {
        struct doublyCircularLinkedList *current = head;
        int currentPosition = 1;
        while (current->next != head && currentPosition < position - 1)
        {
            current = current->next;
            currentPosition++;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
    }
    printf("Here is the updated list: (From first to last)\n");
    printListBynext(head);
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
    scanf("%d",&position);
    if (position <= 1)
    { // Delete the first node
        struct doublyCircularLinkedList *temp = head;
        if (head->next == head)
        { // Only one node in the list
            head = NULL;
        }
        else
        {
            head->previous->next = head->next;
            head->next->previous = head->previous;
            head = head->next;
        }
        free(temp); // Deallocating the node
    }
    else
    {
        struct doublyCircularLinkedList *current = head;
        int currentPosition = 1;
        while (current->next != head && currentPosition < position)
        {
            current = current->next;
            currentPosition++;
        }
        current->previous->next = current->next;
        current->next->previous = current->previous;
        free(current);
    }

    printf("Here is the updated list: (From first to last)\n");
    printListBynext(head);
}

int main()
{
    int n,selection;
    printf("Enter how many nodes you want: ");
    scanf("%d", &n);
    struct doublyCircularLinkedList *list[n]; // creating the list of type: struct doublyLinkedList
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value at index %d: ", i);
        list[i] = malloc(sizeof(struct doublyCircularLinkedList)); // allocating memory
        scanf("%d", &list[i]->value);
    }

    // Assigning the pointers
    head = list[0]; // Assigning the first node
    list[0]->previous = list[n - 1];
    list[0]->next = list[1];
    list[n - 1]->previous = list[n - 2];
    list[n - 1]->next = head;
    for (int i = 1; i < n - 1; i++)
    {
        list[i]->previous = list[i - 1];
        list[i]->next = list[i + 1];
    }

    do
    {
        printf("\n\nEnter 1 to traverse the elements from first to last.\n");
        printf("Enter 2 to traverse the elements from last to first.\n");
        printf("Enter 3 to delete an element.\n");
        printf("Enter 4 to add one element.\n");
        printf("Enter 0 to exit the program.\n");
        printf("Enter your selection: ");
        scanf("%d", &selection);
        switch (selection)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("\nPrinting the value by accessing the next pointer:\n");
            printListBynext(head);
            break;
        case 2:
            printf("\nPrinting the value by accessing the previous pointer:\n");
            printListByprevious(list[n - 1]);
            break;
        case 3:
            deletion();
            break;
        case 4:
            insertion();
            break;
        default:
            // system("cls");  // Commented out because this function only works on windows. If you know any alternative, please let me know.
            printf("Enter the value again.\n");
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
