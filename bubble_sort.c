#include <stdio.h>
#include<stdlib.h>
void bubblesort(int arr[], int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    
    printf("\nEnter n : ");
    scanf("%d",&n);
    int *a = (int*)malloc(n*sizeof(int));
    printf("\nEnter array : ");
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&a[i]);
    }
    bubblesort(a, 6);
    printf("\nBubble sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    return 0;
}
