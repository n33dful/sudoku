#ifndef SUDOKU_H
#define SUDOKU_H

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct sudoku
{
	int i;
	int j;
	int *opts;
	int count_of_opts;
	struct sudoku *next;
} su_list;

void add_next(su_list **list, su_list *new);
int check_all(int board[9][9]);
int check_horizontally(int board[9][9], size_t i);
int check_square(int board[9][9], size_t i, size_t j);
int check_vertically(int board[9][9], size_t j);
int check(int board[9][9], size_t i, size_t j);
void copy_board(int new_board[9][9], int board[9][9]);
void create_board(int board[9][9], char **argv);
su_list *create_list(size_t i, size_t j, int *opts, int count_of_opts);
void del_one_elem_of_list(su_list **list);
void delete_list(su_list **list);
int find_answer(int board[9][9], su_list *list);
su_list *find_opts(int board[9][9]);
void print_board(int new_board[9][9], int board[9][9]);

#endif