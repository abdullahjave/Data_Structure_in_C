#include<iostream>
#include<stdlib.h>
using namespace std;

void insert_left(int);
void insert_right(int);
void del_left();
void del_right();
void display();

struct node
{
	int info;
	struct node *link;
}*front, *rear;

int main()
{
	int choice,n,m,position,i;
	front=NULL;
	rear=NULL;

				insert_left(1);
				insert_left(2);
				insert_left(3);
				insert_left(4);
				insert_right(8);
				insert_right(7);
				insert_right(6);
				insert_right(5);
				del_left();		
				del_left();		
				del_left();				
				del_right();
				del_right();
				del_right();
				display();

}

void insert_right(int data) // rear se insert
{
	struct node *q,*tmp;
	tmp=new node();
	tmp->info=data;

	if(rear==NULL && front==NULL)
	{
	rear=tmp;
	front=tmp;
	rear->link=front;
	}
	else //sunain rear last node hota na , rear k link mai front hota
	{   // ghalt nahi thee donoh theek thap 
		tmp->link=front; //temp->link = rear->link;	
		rear->link=tmp;
		rear=tmp;
	}
}

void insert_left(int data) //front se insert
{
	node *temp = new node();
	temp->info = data;
	if(rear ==NULL && front == NULL)
	{
		rear=temp;
		front=temp;
		rear->link=front;
	}
	else
	{
		temp->link = front;
		rear->link = temp;
		front = temp;
		
	}
	
}


void del_left()
{
    if (rear == NULL && front == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    struct node *temp = front;

    if (front == rear)
    {
        front = NULL;
        rear = NULL;
        delete temp;
    }
    else
    {
        front = front->link;
        rear->link = front;
        delete temp;
    }
}



void del_right()  //rear se del
{
	struct node *temp,*q;
	if(rear == front)  //jab donoh aik he node ko point kren //only for 1 node
	{
		temp = rear;
		delete(temp);
		rear = front = NULL;
		//donoh null hpgaye
	}
	else
	{
		q= front;
		while(q->link!=rear) //2nd last node
		{
			q = q->link;
		}
		temp = q->link; //rear ban gaya
		q->link = front;
		rear = q;
		delete(temp);
	}
	
}

void display()
{
	struct node *q;
	if(rear==NULL && front==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else
	{	
	q=front;
	cout<<"List is:"<<endl;
	while(q->link!=front)
	{
		cout<<q->info<<"   ";
		q=q->link;
	}
	cout<<rear->info<<endl;
	}
}

