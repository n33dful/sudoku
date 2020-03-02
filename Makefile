C=gcc 
FLAGS=-Wall -Wextra -Werror -O3
FILES=ft_boardfuncs.c\
ft_checkfuncs.c\
ft_findfuncs.c\
ft_lstfuncs.c\
main.c
DIR_S=src
DIR_O=temp
HEADER=incl
NAME=sudoku
SOURCES=$(addprefix $(DIR_S)/, $(FILES))
OBJECTS=$(addprefix $(DIR_O)/, $(FILES:.c=.o))

all : $(NAME)

$(NAME): $(OBJECTS)
	@$(C) $(FLAGS) $(OBJECTS) -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(C) $(FLAGS) -I$(HEADER) -c $< -o $@

clean:
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
