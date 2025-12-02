# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matsauva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 09:03:33 by matsauva          #+#    #+#              #
#    Updated: 2024/10/22 18:42:54 by matsauva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC         = cc
CFLAGS     = -Wall -Wextra -Werror -I includes

# Directories
SRC_DIR    = srcs
OBJ_DIR    = objs
INC_DIR    = includes

# Project files
NAME       = libft.a
SRCS       = $(SRC_DIR)/ft_isalpha.c \
             $(SRC_DIR)/ft_isdigit.c \
             $(SRC_DIR)/ft_isalnum.c \
             $(SRC_DIR)/ft_isascii.c \
             $(SRC_DIR)/ft_isprint.c \
             $(SRC_DIR)/ft_strlen.c \
             $(SRC_DIR)/ft_memset.c \
             $(SRC_DIR)/ft_bzero.c \
             $(SRC_DIR)/ft_memcpy.c \
             $(SRC_DIR)/ft_memmove.c \
             $(SRC_DIR)/ft_strlcpy.c \
             $(SRC_DIR)/ft_strlcat.c \
             $(SRC_DIR)/ft_toupper.c \
             $(SRC_DIR)/ft_tolower.c \
             $(SRC_DIR)/ft_strchr.c \
             $(SRC_DIR)/ft_strrchr.c \
             $(SRC_DIR)/ft_strncmp.c \
             $(SRC_DIR)/ft_strnstr.c \
             $(SRC_DIR)/ft_memchr.c \
             $(SRC_DIR)/ft_memcmp.c \
             $(SRC_DIR)/ft_atoi.c \
             $(SRC_DIR)/ft_calloc.c \
             $(SRC_DIR)/ft_strdup.c \
             $(SRC_DIR)/ft_substr.c \
             $(SRC_DIR)/ft_strjoin.c \
             $(SRC_DIR)/ft_strtrim.c \
             $(SRC_DIR)/ft_split.c \
             $(SRC_DIR)/ft_itoa.c \
             $(SRC_DIR)/ft_strmapi.c \
             $(SRC_DIR)/ft_striteri.c \
             $(SRC_DIR)/ft_putchar_fd.c \
             $(SRC_DIR)/ft_putstr_fd.c \
             $(SRC_DIR)/ft_putendl_fd.c \
             $(SRC_DIR)/ft_putnbr_fd.c \
             $(SRC_DIR)/ft_lstnew.c \
             $(SRC_DIR)/ft_lstadd_front.c \
             $(SRC_DIR)/ft_lstsize.c \
             $(SRC_DIR)/ft_lstlast.c \
             $(SRC_DIR)/ft_lstadd_back.c \
             $(SRC_DIR)/ft_lstdelone.c \
             $(SRC_DIR)/ft_lstclear.c \
             $(SRC_DIR)/ft_lstiter.c \
             $(SRC_DIR)/ft_lstmap.c \
             $(SRC_DIR)/ft_rand.c \
             $(SRC_DIR)/ft_strndup.c \
             $(SRC_DIR)/ft_strcat.c \
             $(SRC_DIR)/ft_strcmp.c 
             

OBJS       = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library created: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files and folder removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Library removed."

re: fclean all

.PHONY: all clean fclean re
