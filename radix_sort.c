#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
}*start = NULL;
int largedig()
{
    struct node* p = start;
    int large = 0;
    int las_dig = 0;
    // To find digits in largest element
    while(p!= NULL)
    {
        if(p->info > large)
        {
            large = p->info;
        }
        p = p->link;
    }
    while(large != 0)
    {
        las_dig++;
        large = large/10;
    }
    return las_dig;

}
// Returns kth digit of given no
int digit(int number, int k)
{
    int digit;
    for(int i = 1; i <= k;i++)
    {
        digit = number%10;
        number = number/10;
    }
    return digit;
}
void radix()
{
    int i ,k,dig,lsd,msd;

    struct node*p, *rear[10],*front[10];
    lsd = 1;
    msd = largedig(start);
    for(k= lsd ; k <=msd ; k++)
    {
        for(int i = 0; i <=9 ; i++)
        {
            rear[i] = NULL;
            front[i] = NULL;
        }
        for(p = start ; p != NULL; p=p->link)
        {
            dig = digit(p->info,k);
            if(front[dig] == NULL)
            {
                front[dig] = p;
            }
            else{
                rear[dig]->link = p;
            }
                rear[dig] = p;
           

        }
        i= 0;
        while(front[i] == NULL)
        {
            i++;
        }
            start = front[i];
        
        while(i < 9)
        {
            if(rear[i+1] != NULL)
            {
                rear[i]->link = front[i+1];
            }
            else{
                rear[i+1] = rear[i];
            }
            i++;
        }
        rear[9]->link = NULL;
    }
}
int main()
{
    struct node* temp,*q;
    int i , n , item;
    printf("\nEnter no of elements in list ");
    scanf("%d", &n);
    for(int i = 0; i < n ; i++)
    {
        printf("\nEnter element %d : ",i+1);
        scanf("%d", &item);
        // Making the LL
        temp = malloc(sizeof(struct node));
        temp->info = item;
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
        }
        else{
            q = start;
            while(q->link != NULL)
            {
                q = q->link;
            }
            q->link = temp;
        }

    }
    radix();
    printf("\nSorted list is : ");
    q = start;
    while(q != NULL)
    {
        printf("%d", q->info);
        q = q->link;
    }
}