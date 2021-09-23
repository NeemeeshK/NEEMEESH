#include<iostream>
using namespace std;
int main()
{
    int i,n,sum=0;
    cout<<"Enter last no. upto which sum is required.\n";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        sum=sum+i;
    }
    cout<<sum;
    return 0;
}