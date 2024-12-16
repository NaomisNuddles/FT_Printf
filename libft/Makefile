#			-->|   Files to Compile   |<--
FILES		=		ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint			\
					ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp		\
					ft_toupper ft_tolower ft_strchr ft_strrchr ft_strnstr			\
					ft_strlen ft_strncmp ft_strlcpy ft_strlcat ft_atoi ft_itoa		\
					ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split	\
					ft_strmapi ft_striteri											\
					ft_putchar_fd ft_putstr_fd ft_putnbr_fd ft_putendl_fd			\
					ft_lstnew ft_lstadd_front ft_lstadd_back ft_lstsize ft_lstlast	\
					ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

#			-->|   Titles   |<--
HEAD		=		"42 Library"
NAME		=		libft.a

#			-->|   Command Definitions   |<--
INC_DIR		=		./
SRC_DIR		=		./
OBJ_DIR		=		obj/

SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

FLAGS		=		-Wall -Wextra -Werror
COMPILE		=		@cc $(FLAGS) -I $(INC_DIR) -c $< -o $@
RMV			=		@rm -rf $(OBJ_DIR)
AR			=		@ar -rcs $(NAME) $(OBJ)

#			-->|   Colors & Messages   |<--
START		=		start

GRAY		=		\033[0;30m
GREEN		=		\033[0;32m
YELLOW		=		\033[0;33m
BLUE		=		\033[0;34m
MAGENTA		=		\033[0;35m
CYAN		=		\033[0;36m
WHITE		=		\033[0;37m
DEF			=		\033[0;39m

BGREEN		=		\033[1;32m
BYELLOW		=		\033[1;33m
BBLUE		=		\033[1;34m
BMAGENTA	=		\033[1;35m
BCYAN		=		\033[1;36m

T_CREATING	=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD) at $(NAME) $(GRAY)...\n"
T_BUILDING	=		@echo "	$(GRAY)... $(BYELLOW)Building $(NAME) $(GRAY)... \n"
T_COMPILING	=		@echo "	$(GRAY)... $(YELLOW)Compiling $< $(GRAY)..."
T_REMOVE_O	=		@echo "$(MAGENTA)$(HEAD): Objects Removed!$(DEF)\n"
T_REMOVE_A	=		@echo "$(BMAGENTA)$(HEAD): All Files Removed!$(DEF)\n"
T_COMPILED	=		@echo "\n$(BGREEN)	     $(HEAD) Compiled!   $(GRAY)|<--$(DEF)\n"
T_EXECUTING	=		@echo "\n$(GRAY)-->|	$(BLUE)Executing: $(BCYAN)$(NAME) - main.c $(BLUE)at $(WHITE)exe $(GRAY)...$(DEF)"
T_EXECUTED	=		@echo "$(GRAY)	...$(BGREEN)Execution Ended!   $(GRAY)|<--$(DEF)\n"

#			-->|   Rules   |<--
.PHONY: all clean fclean re

all: $(START) $(NAME)
	$(T_COMPILED)

clean:
	$(RMV)
	$(T_REMOVE_O)

fclean:
	$(RMV) $(NAME)
	$(T_REMOVE_A)

re: fclean all

#			-->|   File Dependencies   |<--
$(START):
	$(T_CREATING)
	$(T_BUILDING)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(T_COMPILING)
	$(COMPILE)

$(NAME): $(OBJ)
	$(AR)
