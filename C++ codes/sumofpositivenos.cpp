#include<iostream>
using namespace std;
int main()
{
    int n,sum=0;
    cout<<"Enter a no.:";
    cin>>n;
    while(n>=0)
    {
        sum=sum+n;
        cout<<"Enter a no.:";
        cin>>n;
    }
    cout<<"Sum of positive nos. entered="<<sum;
    return 0;
}