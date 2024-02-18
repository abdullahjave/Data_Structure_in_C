#include<iostream>
#include<stdlib.h>
using namespace std;


struct node 
{
	int data ;
	struct node *link;	
}*start ;

void createlist(int);
void swap();
void show();


int main()
{
	start = NULL;

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
				
				case 2 :
					{
						swap();
						break;
					}

				case 3:
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

void swap ()
{
	struct node *temp ,*q,*swap1,*swap2;
	temp = new (struct node );
	temp->link = start;
	q=temp;
	
	while (q->link != NULL && q->link->link != NULL)
	{
		swap1 = q->link;
		swap2 = q->link->link;
		
		swap1->link = swap2->link;
		swap2->link = swap1 ;
		
		q->link = swap2;
		q=swap1;
		
		
			}
			start = temp->link;		
	}


void show()
{
	struct node *q;
	
	q=start;

	
	if(start==NULL)
	{
		cout<<"List is Emeespty"<<endl;
		return;
	}
	cout << "1st List:" << endl;
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }

    cout << endl;


}

