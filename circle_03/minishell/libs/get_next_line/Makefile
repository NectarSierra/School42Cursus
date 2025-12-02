# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matsauva <matsauva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 17:00:00 by matsauva          #+#    #+#              #
#    Updated: 2025/01/21 17:00:00 by matsauva         ###   ########.fr        #
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
NAME       = get_next_line.a
SRCS       = $(SRC_DIR)/get_next_line.c
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
