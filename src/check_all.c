#include "sudoku.h"

int check_all(int board[9][9])
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		if (!check_horizontally(board, i))
			return (0);
		while (j < 9)
		{
			if (!check_vertically(board, j) || !check_square(board, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
