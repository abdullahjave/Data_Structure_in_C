#include <iostream>
using namespace std;

// Function to perform selection sort on an array
void selectionSort(int arr[], int n);

// Function to swap two elements in an array
void swap(int &a, int &b);

// A utility function to print an array of size n
void printArray(int arr[], int n);

// Driver code
int main()
{
    int N;

    cout << "Enter the size of the array: ";
    cin >> N;

    int arr[N];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    selectionSort(arr, N);

    cout << "Sorted array: ";
    printArray(arr, N);

    return 0;
}

// Function to perform selection sort on an array
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
	{
        int minIndex = i;
        // Find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) 
		{
            if (arr[j] < arr[minIndex]) 
			{
                minIndex = j;
            }
        }
		// Swap the found minimum element with the first element
        if (minIndex != i) 
		{
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to swap two elements in an array
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

