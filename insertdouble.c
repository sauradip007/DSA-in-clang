#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void doubletraverse(struct Node *head)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
}
struct Node* addhead(struct Node*head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return temp;
}
void atTail(struct Node* head , int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    ptr->data = data;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;
   
    
}
void atNode(struct Node* head , int data, int index)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node*  p = head;
    ptr->data = data;
    int i  = 0;
    while(i != index-1)
    {
        ptr = ptr->next;
    }
    ptr->next = p->next;
    p->next->prev = ptr;
    ptr->prev = p;
    
}
int main()
{
    struct Node *n1;
    struct Node *n2;
    struct Node *n3;
    struct Node *n4;
    n1 = (struct Node *)malloc(sizeof(struct Node));
    n2 = (struct Node *)malloc(sizeof(struct Node));
    n3 = (struct Node *)malloc(sizeof(struct Node));
    n4 = (struct Node *)malloc(sizeof(struct Node));
    n1->data = 1;
    n1->next = n2;
    n1->prev = NULL;
    n2->data = 2;
    n2->next = n3;
    n2->prev = n1;
    n3->data = 3;
    n3->next = n4;
    n3->prev = n2;
    n4->data = 4;
    n4->next = NULL;
    n4->prev = n3;
    n1 = addhead(n1,9);
    atTail(n1,8);
    doubletraverse(n1);
}