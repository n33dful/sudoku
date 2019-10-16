#include "sudoku.h"

void del_one_elem_of_list(su_list **list)
{
	su_list *current;

	current = (*list);
	(*list) = (*list)->next;
	if (current->opts)
		free(current->opts);
	free(current);
}