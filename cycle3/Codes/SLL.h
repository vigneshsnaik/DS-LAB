#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *next;
    int data;
} Node;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
int isEmpty(Node *Head)
{
    if (Head == NULL)
        return 1;
    return 0;
}
int insertAtBack(Node *Head, int data)
{
    Node *n = createNode(data);
    Node *temp = Head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    return n->data;
}

int insertAtFront(Node *Head, int data)
{
    Node *n = createNode(data);
    n->next = Head->next;
    Head->next = n;
    return n->data;
}

int insertAtPosition(Node *Head, int data, int pos)
{
    int i;
    Node *n = createNode(data);
    Node *temp = Head;
    for (i = 1; i < pos; i++)
        if (temp->next != NULL)
            temp = temp->next;
    n->next = temp->next;
    temp->next = n;
    return n->data;
}

int deleteFromBack(Node *Head)
{
    if (isEmpty(&*Head))
        return 0;
    Node *temp = Head;
    while (temp->next->next != NULL)
        temp = temp->next;
    Node *del = temp->next;
    temp->next = NULL;
    int val = del->data;
    free(del);
    return val;
}

int deleteFromFront(Node *Head)
{
    if (isEmpty(&*Head))
        return 0;
    Node *del = Head->next;
    Head->next = Head->next->next;
    int val = del->data;
    free(del);
    return val;
}

int deleteFromPosition(Node *Head, int pos)
{
    if (isEmpty(&*Head))
        return 0;
    int i;
    Node *temp = Head;
    for (i = 1; i < pos; i++)
        if (temp->next != NULL)
            temp = temp->next;
    Node *del = temp->next;
    temp->next = temp->next->next;
    int val = del->data;
    free(del);
    return val;
}
