#include <iostream>
#include <fstream>
#include "tree.h"
using namespace std;
ofstream out("out.txt");
tree *tseek(tree* head, int dir, char item)
{
	tree* move;
	move = head;
	bool found = false;
	while (found != true)
	{
		if (dir == 0 && item != '.')
		{
			if (item > move->item)
			{
				if (move->right != NULL)
				{
					if (move->right->item != NULL)
						move = move->right;
				}
				else
				{
					found = true;
					return(move);
				}
			}
			if (item < move->item)
			{
				if (move->left != NULL)
				{
					if (move->left->item != NULL)
					move = move->left;
				}
				else
				{
					found = true;
					return(move);
				}
			}
			if (item = move->item)
			{
				return(move);
			}
		}
		else if (dir == 1)
		{
			if (move->right != NULL)
				move = move->right;
			else
			{
				found = true;
				return(move);
			}
		}
		else if (dir == -1)
		{
			if (move->left != NULL)
				move = move->left;
			else
			{
				found = true;
				return(move);
			}
		}
		else
		{
			cout << dir << ', ' << item << ", :WRONG VALUE, RETURNED NULL";
			found = true;
			return(NULL);
		}
	}
}

void tinit(tree* head)
{
	head->item = NULL;
	head->right = NULL;
	head->left = NULL;
	head->up = head->left;
}

bool t_ifclear(tree* head)
{
	if (head->item == NULL)
		return(true);
	else return false;
}

void tadd(tree* head, char item)
{
	if (!t_ifclear(head))
	{
		if (tseek(head, 0, item)->item != item)
		{
			if (item > tseek(head, 0, item)->item)
			{
				tseek(head, 0, item)->right = new tree;
				tseek(head, 0, item)->right->up = tseek(head, 0, item);
				tseek(head, 0, item)->right->item = item;
				tseek(head, 0, item)->right->left = NULL;
				tseek(head, 0, item)->right->right = NULL;
			}
		}
	}
	else
	{
		head->item = item;
	}
}

void tdelete(tree* head, int dir, char item)
{
	if (!t_ifclear(head))
	{
		if (dir == -2)
		{
			tinit(head);
		}
		else
		{
			if (dir != 0)
			{
				tree* temp = NULL;
					if (dir == 1)
					{
						if (tseek(head, 1)->left != NULL)
						{
							temp = tseek(head, 1)->left;
						}
						if (tseek(head, 1) != head)
						{
							tseek(head, 1)->up->right = NULL;
							if (temp != NULL)
								tseek(head, 1)->right = temp;
						}
						else
							head = head->left;

					}
					else if (dir == -1)
					{
						if (tseek(head, -1)->right != NULL)
						{
							temp = tseek(head, -1)->right;
						}
						if (tseek(head, -1) != head)
						{
							tseek(head, -1)->up->left = NULL;
							if (temp != NULL)
								tseek(head, -1)->left = temp;
						}
						else
							head = head->right;

					}
			}
			else
			{
				if (item != '.')
				{
					if (tseek(head, 0, item) == head)
					{
						if (head->right == NULL && head->left == NULL)
						{
							tinit(head);
						}
						if (head->right != NULL)
						{
							tree* temp;
							temp = head->left;
							head = head->right;
							tseek(head, -1)->left = temp;
						}
						else if (head->left != NULL)
						{
							head = head->left;
						}
					}
					if (tseek(head, 0, item)->item == item)
					{
						tree* tempr, * templ;
						tempr = tseek(head, 0, item)->right;
						templ = tseek(head, 0, item)->left;
						if (tseek(head, 0, item)->item > tseek(head, 0, item)->up->item)
						{
							tempr->up = tseek(head, 0, item)->up;
							tseek(head, 0, item)->up->right = tempr;
							if (templ->item > tseek(head, 0, templ->item)->item)
							{
								templ->up = tseek(head, 0, templ->item);
								tseek(head, 0, templ->item)->right = templ;
							}
							else if (templ->item < tseek(head, 0, templ->item)->item)
							{
								templ->up = tseek(head, 0, templ->item);
								tseek(head, 0, templ->item)->left = templ;
							}


						}
						else
						{
							templ->up = tseek(head, 0, item)->up;
							tseek(head, 0, item)->up->left = templ;
							if (tempr->item > tseek(head, 0, tempr->item)->item)
							{
								tempr->up = tseek(head, 0, tempr->item);
								tseek(head, 0, tempr->item)->right = tempr;
							}
							else if (tempr->item < tseek(head, 0, tempr->item)->item)
							{
								tempr->up = tseek(head, 0, tempr->item);
								tseek(head, 0, tempr->item)->left = tempr;
							}
						}
					}
				}
			}
		}
	}
	
}

void tout_left(tree* head,tree* pos)
{
	out << pos->item;
	while (pos->left != NULL || pos == head)
	{
		pos = pos->left;
		out << pos->item;
	}
}

void tout_straight(tree* head)
{
	tree* pos;
	pos = head;
	while (pos != tseek(head, 1))
	{
		tout_left(head, pos);
		while (pos->right == NULL)
			pos = pos->up;
		pos = pos->right;
	}
	tout_left(head, pos);
}

void tout_left_up(tree* pos)
{
	while (pos->left != NULL)
		pos = pos->left;
	while (pos->right == NULL)
	{
		out << pos->item;
		pos = pos->up;
	}

}

void tout_reversed(tree* head)
{
	tree* pos;
	pos = head;
	tree* crossroad;
	crossroad = NULL;
	while (pos != tseek(head, 1))
	{
		tout_left_up(pos);
		if (pos == crossroad)
		{
			do {
				pos = pos->up;
			} while (pos->right == NULL);
		}
		crossroad = pos;
		pos = pos->right;
	}
	tout_left_up(pos);
}

/*void tout_endful(tree* head)
{
	tree* pos;
	pos = head;
}*/

void tout(tree* head, int mode)
{
	//mode: 0 - straight, 1 - reversed, 2 - endful;
	switch (mode)
	{
	case 0:
	{
		tout_straight(head);
	}
	case 1:
	{
		tout_reversed(head);
	}
	case 2:
	{
		//tout_endful(head);
		cout << "NOT DONE YET";
	}
	}
}