#include <string>
#include "stack.h"
#include "matrix.h"

/* 위치가 범위 밖에 있는지 판별 */
static bool isOutsideBounds(int x, int y, const Matrix &matrix)
{	
	return ((x < 0 || x >= matrix.getRow()) || (y < 0 || y >= matrix.getCol()));
}

/* 다음 문자를 재귀적으로 검색 */
void findNextCh(int x, int y, Stack &stack, const Matrix &matrix, const std::string &word, int idx)
{
	/* 기저조건 */
	if (idx == word.length()) 
		return;

	/* 현재 스택의 크기 */
	int size = stack.getSize();	

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int nx = x + i;
			int ny = y + j;

			/* (x, y)와 같은 위치 */
			if (nx == x && ny == y)
				continue;
			/* 범위 밖에 있는 위치 */
			if (isOutsideBounds(nx, ny, matrix))
				continue;	
			/* 다음 문자와 일치 */
			if (matrix.getMatrix()[nx][ny] == word[idx]) {
				stack.push(nx, ny);
				findNextCh(nx, ny, stack, matrix, word, idx + 1);
			}
		}
	}
	
	/* 문자 검색 실패 */
	if (stack.getSize() <= size)
		stack.pop();
}

bool findWord(Stack &stack, const Matrix &matrix, const std::string &word)
{
	int idx = 0;
	bool result;

	for (int i = 0; i < matrix.getRow(); i++) {
		for (int j = 0; j < matrix.getCol(); j++) {
			/* 단어의 첫 문자와 일치 */
			if (matrix.getMatrix()[i][j] == word[idx]) {
				stack.push(i, j);
				findNextCh(i, j, stack, matrix, word, idx + 1);
				
				if (word.length() == stack.getSize())
					return true;
			}
		}
	}

	return false;
}
