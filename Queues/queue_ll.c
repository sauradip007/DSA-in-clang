#include <stdio.h>
#include <stdlib.h>
struct Node *f = NULL;
struct Node *r = NULL;
struct Node
{
    int data;
    struct Node *next; //struct node type pointer
};
void linkedlisttraversal(struct Node *head)
{
    printf("\nPrinting the elements of this linked list : ");
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Elements are : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("queue is full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (f == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{

    enqueue(33);
    enqueue(34);
    enqueue(35);
    linkedlisttraversal(f);
    printf("\nDequeuing element : %d", dequeue());
}