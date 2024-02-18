//Queue using Linklist

#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *link;
}*front,*rear;
	int count=0;
void insert(int data)
{
	
	struct node *temp;
	
	temp = new (struct node);
	temp->data = data;
	temp->link = NULL;
	
	if(front ==NULL && rear == NULL)
	{
		front=temp;
		rear=temp; 
		count++;
	}
	else
	{
		rear->link = temp;
		rear = temp;
		count++;
	}
	
	cout<<"Number : "<<count<<endl;
	
}

void del()
{
	struct node *temp;
	temp = front;
	if(front == NULL && rear == NULL) 
	{
		cout<<"List is Empty"<<endl;
	}
	
	else
	{
		cout<<"Deleted atem"<<front->data<<endl;
		front = front->link;
		delete(temp);
	}
}

void display()
{
	struct node *q;
	
	if(front == NULL && rear == NULL)
	{
		cout<<"Empty "<<endl;
	}
	else
	{
		q=front;
		while(q!=NULL)
		{
			cout<<"Data is : "<<q->data<<endl;
			q=q->link;
		}
	}
}

void end()
{
	if(front == NULL && rear == NULL)
	{
		cout<<"Empty "<<endl;
	}
	else
	{
		cout<<"End data : "<<rear->data<<endl;
	}
}

void peek()
{
	if(front == NULL && rear == NULL)
	{
		cout<<"Empty "<<endl;
	}
	else
	{
		cout<<"First data : "<<front->data<<endl;
	}
}
 
int main()
{
	front = NULL;
	rear = NULL;

	int choice , data,d;
	while(1)
	{
		cout<<"Enter the Choice : ";
		cin>>choice;
		
		switch (choice)
		{
			case 1:
				{
					cout<<"Insert the node data"<<endl;
					cin>>data;
					insert(data);
					break;
				}
			case 2:
				{
					del();
					break;
				}
			case 3:
				{
					cout<<"Display the nodes"<<endl;
					display();
					break;
				}
			case 4 :
				{
					peek();
					break;
				}
			case 5 :
				{
					end();
					break;
				}
			case 6:
				{
					exit(1);
					break;
				}
			default :
				{
					cout<<"Invalid Choice"<<endl;
					break;
			}
		}
	}
}



