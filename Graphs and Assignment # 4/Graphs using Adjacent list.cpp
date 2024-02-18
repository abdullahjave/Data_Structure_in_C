#include <iostream>
using namespace std;


struct edge;

struct node
{
    struct node *nodelink;
    char data;
    struct edge *next;
} *start = NULL;

struct edge
{
    char info;
    struct edge *link;
};

struct node *find(char data);
void delete_node(char );
void insert_node(char data);
void delnode_edge(char data);
void insert_edge(char origin , char destin);
void del_edge(char origin,char destin);
void display();


int main ()
{
	int choice;
	char data , origin , destin;
	
	while(1)
	{
		cout<<"Insert a Node "<<endl;
		cout<<"Delete a Node "<<endl;
		cout<<"Insert a Edge "<<endl;
		cout<<"Delete a Edge "<<endl;
		cout<<"Display "<<endl;
		cout<<"Exit "<<endl;
		cout<<"Enter your Choice : ";
		
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					cout<<"Enter a Node to be Inserted : "<<endl;
					cin>>data;
					insert_node(data);
					break;
				}
			case 2:
				{
					cout<<"Enter Node to be Deleted : "<<endl;
					cin>>data;
					// this funt deletes the node from header node lish
					delete_node(data);
					//this fn delete all Edges coming to this node
					delnode_edge(data);
					break;
				}
			case 3:
				{
					cout<<"Enter the Edge to be Inserted : "<<endl;
					cin>>origin ;
					cin>>destin;
					
					insert_edge(origin , destin);
					break;
				}
			case 4:
				{
					cout<<"Enter an Edge to be Deleted : "<<endl;
					cin>>origin ;
					cin>>destin;
					
					del_edge(origin,destin);
					break;
					
				}
			case 5:
				{
					display();
					break;	
				}
			case 6:
				{
					cout<<" :: End of Program ::"<<endl;
					exit(1);
					break;
				}
	}
}
}

void insert_node(char data)
{
	struct node *temp, *q;
	
	// create node 
	temp = new struct node ;
	temp->data = data;
	temp->next = NULL;
	temp->nodelink = NULL;
	
	if(start == NULL)
	{
		start = temp;
		return;
	}
	else
	{
		q = start;
		//   
		while(q->next != NULL)
		{
			q = q->next;
		}
		
		q->next = temp; 
		
	}
}

void delete_node(char u )
{
	struct node *q , *temp;
	
	
	if(start->data == u)
	{
		temp = start;
		start = start->next; 
		temp->next = NULL;
		delete(temp);
		return;
	}
	q=start;
	
	while(q->next->next != NULL)
	{
		if(q->next->data == u )
		{
			temp = q->next;
			q->next = q->next->next;
			temp->next = NULL;
			delete(temp);
			return;
		}
		q=q->next;
	}
	
	if(q->next->data == u )
	{
		temp=q->next;
		delete(temp);
		q->next = NULL;
	}
}

void delnode_edge(char v)
{
	struct node *q;
	struct edge *temp, *p;
	
	q = start;
	while(q != NULL)
	{
	if(q->nodelink->info == v )
	{
		temp = q->nodelink;
		q->nodelink = q->nodelink->link;
		temp=NULL;
		delete(temp);
		continue ;
	}
	
	p = q->nodelink;
	
	while(p->link->link != NULL)
	{
		if(p->link->info == v)
		{
		temp = p->link;
		p->link = temp->link;
		delete(temp);
		continue;
		}
		p = p->link;
	}
	
	if(q->link->info == v)
	{
		temp = q->link;
		delete(temp);
		q->link = NULL;
	}
	q= q->link	
}
}

struct node *find(char data )
{
	struct node *loc, *ptr;
	
	ptr= start;
	
	while(ptr!=NULL)
	{
		if(data == ptr->data)
		{
			loc = ptr;
			return loc;
		}
	ptr=ptr->next;
	
	}
	loc=NULL;
	return loc;
}

void insert_edge(char u, char v)
{
    struct node *locu, *locv;
    struct edge *q, *temp;

    locu = find(u);
    locv = find(v);

    if (locu == NULL)
    {
        cout << "No Node Found " << endl;
        return;
    }
    if (locv == NULL)
    {
        cout << "No Node Found, insert First " << endl;
        return;
    }
    temp = new struct edge;
    temp->info = v;
    temp->link = NULL;

    if (locu->nodelink == NULL)
    {
        locu->nodelink = temp;
        return;
    }
    else
    {
        q = locu->nodelink;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = temp;
    }
}

void del_edge(char u , char v )
{
	struct node *locu ,*locv ;
	struct edge *q , *temp;
	
	locu = find(u);
	
	if(locu == NULL)
	{
		cout<<"Source Node not present "<<endl;
		return;
	}
	
	if(locu->nodelink->info == v )
	{
		temp = locu->nodelink ;
		locu->nodelink = temo->link ;
		temp->link = NULL;
		delete(temp);
		return;
	}
	q = locu->nodelink;
	
	while(q->link->link != NULL)
	{
		if(q->link->info == v)
		{
			temp = q->link;
			q->link = temp->link;
			temp->link = NULL;
			delete(temp);
			return; 
		}
		q= q->link;
	}
	if(q->link->info == v )
	{
		temp = q->link;
		q->link = NULL; 
		delete(temp);
		return;
	}
	
}

void display()
{
	struct node *ptr ; 
	struct edge *q;
	
	ptr=start;
	
	while(ptr != NULL)
	{
		// for Nodes / vertices / Double link list
		cout<<ptr->data;
		q = ptr->nodelink ;
		
		//for Edges / Single link list 
		while(q!=NULL)
		{
			cout<<q->info;
			q = q->link;
		}
		cout<<"\n";
		ptr=ptr->next;
		
	}	
}
