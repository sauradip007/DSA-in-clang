#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Elements are : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void merge(struct Node* head1, struct Node* head2)
{
    struct Node *p1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p3 = (struct Node *)malloc(sizeof(struct Node));
    p1 = head1;
    p2 = head2;
    struct Node *dummyNode = (struct Node *)malloc(sizeof(struct Node));
    dummyNode->data = -1;
    p3 = dummyNode;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while(p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummyNode->next;
}