# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 22:07:22 by norban            #+#    #+#              #
#    Updated: 2025/06/05 15:10:20 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror
INC = include

SRC_DIR = src
OBJ_DIR = obj

DEF_COLOR	=	\033[0;37m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[1;96m
WHITE		=	\033[0;97m

SRCS_LIST = is/ft_islower.c \
			is/ft_isalpha.c \
			is/ft_isdigit.c \
			is/ft_isalnum.c \
			is/ft_isascii.c \
			is/ft_isprint.c \
			is/ft_isspace.c \
			str/ft_strlen.c \
			str/ft_strtrimlen.c \
			mem/ft_memset.c \
			mem/ft_bzero.c \
			mem/ft_memcpy.c \
			mem/ft_memmove.c \
			mem/ft_memchr.c \
			str/ft_strlcpy.c \
			str/ft_strlcat.c \
			to/ft_toupper.c \
			to/ft_tolower.c \
			str/ft_strchr.c \
			str/ft_strrchr.c \
			str/ft_strncmp.c \
			mem/ft_memcmp.c \
			str/ft_strnstr.c \
			to/ft_atoi.c \
			mem/ft_calloc.c \
			str/ft_strdup.c \
			is/ft_isupper.c \
			str/ft_substr.c \
			str/ft_strjoin.c \
			str/ft_strjoin_nl.c \
			str/ft_strtrim.c \
			str/ft_strntrim.c \
			str/sortstring.c \
			str/ft_split.c \
			str/ft_free_split.c \
			str/str_replace.c \
			to/ft_itoa.c \
			str/ft_strmapi.c \
			str/ft_striteri.c \
			str/get_next_line.c \
			str/get_next_line_utils.c \
			put/ft_putchar_fd.c \
			put/ft_putstr_fd.c \
			put/ft_putendl_fd.c \
			put/ft_putnbr_fd.c \
			lst/ft_lstiter_bonus.c \
			lst/ft_lstmap_bonus.c \
			lst/ft_lstnew_bonus.c \
			lst/ft_lstadd_front_bonus.c \
			lst/ft_lstsize_bonus.c \
			lst/ft_lstlast_bonus.c \
			lst/ft_lstadd_back_bonus.c \
			lst/ft_lstdelone_bonus.c \
			lst/ft_lstclear_bonus.c

SRCS		= 	$(addprefix $(SRC_DIR)/, $(SRCS_LIST))
OBJS		= 	$(addprefix $(OBJ_DIR)/, $(SRCS_LIST:.c=.o))

NAME = libft.a

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@echo "$(YELLOW) 📦 Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(NAME): $(OBJS)
		@ar -rcs $(NAME) $(OBJS)
		@echo ""
		@echo "$(BOLD)$(GREEN)		✅ $(NAME) compiled ✅$(DEF_COLOR)"
		@echo ""

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -rf $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR)/is
		@mkdir -p $(OBJ_DIR)/str
		@mkdir -p $(OBJ_DIR)/put
		@mkdir -p $(OBJ_DIR)/mem
		@mkdir -p $(OBJ_DIR)/to
		@mkdir -p $(OBJ_DIR)/lst

re: fclean all



.PHONY:
	re make all fclean clean bonus
