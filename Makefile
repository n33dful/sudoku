NAME=sudoku
CC=gcc 
CPPFLAGS=-Wall -Wextra -Werror
FILES = add_next.c\
		check_all.c\
		check_horizontally.c\
		check_square.c\
		check_vertically.c\
		check.c\
		copy_board.c\
		create_board.c\
		create_list.c\
		del_one_elem_of_list.c\
		delete_list.c\
		find_answer.c\
		find_opts.c\
		main.c\
		print_board.c
OBJECTS = $(FILES:.c=.o)
OBJSDIR=$(addprefix srcs/, $(OBJECTS))


all : $(NAME)

$(NAME) : $(OBJSDIR)
	$(CC) $(OBJSDIR) -o $(NAME)

clean :
	rm -f $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : fclean clean