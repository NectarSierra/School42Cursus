PATHTOLIBFT = "./libft/"
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap
NAME_BONUS = checker
DEPS = ./srcs/push_swap.h
BONUS_SRCS = ./bonus/main.c\
		./srcs/arguments/arg_manager.c\
		./srcs/arguments/arg_overflow.c\
		./srcs/list/list_manager.c\
		./srcs/list/list_free.c\
		./srcs/operations/swap.c\
		./srcs/operations/push.c\
		./srcs/operations/rotate.c\
		./srcs/operations/rotate_n.c\
		./srcs/algorythm/sort.c\
		./srcs/algorythm/median_sort.c\
		./srcs/algorythm/small_sort.c\
		./srcs/algorythm/turk_sort.c\
		./srcs/algorythm/sort_utils.c\
		./srcs/algorythm/apply_rotation.c\

SRCS = ./srcs/main.c\
	   ./srcs/arguments/arg_manager.c\
	   ./srcs/arguments/arg_overflow.c\
	   ./srcs/list/list_manager.c\
	   ./srcs/list/list_free.c\
	   ./srcs/operations/swap.c\
	   ./srcs/operations/push.c\
	   ./srcs/operations/rotate.c\
	   ./srcs/operations/rotate_n.c\
	   ./srcs/algorythm/sort.c\
	   ./srcs/algorythm/median_sort.c\
	   ./srcs/algorythm/small_sort.c\
	   ./srcs/algorythm/turk_sort.c\
	   ./srcs/algorythm/sort_utils.c\
	   ./srcs/algorythm/apply_rotation.c\

LIBFT_A = libft.a\

$(NAME):
	cd $(PATHTOLIBFT) && make bonus
	$(CC) $(SRCS) $(CFLAGS) ./libft/libft.a -o $(NAME)

$(NAME_BONUS):
	cd $(PATHTOLIBFT) && make bonus
	$(CC) $(BONUS_SRCS) $(CFLAGS) ./libft/libft.a -o $(NAME_BONUS)

all: $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	cd $(PATHTOLIBFT) && make clean

fclean: clean
	$(RM) $(NAME) "checker"
	cd $(PATHTOLIBFT) && make fclean

re: fclean $(NAME)

re_bonus: fclean $(NAME_BONUS)

.PHONY: all clean fclean re