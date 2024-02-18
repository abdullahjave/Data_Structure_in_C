#ifndef A1_DS_Q5_H
#define A1_DS_Q5_H
#include<iostream>
using namespace std;
struct node
{
	int info;
	struct node *link;
};
struct cll2{
	public:
		struct node *last=NULL;
	
		void menu();
		void create_list(int data);
		void addatbeg(int data);
		void addafter(int data,int pos);
		void del(int data);
		int getlength();
		void display();
		void splitlist();





};
#endif
