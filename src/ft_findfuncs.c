#include "sudoku.h"

static int	ft_cell_fill(size_t i, size_t j, t_cell **board)
{
	t_list	*new = NULL;

	if (!board)
		return (0);
	for (int num = 1; num <= 9; num++)
	{
		board[i][j].num = num;
		if (ft_check_cell(i, j, board))
		{
			if (!(new = ft_lstnew(&num, sizeof(int))))
				return (0);
			ft_lstadd_back(&(board[i][j].opts), new);
		}
	}
	board[i][j].num = 0;
	return (1);
}

int			ft_find_opts(t_cell **board)
{
	if (!board)
		return (0);
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (board[i][j].num != 0)
				continue;
			if (!ft_cell_fill(i, j, board))
				return (0);
		}
	}
	return (1);
}

int			ft_find_answer(t_cell **board)
{
	t_list	*list_of_opts;

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (board[i][j].is_base || board[i][j].num != 0)
				continue ;
			list_of_opts = board[i][j].opts;
			while (list_of_opts)
			{
				board[i][j].num = *((int *)list_of_opts->content);
				if (!ft_check_all(board))
					list_of_opts = list_of_opts->next;
				else if (ft_find_answer(board))
					return (1);
				else
					list_of_opts = list_of_opts->next;
			}
			board[i][j].num = 0;
			return (0);
		}
	}
	return (1);
}
