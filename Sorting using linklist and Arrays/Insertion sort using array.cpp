#include <iostream>
using namespace std;

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

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

    insertionSort(arr, N);

    cout << "Sorted array: ";
    printArray(arr, N);

    return 0;
}

