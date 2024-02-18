// binary Search 

#include <iostream>
using namespace std;



int main()
{
	int mid,front,loc,last,temp,n,data;
	bool found = false;
	cout<<"Enter the Array Size : ";
	cin>>n;
	cout<<endl;
	
	int arr[n];
	
	for(int i=0 ; i<n ; i++)
	{
		cout<<"Enter Data sort : "<<i+1<<" : ";
		cin>>arr[i];	 
	}
	
//	for(int i=0 ; i<n-1 ; i++)
//	{
//		if(arr[i]>arr[i+1])
//		{
//		temp = arr[i];
//		arr[i] = arr[i+1];
//		arr[i+1] = temp;
//	}}
	
	for(int i=0 ; i<n ; i++)
	{
		cout<<"Data : "<<i+1<<" : "<<arr[i]<<endl;
	}
	
	
	front = 0 ;
	last = n-1;
	loc = -1;
	cout<<"Enter search Data : ";
	cin>>data;
	
	while(front<=last)
	{
		mid = (front + last )/ 2;
		
		if(data==arr[mid])
		{
			loc = mid;
			break;
		}
		else if(data>arr[mid])
		{
			front = mid + 1;
		}
		else
		{
			last = mid-1;
		}
	}
	
	if(loc == -1)
	{
		cout<<data <<" Not found"<<endl;
	}
	else 
{
	cout<<"Data Found : "<<data<<" "<< loc;
}
}
