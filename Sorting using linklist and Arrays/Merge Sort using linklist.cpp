#include <iostream>
using namespace std;

// Structure of a node
struct Node {
    int data;
    Node* next;
};

// Global variable to store the start of the linked list
struct Node* start = NULL;

void create_list(int data) {
    struct Node* tmp = new Node();
    tmp->data = data;
    tmp->next = NULL;

    if (start == NULL)
        start = tmp; // If the list is empty
    else {
        struct Node* q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = tmp;
    }
}

/* Function to print nodes in a given linked list */
void printList() {
    struct Node* temp;
    temp = start;
    cout << endl;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/* Custom swap function */
void customSwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/* Merge two sorted linked lists */
Node* merge(Node* left, Node* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

/* Merge sort for singly linked list */
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    // Find the middle of the list
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = NULL; // Split the list into two halves

    // Recursively sort the two halves
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    // Merge the sorted halves
    return merge(left, right);
}

int main() {
    int num, data;
    cout << "How many nodes do you want? " << endl;
    cin >> num;

    /* Create a singly linked list */
    for (int i = 0; i < num; i++) {
        cout << "Enter the Node data: " << endl;
        cin >> data;
        create_list(data);
    }

    /* Print the list before sorting */
    cout << "\nLinked list before sorting ";
    printList();

    /* Sort the singly linked list using merge sort */
    start = mergeSort(start);

    /* Print the list after sorting */
    cout << "\nLinked list after sorting ";
    printList();

    return 0;
}

