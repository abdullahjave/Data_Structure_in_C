#include<iostream>
#include<stdlib.h>
using namespace std;


struct node 
{
	int data ;
	struct node *link;
	struct node *prev;	
}*start , *start2;

void createlist(int);
void createlist2(int);
void coping();
void show();


int main()
{
	start = NULL;
	start2 = NULL;
	int data,data2;
	int n;

	while(1)
	{
		int choice ;
	cout<<"Enter the Choice " <<endl;
	cin>>choice;
		switch(choice )
		{
			case 1:
				{
					
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
					
					cout<<"Creating List 2 with node :"<< n <<endl;
					for(int i=0 ; i<n ; i++)
					{
						
						cout<<"Enter data : "<<endl;
						cin>>data2;
						createlist2(data2);
					}
					break;	
					}
				case 3 :
					{
						cout<<"Coping nodes "<<endl;
						coping();
						break;
					}
//				case 2 :
//					{
////						cout<<"Enter the Data of Node"<<endl;
////						
////						cin>>data2;
////						splite(data2);
////						cout<<"Splite Done"
////						break;
//					}
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
					temp->prev=NULL;
					
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
						temp->prev = q;
					}
}

void createlist2(int data2)
{
	struct node *q2,*temp2;

	temp2 = new(struct node );
	temp2->data = data2;
	temp2->link = NULL;
	temp2->prev = NULL;
	
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
		temp2->prev = q2;		
	}
}

void coping()
{
    struct node *q, *q2;

    q = start;
    q2 = start2;

    while (q != NULL)
    {
        q2->data = q->data;
        q = q->link;
        q2 = q2->link;
    }
}

//
//void splite(int data){
//	struct node *q,*temp;
//	
//	if(start == NULL)
//	{
//		cout<<"Not possible "<<endl;
//		return;
//	}
//	
//	
//		q=start;
//		while(q->link != NULL)
//		{
//			if(q->data == data)
//			{
//				temp = q;
//				start2 = temp->link;
//				temp->link = NULL;
//				return;
//			}
//			q=q->link;
//		}
//		return;
//	}
//
void show()
{
    struct node *q, *q2;

    q = start;
    q2 = start2;

    if (q == NULL)
    {
        cout << "First list is empty" << endl;
        return;
    }

    cout << "First List:" << endl;
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }

    cout << endl;

    if (q2 == NULL)
    {
        cout << "Copied list is empty" << endl;
        return;
    }

    cout << "Copied List:" << endl;
    while (q2 != NULL)
    {
        cout << q2->data << " ";
        q2 = q2->link;
    }

    cout << endl;
}

