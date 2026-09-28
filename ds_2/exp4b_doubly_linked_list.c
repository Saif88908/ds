// Name : Rohan
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Helper: safely read an integer, clears bad input if user types garbage
int readInt(int *value)
{
    if (scanf("%d", value) != 1)
    {
        printf("Invalid input! Please enter a number.\n");
        while (getchar() != '\n')
            ; // clear leftover bad input from buffer
        return 0;
    }
    return 1;
}

// Helper: free the entire existing list (used before re-creating)
void freeList()
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Create List
void createList()
{
    int n, i, value;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    if (!readInt(&n))
        return;
    if (n <= 0)
    {
        printf("Invalid number of nodes!\n");
        return;
    }

    // Free old list first to avoid memory leak if list already exists
    if (head != NULL)
        freeList();

    head = NULL;
    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        if (!readInt(&value))
        {
            free(newNode);
            return;
        }
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    printf("List Created Successfully.\n");
}

// Insert at Beginning
void insertBegin()
{
    struct Node *newNode;
    int value;

    printf("Enter data: ");
    if (!readInt(&value))
        return;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    printf("Node Inserted Successfully.\n");
}

// Insert at End
void insertEnd()
{
    struct Node *newNode, *temp;
    int value;

    printf("Enter data: ");
    if (!readInt(&value))
        return;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node Inserted Successfully.\n");
}

// Insert at Position
void insertPosition()
{
    int pos, i, value;
    struct Node *newNode, *temp;

    printf("Enter Position: ");
    if (!readInt(&pos))
        return;
    if (pos <= 0)
    {
        printf("Invalid Position!\n");
        return;
    }
    if (pos == 1)
    {
        insertBegin();
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Position not found!\n");
        return;
    }

    printf("Enter data: ");
    if (!readInt(&value))
        return;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("Node Inserted Successfully.\n");
}

// Delete from Beginning
void deleteBegin()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted Node = %d\n", temp->data);
    free(temp);
}

// Delete from End
void deleteEnd()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    temp = head;
    if (temp->next == NULL)
    {
        printf("Deleted Node = %d\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    printf("Deleted Node = %d\n", temp->data);
    free(temp);
}

// Delete by Value
void deleteValue()
{
    int value;
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    printf("Enter value to delete: ");
    if (!readInt(&value))
        return;

    temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }
    if (temp == head)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }
    printf("Deleted Node = %d\n", temp->data);
    free(temp);
}

// Display Forward
void displayForward()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    temp = head;
    printf("\nForward List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display Reverse
void displayReverse()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("\nReverse List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main Function
int main()
{
    int choice;
    printf("Name : Rohan\nRoll No: 25AI101");
    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete by Value\n");
        printf("8. Display Forward\n");
        printf("9. Display Reverse\n");
        printf("10. Exit\n");
        printf("Enter Choice: ");

        if (!readInt(&choice))
            continue;

        switch (choice)
        {
        case 1:
            createList();
            break;
        case 2:
            insertBegin();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            insertPosition();
            break;
        case 5:
            deleteBegin();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deleteValue();
            break;
        case 8:
            displayForward();
            break;
        case 9:
            displayReverse();
            break;
        case 10:
            printf("Program Terminated.\n");
            freeList();
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
