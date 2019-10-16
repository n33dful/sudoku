#include "sudoku.h"

int check(int board[9][9], size_t i, size_t j)
{
	if (!check_vertically(board, j) || !check_horizontally(board, i) || !check_square(board, i, j))
		return (0);
	return (1);
}
