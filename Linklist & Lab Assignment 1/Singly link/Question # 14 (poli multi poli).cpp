#include <iostream>
using namespace std;

struct node
{
    int coeff;
    int power;
    struct node *link;
} *start1 = NULL, *start2 = NULL, *result = NULL;

void create(int coeff, int power, int polyNum);
void multiply(int num);
void display(struct node *poly);

int main()
{
    int choice, coeff, power, num;
    while (1)
    {
        cout << "1. Create Polynomial 1" << endl;
        cout << "2. Create Polynomial 2" << endl;
        cout << "3. Multiply" << endl;
        cout << "6. Display Result Polynomial" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter coefficient for Polynomial 1: ";
            cin >> coeff;
            cout << "Enter power for Polynomial 1: ";
            cin >> power;
            create(coeff, power, 1);
            break;
        case 2:
            cout << "Enter coefficient for Polynomial 2: ";
            cin >> coeff;
            cout << "Enter power for Polynomial 2: ";
            cin >> power;
            create(coeff, power, 2);
            break;
        case 3:
            cout << "Enter a number to multiply: ";
            cin >> num;
            multiply(num);
            break;
        case 4:
            display(start1);
            break;
        case 5:
            display(start2);
            break;
        case 6:
            display(result);
            break;
        case 7:
            exit(0);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

void create(int coeff, int power, int polyNum)
{
    struct node *q, *tmp;
    tmp = new struct node;
    tmp->coeff = coeff;
    tmp->power = power;
    tmp->link = NULL;

    if (polyNum == 1)
    {
        if (start1 == NULL)
        {
            start1 = tmp;
        }
        else
        {
            q = start1;
            while (q->link != NULL)
            {
                q = q->link;
            }
            q->link = tmp;
        }
    }
    else if (polyNum == 2)
    {
        if (start2 == NULL)
        {
            start2 = tmp;
        }
        else
        {
            q = start2;
            while (q->link != NULL)
            {
                q = q->link;
            }
            q->link = tmp;
        }
    }
}

void display(struct node *poly)
{
    struct node *q = poly;
    if (q == NULL)
    {
        cout << "Polynomial is empty" << endl;
        return;
    }
    cout << "Polynomial: ";
    while (q != NULL)
    {
        cout << q->coeff;
        if (q->power != 0)
        {
            cout << "x^" << q->power;
        }
        if (q->link != NULL)
        {
            cout << " + ";
        }
        q = q->link;
    }
    cout << endl;
}

void multiply(int num)
{
    struct node *q1 = start1;
    while (q1 != NULL)
    {
        struct node *q2 = start2;
        while (q2 != NULL)
        {
            int coeff = q1->coeff * q2->coeff;
            int power = q1->power + q2->power;
            create(coeff, power, 3); // Store the result in the third linked list.
            q2 = q2->link;
        }
        q1 = q1->link;
    }
}

