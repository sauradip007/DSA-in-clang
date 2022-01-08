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
void sort(struct Node* head)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    int temp;
    ptr = head;
    while(ptr->next != NULL)
    {
        curr = ptr->next;
        while(curr!=NULL)
        {
            if(ptr->data > curr->data)
            {
                temp = ptr->data;
                ptr->data = curr->data;
                curr->data = temp;

            }
            curr = curr->next;
        }
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head->data = 4;

    head->next = second;
    second->data = 3;

    second->next = third;
    third->data = 5;

    third->next = NULL;
    sort(head);
    linkedlisttraversal(head);
}