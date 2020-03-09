/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:10:12 by cdarci            #+#    #+#             */
/*   Updated: 2020/02/06 16:10:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static int	check_horizontally(size_t i, t_sudoku **sudoku)
{
	size_t	count = 0;

	for (int target = 1; target <= 9; target++)
	{
		count = 0;
		for (size_t j = 0; j < 9; j++)
		{
			if (sudoku[i][j].number_in_the_cell == target)
				count++;
		}
		if (count > 1)
			return (0);
	}
	return (1);
}

static int	check_vertically(size_t j, t_sudoku **sudoku)
{
	size_t	count = 0;

	for (int target = 1; target <= 9; target++)
	{
		count = 0;
		for (size_t i = 0; i < 9; i++)
		{
			if (sudoku[i][j].number_in_the_cell == target)
				count++;
		}
		if (count > 1)
			return (0);
	}
	return (1);
}

static int	check_square(size_t i, size_t j, t_sudoku **sudoku)
{
	size_t	start_i = i / 3 * 3;
	size_t	start_j = j / 3 * 3;
	size_t	end_i = start_i + 3;
	size_t	end_j = start_j + 3;
	size_t	count = 0;

	for (int target = 1; target <= 9; target++)
	{
		count = 0;
		for (size_t new_i = start_i; new_i < end_i; new_i++)
		{	
			for (size_t new_j = start_j; new_j < end_j; new_j++)
			{
				if (sudoku[new_i][new_j].number_in_the_cell == target)
					count++;
			}
		}
		if (count > 1)
			return (0);
	}
	return (1);
}

int			check_cell_in_sudoku(size_t i, size_t j, t_sudoku **sudoku)
{
	if (!check_vertically(j, sudoku))
		return (0);
	if (!check_horizontally(i, sudoku))
		return (0);
	if (!check_square(i, j, sudoku))
		return (0);
	return (1);
}

int			check_the_input_sudoku(t_sudoku **sudoku)
{
	for (size_t i = 0; i < 9; i++)
	{
		if (sudoku[i] && !check_horizontally(i, sudoku))
			return (0);
		for (size_t j = 0; j < 9; j++)
		{
			if (!check_vertically(j, sudoku))
				return (0);
			if (j % 3 == 0 && !check_square(i, j, sudoku))
				return (0);
		}
	}
	return (1);
}
