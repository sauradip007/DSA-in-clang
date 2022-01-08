#include<stdio.h>
#include<stdlib.h>
#define MAX_VAL 9999
void restoreUp(int arr[], int i)
{
    int k = arr[i];
    int parent = i/2;
    while(arr[parent] < k)
    {
        arr[i] = arr[parent];
        i = parent;
        parent = i/2;
    }
    arr[i] = k;
}
void insert(int num, int arr[], int *hsize)
{
    (*hsize)++; //increasing heap size 
    arr[*hsize] = num;//inserting num into the last array space
    restoreUp(arr,*hsize);//restoring array value
}
void restoreDown(int arr[], int i , int hsize)
{
    int lchild = 2*i;
    int rchild = 2*i + 1;
    int num = arr[i]; //stores position of root element
    while(rchild <= hsize)
    {
        if(num >= arr[lchild] && num >= arr[rchild])
        {
            arr[i] = num;
            return;//if its greater than both children return nothing
        }
        else if(arr[lchild] > arr[rchild])
        {
            arr[i] = arr[lchild];
            i = lchild;
        }
        else{
            arr[i] = arr[rchild];
            i = rchild;
        }
        lchild = 2*i;
        rchild = lchild + 1;
    }
    if(lchild == hsize && num < arr[lchild])
    {
        arr[i] = arr[lchild];
        i = lchild;
    }
    arr[i] = num;


}
int delroot(int arr[], int *hsize)
{
    int max = arr[1]; //Stores element at max
    arr[1] = arr[*hsize]; //last element takes its place
    (*hsize)--;
    restoreDown(arr,1,*hsize);
    return max; //element deleted is returned
}
void display(int arr[], int hsize)
{
    int i;
    if(hsize == 0)
    {
        printf("\nHeap is empty");
    }
    for(int i =1 ; i <=hsize;i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("\nThe number of elements are : %d\n",hsize);
}
void buildHeap(int arr[], int size)
{
    for(int i = 2 ; i <= size ; i++)
    {
        restoreUp(arr,i);
    }
}
void heapsort(int arr[], int size)
{
    int max;
    buildHeap(arr,size);
    printf("\nThe initial heap is : \n");
    display(arr,size);
    while(size > 1)
    {
        max = delroot(arr,&size);
        arr[size+1] = max;
    }

}

int main()
{
    int arr[100];
    int hsize = 0;
    int i,choice,num;//num is element to be inserted
    arr[0] = MAX_VAL;
    printf("\nEnter number of elements to be inserted : ");
    scanf("%d", &hsize);
    printf("\nEnter array : ");
    for(int i = 1; i <= hsize; i++)
    {
        scanf("%d", &arr[i]);
    }
    buildHeap(arr,hsize);
    heapsort(arr,hsize);
    

    // printf("\nEnter element to be inserted : ");
    // scanf("%d", &num);
    
    // insert(num,arr,&hsize);
    // printf("\nDeleting an element : %d", delroot(arr,&hsize));
    display(arr,hsize);

}