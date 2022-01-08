#include <stdio.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int a[], int start, int end)
{
    int count_smaller = 0;
    int k = start;
    int pivot = a[k];
    for (int i = k + 1; i <= end; i++)
    {
        if (a[i] < pivot)
        {
            count_smaller++;
        }
    }
    int index = k + count_smaller;
    swap(a, k, index);

    while (k < index && index < end)
    {
        if (a[k] <= pivot)
        {
            k++;
        }
        if (a[end] > pivot)
        {
            end--;
        }

        else
        {
            swap(a, k, end);
            k++;
            end--;
        }
    }

    return index;
}

void quicksort(int a[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int p = partition(a, start, end);
    quicksort(a, start, p - 1);
    quicksort(a, p + 1, end);
}
int main()
{
    int a[7] = {5, 9, 8, 3, 2, 7, 1};
    quicksort(a, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        printf("\t%d",a[i]);
    }
    printf("\n");
}