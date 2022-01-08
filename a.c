#include <stdio.h>
#include <stdlib.h>
void bubblesort(int a[], int n)
{
    if(n <= 1)
    {
        return;
    }
    bubblesort(a+1,n-1);
    for(int i = 0; i < n ; i++)
    {
    if(a[i] > a[i+1])
    {
       int temp = a[i];
       a[i] = a[i+1];
       a[i+1] = temp;
    }
    }
}
int main()
{
    int n;

    printf("\nEnter n : ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("\nEnter array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubblesort(a,n);
    printf("\nBubble sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }

    return 0;
}