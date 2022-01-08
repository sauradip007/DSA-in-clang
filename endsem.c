#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next; // struct node type pointer
};
void func(struct Node *start)
{
    if(start == NULL)
    {
        return;
    }
   
    
        printf("% d", start->data);
    
    func(start->next);
    printf("% d", start->data);
}
void fun(struct Node * start)
{
    if (start == NULL)
        return;
    if (start->next != NULL)
    {
        fun(start->next->next);
    }
    
    printf("\t %d '->' ", start->data);
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
   fifth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 11;

    head->next = second;
    second->data = 15;

    second->next = third;
    third->data = 25;

    third->next =fourth;
    fourth->data = 50;
    fourth->next = fifth;
    fifth->data = 87;
    fifth->next = NULL;
    func(head);

}