#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;//struct node type pointer
};
struct Node* removedup(struct Node* head)
{
    struct Node*  p = head;
    struct Node* q = head->next;
    while(p->data != q-> data)
    {
        p = p->next;
        q = q->next;
    }
    if(p->data == q->data)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
void linkedlisttraversal(struct Node* head)
{
    struct Node* p = head;
    while(p!=NULL)
    {
        printf("\t%d", p->data);
        p = p->next;
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
    third->data = 3 ;
   
    third->next = NULL;
    head = removedup(head);
    printf("\n After : \n");
    linkedlisttraversal(head);

    return 0;
}