#include "sudoku.h"

int check_vertically(int board[9][9], size_t j)
{
	int target;
	size_t count;
	size_t i;

	target = 1;
	while (target <= 9)
	{
		i = 0;
		count = 0;
		while (i < 9)
		{
			if (board[i][j] == target)
				count++;
			i++;
		}
		if (count > 1)
			return (0);
		target++;
	}
	return (1);
}
