#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void makeCycle(struct Node* head , int pos)
{
    struct Node* temp = head;
    struct Node* startNode;
    int count = 1;
    while(temp->next !=NULL)
    {
        if(count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
bool detectCycle(struct Node* head)
{
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }

    }
    return false;

}
void removeCycle(struct Node* head)
{
    struct Node* slow = head;
    struct Node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next;
    }while(slow != fast);
    fast = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;//removes cycle
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
    struct Node* fourth;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
   
    head->next = second;
    second->data = 3;
    
    second->next = third;
    third->data = 5 ;
   
    third->next = fourth;
    fourth->data = 7;
    fourth->next = NULL;
    makeCycle(head,2);
    //linkedlisttraversal(head);
    //bool x = detectCycle(head);
    //printf("\n%d", x);
    removeCycle(head);
    bool x = detectCycle(head);
    printf("\n%d", x);
    linkedlisttraversal(head);
   
}