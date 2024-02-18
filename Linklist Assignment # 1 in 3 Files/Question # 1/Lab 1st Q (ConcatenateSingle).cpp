#include<iostream>
#include<stdlib.h>
using namespace std;


struct node 
{
	int data ;
	struct node *link;	
}*start , *start2;

void createlist(int);
void createlist2(int);
void concatenate();
void show();


int main()
{
	start = NULL;
	start2 = NULL;
	int data,data2;
	

	while(1)
	{
		int choice ;
	cout<<"Enter the Choice " <<endl;
	cin>>choice;
		switch(choice )
		{
			case 1:
				{
					int n;
					cout<<"How many node u want "<<endl;
					cin>>n;
					for(int i=0 ; i<n ; i++)
					{
						cout<<"Enter data : "<<endl;
						cin>>data;
						createlist(data);
					}
					break;
				}
				case 2:
				{
				int n1;
					cout<<"How many in list2 node u want "<<endl;
					cin>>n1;
					cout<<"Creating List 2"<<endl;
					for(int i=0 ; i<n1 ; i++)
					{
						
						cout<<"Enter data : "<<endl;
						cin>>data2;
						createlist2(data2);
					}
					break;	
				}
				case 3 :
					{
						cout<<"Action Performed"<<endl;
						concatenate();
						break;
					}
				case 4 :
					{
						show();
					break;
				}
				default:
                cout << "Invalid choice." << endl;
                break;
        }
        
       
}

}




void createlist(int data)
{
	struct node *q,*temp;

	
					temp = new(struct node);
					temp->data=data;
					temp->link=NULL;
	
					if(start==NULL)
					{
						start=temp;
					}
					else
					{
						q=start;
						while(q->link != NULL)
						{
							q=q->link;
						}
						q->link = temp;
					}
}

void createlist2(int data2)
{
	
	struct node *q2,*temp2;

	temp2 = new(struct node );
	temp2->data = data2;
	temp2->link = NULL;
	
	if(start2 == NULL)
	{
		start2=temp2;
	}
	else
	{
		q2=start2;
		while (q2->link != NULL)
		{
			q2=q2->link;
		}
		
		q2->link = temp2;
		
		
	}
}

void concatenate()
{
	struct node *q;
	
	if(start2 == NULL)
	{
		cout<<"link not found";
	}
	else
	{
		q=start;
		while(q->link!=NULL)
		{
			q=q->link;
		}
		
		q->link = start2;
		start2=NULL;
	}
	
}

void show()
{
	struct node *q;
	
	q=start;
	
	if(start==NULL)
	{
		cout<<"List is Emeespty"<<endl;
	}
	while(q!=NULL)
	{
		
		cout<<"Data is : "<<q->data<<endl;
		q=q->link;
	}
	
}

