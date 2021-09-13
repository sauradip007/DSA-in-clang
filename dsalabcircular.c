#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;//struct node type pointer
};
void linkedlisttraversal(struct Node* head){
    struct Node* ptr = head;
    
    do
    {
        printf(" %d\n", ptr->data);
        ptr = ptr -> next;
    }while(ptr != head);
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
   
    third->next = head;
    linkedlisttraversal(head);
    return 0;
}