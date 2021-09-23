#include<iostream>
using namespace std;
int main()
{
	int a;
	char y='y';
	while(y=='y'||y=='Y')
		{
			cout<<"Enter a No.";
			cin>>a;
			if(a%2==0)
			{
				cout<<"\nEven\npress y to repeat\n";
			}
			else
			{
				cout<<"\nOdd\npress y to repeat\n";
			}
			y=0;
			cin>>y;
		}
	return 0;
}