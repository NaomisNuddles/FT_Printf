SRC =

SRCB =

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
OS = $(SRC:.c=.o)
OSB = $(SRCB:.c=.o)

$(NAME):
	@cc -c $(FLAGS) $(SRC)
	@ar -rcs $(NAME) $(OS)

all: $(NAME)

bonus:
	@cc -c $(FLAGS) $(SRCB)
	@ar -rcs $(NAME) $(OSB)

clean:
	@rm -f $(OS) $(OSB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re