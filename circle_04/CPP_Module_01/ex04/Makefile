# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 12:47:03 by nsaillez          #+#    #+#              #
#    Updated: 2025/09/04 13:18:58 by nsaillez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP     = c++
FLAGS    = -Wall -Wextra -Werror
STD_FLAG = -std=c++98
OUT_NAME = output

SRCS     = main.cpp 

OBJ_DIR  = objs
OBJS     = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(OUT_NAME)

$(OUT_NAME): $(OBJS)
	$(COMP) $(FLAGS) $(STD_FLAG) $(OBJS) -o $(OUT_NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(COMP) -c $(FLAGS) $(STD_FLAG) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(OUT_NAME)

re: fclean all

.PHONY: all clean fclean re
