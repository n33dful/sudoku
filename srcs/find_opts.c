#include "sudoku.h"

su_list *find_opts(int board[9][9])
{
	su_list *new_list;
	size_t count_of_opts;
	int *opts;
	size_t i;
	size_t j;
	int num;

	num = 0;
	i = 0;
	new_list = create_list(0, 0, NULL, 0);
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (board[i][j] == 0)
			{
				num = 1;
				count_of_opts = 0;
				while (num <= 9)
				{
					board[i][j] = num;
					if (check(board, i, j))
						count_of_opts++;
					num++;
				}
				board[i][j] = 0;
				if (!(opts = (int *)malloc(sizeof(int) * count_of_opts)))
				{
					delete_list(&new_list);
					printf("error to allocate the memory!\n");
					exit(EXIT_FAILURE);
				}
				num = 1;
				count_of_opts = 0;
				while (num <= 9)
				{
					board[i][j] = num;
					if (check(board, i, j))
					{
						opts[count_of_opts] = num;
						count_of_opts++;
					}
					num++;
				}
				board[i][j] = 0;
				add_next(&new_list, create_list(i, j, opts, count_of_opts));
			}
			j++;
		}
		i++;
	}
	del_one_elem_of_list(&new_list);
	return (new_list);
}
