#include "question2.h"
#include<stdlib.h>
#include<string>
using namespace std;

void Runner :: menu()
{
	int choice,n,age,position,i;
	string pname,country, m;
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
					cin.ignore();
					cout<<"Enter the player name"<<endl;
					getline(cin,pname);
					cout<<"Enter the country of player "<<endl;
					getline(cin,country);
					cin.ignore();
					cout<<"Enter the age of player "<<endl;
					cin>>age;
					createlist(pname, country, age);
				}
				break;
			case 2:
				cin.ignore();
				cout<<"Enter the player name"<<endl;
				getline(cin,pname);
				cout<<"Enter the country of player "<<endl;
				getline(cin,country);
				cin.ignore();
				cout<<"Enter the age of player "<<endl;
				cin>>age;
				addatbeg(pname, country, age);
				break;
			case 3:
				cin.ignore();
				cout<<"Enter the player name"<<endl;
				getline(cin,pname);
				cout<<"Enter the country of player "<<endl;
				getline(cin,country);
				cin.ignore();
				cout<<"Enter the age of player "<<endl;
				cin>>age;
				cout<<"Enter the position after which this element is inserted"<<endl;
				cin>>position;
				addafter(pname, country, age, position);
				break;
			case 4:
				if(last==NULL)
				{
					cout<<"List is empty"<<endl;
					continue;
				}
				cin.ignore();
				cout<<"Enter the name of the player for deletion"<<endl;
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
void Runner :: createlist(string pname, string country, int age)
{
	struct node *tmp, *q;
	tmp = new (struct node);
	tmp->pname = pname;
	tmp->country = country;
	tmp->age=age;
	if(last == NULL)
	{
		last=tmp;
		tmp->link=last;
	}
	else{
		
		tmp->link=last->link;
		last->link=tmp;
		last=tmp;

	}
	
}

void Runner ::addatbeg(string pname, string country, int age)
{
	struct node *tmp;
	tmp=new (struct node);
	tmp->pname=pname;
	tmp->country=country;
	tmp->age=age;
	tmp->link=last->link;
	last->link=tmp;
}

void Runner :: addafter(string pname, string country, int age, int pos)
{
	struct node *q, *tmp;
	q=last->link;
	for(int i=0; i<pos; i++)
	{
		q=q->link;
		if(q==last->link)
		{
			cout<<" There are less than"<< pos<<" elements "<<endl;
			return;
		}
	}
	tmp = new (struct node);
	tmp->pname=pname;
	tmp->country=country;
	tmp->age=age;
	tmp->link=q->link;
	q->link=tmp;
	if(q==last){
	    last=tmp;
  }
}

void Runner :: del(string name) 
{
	struct node *q, *tmp;
	q=last->link;
	if(q->pname==name)
	{
		tmp=q;
		last->link=tmp->link;
		delete(tmp);
		return;
	}
	q=last->link;
	while(q->link->link!=last->link)
	{
	    if(q->link->pname==name)
		{
			tmp=q->link;
		    q->link=tmp->link;
			delete(tmp);
			return;	
		}	
		q=q->link;
	}	
	if(q->link->pname==name)
	{
		tmp=q->link;
		q->link=last->link;
		delete(tmp);
		last=q;
		return;
	}
	cout<<"element"<<name<<" not found"<<endl;
}

void Runner :: display() {
    struct node *q;
    if (last == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    q = last->link;
    cout << "List is:" << endl;

    do {
        cout << q->pname <<endl;
        cout << q->country <<endl;
		cout << q->age <<endl;
		q = q->link;
    } while (q != last->link);

    cout << endl;
}
