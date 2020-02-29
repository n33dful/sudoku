C=gcc 
FLAGS=-Wall -Wextra -Werror
FILES=add_next.c\
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
DIR_S=src
DIR_O=temp
HEADER=incl
NAME=sudoku
SOURCES=$(addprefix $(DIR_S)/, $(FILES))
OBJECTS=$(addprefix $(DIR_O)/, $(FILES:.c=.o))

all : $(NAME)

$(NAME): $(DIR_O) $(OBJECTS)
	$(C) $(FLAGS) $(OBJECTS) -o $(NAME)

$(DIR_O):
	mkdir -p $(DIR_O)

$(DIR_O)/%.o: $(DIR_S)/%.c
	$(C) $(FLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
