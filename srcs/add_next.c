#include "sudoku.h"

void add_next(su_list **list, su_list *new)
{
	su_list	*last;

	last = (*list);
	if (last && new)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}