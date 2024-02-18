#ifndef QUESTION1_H
#define QUESTION1_H
#include <iostream>
using namespace std;

struct node 
{
	string name, assignto, date;
	struct node *link;	
};

struct Runner 
{
	public :
			struct node *start=NULL;
			void menu();
		void create_list(string , string , string);
		void addatbeg(string, string, string);
		void del(string);
		void display();
	
};
#endif
