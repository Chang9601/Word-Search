#ifndef __STACK_H__
#define __STACH_H__

struct Node {
	int x, y;
	struct Node *next;
};

class Stack {
	Node *head;

	public:
		Stack();
		~Stack();
		void push(int, int);
		void pop();
		Node *getHead() const {
			return head;
		}
};

#endif