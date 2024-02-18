#include <iostream>
using namespace std;

// Structure of a node
struct Node 
{
    int data;
    Node* next;
};

// Global variable to store the start of the linked list
struct Node* start = NULL;

// Function to create a new node and add it to the end of the linked list
void create_list(int data) {
    struct Node* tmp = new Node();
    tmp->data = data;
    tmp->next = NULL;

    if (start == NULL)
        start = tmp; // If the list is empty, the new node becomes the start
    else {
        struct Node* q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = tmp; // Add the new node to the end of the list
    }
}

// Function to print nodes in a given linked list
void printList() {
    struct Node* temp = start;
    cout << endl;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Custom swap function to swap the values of two integers
void customSwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Selection sort for singly linked list
void selectionSort() 
{
    if (start == NULL || start->next == NULL)
        return; // Already sorted or empty list

    struct Node* current = start;

    while (current != NULL) 
	{
        struct Node* minNode = current;
        struct Node* temp = current->next;
        
        // Find the minimum node in the unsorted part of the list
        while (temp != NULL) 
		{
            if (temp->data < minNode->data)
                minNode = temp;
            temp = temp->next;
        }
        // Swap the found minimum node with the current node
        customSwap(current->data, minNode->data);
        current = current->next;
    }
}

int main() {
    int num, data;
    cout << "How many nodes do you want? " << endl;
    cin >> num;

    // Create a singly linked list
    for (int i = 0; i < num; i++) {
        cout << "Enter the Node data: " << endl;
        cin >> data;
        create_list(data);
    }

    // Print the list before sorting
    cout << "\nLinked list before sorting ";
    printList();

    // Sort the singly linked list using selection sort
    selectionSort();

    // Print the list after sorting
    cout << "\nLinked list after sorting ";
    printList();

    return 0;
}

