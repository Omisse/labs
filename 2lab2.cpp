#include <iostream>
#include "dqueue.h"

using namespace std;

void main()
{
	dqueue* head;
	head = new dqueue;
	dq_clear(head);
	float val = 0;
	int pick = 0;
	cout << "Enter the number of your command: \n";
	cout << "1: Clear queue \n";
	cout << "2: Add new element \n";
	cout << "3: Take element from queue \n";
	cout << "4: Print out element from queue \n";
	cout << "5: Print out all elements from queue \n";
	cout << "6: Check if queue is empty \n";
	cout << "7: End work \n";
	while (pick != 7)
	{
		cin >> pick;
		switch (pick)
		{
		case 1:
			dq_clear(head);
			cout << "\n Queue is empty!\n";
			break;
		case 2:
			cout << "\n Enter value \n";
			cin >> val;
			dq_add(head, val);
			val = 0;
			break;
		case 3:
			if (dq_isempty(head))
			{
				cout << "\nQueue is empty!\n";
			}
			else
			{
				cout << "\n Element taken: " << dq_take(head);
			}
			break;
		case 4:
			if (dq_isempty(head))
			{
				cout << "\nQueue is empty!\n";
			}
			else
			{
				cout << "\n First element in queue: " << dq_out(head);
			}
			break;
		case 5:
			if (dq_isempty(head))
			{
				cout << "\nQueue is empty!\n";
			}
			else
			{
				cout << "\n Queue consists of: \n";
				dq_out_all(head);
			}
			break;
		case 6:
			if (dq_isempty(head))
			{
				cout << "\nQueue is empty!\n";
			}
			else
			{
				cout << "\nQueue is not empty.\n";
			}
			break;
		case 7:
			break;
		default:
			cout << "\nIncorrect command!\n";
			break;
		}
	}
	cout << "\nWork ended.\n";
}