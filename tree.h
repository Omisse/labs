#include <iostream>
#include <fstream>

struct tree
{
	char item;
	int count;
	tree* right, * left, *up;
};
tree* tseek(tree* head, int dir = 0, char item = '.');
void tinit(tree* head);
void tadd(tree* head, char item);
void tdelete(tree* head, int dir = -2, char item = '.');
void tout(tree* head, int mode = 0);
void tout_left(tree* head, tree* pos);
void tout_straight(tree* head);
void tout_left_up(tree* pos);
void tout_reversed(tree* head);