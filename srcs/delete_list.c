#include "sudoku.h"

void delete_list(su_list **list)
{
	su_list *current;

	if (list && *list)
	{
		while (*list)
		{
			current = (*list);
			if ((*list)->opts)
				free((*list)->opts);
			(void)((*list)->i);
			(void)((*list)->j);
			(*list) = (*list)->next;
			free(current);
			current = NULL;
		}
		current = NULL;
	}
}
