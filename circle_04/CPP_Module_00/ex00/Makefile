# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 10:39:46 by nsaillez          #+#    #+#              #
#    Updated: 2025/09/02 10:39:49 by nsaillez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP     = g++
FLAGS    = -Wall -Wextra -Werror
STD_FLAG = -std=c++98
OUT_NAME = megaphone
SRCS     = megaphone.cpp
OBJS     = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(COMP) -c $(FLAGS) $(STD_FLAG) $< -o $@

$(OUT_NAME): $(OBJS)
	$(COMP) $(FLAGS) $(STD_FLAG) $(OBJS) -o $(OUT_NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(OUT_NAME)

re: fclean $(OUT_NAME)
