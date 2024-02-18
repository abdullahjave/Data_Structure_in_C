#include<iostream>
#include<stdlib.h>
using namespace std;

struct node 
{
    int info;
    int balance;
    struct node* lchild;
    struct node* rchild;
};

struct node* insert(int, struct node*, bool*);
struct node* search(struct node*, int);
void inorder(struct node*);
struct node* searching(struct node *, int);
void display(struct node*, int);

int main()
 {
    bool ht_inc;
    int info;
    int choice;
    struct node* root = NULL;
    while (1)
	{
        cout << "1.Insert\n";
        cout << "2.Display\n";
        cout << "3.Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> info;
            if (search(root, info) == NULL)
                root = insert(info, root, &ht_inc);
            else
                cout << "Duplicate value ignored\n";
            break;
        case 2:
            if (root == NULL) {
                cout << "Tree is empty\n";
            }
            cout << "Tree is :\n";
            display(root, 1);

            cout << "\n\n";
            cout << "Inorder Traversal is: ";
            inorder(root);
            cout << "\n";
            break;
        case 3:
        	{
    // Option for searching
    cout << "Enter the value to be searched: ";
    cin >> info;
    struct node* searchResult = searching(root, info);
    if (searchResult != NULL) {
        cout << "Value " << info << " found in the tree. Details: \n";
        cout << "Key: " << searchResult->info << "\n";
        cout << "Balance: " << searchResult->balance << "\n";
        // Add more details as needed (e.g., dietary information, availability status)
    }
	else
	{
        cout << "Value " << info << " not found in the tree.\n";
    }
    break;
}
        case 4:
            exit(1);
        default:
            cout << "Wrong choice\n";
        }
    }
}

struct node* search(struct node* ptr, int info) {
    if (ptr != NULL) 
	{
        if (info < ptr->info)
            ptr = search(ptr->lchild, info);
        else if (info > ptr->info)
            ptr = search(ptr->rchild, info);
    }
    return (ptr);
}

struct node* insert(int info, struct node * pptr, bool * ht_inc)
{
    struct node* aptr;
    struct node* bptr;
    if (pptr == NULL) 
	{
        pptr = new struct node;
        pptr->info = info;
        pptr->lchild = NULL;
        pptr->rchild = NULL;
        pptr->balance = 0;
        *ht_inc = true;
        return (pptr);
    }
    if (info < pptr->info) 
	{
        pptr->lchild = insert(info, pptr->lchild, ht_inc);
        
        if (*ht_inc == true) 
		{
            switch (pptr->balance)
			{
            case -1:
                pptr->balance = 0;
                *ht_inc = false;
                break;
            case 0:
                pptr->balance = 1;
                break;
            case 1:
                aptr = pptr->lchild;
                
                if (aptr->balance == 1) 
				{
                    cout << "Left to Left Rotation\n";
                    pptr->lchild = NULL;
                    aptr->rchild = pptr;
                    pptr->balance = 0;
                    aptr->balance = 0;
                    pptr = aptr;
                } 
				else 
				{
                    cout << "Left to right rotation\n";
                    bptr = aptr->rchild;
                    aptr->rchild = NULL;
                    bptr->lchild = aptr;
                    pptr->lchild = bptr->rchild;
                    bptr->rchild = pptr;
                    if (bptr->balance == 1)
                        pptr->balance = -1;
                    else
                        pptr->balance = 0;
                    if (bptr->balance == -1)
                        aptr->balance = 1;
                    else
                        aptr->balance = 0;
                    bptr->balance = 0;
                    pptr = bptr;
                }
                *ht_inc = false;
            }
        }
    }
    if (info > pptr->info) 
	{
        pptr->rchild = insert(info, pptr->rchild, ht_inc);
        
        if (*ht_inc == true) 
		{
            switch (pptr->balance)
			 {
            case 1:
                pptr->balance = 0;
                *ht_inc = false;
                break;
            case 0:
                pptr->balance = 1;
                break;
            case -1:
                aptr = pptr->rchild;

                if (aptr->balance == -1) {
                    cout << "Right to Right Rotation\n";
                    pptr->rchild = aptr->lchild;
                    aptr->lchild = pptr;
                    pptr->balance = 0;
                    aptr->balance = 0;
                    pptr = aptr;
                } 
				else
				 {
                    cout << "Right to Left Rotation\n";

                    bptr = aptr->lchild;
                    aptr->lchild = bptr->rchild;
                    bptr->rchild = aptr;
                    pptr->rchild = bptr->lchild;
                    bptr->lchild = pptr;
                    if (bptr->balance == -1)
                        pptr->balance = 1;
                    else
                        pptr->balance = 0;
                    if (bptr->balance == 1)
                        aptr->balance = -1;
                    else
                        aptr->balance = 0;
                    bptr->balance = 0;
                    pptr = bptr;
                    *ht_inc = false;
                }
            }
        }
    }
    return (pptr);
}

void display(struct node* ptr, int level) 
{
    if (ptr != NULL) 
	{

        display(ptr->rchild, level + 1);
        cout << "\n";

        for (int i = 0; i < level; i++)
            cout << " ";
        cout << (ptr->info);
        display(ptr->lchild, level + 1);
    }
}

struct node* searching(struct node* root, int key) 
{
    struct node* current ;
	current = root;

    while (current != NULL) 
	{
        if (key < current->info) 
		{
            current = current->lchild;
        }
        else if (key > current->info) 
		{
            current = current->rchild;
        }
        else
		{
            return current;
        }
    }

    return NULL;
}

void inorder(struct node* ptr) {

    if (ptr != NULL) 
	{
        inorder(ptr->lchild);
        cout << ptr->info;
        inorder(ptr->rchild);
    }
}

