#include <stdio.h>
#include <stdlib.h>
struct DLL // double linked list
{
    int data;
    struct DLL *next;
    struct DLL *prev;
} *first = NULL, *last = NULL;
typedef struct DLL node; // we created here one node
int count = 0;
void insert();
void del();
void display();
void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void search();
int main()
{
    int ch; // c-> choice
    for (;;)
    {
        printf("Dobly linked list:\n");
        printf("1.insert\n2.delete\n3.display\n4.search\n5.exit");
        printf("enter your choice");
        scanf("%d", &ch);
        switch (ch) // we taken heare one switch case ( i have applyed all the operarions)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            exit(0);
        }
    }
}
void insert()
{
    int c; // c --> choice
    for (;;)
    {
        printf("1.insert at front\n2.insert at rear\n 3.display\n 4.return "); // apply all the operations
        printf("enter your choice");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert_front();
            break;
        case 2:
            insert_rear();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        }
    }
}
void del()
{
    int c; // c-->choice
    for (;;)
    {
        printf("1.delete at front\n2.delete at rear\n 3.display\n 4.return "); // apply all the operations
        printf("enter your choice");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            delete_front();
            break;
        case 2:
            delete_rear();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        }
    }
}
void insert_front()
{
    node *newnode;                          // create one new node
    newnode = (node *)malloc(sizeof(node)); // allocating the memory location
    printf("enter data");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }
}
void insert_rear()
{
    node *newnode;                          // create one new node
    newnode = (node *)malloc(sizeof(node)); // allocating the memory location
    printf("enter data");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        newnode->prev = last;
        last->next = newnode;
        last = newnode;
    }
}
void display()
{
    if (first == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        node *temp = first;
        printf("forwad directional display");
        while (temp)
        {
            printf("\n %d", temp->data);
            temp = temp->next;
        }
        temp = last;
        printf("backward directional display");
        while (temp)
        {
            printf("\n %d", temp->data);
            temp = temp->prev;
        }
    }
}
void delete_front()
{
    if (first == NULL)
    {
        printf("linked list is empty");
        return;
    }
    else
    {
        node *temp = first;
        if (temp->next == NULL)
        {
            printf("%d deleted ", temp->data);
            first = NULL;
            return;
        }
        else
        {
            first = first->next;
            first->prev = NULL;
            printf("%d deleted", temp->data);
            free(temp);
            return;
        }
    }
}
void delete_rear()
{
    if (first == NULL)
    {
        printf("linked list is empty");
        return;
    }
    else
    {
        node *temp = first;
        if (temp->next == NULL)
        {
            printf("%d deleted ", temp->data);
            first = NULL;
            return;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            node *secondlast = temp->prev;
            secondlast->next = NULL;
            printf("%d deleted", temp->data);
            free(temp);
            return;
        }
    }
}
void search()
{
    if (first == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        int s, c = 0; // c --> index,  s --> for serching the elemnets
        node *temp = first;
        printf("enter the element to search");
        scanf("%d", &s);
        while (temp)
        {
            if (temp->data == s)
            {
                printf("item found %d position", ++c);
                break;
            }
            ++c;
            temp = temp->next;
        }
    }
}