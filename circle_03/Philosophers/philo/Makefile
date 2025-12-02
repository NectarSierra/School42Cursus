# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 11:06:40 by nsaillez          #+#    #+#              #
#    Updated: 2025/05/21 09:53:37 by nsaillez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
NAME		= philo
FLAGS		= -Wall -Wextra -Werror
FSAN_FLAGS	= -fsanitize=thread

FILES		= 	./main.c\
				./param.c\
				./init_simu.c\
				./debug.c\
				./philo_cycle.c\
				./philo_actions.c\
				./simu_utils.c\
				./monitor.c\

OBJSDIR = objs
OBJS = $(FILES:%.c=$(OBJSDIR)/%.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -g -o $(NAME)

$(OBJSDIR)/%.o: %.c | $(OBJSDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

wof:
	$(CC) $(FILES) -o $(NAME)	

fsan:
	$(CC) $(FLAGS) $(FSAN_FLAGS) $(FILES) -g -o $(NAME)	

re: fclean $(NAME)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)
