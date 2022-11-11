#include <string>
#include "stack.h"
#include "matrix.h"

/* 위치가 범위 밖에 있는지 판별 */
static bool isOutsideBounds(int x, int y, const Matrix &matrix)
{	
	return ((x < 0 || x >= matrix.getRow()) || (y < 0 || y >= matrix.getCol()));
}

/* 단어를 재귀적으로 검색 */
bool findWord(int x, int y, Stack &stack, const Matrix &matrix, const std::string &word, int idx)
{
	/* 위치가 범위 밖 */
	if (isOutsideBounds(x, y, matrix))
		return false;
	/* 문자가 단어의 문자와 일치 X */
	if (matrix.getMatrix()[x][y] != word[idx])
		return false;
	
	/* 일치하는 문자 발견 */	
	stack.push(x, y);
	
	/* 단어 발견 */
	if (idx == word.length() - 1) 
		return true;
	
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int nx = x + i;
			int ny = y + j;
			/* 동일한 경우 제외 */
			if (nx == x && ny == y)
				continue;

			if (findWord(nx, ny, stack, matrix, word, idx + 1))
				return true;
		}
	}

	stack.pop();
	return false;
}

