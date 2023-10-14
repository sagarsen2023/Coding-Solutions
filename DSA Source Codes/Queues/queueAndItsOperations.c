#include <stdio.h>
#include <stdlib.h>

// Queue using linked List

struct Queue
{
    int value;
    struct Queue *next;
};

// Define the front and rear pointers
struct Queue *front = NULL;
struct Queue *rear = NULL;

int max, currentLength = 0; // Maximum length of queue

void printQueue(struct Queue *ptr)
{
    printf("Currently the queue is: ");
    while (ptr != NULL)
    {
        printf("%d, ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue()
{
    if (currentLength == max)
    {
        printf("The queue is full.\n");
        return;
    }
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    printf("Enter the value to be added: ");
    scanf("%d", &newNode->value);
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    currentLength++;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("The queue is empty.\n");
        return;
    }

    struct Queue *temp = front;
    front = front->next;
    free(temp);
    currentLength--;
}

int main()
{
    printf("Enter the maximum length of the queue: ");
    scanf("%d", &max);

    int selection;
    printf("Enter your selection (1: Enqueue, 2: Dequeue, 3: Print, 0: Exit): ");
    
    while (1)
    {
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printQueue(front);
            break;
        case 0:
            exit(0);
        default:
            printf("Wrong Input. Try again.\n");
            break;
        }
        printf("Enter your selection (1: Enqueue, 2: Dequeue, 3: Print, 0: Exit): ");
    }

    return 0;
}


// You can create it using arrays also.
