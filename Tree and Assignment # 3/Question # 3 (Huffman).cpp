#include <iostream>
using namespace std;

struct tree
{
    int info;
    tree *lchild;
    tree *rchild;
};

struct node
{
    tree *t;
    node *link;
};

node *rear, *front;

// Function declarations
void push(int);
void pop();
void display();
void bubbleSort();
void add();
void addPatient(int);
void getNextPatient();

int main()
{
    rear = NULL;
    front = NULL;

    int num, n, choice;

    while (1)
    {
        cout << endl
             << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Get Next Patient" << endl;
        cout << "3. Display" << endl;
        cout << "4. SORT" << endl;
        cout << "5. ADD" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice" << endl;
        cin >> choice;
        cout << endl
             << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter patient severity: ";
            cin >> n;
            addPatient(n);
            break;
        case 2:
            getNextPatient();
            break;
        case 3:
            cout << endl;
            display();
            cout << endl;
            break;
        case 4:
            bubbleSort();
            cout << endl;
            display();
            break;
        case 5:
            add();
            break;
        case 6:
            cout << "Exiting program" << endl;
            exit(0);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}

void push(int data)
{
    node *temp = new node();
    temp->t = new tree();
    temp->t->info = data;
    temp->t->lchild = NULL;
    temp->t->rchild = NULL;
    temp->link = NULL;

    if (rear == NULL)
    {
        rear = temp;
        front = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void display()
{
    node *q = front;
    if (q == NULL)
    {
        cout << "Priority Queue is EMPTY" << endl;
    }
    else
    {
        cout << "Priority Queue: ";
        while (q != NULL)
        {
            cout << q->t->info << " ";
            q = q->link;
        }
        cout << endl;
    }
}

void pop()
{
    if (front != NULL)
    {
        node *temp;
        temp = front;
        front = front->link;
        delete (temp);
    }
}

void bubbleSort()
{
    if (front == NULL)
    {
        cout << "Priority Queue is EMPTY" << endl;
        return;
    }

    node *current, *nextNode;
    bool swapped;

    do
    {
        swapped = false;
        current = front;

        while (current->link != NULL)
        {
            nextNode = current->link;

            if (current->t->info < nextNode->t->info)
            {
                // Swap the nodes
                int temp = current->t->info;
                current->t->info = nextNode->t->info;
                nextNode->t->info = temp;
                swapped = true;
            }

            current = current->link;
        }
    } while (swapped);
}

void add()
{
    bubbleSort();
    while (front->link != NULL)
    {
        node *a = front;
        node *b = front->link;
        node *temp = new node();
        temp->t = new tree();
        temp->t->info = a->t->info + b->t->info;
        temp->t->lchild = a->t;
        temp->t->rchild = b->t;
        front = temp;
        temp->link = b->link;

        b->link = NULL;
        a->link = NULL;
        delete (a);
        delete (b);
        bubbleSort();
    }

    display();
}

void addPatient(int severity)
{
    push(severity);
}

void getNextPatient()
{
    if (front != NULL)
    {
        cout << "Next patient with highest priority: " << front->t->info << endl;
        pop();
    }
    else
    {
        cout << "No patients in the queue." << endl;
    }
}

