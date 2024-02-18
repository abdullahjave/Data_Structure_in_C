#include <iostream>
using namespace std;
int factorail(int);

int main()
{
	int n;
	cout<<"Enter the Number "<<endl;
	cin>>n;
	if (n!=0)
	{
		cout<<"Fact is : "<<factorail(n);
	}	
	else
	{
	cout<<"Can't run"<<endl;
	}
}

int factorail(int num)
{
	int fact=1;
	
	if(num == 1)
	{
		return 1;
	}
	else
	{
		for(int i=num ; i<1 ; i--)
		{
			fact = i * factorail(num-1);
		}
		return fact;
	}
}
