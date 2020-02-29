#include "sudoku.h"

void copy_board(int new_board[9][9], int board[9][9])
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			new_board[i][j] = board[i][j];
			j++;
		}
		i++;
	}
}
