#include "A1_DS_Q5.h"
#include<iostream>
#include<cstdlib>
using namespace std;

void cll2::menu()
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
		cout<<"6. Find middle point of the list."<<endl;
		cout<<"7. Quit"<<endl;

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
				splitlist();
				break;
			case 7:
				exit(1);
			default:
				cout<<"Wrong choice"<<endl;
		}
	}
}
void cll2::create_list(int data)
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
void cll2::addatbeg(int data)
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
void cll2::addafter(int data,int pos)
{
	struct node *tmp,*q;
	int i;
	q=last->link;
	for(i=1;i<pos;i++)
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
void cll2::del(int data)
{
		struct node *tmp,*q;
	if(last->link==last&&last->info==data)	/*only one element*/
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return;
	}
	q=last->link;
	if(q->info==data)
	{
		tmp=q;
		last->link=q->link;
		free(tmp);
		return;
	}
	while(q->link!=last)
	{
		if(q->link->info==data)	       /*element deleted in between*/
		{
			tmp=q->link;
			q->link=tmp->link;
			free(tmp);
			cout<<"Deleted "<<data<<endl;
			return;
		}
		q=q->link;
	}
	if(q->link->info==data)		/*last element deleted q->link=last*/
	{
		tmp=q->link;
		q->link=last->link;
		free(tmp);
		last=q;
		return;
	}
	cout<<"Element "<<data<<" not found"<<endl;

}
void cll2::display()
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
int cll2::getlength()
{
		int count=0;
	struct node *temp;
	temp=last;
	do{
		temp=temp->link;
		count++;
	}
	while(temp!=last);
	return count;

}
void cll2::splitlist()
{
	    struct node *temp;
    int i, n, k;

    n = getlength();


    temp = last->link;

    if (n % 2 == 0)
    {
        cout << "There is no middle node in the current list." << endl;
		cout << "First half of this circular linked list is :";
    	for (i = 1; i <= (n / 2); i++)
    	{
        cout << temp->info << " , ";
        temp = temp->link;
    }
		cout << "\nSecond half of this circular linked list is:";
    	for (i = (n / 2)+1; i <= n; i++)
    	{
        cout << temp->info << " , ";
        temp = temp->link;
    	}

    }
    else
    {
        k = n / 2;
		cout << "First half of this circular linked list is :\n";
    for (i = 1; i <= k; i++)
    {
        cout << temp->info << " , ";
        temp = temp->link;
    }
    cout<<"Middle node of the list is:"<<temp->info<<endl;
    temp=temp->link;

    cout << "Second half of this circular linked list is:\n";
    for (i = k+2; i <=n; i++)
    {
        cout << temp->info << " , ";
        temp = temp->link;
    }
    }    
    cout << endl;

}
