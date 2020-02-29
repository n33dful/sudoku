#ifndef SUDOKU_H
#define SUDOKU_H

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct	s_cell
{
	int	i;
	int	j;
	int	*opts;
	int	count_of_opts;
}		t_cell;

typedef struct	s_list
{
	void	*content;
	size_t	content_size;
}		t_list;

#endif
