NAME = sudoku

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror main.c
	gcc -Wall -Wextra -Werror main.o -o $(NAME)

clean:
	/bin/rm main.o

fclean:
	/bin/rm $(NAME)

re: fclean all