
#include<iostream>
#include<stdlib.h>
using namespace std;


struct node 
{
	int data ;
	struct node *link;	
}*start ;

void createlist(int);

void evenodd();
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
						evenodd();
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

void evenodd()
{
	struct node *q;
	int nonzero =0;
	int count =0;
	if(start == NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	q=start;
	while(q != NULL)
	{
		if(q->data % 2==0)
		{
			cout<<q->data<<" : Even num "<<endl;
			count++;
		}
		else
		{
			cout<<q->data <<" : Odd num "<<endl;
			count++;
		}
		if (q->data != 0)
        {
            nonzero++;  
        }
        
		q=q->link;
}
	cout<<"Non Zero Elemts are : "<<nonzero<<endl;

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
	cout << "Split 1st List:" << endl;
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }

    cout << endl;


}

