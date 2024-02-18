#ifndef QUESTION5_H
#define QUESTION5_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


struct node
{
	struct node *prev;
	string name, artist, genre;
	struct node *next;
};
struct Runner 
{
	public :
			struct node *end , *start=NULL;
			void menu();
	void create_playlist(string, string, string);
void addatend(string, string, string);
void del(string);
void moveLastToFirst();
void display_forw();
void display_back();	
	
};
#endif
