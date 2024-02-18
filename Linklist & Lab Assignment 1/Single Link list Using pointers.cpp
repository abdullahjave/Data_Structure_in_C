#include<iostream>
#include <conio.h>   
using namespace std;
struct node{
	int info;
	node *link;
};

node *start;
node *start1;
node *start2;
void create_new_node(node **root, int data){
	node *q,*temp;
	temp=new node;
	temp->info=data;
	temp->link=NULL;
		if(*root==NULL){
			*root=temp;
		}
		else{
			q=*root;
			while(q->link!=NULL){
				q=q->link;
			}
			q->link=temp;
		}
}
void insertion_at_beg(node **root,int data){
	node *temp;
	temp=new node;
	temp->info=data;
	temp->link=*root;
	*root=temp;
}
void insertion_in_last(node **root,int value)
 {
  node *temp;
  temp = new node;
  temp->info=value;
  temp->link=NULL;
  if(*root==NULL)
  {
   *root=temp;
  }
 else
  {
  node *temp1=*root;
  while(temp1->link!=NULL)
   {
    temp1=temp1->link;
   }
  temp1->link=temp;
  }
 }
void insertion_at_Middle(node **root,int data,int pos){
	node *temp,*q;
	int i;
	q=*root;
	for(i=0;i<pos-1;i++){
		q=q->link;
		if(q==NULL){
			cout<<"There are less than "<<pos<<" elements"<<endl;
			return;
		}
		temp=new node;
		temp->link=q->link;
		temp->info=data;
		q->link=temp;
	}
}
void print(node* root)
{
	node *q=root;
    while (q != NULL) {
        cout << (char)q -> info <<endl;
        q = q->link;
    }
 
    cout<<endl;
}

void newnode(node** root){
	char choice;
	cout<<"Want To make A new Node (y/n)"<<endl;
	cin>>choice;
	if(choice == 'y'){
		char data;
		cout<<"Enter Data"<<endl;
		cin>>data;
		
		create_new_node(root,(int)data);
	}
	else{
		cout<<"Thanks"<<endl;
	}
}
//deletion
void deletion_from_start(node **root,int data){
	node*temp,*q=*root;
	if(q->info==data){
		temp=q;
		q=q->link;
		delete temp;
		return;
	}
}
void deletion_from_Middle(node **root,int data){
	node*temp,*q;
	q=*root;
	while(q->link->link!=NULL){
		if(q->link->info==data){
			temp=q->link;
			q->link=temp->link;
			delete temp;
			return;
		}
		q=q->link;
	}
}
void deletion_from_End(node **root,int data){
	node*temp,*q=*root;
if(q->link->info==data){
	temp=q->link;
	delete temp;
	q->link=NULL;
	return;
}
else{
	cout<<data<<" Not Found"<<endl;
}
}
void count(node **root,int data){
	node *q=*root;
	int count=0;
	while(q!=NULL){
		q=q->link;
		count++;
	}
	cout<<"Total Numbers Of Elements are "<<count<<endl;
}
void rev(node **root){
	node *p1,*p2,*p3,*p4=*root;
	if(p4->link==NULL){
		return;
	}
	p1=*root;
	p2=p1->link;
	p3=p2->link;
	p1->link=NULL;
	p2->link=p1;
	while(p3!=NULL){
		p1=p2;
		p2=p3;
		p3=p3->link;
		p2->link=p1;
	}
	*root=p2;
}
void search(node **root,int data){
	node* ptr=*root;
	int pos=1;
	while(ptr!=NULL){
		if(ptr->info==data){
			cout<<"Item is found at "<<pos<<" position"<<endl;
			return;
		}
		ptr=ptr->link;
		pos++;
	}
	if(ptr==NULL){
		cout<<"Not Found"<<endl;
	}
}
void concatenation(node **root,node **root1){
	node *q;
	node *n=*root;
	node *n1=*root1;
	if(n==NULL||n1==NULL){
		cout<<"No Linked List to Concatenate"<<endl;
	}
	else{
			q=*root;
			while(q->link!=NULL){
				q=q->link;
			}
			q->link=n1;
	}
	
		
		 do{
			cout<<(char)n->info<<endl;		
            n=n->link;
        }while(n!=NULL);
        
}
void splitting(node **root){
	node *q,*q1,*p1=*root;
	int count=1;
	if(*root==NULL||p1->link==NULL){
		cout<<"No Linked List to Split"<<endl;
	}
	else{
			q=*root;
			while(q->link!=NULL){
				q=q->link;
				count++;
			}
			cout<<"Splitted Array List is :"<<endl;
			q1=*root;
			for(int i=0;i<count/2;i++){
				cout<<q1->info<<endl;
				q1=q1->link;
			}
	}
}
void copying (node **root,node **root1){
	node *q=*root,*q1;
	if(root==NULL){
		cout<<"No Linked List to Copy"<<endl;
	}
	else{
		q=*root;
		cout<<"Before Copying Linked List"<<endl;
		do{
            cout<<(char)q->info<<endl;
            q=q->link;
        }while(q!=NULL);
        cout<<"After  Copying Linked List"<<endl;
		*root1=*root;
		q1=*root1;
		do{
            cout<<(char)q1->info<<endl;
            q1=q1->link;
        }while(q1!=NULL);
	}
}
void firstnode_last(node **root){
	node *p1,*p2,*p3=*root,*q;
	if(p3==NULL||p3->link==NULL){
		cout<<"No Linked List "<<endl;
	}
	p1=p3;
	p2=p1->link;
	p1->link=NULL;
	p3=p2;
	q=p2;
		while(q->link!=NULL){
			q=q->link;
		}
		q->link=p1;
		
	print(p3);
  	
}
void lastnode_first(node **root){
		node *p1=*root,*q,*q1,*temp;
	if(p1==NULL||p1->link==NULL){
		cout<<"No Linked List "<<endl;
	}
	else{
	q=p1;
		while(q->link!=NULL){
			
			if(q->link->link==NULL){
			temp=q;
		}
			q=q->link;	
		}
		q->link=p1;
		p1=q;
		temp->link=NULL;
		

	print(p1);	
}
}

