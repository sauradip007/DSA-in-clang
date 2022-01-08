#include<stdio.h>
int main()
{
    int n;
        int a[6] = {10,2,3,7,8,6};
   int i = 0;
   while(i < 6)
   {
       if(a[i] % 2 != 0)
       {
           i++;
           continue;
       }
       
       
       printf("%d" , a[i]);
       i++;
   }
   return 0;
    
    
}