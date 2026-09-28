

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create List
void createList()
{
    int n, i, value;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of nodes!\n");
        return;
    }

    head = NULL;

    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("List Created Successfully.\n");
}

// Insert at Beginning
void insertBegin()
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

    printf("Node Inserted Successfully.\n");
}

// Insert at End
void insertEnd()
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Node Inserted Successfully.\n");
}

// Insert at Position
void insertPosition()
{
    int pos, i;
    struct Node *newNode, *temp;

    printf("Enter Position: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid Position!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;

        printf("Node Inserted Successfully.\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position not found!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
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

    printf("Deleted Node = %d\n", temp->data);

    free(temp);
}

// Delete from End
void deleteEnd()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("Deleted Node = %d\n", head->data);

        free(head);
        head = NULL;

        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted Node = %d\n", temp->data);

    free(temp);
}

// Delete by Value
void deleteValue()
{
    int value;
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    printf("Deleted Node = %d\n", temp->data);

    free(temp);
}

// Display List
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    temp = head;

    printf("\nLinked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main Function
int main()
{
    int choice;
    printf("Name : rohan\nRoll No: 25AI101");

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete by Value\n");
        printf("8. Display List\n");
        printf("9. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

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
            display();
            break;

        case 9:
            printf("Program Terminated.\n");
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
