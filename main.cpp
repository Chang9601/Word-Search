#include <iostream>
#include <string>
#include "stack.h"
#include "matrix.h"

/* 순수 선언 */
bool findWord(int, int, Stack &, const Matrix &, const std::string &, int);

int main(int argc, char *argv[])
{
	int row, col;
	int idx;
	char ch;	
	Stack stack;
	bool result;	
	std::string word;

	std::cin >> row >> col;
	Matrix matrix(row, col);
	
	std::cin >> word;

	idx = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result = findWord(i, j, stack, matrix, word, idx);	
			if (result)
				break;
		}
		if (result)
			break;
	}

	if (result) {
		stack.print();
	} else {
		std::cout << "not found";
	}

	return EXIT_SUCCESS;
}
