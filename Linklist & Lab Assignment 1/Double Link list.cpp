#include<iostream>
#include<stdlib.h>
using namespace std;
void create_list(int);
void addatbeg(int);
void addafter(int,int);
void del(int);
void display();
void count();
void rev();

struct node
{
	struct node *prev;
	int info;
	struct node *next;
}*start;

int main()
{
	int choice,n,m,position,i;
	start=NULL;
	while(1)
	{
		cout<<"1. Create List"<<endl;
		cout<<"2. Add at beginning"<<endl;
		cout<<"3. Add after"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Count"<<endl;
		cout<<"7. Reverse"<<endl;
		cout<<"8. Search"<<endl;
		cout<<"9. Quit"<<endl;

		cout<<"Enter ur choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"How many nodes u want:"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"Enter the element"<<endl;
					cin>>m;
					create_list(m);
				}
				break;
			case 2:
				cout<<"Enter the element"<<endl;
				cin>>m;
				addatbeg(m);
				break;
			case 3:
				cout<<"Enter the element"<<endl;
				cin>>m;
				cout<<"Enter the position after which this element is inserted"<<endl;
				cin>>position;
				addafter(m,position);
				break;
			case 4:
				cout<<"Enter the element for deletion"<<endl;
				cin>>m;
				del(m);
				break;
			case 5:
				display();
				break;
			case 6:
				count();
				break;
			case 7:
				rev();
				break;
			case 9:
				exit(1);
			default:
				cout<<"Wrong choice"<<endl;
		}
	}
}

void create_list(int data)
{
	struct node *q,*tmp;
	tmp=new(struct node);
	tmp->info=data;
	tmp->next=NULL;

	if(start==NULL)
	{
		tmp->prev=NULL;
		start->prev=tmp;
		start=tmp;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
		{
			q=q->next;
		
		}
		q->next=tmp;
		tmp->prev=q;
	}
}

void addatbeg(int data)
{
	struct node *tmp;
	tmp=new(struct node);
	tmp->prev=NULL;
	tmp->info=data;
	tmp->next=start;
	tmp->prev=tmp;
	start=tmp;
}

void addafter(int data,int pos)
{
	struct node *tmp,*q;
	int i;
	q=start;
	for(i=0;i<pos;i++)
	{
		q=q->next;
		if(q==NULL)
		{
			cout<<"There are less than "<<pos<<" elements"<<endl;
			return;
		}
	}
	tmp=new(struct node);
	tmp->info=data;
	q->next->prev=tmp;
	tmp->next=q->next;
	tmp->prev=q;
	q->next=tmp;
}
void del(int data)
{
	struct node *tmp,*q;
	if(start->info==data)
	{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		return;
	}
	q=start;
	while(q->next->next!=NULL)
	{
		if(q->next->info==data)	       //element deleted in between/
		{
			tmp=q->next;
			q->next=tmp->next;
			tmp->next->prev=q;
			free(tmp);
			return;
		}
		q=q->next;
	}
	if(q->next->info==data)		//last element deleted/
	{
		tmp=q->next;
		free(tmp);
		q->next=NULL;
		return;
	}
	cout<<"Element "<<data<<" not found"<<endl;
}

void display()
{
	struct node *q;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	q=start;
	cout<<"List is:"<<endl;
	while(q!=NULL)
	{
		cout<<q->info<<"   ";
		q=q->next;
	}
	cout<<endl;
}

void count()
{
	struct node *q=start;
	int cnt=0;
	while(q!=NULL)
	{
		q=q->next;
		cnt++;
	}
	cout<<"Number of elements are "<<cnt<<endl;
}

void rev()
{
	struct node *p1,*p2;

	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;  //next of p2 changed to prev/
	}
	start=p1;
}
