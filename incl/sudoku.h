/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:10:12 by cdarci            #+#    #+#             */
/*   Updated: 2020/02/06 16:10:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_RESET "\x1b[0m"

# include <ctype.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct			s_options
{
	int					number;
	struct s_options	*next;
}						t_options;

typedef struct			s_sudoku
{	
	int					number_in_the_cell;
	int					initial_number;
	struct s_options	*filling_options;
}						t_sudoku;

int			find_fill_options_for_each_cell(t_sudoku **sudoku);
int			find_sudoku_solutions(t_sudoku **sudoku);

int			check_cell_in_sudoku(size_t i, size_t j, t_sudoku **sudoku);
int			check_the_input_sudoku(t_sudoku **sudoku);

t_sudoku	**create_sudoku(int argc, char **argv);
void		display_sudoku(size_t solution_number, t_sudoku **sudoku);
void		delete_sudoku(t_sudoku ***sudoku);

#endif
