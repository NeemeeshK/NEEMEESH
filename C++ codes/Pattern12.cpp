#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a no.";
    cin>>n;
    for(int i=1;i<=n;i++)           //ROW
    {
        for(int j=1;j<=2*n-1;j++)   //Column
        {
            if(j<=n-i || j>=n+i)
            cout<<" ";
            else
            {
                if(j>=n)
                {
                    cout<<j-n+1;
                }
                else
                    cout<<n-j+1;
            }
        }
        cout<<endl;
    }
    return 0;
}