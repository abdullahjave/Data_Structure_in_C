#include <iostream>
using namespace std;

struct node
{
    struct node *rchild;
    int info;
    struct node *lchild;
};

node *root;
struct node *foundNode; // Variable to store the result of the search
void swapNodeData(node *a, node *b);
void find(int item, struct node **par, struct node **loc);
void insert(int item);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
void preorder(struct node *ptr);
void del(int item);
void case_a(struct node *par, struct node *loc);
void case_b(struct node *par, struct node *loc);
void case_c(struct node *par, struct node *loc);
struct node *search(struct node *ptr, int info);
void lright();
void displayTree(struct node *root);

//void displayTreeStructure(struct node *ptr, int level = 0, char branch = ' ');

int main()
{
    int choice, num;

    root = NULL;
    while (1)
    {
        cout << "1. Insert Data" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Postorder Traversal" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Delete Data" << endl;
        cout << "6. Search" << endl;
        cout << "7. Display Leftmost and Rightmost" << endl;
//        cout << "8. Display Tree Structure" << endl; // Corrected the menu option
        cout << "9. Quit" << endl; // Corrected the menu option

        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element: " << endl;
            cin >> num;
            insert(num);
            break;
        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Enter element to delete: ";
            cin >> num;
            del(num);
            break;
        case 6:
            cout << "Enter element to search: ";
            cin >> num;
            foundNode = search(root, num);
            if (foundNode != NULL)
            {
                cout << "Element found in the tree." << endl;
            }
            else
            {
                cout << "Element not found in the tree." << endl;
            }
            break;
        case 7:
            lright();
            break;
//        case 8:
//            displayTreeStructure(root); // Corrected the function call
//            break;
        case 9:
            exit(0);
        default:
            cout << "Wrong choice" << endl;
        }
    }

    return 0;
}

void find(int item, struct node **par, struct node **loc)
{
    struct node *ptr, *ptrsave;

    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }

    if (item == root->info) // agar Root Double ajaye valus
    {
        *loc = root;
        *par = NULL;
        return;
    }

    if (item < root->info)
    {
        ptr = root->lchild;
    }
    else
    {
        ptr = root->rchild;
    }
    ptrsave = root;

    while (ptr != NULL)
    {
        if (item == ptr->info) // agar Doble ajaye valus
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;

        if (item < ptr->info)
        {
            ptr = ptr->lchild;
        }
        else
        {
            ptr = ptr->rchild;
        }
    }

    *loc = NULL;
    *par = ptrsave;
}

void insert(int item)
{
    struct node *temp, *parent, *location;
    find(item, &parent, &location);
    if (location != NULL)
    {
        cout << "Item already present" << endl;
        return;
    }

    temp = new node;
    temp->info = item;
    temp->rchild = NULL;
    temp->lchild = NULL;

    if (parent == NULL)
    {
        root = temp;
    }
    else
    {
        if (item < parent->info)
        {
            parent->lchild = temp;
        }
        else
        {
            parent->rchild = temp;
        }
    }
}
void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        cout << "Item ID: " << ptr->info << endl;
        inorder(ptr->rchild);
    }
}

void postorder(struct node *ptr)
{
   
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        cout << ptr->info << " ";
    }
}

void preorder(struct node *ptr)
{
    
    if (ptr != NULL)
    {
        cout << ptr->info << " ";
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}


void del(int item)

{
	struct node *parent, *location;
	if(root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return ;
	}
	find(item, &parent, &location);
	if(location == NULL)
	{
		cout<<"Info is not in list"<<endl;
		return;
	}
	if(location->lchild == NULL && location->rchild == NULL)
	{
		case_a(parent, location);
	}
	else if(location->lchild != NULL && location->rchild == NULL)
	{
		case_b(parent, location);
	}
	else if(location->lchild == NULL && location->rchild != NULL)
	{
		case_b(parent, location);
	}
	else
	{
		case_c(parent, location);
	}
	delete(location);
}

void case_a(struct node *par, struct node *loc)
{
    if (par == NULL)
    {
        root = NULL;	
    }
    else
    {
        if (loc == par->lchild)
        {
            par->lchild = NULL;
        }
        else
        {
            par->rchild = NULL;
        }
    }
}

void case_b(struct node *par, struct node *loc)
{
    struct node *child;
	
    if (loc->lchild != NULL)
    {
        child = loc->lchild; 
    }
    else
    {
        child = loc->rchild;	
    }
	
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (par->rchild == loc)
        {
            par->rchild = child;
        }
        else
        {
            par->lchild = child;
        }
    }
}


void case_c(struct node *par , struct node *loc)
{
	struct node *ptr , *ptrsave , *suc , *parsuc ;
	
	// find inorder successor and its parent 
	ptrsave = loc ;
	ptr = loc->rchild;
	
	while (ptr->lchild != NULL)
	{
		ptrsave = ptr ;
		ptr= ptr->lchild;
	}
	
	suc=ptr;
	parsuc = ptrsave;
	///////////////////////////////////
	if(suc->lchild == NULL && suc->rchild ==NULL)
	{
		case_a(parsuc , suc );
	}
	else
	{
		case_b(parsuc , suc);
	}
	
	if(par==NULL) // if item to be deleted is root node
	{
		root = suc;
	}
	else
	{
		if(loc == par->lchild)
		{
			par->lchild = suc;
		}
		else
		{
			par->rchild = suc;
		}
	}
	
	suc->lchild = loc->lchild;
	suc->rchild = loc->rchild;
}

struct node *search(struct node *root, int info)
{
    while (root != NULL && root->info != info)
    {
        if (info < root->info)
        {
            root = root->lchild;
        }
        else if (info > root->info)
        {
            root = root->rchild;
        }
    }
    return root;
}

void lright()
 {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    struct node *leftmost = root;
    while (leftmost->lchild != NULL) 
	{
        leftmost = leftmost->lchild;
    }

    cout << "Leftmost Node: " << leftmost->info << endl;
    
    if(leftmost->rchild != NULL)
    {
    	leftmost = leftmost->rchild;
    	cout<<"Data Is :"<<leftmost->info<<endl;
	}

    swapNodeData(root, leftmost);

   
}

void swapNodeData(node *a, node *b) {
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

void displayTree(node *root, int level = 0)
{
    if (root != NULL)
    {
        displayTree(root->rchild, level + 1);

        for (int i = 0; i < level; ++i)
            cout << "    ";

        cout << root->info << endl;

        displayTree(root->lchild, level + 1);
    }
}



