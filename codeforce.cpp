#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int f1[3];
    int f2[3];
    int j;
    for(int i = 0 ; i < 3 ; i++)
    
    {
        cin>>f1[i]>>f2[i];
    }
       
    int sum[n];
    bool flag;
    for(int i = 0 ; i < 3 ; i++)
    {
        sum[i] = f1[i] + f2[i];
        if(sum[i] == 0)
        {
            flag = true;
        }
        else {
            flag = false;
        }
        
    }
    if(flag = true)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
}