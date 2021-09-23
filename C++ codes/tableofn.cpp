#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a no. of which table is required.\n";
    cin>>n;
    for(int i=1;i<=10;i++)
    {
        cout<<n<<"*"<<i<<"="<<n*i<<endl;

    }
    return 0;
}