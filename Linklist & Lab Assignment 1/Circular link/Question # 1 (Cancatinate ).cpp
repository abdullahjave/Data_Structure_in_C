#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    struct node *link;
} *start, *start2;

void createlist(int);
void createlist2(int);
void concatenate();
void display();

int main() {
    start = NULL;
    start2 = NULL;
    int data, data2;

    while (1) {
        int choice;
        cout << "Enter the Choice " << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                int n;
                cout << "How many nodes do you want to create in list 1: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter data: ";
                    cin >> data;
                    createlist(data);
                }
                break;
            }
            case 2: {
                int n1;
                cout << "How many nodes do you want to create in list 2: ";
                cin >> n1;
                cout << "Creating List 2" << endl;
                for (int i = 0; i < n1; i++) {
                    cout << "Enter data: ";
                    cin >> data2;
                    createlist2(data2);
                }
                break;
            }
            case 3: {
                cout << "Action Performed" << endl;
                concatenate();
                break;
            }
            case 4: {
                display();
                break;
            }
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}

void createlist(int data) {
    struct node *q, *temp;
    temp = new struct node;
    temp->data = data;
    temp->link = NULL;
    if (start == NULL) {
        start = temp;
        temp->link = start;  // Make it circular
    } else {
        q = start;
        while (q->link != start) {
            q = q->link;
        }
        q->link = temp;
        temp->link = start;  // Make it circular
    }
}

void createlist2(int data2) {
    struct node *q2, *temp2;
    temp2 = new struct node;
    temp2->data = data2;
    temp2->link = NULL;
    if (start2 == NULL) {
        start2 = temp2;
        temp2->link = start2;  // Make it circular
    } else {
        q2 = start2;
        while (q2->link != start2) {
            q2 = q2->link;
        }
        q2->link = temp2;
        temp2->link = start2;  // Make it circular
    }
}

void concatenate() {
    struct node *q;
    if (start2 == NULL) {
        cout << "List 2 is empty." << endl;
    } else {
        q = start;
        while (q->link != start) {
            q = q->link;
        }
        q->link = start2;
        start2 = NULL;
    }
}

void display() {
    struct node *q;
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    q = start;
    cout << "List is:" << endl;
    
    do {
        cout << q->data << "   ";
        q = q->link;
    } while (q != start);
    
    cout << endl;
}

