#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;//struct node type pointer
};
void linkedlisttraversal(struct Node* head){
    struct Node* ptr = head;
    while(ptr!= NULL)
    {
        printf("Elements are : %d\n", ptr->data);
        ptr = ptr -> next;
    }
}
struct Node* insertAtHead(struct Node * head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    
    ptr->next = head;
    ptr->data  = data;
    
    return ptr; //another alternative could have been ptr = head; followed by return head
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
    ptr->next = p->next;//initial next node p was pointing to
    p->next = ptr;
    return head;
}
struct Node* insertAtTail(struct Node* head , int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node*  p = head;
    while(p -> next  != NULL)
    {
         
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node* insertAfterNode(struct Node* head ,struct Node* prevnode, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr -> next = prevnode->next;
    prevnode->next = ptr;
    return head;

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
    linkedlisttraversal(head);
    head = insertAtHead(head, 55);
    printf("\nElements after insertion at head : \n");
    linkedlisttraversal(head);
    head = insertAtNode(head , 56, 2);
    printf("\nElements after insertion at index : \n");
    linkedlisttraversal(head);
    printf("\nElements after insertion at end : \n");
    head = insertAtTail(head, 57);
    linkedlisttraversal(head);
    printf("\nElements after insertion after a node entered : \n");
    head = insertAfterNode(head, second, 50);
    linkedlisttraversal(head);
    

    return 0;
}