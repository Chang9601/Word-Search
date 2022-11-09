#include <iostream>
#include "stack.h"

Stack::Stack() 
{
	head = NULL;
}

Stack::~Stack()
{
	Node *next;
	/**/
	while (head != NULL) {
		next = head -> next;
		delete head;	
		head = next;
	}
}

void Stack::push(int x, int y)
{
	/* 매개변수가 아니기 때문에 이중 포인터 필요 X */
	Node *node = new Node;
	node -> x = x;
	node -> y = y;
	node -> next = head;
	head = node;
}

void Stack::pop()
{
	/* 빈 스택 */
	if (head == NULL)
		return;

	Node *node = head;

	/* 매개변수가 아니기 때문에 이중 포인터 필요 X */
	if (node != NULL) {
		head = head -> next;
		node -> next = NULL;
	}

	delete node;
}