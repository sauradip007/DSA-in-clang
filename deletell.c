
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
struct Node* deleteAtHead(struct Node* head)
{
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node* deleteBetween(struct Node* head , int index)
{
    struct Node* p = head;
    struct Node* q = head ->next;
    for(int i = 0 ; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next; //p's next made to q's next after deletion once q reaches desired index
    free(q);
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
    printf("\nElements before : \n");
    linkedlisttraversal(head);

    /*head = deleteAtHead(head);
    
    printf("\nElements after : \n");
    linkedlisttraversal(head);*/

    /*head = deleteBetween(head, 1);
    printf("\nElements after : \n");
    linkedlisttraversal(head);*/
    /*head = deleteAtTail(head);
    printf("\nElements after : \n");
    linkedlisttraversal(head);*/
    head = deleteAtValue(head , 3);
    printf("\nElements after : \n");
    linkedlisttraversal(head);

        


    return 0;
}
