#include <iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* start = NULL;
int size = 0;

struct Node* insert(int element) 
{
   struct Node* temp= new Node;
    temp->data = element;
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL || element > start->data) 
	{
        temp->next = start;
        if (start != NULL) 
		{
            start->prev = temp;
        }
        start = temp;
    } 
	else 
	{
        Node* current = start;
        while (current->next != NULL && current->next->data > element) 
		{
            current = current->next;
        }
        temp->next = current->next;
        temp->prev = current;
        if (current->next != NULL) 
		{
            current->next->prev = temp;
        }
        current->next = temp;
    }
    return start;
}

struct Node* deleteValue(int x) 
{
    if (size == 0) {
        cout << "Heap is empty!" << endl;
        return NULL;
    }

    if (start->data == x)
	 {
        Node* temp = start;
        start = start->next;
        if (start != NULL) 
		{
            start->prev = NULL;
        }
        delete temp;
        size--;
        return start;
    }

    struct Node* current = start;
    while (current != NULL && current->data != x) 
	{
        current = current->next;
    }

    if (current != NULL) 
	{
        if (current->prev != NULL) 
		{
            current->prev->next = current->next;
        }
        if (current->next != NULL) 
		{
            current->next->prev = current->prev;
        }
        delete current;
        size--;
    } 
	else 
	{
        cout << "Value not found in the heap!" << endl;
    }

    return start;
}

void print()
 {
    if (start == NULL) 
	{
        cout << "Heap is empty!" << endl;
        return;
    }

    cout << "Double-Linked List elements: ";
    struct Node* current = start;
    while (current != NULL) 
	{
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
 {
    int choice, element;
    while (true) 
	{
        cout << "Double-Linked List Menu" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete specific value" << endl;
        cout << "3. Print elements" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> element;
                start = insert(element);
                size++;
                break;
            case 2:
                cout << "Enter the value to be deleted: ";
                cin >> element;
                start= deleteValue(element);
                break;
            case 3:
                print();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }
    }

    return 0;
}

