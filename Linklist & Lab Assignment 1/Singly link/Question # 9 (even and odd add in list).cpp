#include<iostream>
#include<stdlib.h>
using namespace std;

struct node 
{
    int data;
    struct node *link;
};

struct node *start1 = NULL; 
struct node *start2 = NULL; 
struct node *start3 = NULL; 

void createList1(int);
void createList2(int);
void createList3(int);
void func();
void show();

int main()
{
    int data1, data2, data3;

    while(1)
    {
        			int choice;
        			cout << "Enter the Choice " << endl;
       					 cin >> choice;
       						 switch(choice )
        			{
            case 1:
            {
                int n;
                cout << "How many nodes do you want? " << endl;
                cin >> n;
                for(int i = 0; i < n; i++)
                {
                    cout << "Enter data: " << endl;
                    cin >> data1;
                    createList1(data1);
                }
                break;
            }
            case 2:
            {
                int n;
                cout << "How many nodes do you want? " << endl;
                cin >> n;
                for(int i = 0; i < n; i++)
                {
                    cout << "Enter data: " << endl;
                    cin >> data2;
                    createList2(data2);
                    
                    
            
                }
                break;
            }
            case 3:
            {
                int n;
                cout << "How many nodes do you want? " << endl;
                cin >> n;
                for(int i = 0; i < n; i++)
                {
                    cout << "Enter data: " << endl;
                    cin >> data3;
                    createList3(data3);
                }
                break;
            }
            case 4:
            {
                func();
                break;
            }                
            case 5:
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

void createList1(int data1)
{
    struct node *q, *temp;
    temp = new(struct node);
    temp->data = data1;
    temp->link = NULL;

    if(start1 == NULL)
    {
        start1 = temp;
    }
    else
    {
        q = start1;
        while(q->link != NULL)
        {
            q = q->link;
        }
        q->link = temp;
    }
}

void createList2(int data2)
{
    struct node *q, *temp;
    temp = new(struct node);
    temp->data = data2;
    temp->link = NULL;

    if(start2 == NULL)
    {
        start2 = temp;
    }
    else
    {
        q = start2;
        while(q->link != NULL)
        {
            q = q->link;
        }
        q->link = temp;
    }
}

void createList3(int data3)
{
    struct node *q, *temp;
    temp = new(struct node);
    temp->data = data3;
    temp->link = NULL;

    if(start3 == NULL)
    {
        start3 = temp;
    }
    else
    {
        q = start3;
        while(q->link != NULL)
        {
            q = q->link;
        }
        q->link = temp;
    }
}

void func()
{
    struct node* q, *temp;
    while (start1 != NULL) 
    {
    	
        q = start1;
        
        if (q->data % 2 == 0)
        {
        	
            temp = q;
            start1 = start1->link;
            temp->link = NULL;
            temp->link = start2;
            start2 = temp;
        } 
        else 
        {
            temp = q;
            start1 = start1->link;
            temp->link = NULL;
            temp->link = start3;
            start3 = temp;
            
            
        }
    }
}

void show()
{
    struct node *q1, *q2, *q3;
    q1 = start1;
    q2 = start2;
    q3 = start3;
    
    cout << "1st List:" << endl;
    while(q1 != NULL)
    {
        cout << q1->data << " "<<endl;
        q1 = q1->link;
    }
    
    cout << "2nd List:" << endl;
    while(q2 != NULL)
    {
        cout << q2->data << " "<<endl;
        q2 = q2->link;
    }
    
    cout << "3rd List:" << endl;
    while(q3 != NULL)
    {
        cout << q3->data << " ";
        q3 = q3->link;
    }
    cout << endl;
}
