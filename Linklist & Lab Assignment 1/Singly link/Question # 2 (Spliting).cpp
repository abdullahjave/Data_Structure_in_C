#include<iostream>
#include<stdlib.h>
using namespace std;


struct node 
{
	int data ;
	struct node *link;	
}*start , *start2;

void createlist(int);
void splite(int);
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

				case 2 :
					{
						cout<<"Enter the Data of Node"<<endl;
						
						cin>>data2;
						splite(data2);
						cout<<"Splite Done";
						break;
					}
				case 3 :
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

void splite(int data){
	struct node *q,*temp;
	
	if(start == NULL)
	{
		cout<<"Not possible "<<endl;
		return;
	}
	
	
		q=start;
		while(q->link != NULL)
		{
			if(q->data == data)
			{
				temp = q;
				start2 = temp->link;
				temp->link = NULL;
				return;
			}
			q=q->link;
		}
		return;
	}


void show()
{
	struct node *q,*q2;
	
	q=start;
	q2=start2;
	
	if(start==NULL)
	{
		cout<<"List is Emeespty"<<endl;
		return;
	}
	cout << "Split 1st List:" << endl;
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }

    cout << endl;

    cout << "Split 2nd List:" << endl;
    while(q2 != NULL)
    {
        cout << q2->data << " ";
        q2 = q2->link;
    }

    cout << endl;

}

