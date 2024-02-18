#include <iostream>
using namespace std;

#define num 5
int stack[num];
int top = -1;

void push();
void pop();
void topp();
void display();

int main()
{
	int choice;
	
	while(true)
	{
		
	cout<<"Enter the Choice"<<endl;
		cin>>choice ;

		switch(choice)
		{
			case 1:
				{
					push();
					break;
				}
			case 2:
				{
					pop();
					break;
				}
			case 3:
				{
					topp();
					break;
				}
			case 4:
				{
					display();
					break;
				}
			case 5:
				{
					exit(1);
				}
			default :
				{
					cout<<"Not a valid Choice "<<endl;
					break;
				}
				
		}
		
	}
	return 0;
}

void push()
{
	if(top == num-1)
	{
		cout<<"overflow"<<endl;
	}
	else
	{
		int data;
		cout<<"Enter the data"<<endl;
		cin>>data;
		top++;
		stack[top]=data;
	}
}

void pop()
{
	if(top==-1)
	{
		cout<<"outflow"<<endl;
		
	}
	else 
	{
		cout<<"Element is : "<<stack[top]<<endl;
		top--;
	}
}

void topp()
{
	if(top==-1)
	{
		cout<<"Stack is Empty"<<endl;
	}
	else
	{
		cout<<"Element is :"<<stack[top]<<endl;
	}
}

void display()
{
	if(top == -1)
	{
		cout<<"Stack is Empty"<<endl;
	}
	else
	{
		for(int i=0; i<=top ; i++)
		{
			cout<<"Element : "<<i+1<<" "<<stack[i]<<endl;
		}
	}
}
