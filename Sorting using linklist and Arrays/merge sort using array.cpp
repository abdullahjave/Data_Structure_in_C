#include <iostream>
using namespace std;

// Function to perform merge sort on an array
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

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

    mergeSort(arr, 0, N - 1);

    cout << "Sorted array: ";
    printArray(arr, N);

    return 0;
}

// Function to perform merge sort on an array
void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

