#include<iostream>
using namespace std;

#define N 5

void insert(int);
void del();
void peek();
void display();

int arr[N];
int rear = -1;
int front = -1;

int main()
{
    int choice, data;

    while (1)
    {
        cout << "Enter the Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Insert the node data: ";
            cin >> data;
            insert(data);
            break;
        case 2:
            del();
            break;
        case 3:
            cout << "Display the nodes" << endl;
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);  // Exit the program
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}

void insert(int data)
{
    if (rear == N - 1 && front == 0)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        arr[rear] = data;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Empty" << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void del()
{
    if (front == -1)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        int data = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        cout << "Deleted: " << data << endl;
    }
}

void peek()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Front element: " << arr[front] << endl;
    }
}

