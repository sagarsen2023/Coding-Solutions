#include <stdio.h>
#include <stdlib.h> // Important because we are using the malloc() and the free function

// Creating the structure of each node
struct doublyLinkedList
{
    int value;
    struct doublyLinkedList *previous;
    struct doublyLinkedList *next;
};

struct doublyLinkedList *head; // Creating the head globally so that the list can be available globally.

void printListBynext(struct doublyLinkedList *p)
{ // Accessing the list by using the next pointer
    while (p != NULL)
    {
        printf("The value is %d, available at address %p\n", p->value, p);
        p = p->next;
    }
}

void printListByprevious(struct doublyLinkedList *p)
{ // Accessing the list by using the previous pointer
    while (p != NULL)
    {
        printf("The value is %d, available at address %p\n", p->value, p);
        p = p->previous;
    }
}

void insertion()
{ // Insert an element in the list
    // Taking the user input
    int value, position;
    printf("Enter the value you want to add: ");
    scanf("%d", &value);
    printf("Enter the position: ");
    scanf("%d", &position);
    struct doublyLinkedList *newNode = malloc(sizeof(struct doublyLinkedList)); // Creating the new node
    newNode->value = value;                                                     // Assigning the value, entered by the user.
    newNode->previous = NULL;                                                   // Assigning all the pointers to NULL
    newNode->next = NULL;

    if (head == NULL) // When the list is empty
    {
        head = newNode;
    }
    else
    {
        if (position <= 1)
        { // Inserting at the beginning
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        else
        {
            struct doublyLinkedList *current = head; // Start from the head of the list
            int currentPosition = 1;                 // Variable to keep track of the current position while traversing

            while (current->next != NULL && currentPosition < position - 1)
            {
                current = current->next; // Moving to the next node
                currentPosition++;
            }

            if (current->next == NULL)
            {                                // Insert at the end of the list
                current->next = newNode;     // Set the next pointer of the current node to the new node
                newNode->previous = current; // Set the previous pointer of the new node to the current node
            }
            else
            {                                      // Insert at the desired position
                newNode->next = current->next;     // Set the next pointer of the new node to the next node
                newNode->previous = current;       // Set the previous pointer of the new node to the current node
                current->next->previous = newNode; // Set the previous pointer of the next node to the new node
                current->next = newNode;           // Set the next pointer of the current node to the new node
            }
        }
    }
    printf("Here is the updated list: (From first to last)\n");
    printListBynext(head);
}

void deletion()
{
    if (head == NULL)   // Firstly checks the list is empty or not. 
    {
        printf("List is empty. No nodes to delete.\n");
        return;         // Returns from the function if found empty.
    }

    int position;
    printf("Enter the position: ");
    scanf("%d", &position);

    if (position <= 1)
    { // Delete the first node
        struct doublyLinkedList *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->previous = NULL;
        }
        free(temp); // Deallocating the node
    }
    else
    {
        struct doublyLinkedList *current = head;
        int currentPosition = 1;
        while (current->next != NULL && currentPosition < position)
        {
            current = current->next;
            currentPosition++;
        }

        if (current->next == NULL){ // Delete the last node
            current->previous->next = NULL;
            free(current);
        }
        else{   // Delete the node at the desired position
            // we effectively bypass the current node and link the previous node directly to the next node
            current->previous->next = current->next;        //This line updates the next pointer of the node preceding the current node. 
            current->next->previous = current->previous;    //his line updates the previous pointer of the node following the current node. 
            // Important: 
            // When we write current->previous->next, 
            // it means that we are accessing the next member of the structure pointed to by current->previous. 
            // Similarly, current->next->previous means accessing the previous member of the structure pointed 
            // to by current->next.
            free(current);
        }
    }
    printf("Here is the updated list: (From first to last)\n");
    printListBynext(head);
}

int n;
int main(){
    int selection;
    printf("Enter how many nodes you want: ");
    scanf("%d", &n);
    struct doublyLinkedList *list[n]; // creating the list of type: struct doublyLinkedList
    for (int i = 0; i < n; i++){
        printf("Enter the value at index %d: ", i);
        list[i] = malloc(sizeof(struct doublyLinkedList)); // allocating memory
        scanf("%d", &list[i]->value);
    }
    head = list[0];           // Assigning the head pointer to the first node
    list[0]->previous = NULL; // Assigning the first node's previous pointer to NULL
    list[0]->next = NULL;     // Assigning the first node's next pointer to NULL
    for (int i = 1; i < n; i++) {
        // Correctly assigning the pointers.
        list[i]->previous = list[i - 1];
        list[i]->next = NULL;
        list[i - 1]->next = list[i];
    }

    do{
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

