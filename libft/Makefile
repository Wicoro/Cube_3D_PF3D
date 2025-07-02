
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[36m
RESET = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m

LIBFT_DIR = libft_original/
PRINTF_DIR = Printf/
GNL_DIR = GNL/
OBJ_DIR = obj/

NAME = libft.a 
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC

LIBFT_FILES = \
    ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
    ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove \
    ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr \
    ft_strrchr ft_strcmp ft_memchr ft_memcmp ft_strnstr \
    ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim \
    ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd \
    ft_putendl_fd ft_putnbr_fd ft_putstr_fd \
	ft_lstadd_front_bonus ft_lstnew_bonus ft_lstsize_bonus ft_lstlast_bonus \
	ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus \
	ft_lstmap_bonus ft_free ft_isspace ft_strndup ft_strncmp ft_msplit \
	ft_swap ft_strlen_tab ft_atol

PRINTF_FILES = \
	ft_printf_char ft_printf ft_printf_hexa ft_printf_hexup \
	ft_printf_integer ft_printf_string ft_printf_pointer	\
	ft_printf_unsigned

GNL_FILES = \
	get_next_line get_next_line_utils

SRC = $(addprefix $(LIBFT_DIR), $(addsuffix .c, $(LIBFT_FILES))) \
      $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(PRINTF_FILES))) \
      $(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILES)))

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))


all: $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJ)
	@echo ""
	@echo "		⚙ $(UNDERLINE)$(BOLD)Building libft$(RESET) ⚙"
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo "    📚 $(BOLD)$(BLUE)SUCCESS: $(NAME) has been created$(RESET) 📚"
	@echo ""

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🗑️ $(YELLOW)$(BOLD) libft$(RESET)$(YELLOW) object files cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "💾 $(YELLOW)Cleaning $(NAME)$(RESET)"
	@echo "↪️ $(BOLD)$(YELLOW)libft has been cleaned$(RESET) ✅"

re: fclean all

.PHONY: all clean fclean re