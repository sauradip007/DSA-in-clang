#include<stdio.h>
int main()
{
    int a[3][3],i , j , k , c = 0;
    printf("\nEnter elements :  ");
    for(i = 0 ; i < 3 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if(a[i][j] != 0)
            {
                c++;
            }
        }
    }
    int b[i][j];
    for(i = 0 ; i < 3 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            if(a[i][j] != 0)
            {
                b[0][k] = i;
                b[1][k] = j;
                b[2][k] = a[i][j];
            }
        }
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            printf("%d", b[i][j]);
        }
        printf("\n");
    }
    

}