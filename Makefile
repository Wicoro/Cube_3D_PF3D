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
STEF_DIR = stef/
PARSING_DIR = parsing/
EXEC_DIR = exec/

INCLUDE = include

PARSING =	get_assets.c \
			get_map.c \
			get_map_utils.c \
			parse_map_border.c

STEF = 		execution.c

EXEC =		minimap.c

SRC =		cub3d.c \
			$(addprefix $(STEF_DIR), $(STEF)) \
			$(addprefix $(PARSING_DIR), $(PARSING)) \
			$(addprefix $(EXEC_DIR), $(EXEC))

OBJ = 		$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

CFLAGS = -Wall -Wextra -Werror -MMD -MP
OPTIFLAGS = -O3
EXTRAFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
FSANITIZE = #-g3 -fsanitize=address
MAKE = make --no-print-directory

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a

NAME = cub3D

all: logo $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "📦 $(ITALIC)$(YELLOW)Compiling $< $(RESET)"
	@cc $(CFLAGS) $(OPTIFLAGS) $(FSANITIZE) -I $(INCLUDE) -c $< -o $@


$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@echo ""
	@echo "		🚀 $(BOLD)$(YELLOW)Linking $(NAME)...$(RESET)"
	@cc $(CFLAGS) $(OPTIFLAGS) $(FSANITIZE) $(OBJ) -o $(NAME) -I $(INCLUDE) $(LIBFT) $(EXTRAFLAGS)
	@echo ""
	@echo "	🎉 $(BOLD)$(GREEN)SUCCESS: $(NAME) has been created$(RESET) ✅ "
	@echo ""

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "		⚙ $(UNDERLINE)$(BOLD)Building Minilibx $(RESET) ⚙"
	@echo ""

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
	@echo ""
	@echo "    📚 $(BOLD)$(BLUE)SUCCESS: Minilibx has been created$(RESET) 📚"
	@echo ""
	@echo "		⚙ $(UNDERLINE)$(BOLD)Building $(NAME) $(RESET) ⚙"
	@echo ""

logo:
	@echo ""
	@cat logo.txt
	@echo ""

clean:
	@echo ""
	@echo "		🧹 $(BOLD)$(BLUE)Cleaning object files 🧹$(RESET)"
	@echo ""
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
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

.PHONY: all logo clean fclean re

-include $(OBJ:.o=.d)
