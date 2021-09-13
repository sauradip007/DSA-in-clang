#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int length (struct Node* head)
{
    int l  = 0;
    struct Node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
int middle(struct Node* head)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    int count = 0;
    int l = length(head);
    while(temp->next != NULL && count != l/2)
    {
        temp = temp->next;
        count++;
    }
    return temp->data;
}
void traverse(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

}
int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
   
    head->next = second;
    second->data = 3;
    
    second->next = third;
    third->data = 5 ;
   
    third->next = NULL;
  
    int mid = middle(head);
    printf("Middle element is : %d", mid);
    return 0;


}