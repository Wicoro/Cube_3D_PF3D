# ========================= COLORS ===========================

GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[36m
RESET = \033[0m
RED = \033[31m
BOLD = \033[1m
UNDERLINE = \033[4m
ITALIC = \033[3m

# ========================= NAMES ============================

NAME = cub3D
NAME_BONUS = cub3D_bonus

# ======================== DIRECTORIES ========================

LIBFT_DIR = libft
MLX_DIR = minilibx-linux
INCLUDE = include

SRC_DIR = mandatory/
OBJ_DIR = $(SRC_DIR)obj/

SRC_DIR_BONUS = bonus/
OBJ_DIR_BONUS = $(SRC_DIR_BONUS)obj/

# ========================== FILES ===========================

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a

SRC = game/game_loop.c game/init.c game/key_events.c \
	game/player.c game/utils.c parsing/get_assets.c  \
	parsing/get_map_utils.c parsing/get_map.c \
	parsing/parse_map_border.c raycasting/display_wall.c \
	raycasting/draw_ray.c raycasting/raycasting.c main.c \
	parsing/get_rgb_assets.c

SRC := $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SRC_BONUS = game/game_loop_bonus.c game/init_bonus.c game/key_events_bonus.c \
	game/mouse_bonus.c game/player_bonus.c game/utils_bonus.c \
	parsing/get_assets_bonus.c parsing/get_map_utils_bonus.c parsing/get_map_bonus.c \
	parsing/parse_map_border_bonus.c minimap/minimap_utils_bonus.c minimap/minimap_bonus.c \
	raycasting/display_wall_bonus.c raycasting/draw_ray_bonus.c game/interact_door_bonus.c \
	raycasting/raycasting_bonus.c main.c game/init_helper_bonus.c parsing/get_rgb_assets_bonus.c

SRC_BONUS := $(addprefix $(SRC_DIR_BONUS), $(SRC_BONUS))
OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR_BONUS)%.c=$(OBJ_DIR_BONUS)%.o)

# ========================== FLAGS ===========================

CFLAGS = -Wall -Wextra -Werror -MMD -MP -g
EXTRAFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

ifeq ($(SAN),1)
	FSANITIZE = -g3
	OPTIFLAGS =
else
	FSANITIZE =
	OPTIFLAGS = -O3
endif

# ========================= TARGETS ==========================

all: logo $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "📦 $(ITALIC)$(YELLOW)Compiling $< $(RESET)"
	@cc $(CFLAGS) $(OPTIFLAGS) $(FSANITIZE) -I $(INCLUDE) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@echo ""
	@echo "	🚀 $(BOLD)$(YELLOW)Linking $(NAME)...$(RESET)"
	@cc $(CFLAGS) $(OPTIFLAGS) $(FSANITIZE) $(OBJ) -o $(NAME) -I $(INCLUDE) $(LIBFT) $(EXTRAFLAGS)
	@echo ""
	@echo "	🎉 $(BOLD)$(GREEN)SUCCESS: $(NAME) has been created$(RESET) ✅"
	@echo ""

bonus: logo $(NAME_BONUS)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(dir $@)
	@echo "📦 $(ITALIC)$(YELLOW)Compiling $< $(RESET)"
	@cc $(CFLAGS) $(OPTIFLAGS) $(FSANITIZE) -I $(INCLUDE) -c $< -o $@

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJ_BONUS)
	@echo ""
	@echo "	🚀 $(BOLD)$(YELLOW)Linking $(NAME_BONUS)...$(RESET)"
	@cc $(CFLAGS) $(OPTIFLAGS) $(FSANITIZE) $(OBJ_BONUS) -o $(NAME_BONUS) -I $(INCLUDE) $(LIBFT) $(EXTRAFLAGS)
	@echo ""
	@echo "	🎉 $(BOLD)$(GREEN)SUCCESS: $(NAME_BONUS) has been created$(RESET) ✅"
	@echo ""

logo:
	@echo ""
	@cat logo.txt
	@echo ""

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "	⚙ $(UNDERLINE)$(BOLD)Building libft $(RESET) ⚙"
	@echo ""

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
	@echo ""
	@echo "	📚 $(BOLD)$(BLUE)SUCCESS: Minilibx has been created$(RESET) 📚"
	@echo ""

clean:
	@echo ""
	@echo "	🧹 $(BOLD)$(BLUE)Cleaning object files 🧹$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@echo "🗑️ $(YELLOW)$(BOLD)Object files cleaned$(RESET)"

fclean: clean
	@echo ""
	@echo "	🧹 $(BOLD)$(BLUE)Cleaning everything 🧹$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "💾 $(YELLOW)Binaries removed$(RESET)"
	@echo "👉 $(BOLD)$(GREEN)Everything has been cleaned$(RESET) ❎"
	@echo ""

re: fclean all

.PHONY: all bonus clean fclean re logo

-include $(OBJ:.o=.d)
-include $(OBJ_BONUS:.o=.d)
