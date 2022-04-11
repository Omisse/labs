#include <iostream>

struct list
{
	float val;
	list* prev, * next;
};
typedef list dqueue;
void dq_clear(dqueue* head);
void dq_add(dqueue* head, float vl);
float dq_take(dqueue* head);
float dq_out(dqueue* head);
bool dq_isempty(dqueue* head);
void dq_out_all(dqueue* head);