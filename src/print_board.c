#include "sudoku.h"

void print_board(int new_board[9][9], int board[9][9])
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
				printf(ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET, new_board[i][j]);
			else
				printf("%d", new_board[i][j]);
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
