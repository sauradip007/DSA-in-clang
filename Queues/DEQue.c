#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
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
    if (isFull(q))
    {
        printf("\nThe queue is full");
    }
    else
    {
        q->r = q->r + 1;    // incrementing r
        q->arr[q->r] = val; // inserting value of array in queue
    }
} //insert at back

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("\nThe queue is empty");
    }
    else
    {
        q->f++;              // incrementing f
        return q->arr[q->f]; // returns value of int deleted
    }
    return a;
}
void insert_front(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("\nQueue is full");
    }
    if (q->f == -1)
    {
        q->f = 0;
        q->r = 0;
    }
    else if (q->f == 0)
    {
        q->f = q->size - 1;
    }
    else
    {
        q->f = q->f - 1;
    }
    
}
int delete_rear(struct queue* q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("\nQueue underflow");
    }
    int item = q->arr[q->r];
    if(q->f == q->r)
    {
        q->f = -1;
        q->r = -1;
    }
    else if(q->r == 0)
    {
        q->r = q->size - 1;
    }
    else{
        q->r = q->r-1;
    }
    return item;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (isEmpty(&q))
        ;
    {
        printf("\nQueue is empty");
    }
    // enqueue few elements
    enqueue(&q, 12); // passing address to modify value of q in main func
    enqueue(&q, 15);
    enqueue(&q, 17);
    printf("\nDequeueing element %d", dequeue(&q));
    printf("\nDequeueing element %d", dequeue(&q));
}