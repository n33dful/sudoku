#include "sudoku.h"

int check_horizontally(int board[9][9], size_t i)
{
	int target;
	size_t count;
	size_t j;

	target = 1;
	while (target <= 9)
	{
		j = 0;
		count = 0;
		while (j < 9)
		{
			if (board[i][j] == target)
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		target++;
	}
	return (1);
}
