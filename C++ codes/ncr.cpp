#include<iostream>
using namespace std;
int factorial (int num)
{
    int temp=1;
    for(int i=2;i<=num;i++)
    {
        temp=temp*i;
    }
    return temp;
}
int main()
{
    int n,r;
    cin>>n>>r;
    cout<<(factorial(n)/(factorial(r)*factorial(n-r)));
    return 0;
}