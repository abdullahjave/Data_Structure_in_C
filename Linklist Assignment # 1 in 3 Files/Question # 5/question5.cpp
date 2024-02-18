
#include "question5.h"
#include<iostream>
#include<cstdlib>
using namespace std;

void Runner :: menu ()
{
	int choice,n;
	string name, artist, genre, sd;
	start=NULL;
	while(1)
	{
		cout<<"1. Create List"<<endl;
		cout<<"2. Add song at the end"<<endl;
		cout<<"3. Delete"<<endl;
		cout<<"4. Display the playlist in forward way"<<endl;
		cout<<"5. Display the playlist in backward way"<<endl;
		cout<<"6. Quit"<<endl;

		cout<<"Enter ur choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"How many songs you want to add: "<<endl;
				int n;
				cin>>n;
				if(n>4)
				{
					cout<<"Can't Enter "<<endl;	
				}
				else 
				{
				
				cin.ignore();
				
				for(int i=0; i<n; i++)
				{
					cout<<"======================================================"<<endl;
					cout<<"Enter the name of the song "<<endl;
					getline(cin,name);
					cout<<"Enter the artist name  "<<endl;
					getline(cin,artist);
					cout<<"Enter the genre of the song "<<endl;
					getline(cin,genre);
					create_playlist(name, artist, genre);
					cout<<endl;
				}
			}
				break;
			case 2:
				cin.ignore();
				cout<<"Enter the name of the song you want to add at the end of the playlist  "<<endl;
				getline(cin,name);
				cout<<" Enter the name of the artist "<<endl;
				getline(cin,artist);
				cout<<"Enter the genre of song "<<endl;
				getline(cin,genre);
				addatend(name, artist, genre);
				break;

			case 3:
				cout<<"Enter the name of the song you want to delete"<<endl;
				cin>>sd;
				del(sd);
				cout<<"Song is Deleted"<<endl;
				break;
			case 4:
				display_forw();
				break;
		
			case 5:
				display_back();
			    break;
			    
			case 6:
				exit(1);
			default:
				cout<<"Wrong choice"<<endl;
		}
	}
}


void Runner ::create_playlist(string name, string artist, string genre)
{
	
	struct node *q,*tmp;
	tmp=new(struct node);
	tmp->name=name;
	tmp->artist=artist;
	tmp->genre=genre;
	tmp->next=NULL;
	tmp->prev=NULL;
		

	if(start==NULL)
		start=tmp;
	else
	{
		q=start;
		while(q->next!=NULL)	q=q->next;
		q->next=tmp;
		tmp->prev=q;
	}
}

void Runner ::addatend(string name, string artist, string genre)
{
	
	struct node *q, *tmp;
	tmp=new(struct node);
	tmp->name=name;
	tmp->artist=artist;
	tmp->genre=genre;
	tmp->next=NULL;
	if(start==NULL)
	{
		tmp->prev=NULL;
		start=tmp;
	}
	else{
		q=start;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		tmp->prev=q;
		q->next=tmp;
	}
	
}

void Runner ::del(string name)
{
	struct node *tmp, *q;
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (start->name == name) {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);
        
        moveLastToFirst(); 
    
        return;
    }
	q=start;
	while(q->next->next!=NULL)
	{
		if(q->next->name==name)	       //element deleted in between/
		{
			tmp=q->next;
			q->next=tmp->next;
			tmp->next->prev=q;
			free(tmp);
			return;
		}
		q=q->next;
	}
	if(q->next->name==name)		//last element deleted/
	{
		tmp=q->next;
		free(tmp);
		q->next=NULL;
		return;
	}
	cout<<"Song "<<name<<" not found in the playlist "<<endl;
}

void Runner::moveLastToFirst()
 {
    
    struct node *l;
	l = start;
    while (l->next != NULL) 
	{
        l = l->next;
    }

    l->prev->next = NULL;
    l->prev = NULL;
    l->next = start;
    start->prev = l;
    start = l;
}

void Runner :: display_forw()
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
		cout<<q->name<<"   ";
		cout<<q->artist<<"   ";
		cout<<q->genre<<"   ";
		q=q->next;
	}
	cout<<endl;
}

void Runner ::display_back()
{
	struct node *q;
	end=start;
	while(end->next!=NULL)
	{
		end=end->next;
	}
	if(start==NULL)
	{
		cout<<"List is empty."<<endl;
		return;
	}
	q=end;
	while(q!=NULL)
	{
		cout<<"Song Name:"<<q->name<<" , Artist:"<<q->artist<<" , Genre:"<<q->genre<<endl;
		q=q->prev;
	}
}
