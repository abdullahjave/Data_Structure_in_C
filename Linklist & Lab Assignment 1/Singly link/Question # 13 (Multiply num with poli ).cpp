#include <iostream>
using namespace std;

struct node
{
    int cof;
    int pow;
    struct node *link;
} *start;

void create(int cof, int pow);
void multiply(int num);
void display();

int main()
{
	start = NULL;
    int choice, cof, pow, num;
    while (1)
    {
 
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        	int n;
        	cout<<"How many Nodes Do u want"<<endl;
        	cin>>n;
        	for(int i=0 ; i<n ; i++)
        	{
        	cout << "Coefficient: "<<endl;
            cin >> cof;
            cout << "Power: "<<endl;
            cin >> pow;
            create(cof, pow);
			}
            break;
        case 2:
            cout << "Enter a number to multiply: "<<endl;
            cin >> num;
            multiply(num);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

void create(int cof, int pow)
{
    struct node *q, *tmp;
    tmp = new struct node;
    tmp->cof = cof;
    tmp->pow = pow;
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
    struct node *q = start;
    if (q == NULL)
    {
        cout << "Polynomial is empty" << endl;
        return;
    }
    cout << "Polynomial: "<<endl;
    while (q != NULL)
    {
        cout << q->cof << "x^" << q->pow<<"+";
        q = q->link;
    }
    cout << endl;
}

void multiply(int num)
{
    struct node *q = start;
    while (q != NULL)
    {
        q->cof = q->cof * num;
        q = q->link;
    }
}
