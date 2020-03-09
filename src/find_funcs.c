/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:10:12 by cdarci            #+#    #+#             */
/*   Updated: 2020/02/06 16:10:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static int	add_new_option(int number, t_options **list_of_options)
{
	t_options	*new_option = NULL;
	t_options	*pointer = NULL;

	if (list_of_options)
	{
		if (!(new_option = (t_options *)malloc(sizeof(t_options))))
			return (0);
		new_option->number = number;
		new_option->next = NULL;
		if (!(*list_of_options))
			(*list_of_options) = new_option;
		else
		{
			pointer = *list_of_options;
			while (pointer->next)
				pointer = pointer->next;
			pointer->next = new_option;
		}
		return (1);
	}
	return (0);
}

int			find_fill_options_for_each_cell(t_sudoku **sudoku)
{
	if (!sudoku)
		return (0);
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (sudoku[i][j].initial_number == 1)
				continue;
			for (int number = 1; number <= 9; number++)
			{
				sudoku[i][j].number_in_the_cell = number;
				if (check_cell_in_sudoku(i, j, sudoku))
				{
					if (!add_new_option(number, &sudoku[i][j].filling_options))
						return (0);	
				}
			}
			sudoku[i][j].number_in_the_cell = 0;
		}
	}
	return (1);
}

static int	check_if_all_fill(t_sudoku **sudoku)
{
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (sudoku[i][j].number_in_the_cell == 0)
				return (0);
		}
	}
	return (1);
}

int			find_sudoku_solutions(t_sudoku **sudoku)
{
	t_options		*list_of_options = NULL;
	static size_t	solution_number;

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (sudoku[i][j].number_in_the_cell != 0)
				continue ;
			list_of_options = sudoku[i][j].filling_options;
			while (list_of_options)
			{
				sudoku[i][j].number_in_the_cell = list_of_options->number;
				if (!check_cell_in_sudoku(i, j, sudoku))
					list_of_options = list_of_options->next;
				else if (find_sudoku_solutions(sudoku))
					list_of_options = list_of_options->next;
				else if (check_if_all_fill(sudoku))
				{
					list_of_options = list_of_options->next;
					display_sudoku(++solution_number, sudoku);
					printf("\n");
				}
				else
					return (0);
			}
			sudoku[i][j].number_in_the_cell = 0;
			return (1);
		}
	}
	return (0);
}
