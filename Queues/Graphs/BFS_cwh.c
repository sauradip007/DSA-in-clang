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
        q->f++;              // incrementing f
        return q->arr[q->f]; // returns value of int deleted
    }
    return a;
}
int main()
{
    struct queue q;
    q.size = 400;
    q.f=q.r=0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    int i = 0;
    //start from 0
    int visited[7] = {0,1,1,1,0,0,0};//array of nodes it has visited
    int a[7][7] = { {1, 0, 0, 1, 0, 0, 0} ,{1, 1, 0, 1, 1, 0, 0} ,{1, 0, 1, 0, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0}

    }; //adj array
    printf("%d", i);
    visited[i] = 1; //marks which i is visited
    enqueue(&q,i); //for exploration
    while(!isEmpty(&q))
    {
        int node = dequeue(&q);
        for(int j = 0; j < 7;j++)
        {
            if(a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j); //visited
                visited[j] = 1;
                enqueue(&q,j);
            }

        }
    }