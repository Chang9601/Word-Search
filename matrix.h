#ifndef __MATRIX_H__
#define __MAXTIR_H__

class Matrix {
	int row, col;
	char **matrix;

	public:
		Matrix(int, int);
		~Matrix();
		void print() const;
		char **getMatrix() const;
		int getRow() const;
		int getCol() const;
};

#endif
