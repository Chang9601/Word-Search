#include <iostream>
#include "stack.h"

static void printStack(const Stack &stack)
{
	for (Node *curr = stack.getHead(); curr; curr = curr -> next)
		std::cout << curr -> x << ", " << curr -> y << std::endl;

}

int main(int argc, char *argv[])
{
	Stack s;

	s.push(1, 2);
	s.push(3, 4);
	s.push(5, 6);

	s.pop();
	s.pop();
	s.pop();

	printStack(s);

	return EXIT_SUCCESS;
}