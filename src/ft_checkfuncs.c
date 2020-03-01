#include "sudoku.h"

static int	ft_check_horizontally(size_t i, int **board)
{
	size_t count = 0;

	for (int target = 1; target <= 9; target++)
	{
		count = 0;
		for (size_t j = 0; j < 9; j++)
		{
			if (board[i][j] == target)
				count++;
		}
		if (count > 1)
			return (0);
	}
	return (1);
}

static int	ft_check_vertically(size_t j, int **board)
{
	size_t count = 0;

	for (int target = 1; target <= 9; target++)
	{
		count = 0;
		for (size_t i = 0; i < 9; i++)
		{
			if (board[i][j] == target)
				count++;
		}
		if (count > 1)
			return (0);
	}
	return (1);
}

static int	ft_check_square(size_t i, size_t j, int **board)
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

int			ft_check_cell(size_t i, size_t j, int **board)
{
	if (!ft_check_vertically(j, board) || \
!ft_check_horizontally(i, board) || !ft_check_square(i, j, board))
		return (0);
	return (1);
}

int			ft_check_all(int **board)
{
	for (size_t i = 0; i < 9; i++)
	{
		if (!ft_check_horizontally(i, board))
			return (0);
		for (size_t j = 0; j < 9; j++)
		{
			if (!ft_check_vertically(j, board) || !ft_check_square(i, j, board))
				return (0);
		}
	}
	return (1);
}
