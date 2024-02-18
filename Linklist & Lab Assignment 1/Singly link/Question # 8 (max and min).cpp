#include<iostream>
#include<stdlib.h>
using namespace std;


struct node 
{
	int data ;
	struct node *link;	
}*start ;

void createlist(int);
void ava();
void maxmin();
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
						maxmin();;
						break;
					}
				
				case 3:
					{
						ava();
						break;
				}				
				

				case 4:
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

void maxmin()
{
	struct node *q;
	int max=0;
	
	
	if(start == NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	
	q=start;
	if (q != NULL)
    {
    	int min ;
        min = q->data; 
        q = q->link; 
	while(q!=NULL)
	{
		if(max < q->data)
		{
			max = q->data;
		}
		if(min > q->data)
		{
			min = q->data;
		}
		q=q->link;
	}
	cout<<"Maximum Number is : "<<max<<endl;
	cout<<"Minimum Number is : "<<min<<endl;
}
}

void ava()
{
    struct node *q;
    int sum = 0;
    int count = 0;

    if (start == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        q = start;
        while (q != NULL)
        {
            sum =sum + q->data;
            count++;
            q = q->link;
        }
        float avg = (sum) / count;
        cout << "Average is: " << avg << endl;
    }
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

