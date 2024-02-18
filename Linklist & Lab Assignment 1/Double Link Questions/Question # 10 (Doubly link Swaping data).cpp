#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev; // Add a previous pointer
} *start;

void createlist(int);
void swap();
void show();

int main()
{
    start = NULL;
    int data, data2;

    while (1)
    {
        int choice;
        cout << "Enter the Choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "How many nodes you want: " << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter data: " << endl;
                cin >> data;
                createlist(data);
            }
            break;
        }

        case 2:
        {
            swap();
            break;
        }

        case 3:
        {
            show();
            break;
        }

        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
}

void createlist(int data)
{
    struct node* q, * temp;
    temp = new(struct node);
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = temp;
        temp->prev = q; // Set the previous pointer
    }
}

void swap()
{
    struct node* q, * temp, * swap1, * swap2;
    temp = new(struct node);
    temp->next = start;
    temp->prev = NULL;
    q = temp;

    while (q->next != NULL && q->next->next != NULL)
    {
        swap1 = q->next;
        swap2 = q->next->next;

        swap1->next = swap2->next;
        swap2->next = swap1;

        q->next = swap2;
        swap1->prev = swap2; // Update previous pointers
        swap2->prev = q;

        q = swap1;
        start = temp->next;
    }
}

void show()
{
    struct node* q;
    q = start;

    if (start == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    cout << "List: " << endl;
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }

    cout << endl;
}

