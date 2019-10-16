#include "sudoku.h"

su_list *create_list(size_t i, size_t j, int *opts, int count_of_opts)
{
	su_list *new;

	new = NULL;
	if (i >= 0 && i <= 9 && j >= 0 && j <= 9)
	{
		if (!(new = (su_list *)malloc(sizeof(su_list))))
		{
			printf("error to allocate the memory!\n");
			exit(EXIT_FAILURE);
		}
		new->i = i;
		new->j = j;
		new->opts = opts;
		new->count_of_opts = count_of_opts;
		new->next = NULL;
	}
	return (new);
}
