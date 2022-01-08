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
struct Node* athead(struct Node* head)
{
    struct Node* p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    return head;
}
struct Node* atNode(struct Node* head,int index)
{
    struct Node* p = head;
    struct Node* q = head->next;
    q->prev = p;
    int i =0;
    while(i != index -1)
    {
        p = p->next;
        q = q->next;

    }
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return head;

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
    //n1 = athead(n1);
    n1 = atNode(n1,2);
    doubletraverse(n1);
}