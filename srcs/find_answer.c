#include "sudoku.h"

int find_answer(int board[9][9], su_list *list)
{
	int i;

	if (!list)
		return (1);
	i = 0;
	while (i < list->count_of_opts)
	{
		board[list->i][list->j] = list->opts[i];
		if (check_all(board))
		{
			if (find_answer(board, list->next))
				return (1);
		}
		i++;
	}
	board[list->i][list->j] = 0;
	return (0);
}
