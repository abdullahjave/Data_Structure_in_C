#include<iostream>
#include<stdlib.h>
using namespace std;
void create_list(int);
void addatbeg(int);
void addafter(int,int);
void del(int);
void display();

struct node
{
	int info;
	struct node *link;
}*last;

int main()
{
	int choice,n,m,position,i;
	last=NULL;
	while(1)
	{
		cout<<"1. Create List"<<endl;
		cout<<"2. Add at beginning"<<endl;
		cout<<"3. Add after"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Quit"<<endl;

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
				if(last==NULL)
				{
					cout<<"List is empty"<<endl;
					continue;
				}
				cout<<"Enter the element for deletion"<<endl;
				cin>>m;
				del(m);
				break;
			case 5:
				display();
				break;
			case 6:
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

	if(last==NULL)
	{
	last=tmp;
	tmp->link=last;
	}
	else
	{
		tmp->link=last->link;	/*added at the end of list*/
		last->link=tmp;
		last=tmp;
	}
}

void addatbeg(int data)
{
	struct node *tmp;
	tmp=new(struct node);
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
}

void addafter(int data,int pos)
{
	struct node *tmp,*q;
	int i;
	q=last->link;
	for(i=0;i<pos;i++)
	{
		q=q->link;
		if(q==last->link)
		{
			cout<<"There are less than "<<pos<<" elements"<<endl;
			return;
		}
	}
	tmp=new(struct node);
	tmp->link=q->link;
	tmp->info=data;
	q->link=tmp;

	if(q==last)	last=tmp;	/*element inserted at the end*/
}

void del(int data)
{
	struct node *tmp,*q;
	if(last->link==last&&last->info==data)	/*only one element*/
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return;
	}
//	q=last->link;
//	if(q->info==data)
//	{
//		tmp=q;
//		last->link=q->link;
//		free(tmp);
//		return;
//	}
//	while(q->link!=last)
//	{
//		if(q->link->info==data)	       /*element deleted in between*/
//		{
//			tmp=q->link;
//			q->link=tmp->link;
//			free(tmp);
//			cout<<"Deleted "<<data<<endl;
//			return;
//		}
//		q=q->link;
//	}
//	if(q->link->info==data)		/*last element deleted q->link=last*/
//	{
//		tmp=q->link;
//		q->link=last->link;
//		free(tmp);
//		last=q;
//		return;
//	}
//	cout<<"Element "<<data<<" not found"<<endl;
}

void display()
{
	struct node *q;
	if(last==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	q=last->link;
	cout<<"List is:"<<endl;
	while(q!=last)
	{
		cout<<q->info<<"   ";
		q=q->link;
	}
	cout<<last->info<<endl;
}

