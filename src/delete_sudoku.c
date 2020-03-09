
#include "sudoku.h"

static void delete_list_of_options(t_options **list_of_options)
{
	t_options	*current_elem = NULL;

	while ((*list_of_options))
	{
		current_elem = (*list_of_options);
		(*list_of_options) = (*list_of_options)->next;
		free(current_elem);
		current_elem = NULL;
	}
}

void        delete_sudoku(t_sudoku ***sudoku)
{
	if (!(*sudoku))
		return ;
	for (size_t i = 0; i < 9; i++)
	{
		if (!(*sudoku)[i])
			break ;
		for (size_t j = 0; j < 9; j++)
			delete_list_of_options(&(*sudoku)[i][j].filling_options);
		free((*sudoku)[i]);
		(*sudoku)[i] = NULL;
	}
	free((*sudoku));
	(*sudoku) = NULL;
}
