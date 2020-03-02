#ifndef SUDOKU_H
# define SUDOKU_H

# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_RESET "\x1b[0m"

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_cell
{
	int				num;
	int				is_base;
	t_list			*opts;
}					t_cell;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd_back(t_list **alst, t_list *new);

int					ft_find_opts(t_cell **board);
int					ft_find_answer(t_cell **board);

int					ft_check_cell(size_t i, size_t j, t_cell **board);
int					ft_check_all(t_cell **board);

void				ft_celldel(void *content, size_t content_size);
void				ft_board_print(t_cell **board);
void				ft_boarddel(t_cell ***board);
t_cell				**ft_board_fill(int argc, char **argv);

#endif
