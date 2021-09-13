#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next
};
void intersec(struct Node* head1 , struct Node* head2, int pos)
{
    struct Node* temp1 = head1;
    pos--;
    while(pos--)
    {
        temp1 = temp1->next;
    }
    struct Node* temp2 = head2;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;

}
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
int intersect(struct Node* head1 , struct Node* head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr2 = (struct Node*)malloc(sizeof(struct Node));
    //ptr1->data = data;
    //ptr2->data = data;
    if(l1 >l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d  = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(d)
    {
        if(ptr1 == NULL)
        {
            return -1;
        }
        
        ptr1 = ptr1->next;
        d--;
    }
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }
    return -1;

}
int main()
{
    struct Node* head1;
    struct Node* head2;
    struct Node* second2;
    struct Node* third2;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    head1 = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    head2 = (struct Node*)malloc(sizeof(struct Node));
    second2 = (struct Node*)malloc(sizeof(struct Node));
    third2 = (struct Node*)malloc(sizeof(struct Node));
    head1->data = 1;
   
    head1->next = second;
    second->data = 3;
    
    second->next = third;
    third->data = 5 ;
   
    third->next = fourth;
    fourth->data = 7;
    fourth->next = NULL;
    head2 ->data = 2;
    head2->next = second2;
    second2->data = 5;
    second2->next = third2;
    third2->data = 6;
    third2->next = NULL;
    //linkledlisttraversal(head);
    intersec(head1,head2,3);
    int r = intersect(head1,head2);
    printf("%d", r);

    return 0;
}
