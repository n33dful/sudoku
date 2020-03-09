
#include "sudoku.h"

static void		display_soluton_number(size_t solution_number)
{
	printf("Found the %ld", solution_number);
	if (solution_number == 1 || solution_number % 10 == 1)
		printf("st");
	else if (solution_number == 2 || solution_number % 10 == 2)
		printf("nd");
	else if (solution_number == 3 || solution_number % 10 == 3)
		printf("rd");
	else
		printf("th");
	printf(" solution\n");
}

void			display_sudoku(size_t solution_number, t_sudoku **sudoku)
{
	if (solution_number)
		display_soluton_number(solution_number);
	printf("0-------0-------0-------0\n");
	for (size_t i = 0; i < 9; i++)
	{
		printf("| ");
		for (size_t j = 0; j < 9; j++)
		{
			if (!sudoku[i][j].initial_number)
				printf(ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET, \
				sudoku[i][j].number_in_the_cell);
			else
				printf("%d", sudoku[i][j].number_in_the_cell);
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
