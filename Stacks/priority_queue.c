#include<stdio.h>
#include<stdlib.h>
struct node{
    int priority;
    int info;
    struct node* link;
}*front = NULL;
int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert(int item, int priority)
{
    struct node* tmp,*p;
    tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("\nNo memory available");
        return;
    }
    tmp->info = item;
    tmp->priority = priority;
    if(isEmpty() || priority < front->priority)
    {
        tmp->link = front;
        front = tmp;
    }
    else{
        p = front;
        while(p->link != NULL && p->link->priority <= priority)
        {
            p = p->link;
            tmp->link = p->link;
            p->link = tmp;
        }
    }
}
int del()
{
    struct node* tmp;
    int item;
    if(isEmpty())
    {
        printf("\nQueue undeflow");
    }
    else{
        tmp = front;
        item = tmp->info;
        front = front->link;
        free(tmp);
    }
    return item;
}

void display()
{
    struct node* ptr;
    ptr = front;
    if(isEmpty())
    {
        printf("\nQueue is empty");
    }
    else{
        printf("\nQueue is : \n");
        while(ptr != NULL)
        {
            printf("\n%d", ptr->priority,ptr->info);
            ptr = ptr->link;
        }
    }
}
int main()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    insert(1,5);
    insert(2,4);
    insert(3,3);
    insert(4,2);
    insert(5,1);
    del();
    display();
    // int choice,item,priority;
    // while(1)
    // {
    //     printf("\n1. Insert\n");
    //     printf("\n2. Delete\n");
    //     printf("\n3. Display\n");
    //     printf("\n4. Quit");
    //     printf("\nEnter choice : ");
    //     scanf("%d", &choice);
    //     switch(choice)
    //     {
    //         case 1:
    //         printf("\nEnter item to be added");
    //         scanf("%d", &item);
    //         printf("\nEnter priority");
    //         scanf("%d", &priority);
    //         insert(item,priority);
    //         break;
    //         case 2:
    //         printf("\nDeleted item is %d\n", del());
    //         break;
    //         case 3:
    //         display();
    //         break;
    //         case 4:
    //         exit(1);
    //         default:
    //         printf("\nWrong choice");

    //     }
    // }
}