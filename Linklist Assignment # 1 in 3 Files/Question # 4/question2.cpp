#include "question2.h"
#include<stdlib.h>
#include<string>
using namespace std;


void Runner :: menu()
{
	 int choice, roll_no, k, n, pos;
    string name, sclass, addr, m, p;
   

    while (1)
	 {
        cout << "1.Create the list of the students." << endl;
        cout << "2.Add the student at the beginning of the list." << endl;
//        cout << "3.Add the student after another student position in the list." << endl;
        cout << "3.Delete a student record from the list." << endl;
        cout << "4.Display Student list(alphabetically)." << endl;
        cout << "5. Search Student from the list." << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice" << endl;
        cin >> choice;

        if (choice == 6) {
            break; // Exit the loop if the user chooses option 7
        }

        switch (choice) {
            case 1:
                cout << "How many students you want to add in list?" << endl;
                cin >> n;
                cin.ignore();
                for (k = 0; k < n; k++) {
                    cout << "Enter Name of the student " << k + 1 << " :";
                    getline(cin, name);
                    cout << "Enter Roll Number of " << name << ":";
                    cin >> roll_no;
                    cin.ignore();
                    cout << "Enter Class/Section:";
                    getline(cin, sclass);
                    cout << "Enter Address:";
                    getline(cin, addr);
                    createlist(name, roll_no, sclass, addr);
                }
                break;
			case 2:
                cin.ignore();
                cout << "Enter Name of the student " << k + 1 << " :";
                getline(cin, name);
                cout << "Enter Roll Number of " << name << ":";
                cin >> roll_no;
                cin.ignore();
                cout << "Enter Class/Section:";
                getline(cin, sclass);
                cout << "Enter Address:";
                getline(cin, addr);
                addtolistbeg(name, roll_no, sclass, addr);
                break;

            case 3:
                if (start == NULL) {
                    cout << "List is empty" << endl;
                    continue;
                }
                cout << "Enter Student's name for deletion" << endl;
                cin >> m;
                del(m);
                break;
            case 4:
                sortList();
                DisplayList();
                break;
            case 5:
                if (start == NULL) {
                    cout << "List is empty" << endl;
                    continue;
                }
                cout << "Enter student name to be searched in the list:";
                cin >> p;
                search(p);
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

	
}
void Runner :: createlist(string name, int roll_no, string sclass, string addr) {
    struct node *tmp, *q;
    tmp = new node();
    tmp->name = name;
    tmp->roll_no = roll_no;
    tmp->sclass = sclass;
    tmp->addr = addr;
    tmp->prev = NULL;
    tmp->next = NULL;
    if (start == NULL)
        start = tmp;
    else {
        q=start;
        while(q->next!=NULL)	q=q->next;
        q->next=tmp;
        tmp->prev=q;
    }
}

void Runner ::addtolistbeg(string name, int roll_no, string sclass, string addr) {
    struct node *tmp;
    tmp = new node();
    tmp->name = name;
    tmp->roll_no = roll_no;
    tmp->sclass = sclass;
    tmp->addr = addr;
    start->prev = tmp;
    tmp->next = tmp;
    start = tmp;
}

//void Runner :: addtolistafter(string name, int roll_no, string sclass, string addr, int pos) {
//    struct node *newnode, *temp;
//    int i = 1, count = 0;
//    temp = head;
//    while (temp != NULL) {
//        temp = temp->next;
//        count++;
//    }
//    if (pos <= 0 || pos > count + 1) {
//        cout << "Invalid Position." << endl;
//    } else {
//        temp = head;
//        newnode = new node();
//        while (i < pos) {
//            temp = temp->next;
//            i++;
//        }
//        newnode->prev = temp;
//        newnode->next = temp->next;
//        if(temp->next!=NULL)
//        {
//        	temp->next->prev=newnode;
//		}
//        temp->next = newnode;
//    }
//}
//
void del(int name)
{
	struct node *tmp,*q;
	if(start->name==name)
	{
		tmp=start;
		start=start->next;	
		start->prev=NULL;
		free(tmp);
		return;
	}
	q=start;
	while(q->next->next!=NULL)
	{
		if(q->next->name==name)	       
		{
			tmp=q->next;
			q->next=tmp->next;
			tmp->next->prev=q;
			free(tmp);
			return;
		}
		q=q->next;
	}
	if(q->next->name==name)		
	{
		tmp=q->next;
		free(tmp);
		q->next=NULL;
		return;
	}
	cout<<"Element "<<name<<" not found"<<endl;
}
void Runner ::sortList() {
    struct node *i, *j, *q;
    q = start;
    string tempName, tempClass, tempAddr;
    int tempRoll_no;

    for (i = start; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->name > j->name) {
                // Swap data
                tempName = i->name;
                tempRoll_no = i->roll_no;
                tempClass = i->sclass;
                tempAddr = i->addr;

                i->name = j->name;
                i->roll_no = j->roll_no;
                i->sclass = j->sclass;
                i->addr = j->addr;

                j->name = tempName;
                j->roll_no = tempRoll_no;
                j->sclass = tempClass;
                j->addr = tempAddr;
            }
        }
    }
}

void Runner ::DisplayList() {
    struct node *q;
    q = start;

    while (q != NULL) {
        cout << "Student Name: " << q->name << " , Roll Number: " << q->roll_no
             << " ,Class/Section: " << q->sclass << " ,Address: " << q->addr << endl;
        q = q->next;
    }
}

void Runner ::search(string name) {
    struct node *q;
    q = start;
    bool found = false;
    while (q != NULL) {
        if (q->name == name) {
            found = true;
            cout << "Student found." << endl;
            cout << "Student Name: " << q->name << ", Roll Number: " << q->roll_no
                 << ", Class/Section: " << q->sclass << ", Address: " << q->addr << endl;
            break;
        }
        q = q->next;
    }
    if (!found) {
        cout << "Student with name " << name << " not found." << endl;
    }
}

