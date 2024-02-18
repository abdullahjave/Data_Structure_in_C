//Queue Using Arrays 

#include<iostream>
using namespace std;

#define N 5 

void insert(int);
void del();
void peek();
void display();
void end();

int arr[N];
int rear = -1;
int front = -1;

int main()
{
	
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

void insert(int data)
{
	if(rear == N-1 )
	{
		cout<<"Overflow"<<endl;
	}
//	else if(front == -1 && rear == -1)
//	{
//		front =0; 
//		rear =0;
//		arr[rear]=data;
//	}
	else
	{
		front = 0;
		rear ++ ;
		arr[rear] = data;
	}
	
}

void display()
{
	if(front == -1 && rear == -1)
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		for(int i = front ; i<= rear ; i++ )
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

void del()
{
	if(front == -1 && rear == -1)
	{
		cout<<"Empty"<<endl;
	}
	else if(front==rear)
	{
		cout<<"Element Deleted "<<arr[rear]<<endl;
		 front = -1;
		 rear= -1;
	}
	else
	{
		cout<<"Deleted element is :"<<arr[front]<<endl;
		front ++;
	}
	
}

void peek()
{
	if(front == -1 && rear == -1)
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Peek element is :"<<arr[rear];
	}
}
