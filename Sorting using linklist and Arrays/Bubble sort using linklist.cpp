#include <iostream>
using namespace std;

// Structure of a node
struct Node 
{
    int data;
    Node* next;
}*start = NULL;

void create_list(int data) 
{
    struct Node* tmp = new Node();
    tmp->data = data;
    tmp->next = NULL;

    if (start == NULL)
    {
        start = tmp; // If the list is empty
	}
	else
	{
        struct Node* q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = tmp;
    }
}

/* Function to print nodes in a given linked list */
void printList() 
{
    struct Node* temp;
    temp = start;
    cout << endl;
    while (temp != NULL) 
	{
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/* Custom swap function */
void customSwap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

/* Bubble sort the given singly linked list */
void bubbleSort() 
{
    //int swapped;
    struct Node* ptr1;

    /* Checking for an empty list */
    if (start == NULL)
    {
        return;
	}
    while (true) 
    {
        int swapped = 0;
        ptr1 = start;

        while (ptr1->next != NULL) 
        {
            if (ptr1->data > ptr1->next->data) 
            {
                customSwap(ptr1->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }


        // If no swapping happened in the inner loop, the list is already sorted
        if (swapped==0)
            break;
    }
}
int main() 
{
    int num, data;
    cout << "How many nodes do you want? " << endl;
    cin >> num;

    /* Create a singly linked list */
    for (int i = 0; i < num; i++) 
	{
        cout << "Enter the Node data: " << endl;
        cin >> data;
        create_list(data);
    }

    /* Print the list before sorting */
    cout << "\nLinked list before sorting ";
    printList();

    /* Sort the singly linked list using bubble sort */
    bubbleSort();

    /* Print the list after sorting */
    cout << "\nLinked list after sorting ";
    printList();

    return 0;
}

