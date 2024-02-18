#include <iostream>
using namespace std;
int factorail(int);

int main()
{
	int n;
	
	cout<<"Enter the num :";
	cin>>n;
	
	if(n<0)
	{
		cout<<"Dosn't work"<<endl;
		
	}
	
	else
	{
		cout<<"Factorial is : "<<factorail(n)<<endl;
	}	
}

int factorail(int num)
{
	int fact=1;
	
	if(num >= 1)
	{
		fact = num * factorail(num-1);
	}
	 
}
