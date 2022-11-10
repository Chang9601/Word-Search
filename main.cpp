#include <iostream>
#include <string>
#include "stack.h"
#include "matrix.h"

/* 순수 선언 */
bool findWord(Stack &, const Matrix &, const std::string &);

int main(int argc, char *argv[])
{
	int row, col;
	char ch;	
	Stack stack;
	bool result;	
	std::string word;

	std::cin >> row >> col;
	Matrix matrix(row, col);
	
	std::cin >> word;

	result = findWord(stack, matrix, word);
	if (result) {
		stack.print();
	} else {
		std::cout << "not found";
	}

	return EXIT_SUCCESS;
}
