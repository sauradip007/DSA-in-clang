#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q)
{
    if(q->r == q->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("\nThe queue is full");
    }
    else{
        q->r = q->r+1;//incrementing r
        q->arr[q->r] = val;//inserting value of array in queue
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("\nThe queue is empty");
    }
    else
    {
        q->f++;    //incrementing f
        return q->arr[q->f]; //returns value of int deleted
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    if(isEmpty(&q));
    {
        printf("\nQueue is empty");
    }
    //enqueue few elements
    enqueue(&q,12); //passing address to modify value of q in main func
    enqueue(&q, 15);
    enqueue(&q, 17);
    printf("\nDequeueing element %d", dequeue(&q));
    printf("\nDequeueing element %d", dequeue(&q));
}