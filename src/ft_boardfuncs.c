#include "sudoku.h"

static int	**ft_boardnew()
{
	int	**board = NULL;

	if (!(board = (int **)malloc(sizeof(int *) * 9)))
		return (NULL);
	for (size_t i = 0; i < 9; i++)
	{
		if (!(board[i] = (int *)malloc(sizeof(int) * 9)))
		{
			ft_boarddel(board);
			return (NULL);
		}
		for (size_t j = 0; j < 9; j++)
			board[i][j] = 0;
	}
	return (board);
}

static int	**ft_error(int **board)
{
	ft_boarddel(board);
	return (NULL);
}

int			**ft_board_fill(int argc, char **argv)
{
	int		**board = NULL;

	if (argc == 10)
	{
		if (!(board = ft_boardnew()))
			return (NULL);
		for (int i = 0; i < 9; i++)
		{
			if (strlen(argv[i + 1]) != 9)
				return (ft_error(board));
			for (int j = 0; j < 9; j++)
			{
				if (argv[i + 1][j] == '.')
					continue;
				else if (isdigit(argv[i + 1][j]) && argv[i + 1][j] != '0')
					board[i][j] = argv[i + 1][j] - '0';
				else
					return (ft_error(board));
			}
		}
		if (!ft_check_all(board))
			return (ft_error(board));
	}
	return (board);
}

void    ft_boarddel(int **board)
{
	size_t	i = 0;

	if (!board)
		return ;
	while (i < 9 && board[i])
		free(board[i++]);
	free(board);
	board = NULL;
}

int	**ft_boardcpy(int **board)
{
	int	**new_board = NULL;

	if (!board || !(new_board = (int **)malloc(sizeof(int *) * 9)))
		return (NULL);
	for (size_t i = 0; i < 9; i++)
	{
		if (!(new_board[i] = (int *)malloc(sizeof(int) * 9)))
		{
			ft_boarddel(board);
			return (NULL);
		}
		for (size_t j = 0; j < 9; j++)
			new_board[i][j] = board[i][j];
	}
	return (new_board);
}

void	ft_board_print(int **new_board, int **board)
{
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
				printf(ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET, new_board[i][j]);
			else
				printf("%d", new_board[i][j]);
			if (j != 8)
			{
				printf(" ");
				if ((j + 1) % 3 == 0)
					printf("| ");
			}
		}
		printf("\n");
		if (i != 8 && (i + 1) % 3 == 0)
			printf("------+-------+------\n");
	}
}
