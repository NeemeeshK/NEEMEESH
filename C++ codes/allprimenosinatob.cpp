#include<iostream>
using namespace std;
int main()
{
    int a,b,i,j;
    cout<<"Enter starting of Range."<<endl;
    cin>>a;
    cout<<"Enter ending of Range."<<endl;
    cin>>b;
    for(i=a;i<=b;i++)
    {
         for(j=2;j<i;j++)
    {
        if(i%j==0)
        {
            break;
        }
    }
    if(j==i)
    {
    cout<<i<<endl;
    }
    }
    return 0;
}
