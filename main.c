#include "sudoku.h"

int check_vertically(int board[9][9], size_t j)
{
	int target;
	size_t count;
	size_t i;

	target = 1;
	while (target <= 9)
	{
		i = 0;
		count = 0;
		while (i < 9)
		{
			if (board[i][j] == target)
				count++;
			i++;
		}
		if (count > 1)
			return (0);
		target++;
	}
	return (1);
}

int check_horizpntally(int board[9][9], size_t i)
{
	int target;
	size_t count;
	size_t j;

	target = 1;
	while (target <= 9)
	{
		j = 0;
		count = 0;
		while (j < 9)
		{
			if (board[i][j] == target)
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		target++;
	}
	return (1);
}

int check_square(int board[9][9], size_t i, size_t j)
{
	int target;
	size_t count;
	size_t new_i;
	size_t new_j;
	size_t end_i;
	size_t end_j;

	target = 1;
	while (target <= 9)
	{
		count = 0;
		new_i = i / 3 * 3;
		end_i = new_i + 3;
		while (new_i < end_i)
		{
			new_j = j / 3 * 3;
			end_j = new_j + 3;
			while (new_j < end_j)
			{
				if (board[new_i][new_j] == target)
					count++;
				new_j++;
			}
			new_i++;
		}
		if (count > 1)
			return (0);
		target++;
	}
	return (1);
}

int check(int board[9][9], size_t i, size_t j)
{
	if (!check_vertically(board, j) || !check_horizpntally(board, i) || !check_square(board, i, j))
		return (0);
	return (1);
}

void create_board(int board[9][9], char **argv)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 9)
	{
		if (strlen(argv[i + 1]) != 9 || !argv[i + 1])
		{
			printf("%s", "invalid data\n");
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (j < 9)
		{
			if (isdigit(argv[i + 1][j]) && argv[i + 1][j] - '0' != 0)
				board[i][j] = argv[i + 1][j] - '0';
			else if (argv[i + 1][j] == '.')
				board[i][j] = 0;
			else
			{
				printf("%s", "invalid data\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (!check(board, i, j))
			{
				printf("%s", "invalid data\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void print_board(int board[9][9])
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (board[i][j] == 0)
				printf(ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET, board[i][j]);
			else
				printf("%d", board[i][j]);
			if (j != 8)
			{
				printf(" ");
				if ((j + 1) % 3 == 0)
					printf("| ");
			}
			j++;
		}
		printf("\n");
		if (i != 8 && (i + 1) % 3 == 0)
			printf("------+-------+------\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	int board[9][9];

	if (argc != 10)
	{
		printf("%s", "invalid count of arguments\n");
		exit(EXIT_FAILURE);
	}
	create_board(board, argv);
	print_board(board);
	exit(EXIT_SUCCESS);
}