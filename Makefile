SRC = ft_printf.c		\
		aux_funcs.c

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
OS = $(SRC:.c=.o)
OSB = $(SRCB:.c=.o)

$(NAME):
	@cc -c $(FLAGS) $(SRC)
	@ar -rcs $(NAME) $(OS)
	@make all -C ./libft
	@ar -rcs $(NAME) ./libft/libft.a

all: $(NAME) clean

clean:
	@rm -f $(OS) $(OSB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re