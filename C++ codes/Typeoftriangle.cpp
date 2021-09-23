#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter 3 sides of Triangle.\n";
    cin>>a>>b>>c;
    if(a+b>c && b+c>a && c+a>b)
    {
    if(a==b==c)
    {
         cout<<"Equilateral Triangle.\n";
    }
    else if(a==b || b==c || c==a)
            {
                 cout<<"Isosceles Triangle.\n";
            }
            else
            {
                 cout<<"Sclene Triangle.\n";
            }
    }
    else
    {
         cout<<"No such triangle exists.\n";
    }
    return 0;

}