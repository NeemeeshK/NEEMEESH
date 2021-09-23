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
    int n,f;
    cin>>n;
    f=factorial(n);
    cout<<"Factorial of "<<n<<" = "<<f;
    return 0;
}