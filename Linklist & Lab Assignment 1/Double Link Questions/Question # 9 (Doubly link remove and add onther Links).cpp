#include<iostream>
#include<stdlib.h>
using namespace std;


struct node 
{
	int data ;
	struct node *link;
	struct node *prev;	
} ;

	struct node *start = NULL;
	struct node *start1 = NULL;
	struct node *start2 = NULL;

void createlist(int);
void createlist2(int);
void createlist3(int);
void funct();
void show();


int main()
{
	int data,data2;
	

	while(1)
	{
		int choice ;
	cout<<"Enter the Choice " <<endl;
	cin>>choice;
		switch(choice )
		{
			case 1:
				{
					int n;
					cout<<"How many node u want "<<endl;
					cin>>n;
					for(int i=0 ; i<n ; i++)
					{
						cout<<"Enter data : "<<endl;
						cin>>data;
						createlist(data);
					}
					break;
				}
				case 2:
					{
					int n,data3;
					cout<<"How many node u want "<<endl;
					cin>>n;
					for(int i=0 ; i<n ; i++)
					{
						cout<<"Enter data : "<<endl;
						cin>>data3;
						createlist2(data3);
					}
					break;
				}
				case 3:
					{
						
					int n,data4;
					cout<<"How many node u want "<<endl;
					cin>>n;
					for(int i=0 ; i<n ; i++)
					{
						cout<<"Enter data : "<<endl;
						cin>>data4;
						createlist3(data4);
					}
					break;
				}
				case 4:
					{
						funct();
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

void createlist(int data)
{
	struct node *q,*temp;

	temp = new(struct node );
	temp->data = data;
	temp->link = NULL;
	temp->prev = NULL;
	
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		q=start;
		while (q->link != NULL)
		{
			q=q->link;
		}
		
		q->link = temp;
		temp->prev = q;		
	}
}


void createlist2(int data)
{
	struct node *q,*temp;

	temp = new(struct node );
	temp->data = data;
	temp->link = NULL;
	temp->prev = NULL;
	
	if(start1 == NULL)
	{
		start1 = temp;
	}
	else
	{
		q=start1;
		while (q->link != NULL)
		{
			q=q->link;
		}
		
		q->link = temp;
		temp->prev = q;		
	}
}


void createlist3(int data)
{
	struct node *q,*temp;

	temp = new(struct node );
	temp->data = data;
	temp->link = NULL;
	temp->prev = NULL;
	
	if(start2 == NULL)
	{
		start2 = temp;
	}
	else
	{
		q=start2;
		while (q->link != NULL)
		{
			q=q->link;
		}
		
		q->link = temp;
		temp->prev = q;		
	}
}



void funct()
{
    struct node *temp;

    while (start != NULL)
    {
        temp = start;
        start = start->link;
        temp->link = NULL; 
        temp->prev = NULL; 
        
        if (temp->data % 2 == 0)
        {
            temp->link = start1;
            if (start1 != NULL)
            {
                start1->prev = temp;
            }
            start1 = temp;
        }
        else
        {
            temp->link = start2;
            if (start2 != NULL)
            {
                start2->prev = temp;
            }
            start2 = temp;
        }
    }
}


void show()
{
	struct node *q,*q1,*q2;
	
	q=start;
	q1=start1;
	q2=start2;
	
	
	cout <<endl<< "1st List:" << endl;
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    
    cout <<endl<< "2st List:" << endl;
    while(q1 != NULL)
    {
        cout << q1->data << " ";
        q1 = q1->link;
    }
    cout <<endl<< "3st List:" << endl;
    while(q2 != NULL)
    {
        cout << q2->data << " ";
        q2 = q2->link;
    }
	cout << endl;
}

