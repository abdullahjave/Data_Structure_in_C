#include "stack_link.h"
#include <iostream>
using namespace std;

void runner :: menu()
{
	int choice ;
	
	while(true)
	{
		cout<<"press 1). for Push "<<endl;
		cout<<"press 2). for Pop "<<endl;
		cout<<"press 3). for Dispay "<<endl;
		cout<<"press 4). for Peek "<<endl;
		cout<<"press 5). for Exit "<<endl;
		cout<<endl;
		cout<<"Enter the Choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1 : 
			{
				int data;
				cout<<"Enter the Node Data"<<endl;
				cin>>data;
				push(data);
				break;
			}
			case 2:
			{	
				pop();
				break;
			}
			case 3:
				{
					display();
					break;
				}
			case 4:
				{
					peek();
					break;
				}
			case 5:
				{
					exit(1);
				}
			default :
				{
					cout<<"Invalid Choice"<<endl;
				}
		}		
	}
}

void runner :: push(int data)
{
	cout<<endl;
	cout<<"Fill the node"<<endl;
	struct node *temp;
	
	temp = new (struct node);
	temp->data = data;
	temp->link = top;
	top=temp;
}

void runner :: pop()
{
	struct node *q;
	
	if (top == NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	
	else
	{
		q=top;
		cout<<"Data Remove : "<<q->data;
		top=top->link;
		q->link = NULL;
		delete(temp);
	}
}
void runner :: display()
{
	struct node *q;
	if(top == NULL)
	{
		cout<<"List is Empty"<<endl;
	}

	else
	{
		q=top;
		cout<<"Data : "<<q->data;
		q=q->link;
	}
}

void runner :: peek()
{
	if(top == NULL)
	{
		cout<<"List is Empty"<<endl;
	}

	else
	{
		cout<<"Data : "<<top->data;
	}
}

