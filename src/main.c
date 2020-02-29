#include "sudoku.h"

int main(int argc, char **argv)
{
	su_list *list;
	int new_board[9][9];
	int board[9][9];

	if (argc != 10)
	{
		printf("usege: ./sudoku \"..2...41.\" \"...2...6.\" ...\n");
		exit(EXIT_FAILURE);
	}
	create_board(board, argv);
	copy_board(new_board, board);
	list = find_opts(new_board);
	find_answer(new_board, list);
	print_board(new_board, board);
	delete_list(&list);
	exit(EXIT_SUCCESS);
}