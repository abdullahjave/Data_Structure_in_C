#include <iostream>
using namespace std;

void toh(int ndisk, char source , char temp ,char dest)
{
	if(ndisk == 1 )
	{
		cout<<"Move Disk "<<ndisk<<" -> "<<source << " "<<dest<<endl;
		return;
	}
	toh(ndisk-1 , source , dest , temp);
 	toh(1, source , temp , dest);
	toh(ndisk-1 , temp , source , temp);
}


int main()
{
	toh (4, 'A' , 'B' , 'C');
}



