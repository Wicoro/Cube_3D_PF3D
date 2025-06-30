GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[36m
RESET = \033[0m
RED = \033[31m
BOLD = \033[1m
UNDERLINE = \033[4m
ITALIC = \033[3m

OBJ_DIR = obj/
SRC_DIR = src/

INCLUDE = headers/minishell.h


SRC = main.c env.c \
	$(addprefix $(BUILTIN_DIR), $(BUILTIN)) $(addprefix $(PARSING_DIR), $(PARSING)) \
	$(addprefix $(HEREDOC_DIR), $(HEREDOC)) $(addprefix $(EXEC_DIR), $(EXEC)) \
	$(addprefix $(FREE_DIR), $(FREE)) $(addprefix $(SIGNALS_DIR), $(SIGNALS))

OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

CFLAGS = -Wall -Wextra -Werror -g3
EXTRAFLAGS = -lreadline
FSANITIZE = -fsanitize=address
MAKE = make --no-print-directory

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = minishell

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "📦 $(ITALIC)$(YELLOW)Compiling $< $(RESET)"
	@cc $(CFLAGS) -I $(INCLUDE) -c $< -o $@


$(NAME): $(LIBFT) $(OBJ)
	@echo ""
	@echo "		🚀 $(BOLD)$(YELLOW)Linking $(NAME)...$(RESET)"
	@cc $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLUDE) $(LIBFT) $(EXTRAFLAGS)
	@echo ""
	@echo "	🎉 $(BOLD)$(GREEN)SUCCESS: $(NAME) has been created$(RESET) ✅ "
	@echo ""

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "		⚙ $(UNDERLINE)$(BOLD)Building $(NAME)$(RESET) ⚙"
	@echo ""

valgrind:
	valgrind --leak-check=full --track-origins=yes --track-fds=yes \
	--trace-children=yes ./minishell

clean:
	@echo ""
	@echo "		🧹 $(BOLD)$(BLUE)Cleaning object files 🧹$(RESET)"
	@echo ""
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "🗑️ $(YELLOW)$(BOLD) minishell$(RESET)$(YELLOW) object files cleaned$(RESET)"



fclean: clean
	@echo ""
	@echo "		🧹 $(BOLD)$(BLUE)Cleaning everything 🧹$(RESET)"
	@echo ""
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "💾 $(YELLOW)Cleaning $(NAME)$(RESET)"
	@echo "↪️ $(YELLOW)$(BOLD)$(NAME) has been cleaned$(RESET) ✅"
	@rm -f $(NAME)
	@echo ""
	@echo "	👉 $(BOLD)$(GREEN)Everything has been cleaned$(RESET) ❎"
	@echo ""

re: fclean $(NAME)

.PHONY: all clean fclean re
