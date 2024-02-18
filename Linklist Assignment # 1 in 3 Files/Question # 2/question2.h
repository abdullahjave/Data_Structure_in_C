#ifndef QUESTION2_H
#define QUESTION2_H
#include <iostream>
using namespace std;

struct node
{
	string pname, country;
	int age;
	struct node *link;
};

struct Runner 
{
	public :
			struct node *last=NULL;
				void menu();
			void createlist(string , string , int );
			void addatbeg(string , string , int);
			void  addafter(string , string , int, int );
			void  del(string );
			void  display();
			
};
#endif
