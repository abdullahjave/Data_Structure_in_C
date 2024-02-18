#include <iostream>
using namespace std;

struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
};

node *root = NULL;

void find(int item, node **parent, node **location) {
    struct node *ptr, *ptrSave;

    if (root == NULL)
	{
        *location = *parent = NULL;
        return;
    }

    if (item == root->info) {
        *location = root;
        *parent = NULL;
        return;
    }

    if (item < root->info)
        ptr = root->lchild;
    else
        ptr = root->rchild;

    ptrSave = root;

    while (ptr != NULL) {
        if (item == ptr->info) {
            *location = ptr;
            *parent = ptrSave;
            return;
        }
        ptrSave = ptr;

        if (item < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }

    *location = NULL;
    *parent = ptrSave;
}

void insert(int item) {
    struct node *temp, *parent, *location;

    find(item, &parent, &location);

    if (location != NULL) {
        cout << "Item already inserted in the tree." << endl;
        return;
    } else {
        temp = new node;
        temp->info = item;
        temp->lchild = temp->rchild = NULL;

        if (parent == NULL)
            root = temp;
        else {
            if (parent->lchild == NULL)
                parent->lchild = temp;
            else
                parent->rchild = temp;

            
            while (parent != NULL && temp->info < parent->info) {
                swap(temp->info, parent->info);
                temp = parent;
            
                find(temp->info, &parent, &location);
            }
        }
    }
}

void swap(node *temp, node *par) 
{
    int tempInfo = temp->info;
    temp->info = par->info;
    par->info = tempInfo;

    temp->lchild = par->lchild;
    temp->rchild = par->rchild;
}

void set(node* root) {
    if (root == NULL) {
        return;
    }

    node* smallest = root;
    node* left = root->lchild;
    node* right = root->rchild;

    if (left != NULL && left->info < smallest->info) {
        smallest = left;
    }

    if (right != NULL && right->info < smallest->info) {
        smallest = right;
    }

    if (smallest != root) {
        swap(root->info, smallest->info);
        set(smallest);
    }
}

int extractMin() {
    if (root == NULL) {
        cout << "The seating arrangement is empty." << endl;
        return -1; 
    }

    int minID = root->info;
    struct node *temp;

    if (root->rchild == NULL) {
        temp = root;
        root = root->lchild;
        delete temp;
    } else {
        struct node *parent = root;
        temp = root->rchild;
        
        while (temp->lchild != NULL) {
            parent = temp;
            temp = temp->lchild;
        }
        
        root->info = temp->info;

        if (parent->lchild == temp)
            parent->lchild = temp->rchild;
        else
            parent->rchild = temp->rchild;

        delete temp;
        set(root);
    }

    return minID;
}

int main() {
    int choice, studentID;

    do {
        cout << "\n1. Insert Student ID\n2. Extract Minimum ID for Seating\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the Student ID: ";
                cin >> studentID;
                insert(studentID);
                break;
            case 2:
                studentID = extractMin();
                if (studentID != -1)
                    cout << "Allocated seat to Student ID: " << studentID << endl;
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
