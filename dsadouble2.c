#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
void insertAtTail(struct Node* head , int data)
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    struct Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;

}
struct Node* insertAtNode(struct Node* head , int data , int index)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while(i != index-1)
    {
        p = p->next;
        i++;
  
    
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
void traverse(struct Node* head)
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
    //insertAtTail(n1,30);
    n1 = insertAtNode(n1,20,2);
    traverse(n1);
}