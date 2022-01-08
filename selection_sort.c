#include<stdio.h>
void selectsort(int a[], int n)
{
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j =i+1 ; j < n ; j++)
        {
            if(a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
int main()
{
    printf("\nEnter size of array : ");
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    printf("\nEnter array : ");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &a[i]);
    }
    selectsort(a,n);
    printf("\nSorted array is : ");
    for(int i = 0; i < n ; i++)
    {
        printf("\t%d", a[i]);
    }
}