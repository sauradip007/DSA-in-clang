#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* addtoempty(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
struct Node* addtoEmpty(struct Node* head , int data)
{
    struct Node* newP = (struct Node*)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = NULL;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newP;
    return head;
}
void linkedlisttraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Elements are : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node* insert(struct Node* head , int data)
{
    struct Node* newP = (struct Node*)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = NULL;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    int key = data;
    if(head == NULL || key < head->data)
    {
        newP->next = head;
        head = newP;
    }
    else{
    while(temp->next != NULL && temp->next->data < key)
    {
        temp = temp->next;
    }
    newP->next = temp->next;
    temp->next  = newP;
    }
    return head;
    
}