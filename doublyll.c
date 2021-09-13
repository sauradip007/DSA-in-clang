#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
void insertAtTail(struct Node* head)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;

    }
    temp->next = p;
    p->prev = temp;
}