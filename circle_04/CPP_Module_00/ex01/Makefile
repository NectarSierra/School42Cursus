# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 10:39:55 by nsaillez          #+#    #+#              #
#    Updated: 2025/09/02 12:08:29 by nsaillez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP     = g++
FLAGS    = -Wall -Wextra -Werror
STD_FLAG = -std=c++98
OUT_NAME = phonebook
SRCS     = main.cpp \
		   PhoneBook.cpp \
		   Contact.cpp
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
