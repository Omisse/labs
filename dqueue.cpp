#include "dqueue.h"
#include <iostream>
using namespace std;



void dq_clear(dqueue* head)
{
	head->next = NULL;
	head->prev = NULL;
}

void dq_add(dqueue* head, float vl)
{
	if (head->next == NULL)
	{
		head->next = new dqueue;
		head->next->val = vl;
		head->prev = head->next;
		head->next->next = head;
		head->next->prev = head;
	}
	else
	{
		dqueue* h;
		h = head->next;
		while (h->next != head)
		{
			h = h->next;
		}
		h->next = new dqueue;
		h->next->prev = head->prev;
		h->next->next = head;
		h->next->val = vl;
	}
}

float dq_take(dqueue* head)
{
	float vl = head->next->val;
	head->next = head->next->next;
	head->next->prev = head;
	return(vl);
}

float dq_out(dqueue* head)
{
	return(head->next->val);
}

void dq_out_all(dqueue* head)
{
	dqueue* h;
	h = head->next;
	cout << '\n';
	cout << h->val << ' ';
	while (h->next != head)
	{
		h = h->next;
		if (h != head) cout << h->val << ' ';
	}
}

bool dq_isempty(dqueue* head)
{
	if (head->next == head || head->next == NULL) return(true);
	else return(false);
}