#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int linktraverse(struct Node* head)
{
    struct Node* p = head;
    int nodes = 0;
    while(p != NULL)
    {
        p = p->next;
        nodes++;
    }
    return nodes;
}
struct Node* swapk (struct Node* head, int k)
{
    struct Node* p = head;
    struct Node* q = head->next;
    int count = 0;
    int nodes = linktraverse(head);
    while(count != k)//traversing p till the kth node
    {
        p = p->next;
        count++;
        }
    int r =  nodes - k;
    int count2 = 0;
    while( count2 != r)
    {
        q = q->next;
        count2++;
    p->next = q->next;
    
}