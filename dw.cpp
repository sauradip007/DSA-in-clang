#include<iostream>
using namespace std;

int main()
{
    int x;
    int &p = x;
    x = 25;
    cout<<p--<<" "<<x;

}