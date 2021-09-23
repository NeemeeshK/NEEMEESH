#include<iostream>
using namespace std;
int main()
{
    float a,b;
    float c;
    char op;
    cout<<"Enter two nos."<<endl;
    cin>>a>>b;
    cout<<"Choose an operand"<<endl;
    cin>>op;
    switch(op)
    {
        case '+':
        cout<<a<<"+"<<b<<"="<<a+b<<endl;
        break;
        case '-':
        c=a-b;
        cout<<a<<"-"<<b<<"="<<c<<endl;
        break;
        case '*':
        c=a*b;
        cout<<a<<"*"<<b<<"="<<c<<endl;
        break;
        case '/':
        c=a/b;
        cout<<a<<"/"<<b<<"="<<c<<endl;
        break;
        case '%':
        c=int(a)%int(b);
        cout<<a<<"%"<<b<<"="<<c<<endl;
        break;
        default :
        cout<<"Operator not found"<<endl;
        break;
    }
    return 0;
}