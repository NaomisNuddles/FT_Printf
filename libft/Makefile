#			-->|   Files   |<--
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
START		=		start
HEAD		=		"42 Library"

NAME		=		libft.a
#DIRS		=		libft
DIRS		=		"FALSE"

#			-->|   Directory Definitions   |<--
INC			=		./
SRC			=		./
OBJ			=		obj/

#			-->|   Colors   |<--
DEF			=		\033[0;39m
ORANGE		=		\033[0;33m
PURPLE		=		\033[0;35m
GRAY		=		\033[0;90m
RED			=		\033[0;91m
GREEN		=		\033[0;92m
YELLOW		=		\033[0;93m
BLUE		=		\033[0;94m
MAGENTA		=		\033[0;95m
CYAN		=		\033[0;96m
WHITE		=		\033[0;97m

#			-->|   Object Handle   |<--
SRC_C		=		$(addprefix $(SRC), $(addsuffix .c, $(FILES)))
SRC_O		=		$(addprefix $(OBJ), $(addsuffix .o, $(FILES)))
LIBS		=		$(addprefix $(DIRS)/, $(addsuffix .a, $(DIRS))) 

#			-->|   Command Definitions   |<--
CC_F		=		@cc -Wall -Wextra -Werror -I
M			=		@make --no-print-directory

ifeq ($(DIRS),"FALSE")
M_DA		=
M_DC		=
M_DF		=
CP			=
LIBS		=
else
M_DA		=		@make --no-print-directory -C $(DIRS) all
M_DC		=		@make --no-print-directory -C $(DIRS) clean
M_DF		=		@make --no-print-directory -C $(DIRS) fclean
CP			=		@cp $(LIBS) $(NAME)
LIBS		=		$(addprefix $(DIRS)/, $(addsuffix .a, $(DIRS)))
endif

#			-->|   Rules   |<--
.PHONY: all bonus clean fclean re exe

all: $(START) $(NAME)
	@echo "$(GREEN)	     $(HEAD) Compiled!   $(GRAY)|<--$(DEF)\n"

bonus: re

clean:
	$(M_DC)
	@rm -rf $(OBJ)
	@echo "$(CYAN)$(HEAD): Objects Removed!$(DEF)\n"


fclean:
	$(M_DF)
	@rm -rf $(NAME) $(OBJ)
	@echo "$(BLUE)$(HEAD): All Files Removed!$(DEF)\n"

re: fclean all

exe: re
	@echo "\n$(GRAY)	-->|	$(PURPLE)Executing: $(WHITE) exe.a of $(MAGENTA)$@ - main.c $(DEF)..."
	$(CC) -o exe main*.c $(NAME)
	@./exe.a bonus
	@rm -f exe
	$(M) clean
	@echo "$(GRAY)...$(GREEN)Execution Ended!   $(GRAY)|<--$(DEF)\n"

#			-->|   File Dependencies   |<--
$(START):
	@echo "$(GRAY)-->|	$(MAGENTA)Creating $(HEAD) at $(NAME) $(GRAY)...\n"

$(OBJ):
	@mkdir $(OBJ)

$(OBJ)%.o: $(SRC)%.c | $(OBJ)
	@echo "	$(GRAY)... $(YELLOW)Compiling $< $(GRAY)..."
	$(CC_F) $(INC) -c $< -o $@

$(NAME): $(SRC_O)
	@echo "\n	$(GRAY)... $(ORANGE)Building $@ $(GRAY)... \n"
	$(M_DA)
	$(CP)
	@ar -rcs $@ $(SRC_O)
