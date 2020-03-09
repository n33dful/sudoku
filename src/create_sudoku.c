/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sudoku.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:10:12 by cdarci            #+#    #+#             */
/*   Updated: 2020/02/06 16:10:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static t_sudoku	**create_empty_sudoku(void)
{
	t_sudoku	**sudoku = NULL;

	if (!(sudoku = (t_sudoku **)malloc(sizeof(t_sudoku *) * 9)))
		return (NULL);
	for (size_t i = 0; i < 9; i++)
	{
		if (!(sudoku[i] = (t_sudoku *)malloc(sizeof(t_sudoku) * 9)))
		{
			delete_sudoku(&sudoku);
			return (NULL);
		}
		for (size_t j = 0; j < 9; j++)
		{
			sudoku[i][j].number_in_the_cell = 0;
			sudoku[i][j].initial_number = 0;
			sudoku[i][j].filling_options = NULL;
		}
	}
	return (sudoku);
}

static int		fill_line_in_sudoku(size_t i, char *line, t_sudoku **sudoku)
{
	for (size_t j = 0; j < 9; j++)
	{
		if (line[j] == '.')
			continue;
		else if (isdigit(line[j]) && line[j] != '0')
		{
			sudoku[i][j].number_in_the_cell = line[j] - '0';
			sudoku[i][j].initial_number = 1;
		}
		else
			return (0);
	}
	return (1);
}

static t_sudoku	**ft_error(char **line, t_sudoku ***sudoku, FILE **stream)
{
	if (line && (*line))
	{
		free((*line));
		(*line) = NULL;
	}
	delete_sudoku(sudoku);
	if (stream && (*stream))
	{
		fclose((*stream));
		(*stream) = NULL;
	}
	return (NULL);
}

static t_sudoku	**create_sudoku_from_args(char **argv)
{
	t_sudoku	**sudoku = NULL;

	if (!(sudoku = create_empty_sudoku()))
		return (NULL);
	for (size_t i = 0; i < 9; i++)
	{
		if (strlen(argv[i + 1]) != 9)
			return (ft_error(NULL, &sudoku, NULL));
		if (!fill_line_in_sudoku(i, argv[i + 1], sudoku))
			return (ft_error(NULL, &sudoku, NULL));
	}
	if (!check_the_input_sudoku(sudoku))
		delete_sudoku(&sudoku);
	return (sudoku);
}

static t_sudoku	**create_sudoku_from_file(FILE *stream)
{
	t_sudoku	**sudoku = NULL;
	ssize_t		nread = 0;
	size_t		i = 0;
	size_t		len = 0;
	char		*line = NULL;

	if (!(sudoku = create_empty_sudoku()))
		return (NULL);
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		line[nread - 1] = '\0';
		if (strlen(line) != 9 || i == 9)
			return (ft_error(&line, &sudoku, &stream));
		if (!fill_line_in_sudoku(i++, line, sudoku))
			return (ft_error(&line, &sudoku, &stream));
	}
	free(line);
	if (!check_the_input_sudoku(sudoku))
		delete_sudoku(&sudoku);
	return (sudoku);
}

t_sudoku		**create_sudoku(int argc, char **argv)
{
	t_sudoku	**sudoku = NULL;
	FILE		*stream = NULL;

	if (argc == 2)
	{
		if (!(stream = fopen(argv[1], "r")))
			return (NULL);
		if (!(sudoku = create_sudoku_from_file(stream)))
		{
			fclose(stream);
			return (NULL);
		}
		fclose(stream);
		return (sudoku);
	}
	else if (argc == 10)
	{
		if (!(sudoku = create_sudoku_from_args(argv)))
			return (NULL);
	}
	return (sudoku);
}
