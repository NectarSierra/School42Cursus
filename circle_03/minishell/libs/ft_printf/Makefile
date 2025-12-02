# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: 541l0r <541l0r@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 00:00:00 by 541l0r            #+#    #+#              #
#    Updated: 2024/01/17 00:00:00 by 541l0r           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC         = cc
CFLAGS     = -Wall -Wextra -Werror -I includes

# Directories
SRC_DIR    = srcs
OBJ_DIR    = objs
INC_DIR    = includes

NAME      = libftprintf.a

# Project files
SRC = $(SRC_DIR)/ft_printf.c \
      $(SRC_DIR)/writer.c

OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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

