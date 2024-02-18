#include "question1.h"
#include<stdlib.h>
#include<string>
using namespace std;


void Runner :: menu()
{
	int choice,n;
	string m,as,d;
	
	
	while(1)
	{
		cout<<"1. Create List"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Add at beginning"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. Quit"<<endl;

		cout<<"Enter ur choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"How many Data u want:"<<endl;
				cin>>n;
			    
				for(int i=0;i<n;i++)
				{
					cin.ignore();
					cout<<"----------------------------------------------------"<<endl;
					cout<<"Enter the Name "<<endl;
					getline(cin,m);
					cout<<"Enter the Date  "<<endl;
					getline(cin,d);
					cout<<"Enter the Assignto "<<endl;
					getline(cin,as);
					create_list(m,d,as);
				}
				break;
			case 3:
				
				cin.ignore();
				    cout<<"Enter the data of new node: "<<endl;
					cout<<"Enter the Name "<<endl;
					getline(cin,m);
					cout<<"Enter the Date  "<<endl;
					getline(cin,d);
					cout<<"Enter the Assignto "<<endl;
					getline(cin,as);
				    addatbeg(m,d,as);
				break;


			case 4:
				if(start==NULL)
				{
					cout<<"Data is not available"<<endl;
					continue;
				}
				cout<<"Enter the element for deletion"<<endl;
				cin>>m;
				del(m);
				break;
			case 2:
				display();
				break;

			default:
				cout<<"Wrong choice"<<endl;
		}
	}
}

void Runner :: create_list(string name,string date , string assignto)
{
	struct node *q,*tmp;
	tmp=new(struct node);
	tmp->name=name;
	tmp->date=date;
	tmp->assignto=assignto;
	tmp->link=NULL;

	if(start==NULL)	
	  start=tmp;	
	else    
	{
		q=start;
		while(q->link!=NULL) 	
		{
		    q=q->link;
	    }
		q->link=tmp;
	}
}

void Runner :: addatbeg(string name, string assignto, string date)
{
	struct node *tmp;
	tmp=new(struct node);
	tmp->name=name;
	tmp->assignto=assignto;
	tmp->date=date;
	tmp->link=start;
	start=tmp;
}


void Runner :: del(string name)
{
	struct node *tmp,*q;
	if(start->name == name)
	{
		tmp=start;
		start=start->link;
		delete(tmp);
		return;
	}
	q=start;
	while(q->link->link!=NULL)
	{
		if(q->link->name==name)	       
		{
			tmp=q->link;
			q->link=tmp->link;
			free(tmp);
			return;
		}
		q=q->link;
	}
	if(q->link->name==name)	
	{
		tmp=q->link;
		free(tmp);
		q->link=NULL;
		return;
	}
	cout<<"Element "<<name<<" not found"<<endl;
}

void Runner :: display()
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
		cout<<"------------Displayed Data----------- "<<endl;
		cout<<q->name<<"   "<<endl;
		cout<<q->date<<"   "<<endl;
		cout<<q->assignto<<"   "<<endl;
		q=q->link;
	}
	cout<<endl;
}
