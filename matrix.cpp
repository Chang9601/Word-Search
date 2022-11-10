#include <iostream>
#include "matrix.h"

Matrix::Matrix(int r, int c): row(r), col(c)
{
	matrix = new char*[row];
	for (int i = 0; i < row; i++)
		matrix[i] = new char[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			std::cin >> matrix[i][j];
}

Matrix::~Matrix()
{
	for (int i = 0; i < row; i++)
		delete[] matrix[i];

	delete[] matrix;
}

char **Matrix::getMatrix() const 
{
	return matrix;
}

void Matrix::print() const 
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int Matrix::getRow() const
{
	return row;
}
		
int Matrix::getCol() const
{
	return col;
}
