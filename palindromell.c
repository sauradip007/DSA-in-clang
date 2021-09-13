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
struct Node* middle(struct Node* head)
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
    return temp;
}
struct Node* reverse(struct Node* head){
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* nex;
    while(curr != NULL)
    {
        nex = curr->next;
        curr->next = prev;
      
        prev = curr;
        curr = nex;

    }
    return prev;
}

int isPalindrome(struct Node* head)
{
    struct Node* p = head;
   
    struct Node* m = (struct Node*)malloc(sizeof(struct Node));
    
  
    m = middle(head);
    struct Node* q = m->next;
    while( q != NULL)
    {
       
        q = q->next;
    }
    q = reverse(m);
    while(q!= m && p != m)
    {
        if(p->data == q->data)
        {
            return 1;
        }
         else{
            return -1;
        }
        p = p->next;
        q = q->next;
       
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
    second->data = 2;
    
    second->next = third;
    third->data = 3;
   
    third->next = NULL;
    int r = isPalindrome(head);
    printf("%d", r);
    return 0;
}