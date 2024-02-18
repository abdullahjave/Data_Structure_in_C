// Optimized implementation of Bubble sort 
#include <iostream>
using namespace std; 
  
// An optimized version of Bubble Sort 
void bubbleSort(int arr[], int n) 
{
	int temp;
	for(int i=0 ; i<n ;i++ )
	{
		for(int j=0 ; j<(n-1) ;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	 } 
}
  
// Function to print an array 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++)
	{ 
        cout <<" "<< arr[i]; 
	} 
}
  
// Driver program to test above functions 
int main() 
{ 
    int  N;
    cout<<"Enter the Number of Array"<<endl;
    cin>>N;
    int arr[N];
    for(int i=0 ; i<N ;i++)
    {
    	cout<<"Enter Value: ";
    	cin>>arr[i];
	}
    
    bubbleSort(arr, N); 
    cout <<"Sorted array: \n"; 
    printArray(arr, N); 
    return 0; 
} 
// This code is contributed by shivanisinghss2110 
