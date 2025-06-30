CC = cc

NAME		= cube_3d

INC			= include
INC_LIBFT	= libft/include
CFLAGS		= -Wall -Wextra -g3 -Werror #-fsanitize=address
RL_FLAGS	= -lreadline
LIBFT		= libft
LIBFT_A		= libft/libft.a
MAKE_LIB	= make_lib


SRC_DIR		= src/
OBJ_DIR		= obj/

DEF_COLOR	=	\033[0;37m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

BOLD		=	\033[1m
UNDERLINE	=	\033[4m

SRC_LIST	= 	

# BONUS_LIST	=

SRCS		= 	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJS		= 	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

# SRCS_BONUS	=	$(addprefix $(BONUS_DIR), $(BONUS_LIST))
# OBJS_BONUS	= 	$(addprefix $(BOBJ_DIR), $(BONUS_LIST:.c=.o))


all:		$(OBJ_DIR) $(NAME)

$(NAME):	logo $(MAKE_LIB) $(OBJS)
			@$(CC) $(CFLAGS) -I $(INC) $(OBJS) $(LIBFT_A) -o $(NAME) $(RL_FLAGS)
			@echo ""
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) compiled ✅$(DEF_COLOR)"

# bonus:		logo $(MAKE_LIB) $(OBJS_BONUS)
# 			@$(CC) $(CFLAGS) -I $(INC) $(OBJS_BONUS) $(LIBFT_A) -o $(NAME)
# 			@echo ""
# 			@echo "$(GREEN)$(BOLD)		✅ $(NAME)_bonus compiled ✅$(DEF_COLOR)"

re:			fclean all

clean:
			@echo " 🗑 $(YELLOW) Cleaning $(LIBFT) $(DEF_COLOR)"
			@make clean --no-print-directory --silent -C $(LIBFT)

fclean:		clean
			@echo " 🗑 $(YELLOW) Cleaning $(NAME) $(DEF_COLOR)"
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)
			@make fclean --no-print-directory -C $(LIBFT)
			@echo ""
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) files cleaned ✅$(DEF_COLOR)"

logo:
			@cat logo.txt

$(MAKE_LIB):
			@echo "		📚 $(CYAN)$(BOLD) Compiling $(LIBFT) 📚$(DEF_COLOR)"
			@echo ""
			@make --no-print-directory --silent -C $(LIBFT)
			@echo "		💾$(CYAN)$(BOLD) Compiling $(NAME) $(DEF_COLOR)💾"
			@echo ""

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@echo "$(YELLOW) 📦 Compiling $< $(DEF_COLOR)"
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -I $(INC) -I $(INC_LIBFT) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(BOBJ_DIR)%.o: $(BONUS_DIR)%.c
			@echo "$(YELLOW) 📦 Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I $(INC) -I $(INC_LIBFT) -c $< -o $@

$(BOBJ_DIR):
			@mkdir -p $(BOBJ_DIR)

.PHONY:		all clean fclean re
