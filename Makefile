# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 16:10:12 by cdarci            #+#    #+#              #
#    Updated: 2020/02/06 16:10:17 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc 
CCFLAGS=-Wall -Wextra -Werror -O3
DFLAGS=-MD
FILES=main.c\
check_sudoku.c\
delete_sudoku.c\
create_sudoku.c\
display_sudoku.c\
find_funcs.c
DIR_S=src
DIR_O=temp
DIR_H=incl
NAME=sudoku
SOURCES=$(addprefix $(DIR_S)/, $(FILES))
OBJECTS=$(addprefix $(DIR_O)/, $(FILES:.c=.o))

all : $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(DFLAGS) $(CCFLAGS) -I$(DIR_H) -c $< -o $@
	
-include $(OBJECTS:.o=.d)

clean:
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
