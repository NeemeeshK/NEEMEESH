#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cout<<"Enter a no."<<endl;
    cin>>n;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            cout<<"Entred no. is not a Prime."<<endl;
            return 0;
        }
    }
        cout<<"Entred no. is a Prime."<<endl;
    return 0;
}