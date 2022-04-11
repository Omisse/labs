#include <iostream>
#include <fstream>
#include "tree.h"

using namespace std;

void main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	
	tree *head;
	head = new tree;
	char r;
	tinit(head);
	if (in.is_open())
	{
		cout << "\nReading file \n";
		do
		{
			in >> r;
			if (r != '.')
				tadd(head, r);
			cout << '\n' << r << " Read";

		} while (r != '.');
	}
	else cout << "\n Couldn't find in.txt!\n";
	cout << "\nFile read \n";
	tout(head);
}