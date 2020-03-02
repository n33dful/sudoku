#include "sudoku.h"

static t_cell	**ft_error(t_cell ***board)
{
	ft_boarddel(board);
	return (NULL);
}

static t_cell	**ft_boardnew()
{
	t_cell	**board = NULL;

	if (!(board = (t_cell **)malloc(sizeof(t_cell *) * 9)))
		return (NULL);
	for (size_t i = 0; i < 9; i++)
	{
		if (!(board[i] = (t_cell *)malloc(sizeof(t_cell) * 9)))
			return (ft_error(&board));
		for (size_t j = 0; j < 9; j++)
		{
			board[i][j].num = 0;
			board[i][j].is_base = 0;
			board[i][j].opts = NULL;
		}
	}
	return (board);
}

t_cell			**ft_board_fill(int argc, char **argv)
{
	t_cell	**board = NULL;

	if (argc == 10)
	{
		if (!(board = ft_boardnew()))
			return (NULL);
		for (size_t i = 0; i < 9; i++)
		{
			if (strlen(argv[i + 1]) != 9)
				return (ft_error(&board));
			for (size_t j = 0; j < 9; j++)
			{
				if (argv[i + 1][j] == '.')
					continue;
				else if (isdigit(argv[i + 1][j]) && argv[i + 1][j] != '0')
				{
					board[i][j].num = argv[i + 1][j] - '0';
					board[i][j].is_base = 1;
				}
				else
					return (ft_error(&board));
			}
		}
		if (!ft_check_all(board))
			return (ft_error(&board));
	}
	return (board);
}

void			ft_boarddel(t_cell ***board)
{
	if ((*board))
	{
		for (size_t i = 0; i < 9; i++)
		{
			if (!(*board)[i])
				break ;
			for (size_t j = 0; j < 9; j++)
				ft_lstdel(&((*board)[i][j].opts), ft_celldel);
			free((*board)[i]);
			(*board)[i] = NULL;
		}
		free((*board));
		(*board) = NULL;
	}
}

void			ft_board_print(t_cell **board)
{
	if (!board)
		return ;
	printf("0-------0-------0-------0\n");
	for (size_t i = 0; i < 9; i++)
	{
		printf("| ");
		for (size_t j = 0; j < 9; j++)
		{
			if (!board[i][j].is_base)
				printf(ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET, board[i][j].num);
			else
				printf("%d", board[i][j].num);
			if (j != 8)
			{
				printf(" ");
				if ((j + 1) % 3 == 0)
					printf("| ");
			}
		}
		printf(" |\n");
		if (i != 8 && (i + 1) % 3 == 0)
			printf("0-------0-------0-------0\n");
	}
	printf("0-------0-------0-------0\n");
}
