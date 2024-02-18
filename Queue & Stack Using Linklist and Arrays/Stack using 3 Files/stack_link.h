#ifndef stack_link_H
#define stack_link_H

#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

struct runner
{
	public:
		
	struct node *top = NULL;
	
	void push(int);
	void pop();
	void display();
	void peek();
	void menu();
	
};

#endif
