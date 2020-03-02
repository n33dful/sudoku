#include "sudoku.h"

/*
** TODO:
** 1. Add function to read from file (rea from argv already yet).
** 2. Make refactoring.
** 3. Сделать перекрестные ссылки по методу: перед цилом вайл когда
** идет прогон возможных вариантов заранее подготовить его путем
** перепроверки на чек_олл и удилить только те, которые уже не подходят
** таким образом уменьшить количество итераций.
*/

/*
** Function to delete all allocated memory and exit
*/

static void	ft_program_exit(int ex, t_cell ***board)
{
	if (ex == EXIT_FAILURE)
		printf("Error!\n");
	else if (!(*board))
		printf("Check README.txt\n");
	ft_boarddel(board);
	exit(ex);
}

/*
** Main function
*/

int			main(int argc, char **argv)
{
	t_cell	**board = NULL;

	if (argc == 1)
		ft_program_exit(EXIT_SUCCESS, &board);
	else if (argc == 10 && !(board = ft_board_fill(argc, argv)))
		ft_program_exit(EXIT_FAILURE, &board);
	else if (!ft_find_opts(board))
		ft_program_exit(EXIT_FAILURE, &board);
	else if (!ft_find_answer(board))
		ft_program_exit(EXIT_FAILURE, &board);
	else
		ft_board_print(board);
	ft_program_exit(EXIT_SUCCESS, &board);
}