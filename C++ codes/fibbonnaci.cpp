#include<iostream>
#include<math.h>
using namespace std;
void fib(int a)
{
    int next=0,t1=0,t2=1;
    for(int i=1;i<=a;i++)
    {
        cout<<t1<<endl;
        next=t1+t2;
        t1=t2;
        t2=next;
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    fib(n);
    return 0;
}