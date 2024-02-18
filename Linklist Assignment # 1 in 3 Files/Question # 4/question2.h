#ifndef QUESTION2_H
#define QUESTION2_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


struct node
 {
    string name, sclass, addr;
    int roll_no;
    struct node *next, *prev;
};

struct Runner 
{
	public :
			struct node *start=NULL;
			void menu();
	void createlist(string name, int roll_no, string sclass, string addr);
void addtolistbeg(string name, int roll_no, string sclass, string addr);
void addtolistafter(string name, int roll_no, string sclass, string addr, int pos);
void del(string name);
void sortList();
void DisplayList();
void search(string name);	
	
};
#endif
