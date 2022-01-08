#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *head)
{
    struct Node* ptr = head;
    /*printf( "%d", ptr->data);
    ptr = ptr -> next;
    while(ptr!= head)
    {
        printf( "%d", ptr->data);
        ptr = ptr -> next;
    }*/
    do
    {
        printf("%d", ptr->data);
        ptr = ptr->next;

    } while (ptr != head);
}
struct Node* insertAtFirst(struct Node* head , int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p=(struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    p = head->next;
    while(p->next != head)//moves till the last node
    {
        p= p->next;

    }
    //At this point p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    return head;

}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;

    head->next = second;
    second->data = 2;

    second->next = third;
    third->data = 3;

    third->next = NULL;
    head = insertAtFirst(head,80);
    linkedlisttraversal(head);
}