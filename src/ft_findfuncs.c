#include "sudoku.h"

static void	ft_cell_fill(int i, int j, int **board, t_cell *cell)
{
	cell->i = i;
	cell->j = j;
	cell->count_of_opts = 0;
	for (int num = 1; num <= 9; num++)
	{
		board[i][j] = num;
		if (ft_check_cell(i, j, board))
			cell->opts[cell->count_of_opts++] = num;
	}
	board[i][j] = 0;
}

t_list		*ft_find_opts(int **board)
{
	t_list	*list = NULL;
	t_list	*new = NULL;
	t_cell	cell;

	if (!board)
		return (NULL);
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (board[i][j] != 0)
				continue;
			ft_cell_fill(i, j, board, &cell);
			if (!(new = ft_lstnew(&cell, sizeof(t_cell))))
			{
				ft_lstdel(&list, ft_celldel);
				return (NULL);
			}
			ft_lstadd_back(&list, new);
		}
	}
	return (list);
}

int			ft_find_answer(int **board, t_list *list)
{
	t_cell	*cell = NULL;

	if (!list)
		return (1);
	cell = list->content;
	for (int i = 0; i < cell->count_of_opts; i++)
	{
		board[cell->i][cell->j] = cell->opts[i];
		if (ft_check_all(board) && ft_find_answer(board, list->next))
			return (1);
	}
	board[cell->i][cell->j] = 0;
	return (0);
}
