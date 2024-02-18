#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *link;
} *start = NULL;

void create_list(int data);
void display();

int main()
{
    int choice, n, m, i;
    while (1)
    {
        
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter a number: ";
            cin >> n;
            while (n > 0)
            {
                int num = n % 10;
                create_list(num);
                n /= 10;
            }
            break;
        case 2:
            display();
            break;
        case 3:
            exit(1);
        default:
            cout << "invalid choice" << endl;
        }
    }
    return 0;
}

void create_list(int data)
{
    struct node *q, *tmp;
    tmp = new struct node;
    tmp->info = data;
    tmp->link = NULL;

    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        q = start;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = tmp;
    }
}

void display()
{
    struct node *q;
	q = start;
    if (q == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    int count = 0;
    while (q != NULL)
    {
        count++;
        q = q->link;
    }

    cout << "List is:" << endl;
    for (int i = count - 1; i >= 0; i--)
    {
        q = start;
        for (int j = 0; j < i; j++)
        {
            q = q->link;
        }
        cout << q->info << ", ";
    }

    cout << endl;
}
