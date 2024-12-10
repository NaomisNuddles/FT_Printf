SRC = 	aux_itoas.c		\
		aux_types.c		\
		aux_checks.c	\
		aux_builds.c		\
		ft_printf.c

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = libft/libft.a
OS = $(SRC:.c=.o)

$(NAME):
	@make all -C $(LIBFT_DIR) --no-print-directory
	@cp $(LIBFT) $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@cc -c $(FLAGS) $(SRC)
	@ar -rcs $(NAME) $(OS)
	@make clean --no-print-directory

all: $(NAME)

bonus: re

clean:
	@rm -f $(OS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run:
	@cc -o t $(FLAGS) main.c $(NAME)
	@./t

.PHONY: all bonus clean fclean re run