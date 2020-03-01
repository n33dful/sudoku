#ifndef SUDOKU_H
#define SUDOKU_H

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct		s_cell
{
	int				i;
	int				j;
	int				opts[9];
	int				count_of_opts;
}					t_cell;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd_back(t_list **alst, t_list *new);

t_list				*ft_find_opts(int **board);
int 				ft_find_answer(int **board, t_list *list);

int 				ft_check_cell(size_t i, size_t j, int **board);
int 				ft_check_all(int **board);

void				ft_celldel(void *content, size_t content_size);
void    			ft_boarddel(int **board);
int					**ft_boardcpy(int **board);
void				ft_board_print(int **new_board, int **board);
int					**ft_board_fill(int argc, char **argv);

#endif
