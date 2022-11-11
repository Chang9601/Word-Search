#include <iostream>
#include "stack.h"

Stack::Stack() 
{
	/* 더미 노드 */
	Node *sentinel = new Node;
	sentinel -> x = 0;
	sentinel -> y = 0;

	sentinel -> prev = sentinel -> next = sentinel;
	head = sentinel;
	size = 0;
}

Stack::~Stack()
{
	Node *curr = head -> next;
	Node *next;
	while (curr != head) {
		next = curr -> next;
		delete curr;	
		curr = next;
	}

	delete head;
}

void Stack::push(int x, int y)
{
	Node *node = new Node;
	node -> x = x;
	node -> y = y;
	node -> next = head -> next;
	node -> prev = head;
	node -> next -> prev = node;
	head -> next = node;

	size++;
}

void Stack::pop()
{
	/* 더미 노드만 있으면 빈 연결 리스트 */
	if (head == head -> next)
		return;

	Node *node = head -> next;
	head -> next = node -> next;
	node -> next -> prev = head;
	delete node;

	size--;
}

void Stack::print() const
{
	/* 스택의 역순으로 출력 */
	for (Node *curr = head -> prev; curr != head; curr = curr -> prev)
		std::cout << "(" << curr -> x << ", " << curr -> y << ")" << std::endl;
}

Node* Stack::getHead() const
{
	return head;
}

int Stack::getSize() const
{
	return size;
}
