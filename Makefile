FLAGS=-Werror -Wextra -Wall
NAME=push_swap
SRC=*.c
INCLUDES=libft/libft.a

all:
	@make -C libft/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES)

clean:
	@make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
