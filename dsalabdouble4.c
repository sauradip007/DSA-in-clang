#include<stdio.h>
#include<stdlib.h>
struct Node{ 
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* deleteAtHead(struct Node* head)
{
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node* deleteAtTail(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct Node* deleteAtValue(struct Node* head , int value)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->data != value && q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value)
    {
        p->next = q->next;
        free(q);

    }
   
    return head;
}
void doubletraverse(struct Node* head)
{
    
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct Node* n1;
    struct Node* n2;
    struct Node* n3;
    struct Node* n4;
    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n4 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = 1;
    n1->next = n2;
    n1->prev = NULL;
    n2->data = 2;
    n2->next = n3;
    n2->prev= n1;
    n3->data = 3;
    n3->next = n4;
    n3->prev = n2;
    n4->data = 4;
    n4->next = NULL;
    //n1 = deleteAtTail(n1);
    //n1 = deleteAtValue(n1,3);
    n1 = deleteAtHead(n1);
    
    doubletraverse(n1);
}