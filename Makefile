#			-->|   Files to Compile   |<--
FILES		=		aux_itoas aux_types aux_checks aux_builds aux_data aux_format ft_printf

FILES_B		=		aux_itoas_bonus aux_types_bonus aux_checks_bonus aux_builds_bonus aux_data_bonus aux_format_bonus ft_printf_bonus

#			-->|   Titles   |<--
HEAD		=		"42 Printf"
HEAD_B		=		"42 Printf Bonus"
NAME		=		libftprintf.a
LIBFT		=		libft

#			-->|   Command Definitions   |<--
INC_DIR		=		./
SRC_DIR		=		./
OBJ_DIR		=		obj/

SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
SRC_B		=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES_B)))
OBJ_B		=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_B)))
LIBS		=		$(addprefix $(LIBFT)/, $(addsuffix .a, $(LIBFT)))

AR_EXT		=		@make --no-print-directory -C $(LIBFT) all && cp $(LIBS) $(NAME)
M_C			=		@make --no-print-directory -C $(LIBFT) clean
M_F			=		@make --no-print-directory -C $(LIBFT) fclean

FLAGS		=		-Wall -Wextra -Werror
COMPILE		=		@cc $(FLAGS) -I $(INC_DIR) -c $< -o $@
RMV			=		@rm -rf $(OBJ_DIR)
AR			=		@ar -rcs $(NAME) $(OBJ)
AR_B		=		@ar -rcs $(NAME) $(OBJ_B)

EXE			=		@cc -I $(INC_DIR) -o exe .main.c $(NAME) && ./exe other && rm -f exe

#			-->|   Colors & Messages   |<--
START		=		start
START_B		=		start_b

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
T_CREATING_B=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD_B) at $(NAME) $(GRAY)...\n"
T_BUILDING	=		@echo "	$(GRAY)... $(BYELLOW)Building $(NAME) $(GRAY)... \n"
T_COMPILING	=		@echo "	$(GRAY)... $(YELLOW)Compiling $(WHITE)$(FLAGS) $(YELLOW)$< $(GRAY)..."
T_REMOVE_O	=		@echo "$(MAGENTA)$(HEAD): Objects Removed!$(DEF)\n"
T_REMOVE_A	=		@echo "$(BMAGENTA)$(HEAD): All Files Removed!$(DEF)\n"
T_COMPILED	=		@echo "\n$(BGREEN)	     $(HEAD) Compiled!   $(GRAY)|<--$(DEF)\n"
T_EXECUTING	=		@echo "\n$(GRAY)-->|	$(BLUE)Executing: $(BCYAN)$(NAME) - main.c $(BLUE)at $(WHITE)exe $(GRAY)...$(DEF)"
T_EXECUTED	=		@echo "$(GRAY)	...$(BGREEN)Execution Ended!   $(GRAY)|<--$(DEF)\n"

#			-->|   Rules   |<--
.PHONY: all bonus clean fclean re exe

all: $(START) $(NAME) $(OBJ)
	$(AR)
	$(T_COMPILED)

bonus: re
# $(START_B) $(NAME) $(OBJ_B)
#	$(AR_B)
#	$(T_COMPILED)

clean:
	$(M_C)
	$(RMV)
	$(T_REMOVE_O)

fclean:
	$(M_F)
	$(RMV) $(NAME)
	$(T_REMOVE_A)

re: fclean all

exe: re
	$(T_EXECUTING)
	$(EXE)
	$(T_EXECUTED)

#			-->|   File Dependencies   |<--
$(START):
	$(T_CREATING)
	$(T_BUILDING)

$(START_B):
	$(T_CREATING_B)
	$(T_BUILDING)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(T_COMPILING)
	$(COMPILE)

$(NAME):
	$(AR_EXT)