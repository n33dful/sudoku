#include "sudoku.h"

static void	ft_error(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void		create_board(int board[9][9], char **argv)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 9)
	{
		if (strlen(argv[i + 1]) != 9 || !argv[i + 1])
			ft_error("invalid data!");
		j = 0;
		while (j < 9)
		{
			if (isdigit(argv[i + 1][j]) && argv[i + 1][j] - '0' != 0)
				board[i][j] = argv[i + 1][j] - '0';
			else if (argv[i + 1][j] == '.')
				board[i][j] = 0;
			else
				ft_error("invalid data!");
			j++;
		}
		i++;
	}
	if (!check_all(board))
		ft_error("invalid data!");
}
