#ifndef __STACK_H__
#define __STACH_H__

/* 원형 이중 연결 리스트 */
struct Node {
	int x, y;
	struct Node *next;
	struct Node *prev;
};

class Stack {
	Node *head;
	int size;

	public:
		Stack();
		~Stack();
		void push(int, int);
		void pop();
		void print() const;
		Node *getHead() const;
		int getSize() const;
};

#endif
