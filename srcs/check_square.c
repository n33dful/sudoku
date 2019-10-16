#include "sudoku.h"

int check_square(int board[9][9], size_t i, size_t j)
{
	int target;
	size_t count;
	size_t new_i;
	size_t new_j;
	size_t end_i;
	size_t end_j;

	target = 1;
	while (target <= 9)
	{
		count = 0;
		new_i = i / 3 * 3;
		end_i = new_i + 3;
		while (new_i < end_i)
		{
			new_j = j / 3 * 3;
			end_j = new_j + 3;
			while (new_j < end_j)
			{
				if (board[new_i][new_j] == target)
					count++;
				new_j++;
			}
			new_i++;
		}
		if (count > 1)
			return (0);
		target++;
	}
	return (1);
}
