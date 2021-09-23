#include<iostream>
using namespace std;
class primeornot
{
    public:
    int i,j;
	primeornot(int a, int b)
	{
		for(i=a;i<=b;i++)
    	{
      	   for(j=2;j<i;j++)
    		{
        		if(i%j==0)
        		{
            		break;
        		}
    		}
    		if(j==i)
    		{
    			cout<<i<<endl;
    		}
    	}
	}
};
int main()
{
	int x,y;
	cout<<"Enter starting no. of range from which to find prime no."<<endl;
	cin>>x;
	cout<<"Enter ending no. of range from which to find prime no."<<endl;
	cin>>y;
    cout<<"\n";
	primeornot obj1(x,y);
    return 0;
}