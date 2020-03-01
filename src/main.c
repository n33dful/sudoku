#include "sudoku.h"

/*
** TODO:
** 1. Replace int** to t_cell** (add field "is base") and 
** concatenate t_cell and int ** like FdF.
** 2. Add function to read from file (rea from argv already yet).
** 3. Make refactoring.
*/

/*
** Function to delete all allocated memory and exit
*/

static void	ft_program_exit(int ex, int **bd, int **new_bd, t_list **list)
{
	if (ex == EXIT_FAILURE)
		printf("Error!\n");
	else if (!bd && !new_bd && !(*list))
		printf("Check README.txt\n");
	ft_boarddel(bd);
	ft_boarddel(new_bd);
	ft_lstdel(list, ft_celldel);
	exit(ex);
}

/*
** Main function
*/

int			main(int argc, char **argv)
{
	t_list	*list = NULL;
	int		**new_board = NULL;
	int		**board = NULL;

	if (argc == 1)
		ft_program_exit(EXIT_SUCCESS, board, new_board, &list);
	else if (argc == 10 && !(board = ft_board_fill(argc, argv)))
		ft_program_exit(EXIT_FAILURE, board, new_board, &list);
	else if (!(new_board = ft_boardcpy(board)))
		ft_program_exit(EXIT_FAILURE, board, new_board, &list);
	else if (!(list = ft_find_opts(new_board)))
		ft_program_exit(EXIT_FAILURE, board, new_board, &list);
	else if (!(ft_find_answer(new_board, list)))
		ft_program_exit(EXIT_FAILURE, board, new_board, &list);
	else
		ft_board_print(new_board, board);
	ft_program_exit(EXIT_SUCCESS, board, new_board, &list);
}