void menu(){

	cout<<"		MENU			"<<endl;
	cout<<"Select from Following:"<<endl;
	cout<<"1. Create Node "<<endl;
	cout<<"2. Insertion "<<endl;
	cout<<"3. Deletion "<<endl;
	cout<<"4. Transverse"<<endl;
	cout<<"5. Concatenation"<<endl;
	cout<<"6. Splitting"<<endl;
	cout<<"7. Copying"<<endl;
	cout<<"8. Remove First Node and Insert at End"<<endl;
	cout<<"9. Remove Last Node and Insert at First"<<endl;
	cout<<"10. Exit		"<<endl;
	cout<<"Enter Your choice"<<endl;
	int choice;
	cin>>choice;
	do{
	switch(choice){
		case 1:
			{
				int choice;
				cout<<"1. for int 2. for char 3.For Exit"<<endl;
				cin>>choice;
				if(choice==1){
					newnode(&start);
				}	
				
				if(choice==2){
				newnode(&start1);
				}
				if(choice==3)
				{
					menu();
				}
				
				break;
			}
		case 2:
			{
				int choice2;
				cout<<endl;
				cout<<"1. Insert in Beginning"<<endl;
				cout<<"2. Insert in Any Position"<<endl;
				cout<<"3. Insert in End"<<endl;
				cout<<"Enter Your choice"<<endl;
				cin>>choice2;
				switch(choice2){
					case 1:
						{
						char data;
						cout<<"Enter Data"<<endl;
						cin>>data;
						insertion_at_beg(&start,(int)data);
							break;
						}
					case 2:
						{
						char data,pos;
						cout<<"Enter Data"<<endl;
						cin>>data;
						cout<<"Enter Position"<<endl;
						cin>>pos;
						insertion_at_Middle(&start,(int)data,(int)pos);
							break;
						}
					case 3:
						{
						char data;
						cout<<"Enter Data"<<endl;
						cin>>data;
						insertion_in_last(&start,(int)data);
							break;
						}					
				}
				break;
			}
		case 3:
			{
				int choice2;
				cout<<endl;
				cout<<"1. Delete From The Beginning"<<endl;
				cout<<"2. Delete From Any Position"<<endl;
				cout<<"3. Delete From The End"<<endl;
				cout<<"Enter Your choice"<<endl;
				cin>>choice2;
				switch(choice2){
					case 1:
						{
						char data;
						cout<<"Enter Data"<<endl;
						cin>>data;
						deletion_from_start(&start,(int)data);
						cout<<"Linked List After Deletion is:"<<endl;
						print(start);
							break;
						}
					case 2:
						{
						char data;
						cout<<"Enter Data"<<endl;
						cin>>data;
						deletion_from_Middle(&start,(int)data);
						cout<<"Linked List After Deletion is:"<<endl;
						print(start);
							break;
						}
					case 3:
						{
						char data;
						cout<<"Enter Data"<<endl;
						cin>>data;
						deletion_from_End(&start,(int)data);
						cout<<"Linked List After Deletion is:"<<endl;
						print(start);
							break;
						}					
				}
				break;
			}
		case 4:
			{
				int choice2;
				cout<<endl;
				cout<<"1. Print Linked List"<<endl;
				cout<<"2. Search Number"<<endl;
				cout<<"3. Count TOtal Nodes"<<endl;
				cout<<"4. Reverse Linked List"<<endl;
				cout<<"Enter Your choice"<<endl;
				cin>>choice2;
				switch(choice2){
					case 1:
						{
						print(start);
							break;
						}
					case 2:
						{
						int data;
						cout<<"Enter Data"<<endl;
						cin>>data;
						search(&start,data);
							break;
						}
					case 3:
						{
						int data;
						cout<<"Enter Data"<<endl;
						cin>>data;
						count(&start,data);
							break;
						}
					case 4:
						{
						rev(&start);
						char choice;
						cout<<"Do you Want to show the Reverse Linked List(y/n)"<<endl;
						cin>>choice;
						if(choice=='y'){
							print(start);
						}
						else{
							menu();
						}
							break;
						}		
								
				}
				break;
			}
		case 5:
		{
		char choice1;
		cout<<"In order to Concatenate You Have to Enter 2 Linked Lists"<<endl;
		cout<<"Press Enter For 1st Linked list of Numbers"<<endl;
		getch();   
		do{
					newnode(&start);
					cout<<"Enter Another Node (y/n)"<<endl;
					cin>>choice1;
				}while(choice1!='n');
		cout<<"Press Enter For 2nd Linked list of Characters"<<endl;
		getch();
		char choice2;
				do{
					newnode(&start1);
					cout<<"Enter Another Node (y/n)"<<endl;
					cin>>choice2;
				}while(&start,&start1);
			break;
				}
		case 6:
		{
			splitting(&start);
			break;		
			}	
		case 7:
		{
			copying (&start,&start2);
			break;
						}	
		case 8:
		{
			firstnode_last(&start);
			
			break;
		}
		case 9:
		{
		lastnode_first(&start);
		
			break;
		}							
		case 10:
            	{
            		exit(0);
            		break;
				}	
	}}while(choice!=0);
	}


int main()
{
	menu();
}
