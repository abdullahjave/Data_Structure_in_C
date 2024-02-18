//Write a program to remove first node of the linked list and insert it at the end.

#include<iostream>
#include<stdlib.h>
using namespace std;


struct node 
{
	int data ;
	struct node *link;	
}*start ;

void createlist(int);
//void removeplace(int);
void remEndatbeg(int );
////void splite(int);
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
				
				case 2:
					{
						cout<<"Enter the Node add and Delete"<<endl;
						int data1;
						cin>>data1;
						remEndatbeg(data1);
						break;
					}
//				case 3 :
//				{
//					cout<<"Enter the Data of First node for Remove nad Place it end "<<endl;
//					cin>>data;
//					removeplace(data);
//					break;
//				}
				
				

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

void remEndatbeg(int data)
{
	struct node *q,*temp;
	
	q=start;
	
	while(q->link != NULL)
	{
		q=q->link;
		
	}
	if(q->data == data)
	{
		temp=start;
		while(temp->link!=q)
		{
			temp = temp->link;
		}
		temp->link = NULL;
		q->link = start;
		start = q;
	}
	else 
	{
		cout<<"Not Match Found"<<endl;
		return;
	}
}
//
//void removeplace(int data)
//{
//	struct node *q,*temp;
//	
//	q=start;
//	while(q->link != NULL)
//	{
//		q=q->link;
//	}
//	
//	if(start->data == data)
//	{
//		temp=start;
//		start=start->link;
//		temp->link =NULL;
//		q->link = temp ;
//	}
//	
//	else
//	{
//		cout<<"Node Not Found "<<endl;
//	}
//}

void show()
{
	struct node *q;
	
	q=start;

	
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


}

