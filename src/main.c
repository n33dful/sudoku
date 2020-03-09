/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:10:12 by cdarci            #+#    #+#             */
/*   Updated: 2020/02/06 16:10:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** Function to delete all allocated memory and exit
*/
static void	termination(int exit_code, char *message, t_sudoku ***sudoku)
{
	if (message && !errno)
		printf("%s\n", message);
	else
		printf("%s\n", strerror(errno));
	delete_sudoku(sudoku);
	exit(exit_code);
}

/*
** Main Function
*/
int			main(int argc, char **argv)
{
	t_sudoku	**sudoku = NULL;

	if (argc == 1)
		termination(EXIT_SUCCESS, "Check README.txt", &sudoku);
	else if (!(sudoku = create_sudoku(argc, argv)))
		termination(EXIT_FAILURE, "Invalid map!", &sudoku);
	else if (!find_fill_options_for_each_cell(sudoku))
		termination(EXIT_FAILURE, "Memory error!", &sudoku);
	else if (find_sudoku_solutions(sudoku))
		termination(EXIT_SUCCESS, "All solutions are found", &sudoku);
	else
		display_sudoku(0, sudoku);
	termination(EXIT_SUCCESS, NULL, &sudoku);
}
